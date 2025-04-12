################################################################################
# MRS Version: 1.9.2
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
X:/300-�������/205-��д��MCU����/CH32/5.86�ջ������������/project/code/Ring_Buffer.c \
X:/300-�������/205-��д��MCU����/CH32/5.86�ջ������������/project/code/Task_Manager.c \
X:/300-�������/205-��д��MCU����/CH32/5.86�ջ������������/project/code/UART_Data_Unpacker.c \
X:/300-�������/205-��д��MCU����/CH32/5.86�ջ������������/project/code/XxxTimeSliceOffset.c 

OBJS += \
./code/Ring_Buffer.o \
./code/Task_Manager.o \
./code/UART_Data_Unpacker.o \
./code/XxxTimeSliceOffset.o 

C_DEPS += \
./code/Ring_Buffer.d \
./code/Task_Manager.d \
./code/UART_Data_Unpacker.d \
./code/XxxTimeSliceOffset.d 


# Each subdirectory must supply rules for building sources it contributes
code/Ring_Buffer.o: X:/300-�������/205-��д��MCU����/CH32/5.86�ջ������������/project/code/Ring_Buffer.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\Libraries\doc" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_components" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Core" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Ld" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Peripheral" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Startup" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\project\user\inc" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_common" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_device" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\project\code" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Task_Manager.o: X:/300-�������/205-��д��MCU����/CH32/5.86�ջ������������/project/code/Task_Manager.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\Libraries\doc" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_components" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Core" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Ld" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Peripheral" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Startup" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\project\user\inc" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_common" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_device" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\project\code" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/UART_Data_Unpacker.o: X:/300-�������/205-��д��MCU����/CH32/5.86�ջ������������/project/code/UART_Data_Unpacker.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\Libraries\doc" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_components" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Core" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Ld" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Peripheral" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Startup" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\project\user\inc" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_common" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_device" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\project\code" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/XxxTimeSliceOffset.o: X:/300-�������/205-��д��MCU����/CH32/5.86�ջ������������/project/code/XxxTimeSliceOffset.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\Libraries\doc" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_components" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Core" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Ld" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Peripheral" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\sdk\Startup" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\project\user\inc" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_common" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_device" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\project\code" -I"X:\300-�������\205-��д��MCU����\CH32\5.86�ջ������������\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

