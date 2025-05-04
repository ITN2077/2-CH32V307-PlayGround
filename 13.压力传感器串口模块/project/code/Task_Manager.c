#include "Task_Manager.h"

uint8_t uart7_buffer[32] = {0};
ring_buffer_t uart7_ringbuffer;

void uart7_callback(uint8_t *data, uint16_t length)
{
    uart_write_buffer(UART_7, data, length);
}

void uart7_irq_handler(void)
{
    uint8_t byte = 0;
    if (uart_query_byte(UART_7, &byte))
    {
        ring_buffer_queue(&uart7_ringbuffer, byte); // 将字节放入环形缓冲区
    }
}

/* 处理传感器数据的函数 */
void handle_sensor_data(weight_sensor_data_t *data)
{
    if (!data->is_valid)
    {
        return;
    }

    printf_USART_DEBUG("address: %d \r\n", data->address);

    switch (data->command)
    {
    case 0xA1: /* 读取AD值响应 */

        printf_USART_DEBUG("  AD: %d\n", data->value);
        break;

    case 0xA3: /* 读取重量响应 */
  
        printf_USART_DEBUG("  weight: %d\n", data->value);
        break;

    case 0xAA: /* 零点校准响应 */

        printf_USART_DEBUG("  zero: %d\n", data->value);
        break;

    case 0xAB: /* 去皮操作响应 */

        printf_USART_DEBUG("  tare: %d\n", data->value);
        break;

    default:

        break;
    }
}

void weight_sensor_task_handler(void)
{
    weight_sensor_data_t weight_sensor_data;
    /* 处理所有可用的数据帧 */
    while (weight_sensor_parse_from_ringbuffer(&uart7_ringbuffer, &weight_sensor_data) > 0)
    {
        handle_sensor_data(&weight_sensor_data);
    }
    weight_sensor_read_ad(0x00);
}

//!------------------🍅🍅🍅🍅🍅🍅 注册时间片轮询任务 START 🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
STR_XxxTimeSliceOffset Uart_task, Weight_sensor_task; // 创建任务句柄,While_task,Key_task,
/**
 *  @brief 时间片轮询任务创建函数
 *  @note 记得创建任务句柄
 */
void Time_Slice_Offset_Register(void)
{
    // !任务调度系统节拍 单位 10 ms 以下是注册任务
    // XxxTimeSliceOffset_Register(&While_task, While_Task, 0, 0);             // 注册while循环任务。
    XxxTimeSliceOffset_Register(&Uart_task, UART_packet_TASKhandler, 0, 0); // 注册串口数据包接收任务, 轮询时间为0即while，偏移0.
    XxxTimeSliceOffset_Register(&Weight_sensor_task, weight_sensor_task_handler, 10, 0); // 注册串口数据包接收任务, 轮询时间为0即while，偏移0.
    // XxxTimeSliceOffset_Register(&Key_task, key_Processing, 2, 1);           // 按键扫描函数,需要使用记得注册任务以及初始化 key_init(20);
    //  注册任务结束
}
//!------------------✨✨✨✨✨✨ 注册时间片轮询任务 END 🌸🌸🌸🌸🌸🌸---------⬆️⬆️⬆️⬆️⬆️⬆️




//!----------------🍅🍅🍅🍅🍅🍅 串口数据包任务使用的 START 🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
#define NumOfMsg 2 //定义串口接收的数据要解析的数据的个数
int test_value_1 = 0;
float test_value_2 = 0.000;

PacketTag_TpDef_struct Test_packet[] = {
    {"1", UnpackData_Handle_Int_FireWater, &test_value_1},
    {"2", UnpackData_Handle_Float_FireWater, &test_value_2},
    // 添加更多的映射关系
};
//!------------------✨✨✨✨✨✨ 串口数据包任务使用的 END 🌸🌸🌸🌸🌸🌸---------⬆️⬆️⬆️⬆️⬆️⬆️




//!------------------🍅🍅🍅🍅🍅🍅 非时间片轮询任务调度函数 START  🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
/**********************************************************************
 *  @brief 全部外设的初始化
 *  @param
 *  @return
 *  @note
 *  @warning
 */
