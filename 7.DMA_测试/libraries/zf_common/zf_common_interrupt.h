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
 * �ļ�����          zf_common_interrupt
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

#ifndef _zf_nvic_h
#define _zf_nvic_h

#include "ch32v30x.h"
#include "zf_common_typedef.h"

/**
 * @brief   ��ʼ���ж�ϵͳ
 * @note    �˺������ڳ�ʼ��NVIC�жϿ����������û������ж�����
 */
void interrupt_init(void);

/**
 * @brief   ȫ��ʹ���ж�
 * @param   primask    ֮ǰ�����PRIMASKֵ
 * @note    ���ڻָ�֮ǰ�����õ�ȫ���ж�״̬
 */
void interrupt_global_enable(uint32 primask);

/**
 * @brief   ȫ�ֽ����ж�
 * @return  ���ص�ǰ��PRIMASKֵ�����ں����ָ��ж�״̬
 * @note    �˺�������������жϣ����ص�ǰ��PRIMASKֵ�������ָ�ʹ��
 */
uint32 interrupt_global_disable(void);

/**
 * @brief   ʹ��ָ���ж�
 * @param   irqn       Ҫʹ�ܵ��жϺ�
 * @note    ����ʹ���ض����ж�Դ��ʹ���ܹ���Ӧ�ж�����
 */
void interrupt_enable(IRQn_Type irqn);

/**
 * @brief   ����ָ���ж�
 * @param   irqn       Ҫ���õ��жϺ�
 * @note    ���ڽ����ض����ж�Դ��ʹ����ʱ����Ӧ�ж�����
 */
void interrupt_disable(IRQn_Type irqn);

/**
 * @brief   �����ж����ȼ�
 * @param   irqn       Ҫ���õ��жϺ�
 * @param   priority   ���ȼ�ֵ(0-255)
 * @note    ��������ָ���жϵ����ȼ�����ֵԽС���ȼ�Խ��
 */
void interrupt_set_priority(IRQn_Type irqn, uint8 priority);

#endif
