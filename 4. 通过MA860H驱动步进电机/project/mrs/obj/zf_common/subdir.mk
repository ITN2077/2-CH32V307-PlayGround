################################################################################
# MRS Version: 1.9.2
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/zf_common/zf_common_clock.c \
X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/zf_common/zf_common_debug.c \
X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/zf_common/zf_common_fifo.c \
X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/zf_common/zf_common_font.c \
X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/zf_common/zf_common_function.c \
X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/zf_common/zf_common_interrupt.c 

OBJS += \
./zf_common/zf_common_clock.o \
./zf_common/zf_common_debug.o \
./zf_common/zf_common_fifo.o \
./zf_common/zf_common_font.o \
./zf_common/zf_common_function.o \
./zf_common/zf_common_interrupt.o 

C_DEPS += \
./zf_common/zf_common_clock.d \
./zf_common/zf_common_debug.d \
./zf_common/zf_common_fifo.d \
./zf_common/zf_common_font.d \
./zf_common/zf_common_function.d \
./zf_common/zf_common_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
zf_common/zf_common_clock.o: X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/zf_common/zf_common_clock.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\Libraries\doc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_components" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Core" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Ld" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Peripheral" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Startup" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\user\inc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_common" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_device" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\code" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_debug.o: X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/zf_common/zf_common_debug.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\Libraries\doc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_components" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Core" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Ld" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Peripheral" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Startup" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\user\inc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_common" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_device" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\code" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_fifo.o: X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/zf_common/zf_common_fifo.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\Libraries\doc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_components" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Core" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Ld" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Peripheral" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Startup" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\user\inc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_common" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_device" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\code" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_font.o: X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/zf_common/zf_common_font.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\Libraries\doc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_components" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Core" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Ld" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Peripheral" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Startup" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\user\inc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_common" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_device" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\code" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_function.o: X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/zf_common/zf_common_function.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\Libraries\doc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_components" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Core" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Ld" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Peripheral" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Startup" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\user\inc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_common" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_device" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\code" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_interrupt.o: X:/300-�������/205-��д��MCU����/CH32/4.\ ͨ��MA860H�����������/libraries/zf_common/zf_common_interrupt.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\Libraries\doc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_components" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Core" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Ld" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Peripheral" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\sdk\Startup" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\user\inc" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_common" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_device" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\project\code" -I"X:\300-�������\205-��д��MCU����\CH32\4. ͨ��MA860H�����������\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

