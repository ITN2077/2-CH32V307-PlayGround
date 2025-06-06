/*********************************************************************************************************************
/**
 * @file    motor_step_controller.h
 * @brief   步进控制模块（适用于无编码器直流有刷电机）
 *
 * @details 本模块通过状态机控制电机"运行-冷却"周期，适用于模拟步进推进等需求。
 *          支持多实例管理，控制逻辑与底层GPIO解耦，用户需提供控制函数。
 *
 * 使用示例：
 *  -------------------------------------------------------------------
 *   1. 初始化GPIO（电机使能、正转、反转）
 *  gpio_init(E2, GPO, 0, GPIO_PIN_CONFIG);
 *  gpio_init(E3, GPO, 0, GPIO_PIN_CONFIG);
 *  gpio_init(E4, GPO, 0, GPIO_PIN_CONFIG);
 *
 *   2. 实现PWM控制函数
 *  void motor1_start(unsigned short duty, motor_direction_et dir) { ... }
 *  void motor1_stop(void) { ... }
 *
 *   3. 创建实例
 *  motor_step_instance_t *m1 = motor_step_instance_create(motor1_start, motor1_stop);
 *
 *   4. 启动电机
 *  motor_step_instance_start(m1, 100, MOTOR_DIR_FORWARD, 100, 30); // 非抢占调用
 *  motor_step_instance_start_non_preemptive(m1, 100, MOTOR_DIR_FORWARD, 100, 30); // 抢占调用
 *
 *   5. 在定时任务中定期调用更新（如每10ms）
 *  motor_step_update(10);
 *  -------------------------------------------------------------------
 *
 * 往复运动功能使用示例：
 *  -------------------------------------------------------------------
 *   1. 初始化GPIO（电机使能、正转、反转）
 *  gpio_init(E2, GPO, 0, GPIO_PIN_CONFIG);
 *  gpio_init(E3, GPO, 0, GPIO_PIN_CONFIG);
 *  gpio_init(E4, GPO, 0, GPIO_PIN_CONFIG);
 *
 *   2. 实现PWM控制函数
 *  void motor1_start(unsigned short duty, motor_direction_et dir) { ... }
 *  void motor1_stop(void) { ... }
 *
 *   3. 创建往复运动实例
 *  motor_recip_instance_t *m1_recip = motor_recip_instance_create(motor1_start, motor1_stop);
 *
 *   4. 启动电机往复运动
 *  // 参数分别为：占空比、正向运动时间(ms)、反向运动时间(ms)、冷却时间(ms)
 *  motor_recip_instance_start(m1_recip, 100, 200, 200, 50); // 抢占式调用
 *  // 或者非抢占式调用
 *  motor_recip_instance_start_non_preemptive(m1_recip, 100, 200, 200, 50);
 *
 *   5. 停止往复运动
 *  motor_recip_instance_stop(m1_recip);
 *
 *   6. 在定时任务中定期调用更新（与步进控制使用相同函数）
 *  motor_step_update(10);
 *  -------------------------------------------------------------------
 *
 * @author 示新Sxx
 * @date   2025/04/24
 * @version V1.0
********************************************************************************************************************/
/**
 * @file motor_step_controller.h
 * @brief 步进电机控制模块，用于控制直流无刷电机的步进驱动
 */
#ifndef __MOTOR_STEP_CONTROLLER_H__
#define __MOTOR_STEP_CONTROLLER_H__

#define MAX_MOTOR_INSTANCES 2

/**
 * @brief 电机旋转方向枚举
 */
typedef enum
{
    MOTOR_DIR_FORWARD,  /**< 电机正向旋转 */
    MOTOR_DIR_BACKWARD, /**< 电机反向旋转 */
} motor_direction_et;

/**
 * @brief 电机步进状态枚举
 */
typedef enum
{
    MOTOR_STEP_STATE_IDLE,    /**< 空闲状态 */
    MOTOR_STEP_STATE_DRIVING, /**< 驱动状态 */
    MOTOR_STEP_STATE_COOLDOWN /**< 冷却状态 */
} motor_step_state_et;

/**
 * @brief 电机步进控制实例结构体
 */
typedef struct
{
    motor_step_state_et state;    /**< 当前状态 */
    unsigned short timer_ms;      /**< 计时器（毫秒） */
    motor_direction_et direction; /**< 旋转方向 */
    _Bool request_pending;        /**< 待处理请求标志 */
    unsigned short pwm_duty;      /**< PWM占空比 */

    unsigned short drive_duration_ms;    /**< 驱动持续时间（毫秒） */
    unsigned short cooldown_duration_ms; /**< 冷却持续时间（毫秒） */

    const void (*start_pwm)(unsigned short duty, motor_direction_et dir); /**< 启动PWM输出函数 */
    const void (*stop_pwm)(void);                                         /**< 停止PWM输出函数 */
} motor_step_instance_t;

/**
 * @brief 电机往复运动状态枚举
 */
