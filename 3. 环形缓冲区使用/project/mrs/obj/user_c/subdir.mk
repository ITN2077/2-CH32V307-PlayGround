################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
X:/Embedded\ folder/My\ programming\ files/CH32/3.\ ���λ�����ʹ��/project/user/src/isr.c \
X:/Embedded\ folder/My\ programming\ files/CH32/3.\ ���λ�����ʹ��/project/user/src/main.c 

OBJS += \
./user_c/isr.o \
./user_c/main.o 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 


# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: X:/Embedded\ folder/My\ programming\ files/CH32/3.\ ���λ�����ʹ��/project/user/src/isr.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\Libraries\doc" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\zf_components" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\sdk\Core" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\sdk\Ld" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\sdk\Peripheral" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\sdk\Startup" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\project\user\inc" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\zf_common" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\zf_device" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\project\code" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
user_c/main.o: X:/Embedded\ folder/My\ programming\ files/CH32/3.\ ���λ�����ʹ��/project/user/src/main.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\Libraries\doc" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\zf_components" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\sdk\Core" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\sdk\Ld" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\sdk\Peripheral" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\sdk\Startup" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\project\user\inc" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\zf_common" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\zf_device" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\project\code" -I"X:\Embedded folder\My programming files\CH32\3. ���λ�����ʹ��\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

