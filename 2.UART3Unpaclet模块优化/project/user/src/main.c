/*********************************************************************************************************************
 * CH32V307VCT6 Opensourec Library ����CH32V307VCT6 ��Դ�⣩��һ�����ڹٷ� SDK �ӿڵĵ�������Դ��
 * Copyright (c) 2022 SEEKFREE ��ɿƼ�
 *
 * ���ļ���CH32V307VCT6 ��Դ���һ����
 *
 * CH32V307VCT6 ��Դ�� ��������
 * �����Ը��������������ᷢ���� GPL��GNU General Public License���� GNUͨ�ù������֤��������
 * �� GPL �ĵ�3�棨�� GPL3.0������ѡ��ģ��κκ����İ汾�����·�����/���޸���
 *
 * ����Դ��ķ�����ϣ�����ܷ������ã�����δ�������κεı�֤
 * ����û�������������Ի��ʺ��ض���;�ı�֤
 * ����ϸ����μ� GPL
 *
 * ��Ӧ�����յ�����Դ���ͬʱ�յ�һ�� GPL �ĸ���
 * ���û�У������<https://www.gnu.org/licenses/>
 *
 * ����ע����
 * ����Դ��ʹ�� GPL3.0 ��Դ���֤Э�� �����������Ϊ���İ汾
 * �������Ӣ�İ��� libraries/doc �ļ����µ� GPL3_permission_statement.txt �ļ���
 * ���֤������ libraries �ļ����� �����ļ����µ� LICENSE �ļ�
 * ��ӭ��λʹ�ò����������� ���޸�����ʱ���뱣����ɿƼ��İ�Ȩ����������������
 *
 * �ļ�����          main
 * ��˾����          �ɶ���ɿƼ����޹�˾
 * �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
 * ��������          MounRiver Studio V1.8.1
 * ����ƽ̨          CH32V307VCT6
 * ��������          https://seekfree.taobao.com/
 *
 * �޸ļ�¼
 * ����                                      ����                             ��ע
 * 2022-09-15        ��W            first version
 ********************************************************************************************************************/
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
    printf_USART3("hello i am ok");
    while (1)
    {
        // �˴���д��Ҫѭ��ִ�еĴ���
        if (UART3_data_packet_ready)
        {
            UART3_data_packet_ready = false;
            printf_USART3("\r\nReturn:%s\r\n", UART3_get_data);
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
