/*********************************************************************************************************************
 * ��ģ�����USART3ʵ��
 * 
 * 
 *
 * �޸ļ�¼
 * 
 * ����                                      ����                             ��ע
 * 2024-03-24                               Sxxx
 ********************************************************************************************************************/
#include "zf_common_headfile.h"

#define LOAD_QUANTITY 18                       // �غɴ�С
uint8_t UART3_get_data[LOAD_QUANTITY];         // ����3���յ�����
volatile bool UART3_data_packet_ready = false; // ����3���������ݰ��ı�־λ

int test_value_2 = 0;
float test_value_1 = 0.000;

typedef void (*Function_Unpack_Handler)(const char *, void *); // ����һ������ָ�����ͣ���ӵ������Ρ������ͽ������
void Function_Unpack_Handle_Float(const char *packet, void *value);
void Function_Unpack_Handle_Int(const char *packet, void *value);


typedef struct // ����һ���ṹ������װ��ǩ�͹ҽӺ����Լ��洢��ֵ
{
    const char tag[5];
    Function_Unpack_Handler function_handler;
    void *value_ptr;
} PacketTag_TpDef_struct;

void PacketTag_Analysis(PacketTag_TpDef_struct Tag_packet[], uint8_t tag_length);
void printf_USART3(char *format_str, ...);

// ���ұ�,�洢�ڽṹ�壬��һ���Ǳ�ǩ�������ĸ��ַ�
PacketTag_TpDef_struct Test_packet[] = {
    {"TEST", Function_Unpack_Handle_Float, &test_value_1},
    {"TES1", Function_Unpack_Handle_Int, &test_value_2},
    // ��Ӹ����ӳ���ϵ
};

int main(void)
{
    clock_init(SYSTEM_CLOCK_120M);                                                          // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 120MHz
    debug_init();                                                                           // ��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
    uart_init(DEBUG_UART_INDEX, DEBUG_UART_BAUDRATE, DEBUG_UART_TX_PIN, DEBUG_UART_RX_PIN); // ���ڳ�ʼ��
    uart_rx_interrupt(DEBUG_UART_INDEX, ENABLE);                                            // ���������ж�
    interrupt_set_priority(USART3_IRQn, (0 << 5) || 1);                                     // ����usart3���ж����ȼ�
    uart_write_string(DEBUG_UART_INDEX, "Hello,world,start.\r\n");

    // �˴���д�û����� ���������ʼ�������

    // �˴���д�û����� ���������ʼ�������

    while (1)
    {
        // �˴���д��Ҫѭ��ִ�еĴ���
        if (UART3_data_packet_ready)
        {
            UART3_data_packet_ready = false;
            printf_USART3("\r\nReturn:%s\r\n", UART3_get_data);
            PacketTag_Analysis(Test_packet,2);
            printf_USART3("\r\ntestv1:%f\r\n", test_value_1);
            printf_USART3("\r\ntestv2:%d\r\n", test_value_2);
        }
        // �˴���д��Ҫѭ��ִ�еĴ���
    }
}

/**
 *  @brief ʹ��USART3��printf
 *  @param ��ʽ���ַ���
 *  @return void
 *  @warning
 *  @note ���ӣ� printf_USART3("text:%d", 1212); ���ڽ��յ� text:1212
 */
void printf_USART3(char *format_str, ...)
{
    uint8_t buffer[32];
    va_list arg;
    va_start(arg, format_str);
    vsprintf(buffer, format_str, arg);
    va_end(arg);
    uart_write_string(DEBUG_UART_INDEX, buffer);
}

void USART3_IRQ_Function(void)
{
    static uint8_t UART3_get_data_index = 0; // �������ݰ���������
    uint8_t byte = 0;
    static bool start_load_packet_flag = false; // ��ʼ�������ݰ��ı�־
    if (uart_query_byte(DEBUG_UART_INDEX, &byte))
    {
        if (byte == '@')
        {
            // ��⵽���ݰ���ʼ
            start_load_packet_flag = true;
            UART3_get_data_index = 0; // ��������
        }
        else if (byte == '#' && start_load_packet_flag)
        {
            // ��⵽���ݰ�����
            UART3_get_data[UART3_get_data_index] = '\0';
            UART3_data_packet_ready = true;
            start_load_packet_flag = false;
            // ����������Դ������ݰ�����Ϊ���Ѿ�����
            // ������Ϻ���������Ҫ������Ҫ����data_index
        }
        else if (start_load_packet_flag)
        {
            // ����������ݰ�����ģʽ������û�дﵽ���ݰ���β
            if (UART3_get_data_index < LOAD_QUANTITY - 1)
            {
                // �洢���ݲ���������
                UART3_get_data[UART3_get_data_index++] = byte;
            }
            else
            {
                // ���������������ݰ�
                memset(UART3_get_data, 0, LOAD_QUANTITY); // ��ս��ջ�����
                UART3_data_packet_ready = false;
                UART3_get_data_index = 0; // ��������
                start_load_packet_flag = false;
                printf_USART3("Error: Data packet overflow.\r\n"); // ������
            }
        }
    }
}

// ���ݴ�����,ģ����ʹ��
void Function_Unpack_Handle_Float(const char *packet, void *value)
{
    char numString[LOAD_QUANTITY];                     // Assuming the maximum length of the number string is 20
    strncpy(numString, packet + 4, LOAD_QUANTITY - 1); // Copy the number part of the special string
                                                       // Convert the number string to a float
    *((float *)value) = atof(numString);
}

void Function_Unpack_Handle_Int(const char *packet, void *value)
{
    char numString[LOAD_QUANTITY];                     // Assuming the maximum length of the number string is 20
    strncpy(numString, packet + 4, LOAD_QUANTITY - 1); // Copy the number part of the special string
                                                       // Convert the number string to a float
    *((int *)value) = atoi(numString);
}

/**
 * @brief �Ի��������������ǩƥ�������ʹ�á�
 * @note  ���еı�ǩ���������оٴ���
 *
 */
void PacketTag_Analysis(PacketTag_TpDef_struct Tag_packet[], uint8_t tag_length)
{
    uint8_t i = 0;
    for (i = 0; i < tag_length; i++)
    {
        // ����ǩ�Ƿ�ƥ��
        if (strncmp(UART3_get_data, Tag_packet[i].tag, 4) == 0)
        {
            // ���ù����Ĵ�����
            Tag_packet[i].function_handler(UART3_get_data, Tag_packet[i].value_ptr);
            return; // �ҵ�ƥ����󷵻�
        }
    }
    uint8_t error_tag[5] = {0};
    strncpy(error_tag, UART3_get_data, 4);
    error_tag[4] = '\0';                                 // ��ʽ�����ÿ���ֹ��
    printf_USART3("The \"%s\" is not find.", error_tag); // ������
    // ���û���ҵ��κ�ƥ�䣬���������ﴦ�����
    // U1_printf("The \"%s\" is not find.", Tag_packet[i].tag);
}
