################################################################################
# MRS Version: 1.9.2
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/sdk/Core/core_riscv.c 

OBJS += \
./sdk/Core/core_riscv.o 

C_DEPS += \
./sdk/Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
sdk/Core/core_riscv.o: X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/sdk/Core/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\Libraries\doc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_components" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Core" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Ld" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Peripheral" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Startup" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\user\inc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_common" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_device" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\code" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