void PeripheraAll_Init()
{
    UART_DEBUG_Init();

    pit_ms_init(TIM6_PIT, 10);            // 定时器6初始化，提供软实时任务调度系统节拍
    interrupt_set_priority(TIM6_IRQn, 0); // 最高中断优先级

    // pit_ms_init(TIM7_PIT, 50);            // 定时器七初始化，用于硬实时任务调度
    // interrupt_set_priority(TIM7_IRQn, 0);

    //timer_init(TIM_5, TIMER_US); // 初始化定时器5用于计时

    uart_init(UART_7, 115200, UART7_MAP3_TX_E12, UART7_MAP3_RX_E13);
    uart_rx_interrupt(UART_7, ENABLE);
    interrupt_set_priority(UART7_IRQn, 0);
    ring_buffer_init(&uart7_ringbuffer, uart7_buffer, sizeof(uart7_buffer));

    weight_sensor_init(uart7_callback);
    weight_sensor_tare(0x01);
    system_delay_ms(1000);

    //key_init(20); // 按键初始化，20ms一次中断
    printf_USART_DEBUG("hello,WSY!\r\n");
    printf_USART_DEBUG("hello,WSY! Let`s start!\r\n");
    // Task_Disable();  // 定时器中断失能。即所有实时任务停止
}
//!------------------✨✨✨✨✨✨ 非时间片轮询任务调度函数 END 🌸🌸🌸🌸🌸🌸---------⬆️⬆️⬆️⬆️⬆️⬆️




//!------------------🍅🍅🍅🍅🍅🍅 时间片轮询任务 START 🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
/**
 * @brief While 循环，无定时任务，全速运行。
 *
 */
void While_Task(void)
{
    // 写入while循环任务
}
/**
 *  @brief 串口数据包处理任务函数
 *  @note  务必设置为无定时任务，全速运行防止缓冲区溢出
 */
void UART_packet_TASKhandler(void)
{
    UART_DEBUG_Ringbuffer_Processer();
    if (UART_DEBUG_data_packet_ready)
    {
        UART_DEBUG_data_packet_ready = false;
        PacketTag_Analysis(Test_packet, NumOfMsg);//此处NumOfMsg在串口处定义。
        DebugPrint(); // 输出接收的数据
        printf_USART_DEBUG("\r\ntestv1:%d\r\n", test_value_1);
        printf_USART_DEBUG("\r\ntestv2:%f\r\n", test_value_2);
    }
}
/**
 *  @brief 按键扫描、处理任务，默认20ms处理一次
 *  @note   按键引脚要修改key.h中的key.list，对应任务句柄Key_task
 */
void key_Processing(void)
{
    key_scanner();
    if (KEY_SHORT_PRESS == key_get_state(KEY_1)) // 按键1短按
    {
        //printf_USART_DEBUG("KEY_1 pressed.");
    }
    else if (KEY_LONG_PRESS == key_get_state(KEY_1)) // 按键1长按
    {

    }
    else if (KEY_SHORT_PRESS == key_get_state(KEY_2))
    {

    }
    else if (KEY_LONG_PRESS == key_get_state(KEY_2))
    {

    }
}
//!------------------✨✨✨✨✨✨ 时间片轮询任务调度 END 🌸🌸🌸🌸🌸🌸---------⬆️⬆️⬆️⬆️⬆️⬆️




//!------------------🍅🍅🍅🍅🍅🍅 硬实时任务 START 🍒🍒🍒🍒🍒🍒---------⬇️⬇️⬇️⬇️⬇️⬇️
/**
 *  @brief 硬实时任务处理，到点就触发，比软实时任务高一级
 *  @param
 *  @return
 *  @note   此函数在TIM7中断中被使用，将函数写入此函数中即可。
 *  @warning
 */
void Hard_Real_Time_Processing(void)
{

}
//!------------------✨✨✨✨✨✨ 硬实时任务 END 🌸🌸🌸🌸🌸🌸---------⬆️⬆️⬆️⬆️⬆️⬆️