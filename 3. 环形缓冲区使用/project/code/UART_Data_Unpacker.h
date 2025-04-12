/*********************************************************************************************************************
 * ��ģ�����USART3ʵ��
 * ��飺������~}��ͷ��}~��β�����ݰ������ݰ�ǰTAG_LENGTHλ���ڱ�ǩƥ�䣬�������Ϊ���ݽ���
 * ʵ�֣�
 *    �ж��н���ȡ���ֽ�ֱ�Ӵ��뻷�λ��������ڻ��λ������а��չ̶���ʽ�������ݰ������� UART3_get_data[PACKET_MAX_SIZE] �У�
 *   ���� UART3_Ringbuffer_Processer(); �Ի��λ������е����ݴ���
 *   ͨ������ PacketTag_Analysis(); �� PacketTag_TpDef_struct �ṹ�������еı�ǩƥ�䣬Ȼ��Թ��ر�����ֵ��
 * �÷���
 * *.�غɴ�Сͨ�� #define PACKET_MAX_SIZE �޸�
 * *.��ǩ����ͨ�� TAG_LENGTH �޸�
 * *.���λ�������Сͨ�� RINGBUFFER_SIZE �޸ģ�ֻ����2���ݴη�
 * *.PacketTag_TpDef_struct �����ṹ�����飬�洢��ǩ�����غ����Լ����ر���
 * *.���ݾ������λ��������棬���մ洢�� UART3_get_data[] �У�ʹ��ʱֱ����
 * *.UART3_data_packet_ready ���ǽ���������ϱ�־λ�������1
 * *.�ṩ�˶������ݽ�����ʽ
 * ע�⣺
 * *.ʹ��ʱ��Ҫ��USART3��ʼ���������ж�
 * *.ʹ��ʱҪ ring_buffer_init(&ringbuffer_UART3, ringbuffer_place_UART3, RINGBUFFER_SIZE); ��ʼ�����λ������ṹ��
 * *.�жϺ�����ʹ�ùر���zf_common_debug.h �ļ��е� #define DEBUG_UART_USE_INTERRUPT    (0)����Ҫʹ��debug uart�����ֶ���
 * ���ӣ�main.c
#include "zf_common_headfile.h"

int16_t test_value_2 = 0;
float test_value_1 = 0.000;

PacketTag_TpDef_struct Test_packet[] = {
    {"2", UnpackData_Handle_Float_FireWater, &test_value_1},
    {"1", UnpackData_Handle_Int_FireWater, &test_value_2},
    // ��Ӹ����ӳ���ϵ
};

int main(void)
{
    clock_init(SYSTEM_CLOCK_120M);                                                          // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 120MHz
    debug_init();                                                                           // ��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
    uart_init(DEBUG_UART_INDEX, DEBUG_UART_BAUDRATE, DEBUG_UART_TX_PIN, DEBUG_UART_RX_PIN); // ���ڳ�ʼ��
    uart_rx_interrupt(DEBUG_UART_INDEX, ENABLE);                                            // ���������ж�
    interrupt_set_priority(USART3_IRQn, (0 << 5) || 1);                                     // ����usart3���ж����ȼ�
    ring_buffer_init(&ringbuffer_UART3, ringbuffer_place_UART3, RINGBUFFER_SIZE);           // ���λ�������ʼ�� V1.1���
    printf_USART3("hello");
    while (1)
    {
        // �˴���д��Ҫѭ��ִ�еĴ���
        UART3_Ringbuffer_Processer();
        if (UART3_data_packet_ready)
        {
            UART3_data_packet_ready = false;
            printf_USART3("\r\nReturns:%s\r\n", UART3_get_data);
            for (int i = 0; i < PACKET_MAX_SIZE; i++)
            {
                printf_USART3("0x%02X ", UART3_get_data[i]);
            }
            printf_USART3("\r\n");
            PacketTag_Analysis(Test_packet, 2);
            printf_USART3("\r\ntestv1:%f\r\n", test_value_1);
            printf_USART3("\r\ntestv2:%d\r\n", test_value_2);
        }
        // �˴���д��Ҫѭ��ִ�еĴ���
    }
}
 * �޸ļ�¼
 *
 * ����            ����                             ��ע
 * 2024-03-24     Sxxx
 * 2024-03-31     Sxxx      ����V1.1����ӻ��λ�����ת�����ݣ����ٴ����жϿ���
 ********************************************************************************************************************/
#ifndef UART_DATA_UNPACKER_H
#define UART_DATA_UNPACKER_H

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include <stdbool.h>
#include "zf_driver_uart.h"
#include "Ring_Buffer.h"

#define PACKET_MAX_SIZE 10 // �غɴ�С,�Զ����޸�
#define TAG_LENGTH 1       // ��ǩ���ȣ��Զ����޸�
#define RINGBUFFER_SIZE 64 // ���λ�������С��������2����

// ���λ��������������������޸ģ�˽��
extern ring_buffer_t ringbuffer_UART3;
extern uint8_t ringbuffer_place_UART3[RINGBUFFER_SIZE];

extern uint8_t UART3_get_data[PACKET_MAX_SIZE]; // ����3���յ����ݣ�����
extern volatile bool UART3_data_packet_ready;   // ����3���������ݰ��ı�־λ�����ݰ����������1������

// ˽��Ԫ��START���ṹ���к������ص��ã�˽�У�
// ����һ������ָ�����ͣ���ӵ��ý������
typedef void (*Function_Unpack_Handler)(const char *, void *); 
// �����ı���ʽ��ȡ��float����,������Ϊ ��ǩ����+3+С������+��������
void UnpackData_Handle_Float_FireWater(const char *packet, void *value);
// �����ı���ʽ��ȡ��int���ݣ����������Ϊ ��ǩ����+1+��������
void UnpackData_Handle_Int_FireWater(const char *packet, void *value);
// ��ieee754��ʽ��ȡ��int16���ݣ������ű�ǩ���Ǹ߰�λ����һλ�ǵͰ�λ�������޷�-32100~32100�����������Ϊ ��ǩ����+3
void UnpackData_Handle_Int_IEEE754(const uint8 *packet, void *int_value);

// ˽�нṹ�壬��װ��ǩ�͹ҽӺ����Լ��洢��ֵ
typedef struct
{
    const char tag[TAG_LENGTH + 1];
    Function_Unpack_Handler function_handler;
    void *value_ptr;
} PacketTag_TpDef_struct;
// ˽��Ԫ��END

// �����ӿں���

void PacketTag_Analysis(PacketTag_TpDef_struct Tag_packet[], uint8_t tag_count);
void printf_USART3(char *format_str, ...);
void UART3_Ringbuffer_Processer(void);

#endif // UART_DATA_UNPACKER_H