typedef enum
{
    MOTOR_RECIP_STATE_IDLE,             /**< 空闲状态 */
    MOTOR_RECIP_STATE_FORWARD,          /**< 正向驱动状态 */
    MOTOR_RECIP_STATE_FORWARD_COOLDOWN, /**< 正向驱动后冷却状态 */
    MOTOR_RECIP_STATE_BACKWARD,         /**< 反向驱动状态 */
    MOTOR_RECIP_STATE_BACKWARD_COOLDOWN /**< 反向驱动后冷却状态 */
} motor_recip_state_et;

/**
 * @brief 电机往复运动控制实例结构体
 */
typedef struct
{
    motor_recip_state_et state; /**< 当前状态 */
    unsigned short timer_ms;    /**< 计时器（毫秒） */
    _Bool request_pending;      /**< 待处理请求标志 */
    _Bool running;              /**< 运行标志，表示是否在执行往复运动 */

    unsigned short pwm_duty;             /**< PWM占空比 */
    unsigned short forward_duration_ms;  /**< 正向驱动持续时间（毫秒） */
    unsigned short backward_duration_ms; /**< 反向驱动持续时间（毫秒） */
    unsigned short cooldown_duration_ms; /**< 冷却持续时间（毫秒） */

    const void (*start_pwm)(unsigned short duty, motor_direction_et dir); /**< 启动PWM输出函数 */
    const void (*stop_pwm)(void);                                         /**< 停止PWM输出函数 */
} motor_recip_instance_t;

/**
 * @brief 创建电机步进控制实例
 * @param start_pwm 启动PWM输出函数
 * @param stop_pwm 停止PWM输出函数
 * @return 电机步进控制实例指针，如果创建失败则返回NULL
 */
motor_step_instance_t *motor_step_instance_create(const void (*start_pwm)(unsigned short duty, motor_direction_et dir), const void (*stop_pwm)(void));

/**
 * @brief 启动电机步进控制
 * @param instance 电机步进控制实例
 * @param pwm_duty PWM占空比
 * @param direction 旋转方向
 * @param dirve_duration_ms 驱动持续时间（毫秒）
 * @param cooldown_duration_ms 冷却持续时间（毫秒）
 */
void motor_step_instance_start(motor_step_instance_t *instance, const unsigned short pwm_duty, const motor_direction_et direction, const unsigned short dirve_duration_ms, const unsigned short cooldown_duration_ms);

/**
 * @brief 启动电机步进控制（非抢占式）
 * @param instance 电机步进控制实例
 * @param pwm_duty PWM占空比
 * @param direction 旋转方向
 * @param drive_duration_ms 驱动持续时间（毫秒）
 * @param cooldown_duration_ms 冷却持续时间（毫秒）
 */
void motor_step_instance_start_non_preemptive(motor_step_instance_t *instance, const unsigned short pwm_duty, const motor_direction_et direction, const unsigned short drive_duration_ms, const unsigned short cooldown_duration_ms);

/**
 * @brief 创建电机往复运动控制实例
 * @param start_pwm 启动PWM输出函数
 * @param stop_pwm 停止PWM输出函数
 * @return 电机往复运动控制实例指针，如果创建失败则返回NULL
 */
motor_recip_instance_t *motor_recip_instance_create(const void (*start_pwm)(unsigned short duty, motor_direction_et dir), const void (*stop_pwm)(void));

/**
 * @brief 启动电机往复运动控制
 * @param instance 电机往复运动控制实例
 * @param pwm_duty PWM占空比
 * @param forward_move_duration_ms 正向驱动持续时间（毫秒）
 * @param backward_move_duration_ms 反向驱动持续时间（毫秒）
 * @param cooldown_duration_ms 冷却持续时间（毫秒）
 */
void motor_recip_instance_start(motor_recip_instance_t *instance, const unsigned short pwm_duty, const unsigned short forward_move_duration_ms, const unsigned short backward_move_duration_ms, const unsigned short cooldown_duration_ms);

/**
 * @brief 启动电机往复运动控制（非抢占式）
 * @param instance 电机往复运动控制实例
 * @param pwm_duty PWM占空比
 * @param forward_move_duration_ms 正向驱动持续时间（毫秒）
 * @param backward_move_duration_ms 反向驱动持续时间（毫秒）
 * @param cooldown_duration_ms 冷却持续时间（毫秒）
 */
void motor_recip_instance_start_non_preemptive(motor_recip_instance_t *instance, const unsigned short pwm_duty, const unsigned short forward_move_duration_ms, const unsigned short backward_move_duration_ms, const unsigned short cooldown_duration_ms);

/**
 * @brief 停止电机往复运动
 * @param instance 电机往复运动控制实例
 */
void motor_recip_instance_stop(motor_recip_instance_t *instance);

/**
 * @brief 更新电机步进控制状态
 * @param elapse_ms 经过的时间（毫秒）
 * @note 在一个定时任务中调用，需要固定的时间调用，并将定时时间（ms）写入这个函数的参数中。用于更新电机步进控制状态
 */
void motor_step_update(unsigned short elapse_ms);

#endif
