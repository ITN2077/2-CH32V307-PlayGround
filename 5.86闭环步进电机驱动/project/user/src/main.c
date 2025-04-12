/*********************************************************************************************************************
 SWDIO PA13 ,SWCLK PA14
Ĭ��DEBUG������UART8  TX_E14��RX_E15
KEY_LIST   {A8 , D8 , B12 , B0 } ��Ӧ zf_device_key.h �� KEY_LIST

��ʱ��6������ʵʱ�������
��ʱ��7����Ӳʵʱ�������

 ********************************************************************************************************************/
#include "Task_Manager.h"

int main(void)
{
    clock_init(SYSTEM_CLOCK_120M); // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 120MHz
    debug_init();                  // ��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
    PeripheraAll_Init();           // ȫ�������ʼ��

    // !�������ϵͳ���� ��λ 10 ms ������ע������
    XxxTimeSliceOffset_Register(&While_task, While_Task, 0, 0);             // ע��whileѭ������
    XxxTimeSliceOffset_Register(&Uart_task, UART_packet_TASKhandler, 0, 0); // ע�ᴮ�����ݰ���������, ��ѯʱ��Ϊ0��while��ƫ��0.
    XxxTimeSliceOffset_Register(&Speed_task, control_Speed, 2, 2);        // �ٶȿ��ƺ�����100msִ��һ��
    XxxTimeSliceOffset_Register(&Key_task, key_Processing, 2, 1);           // ����ɨ�躯��
    // ע���������

    XxxTimeSliceOffset_Start(); // ִ�����񣬰���while���������ѭ��while
}