/*********************************************************************************************************************
Ĭ��DEBUG������UART8

 ********************************************************************************************************************/
#include "zf_common_headfile.h"

int test_value_1 = 0;
float test_value_2 = 0.000;

PacketTag_TpDef_struct Test_packet[] = {
    {"1", UnpackData_Handle_Int_FireWater, &test_value_1},
    {"2", UnpackData_Handle_Float_FireWater, &test_value_2},
    // ��Ӹ����ӳ���ϵ
};


int main(void)
{
    clock_init(SYSTEM_CLOCK_120M);                                                          // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 120MHz
    debug_init();                                                                           // ��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
    uart_init(DEBUG_UART_INDEX, DEBUG_UART_BAUDRATE, DEBUG_UART_TX_PIN, DEBUG_UART_RX_PIN); // ���ڳ�ʼ��
    uart_rx_interrupt(DEBUG_UART_INDEX, ENABLE);                                            // ���������ж�
    interrupt_set_priority(UART8_IRQn, (0 << 5) || 1);                                      // ����uart���ж����ȼ�
    ring_buffer_init(&ringbuffer_UART_DEBUG, ringbuffer_place_UART_DEBUG, RINGBUFFER_SIZE); // ���λ�������ʼ�� V1.1���
    printf_USART_DEBUG("hello,WSY!");
    system_delay_ms(2000);
    printf_USART_DEBUG("hello,WSY!");

    // �û���ʼ��
    gpio_init(A1, GPO, GPIO_HIGH, GPO_PUSH_PULL); // ��ת����
    gpio_init(A5, GPO, GPIO_LOW, GPO_PUSH_PULL);  // ����
    gpio_init(A3, GPO, GPIO_HIGH, GPO_PUSH_PULL); // ���������ʹ��
    // END

    while (1)
    {
        // �˴���д��Ҫѭ��ִ�еĴ���
        UART_DEBUG_Ringbuffer_Processer();
        if (UART_DEBUG_data_packet_ready)
        {
            UART_DEBUG_data_packet_ready = false;
            PacketTag_Analysis(Test_packet, 2);
            DebugPrint(); // ������յ�����
            printf_USART_DEBUG("\r\ntestv1:%d\r\n", test_value_1);
            printf_USART_DEBUG("\r\ntestv2:%f\r\n", test_value_2);
        }

        // pulse(test_value_1);

        gpio_set_level(A5, 1);
        system_delay_us(650);
        gpio_set_level(A5, 0);
        system_delay_us(650);

        // �˴���д��Ҫѭ��ִ�еĴ���
    }
}
