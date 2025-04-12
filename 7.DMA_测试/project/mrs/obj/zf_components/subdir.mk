################################################################################
# MRS Version: 1.9.2
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
X:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/7.DMA_����/libraries/zf_components/seekfree_assistant.c \
X:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/7.DMA_����/libraries/zf_components/seekfree_assistant_interface.c 

OBJS += \
./zf_components/seekfree_assistant.o \
./zf_components/seekfree_assistant_interface.o 

C_DEPS += \
./zf_components/seekfree_assistant.d \
./zf_components/seekfree_assistant_interface.d 


# Each subdirectory must supply rules for building sources it contributes
zf_components/seekfree_assistant.o: X:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/7.DMA_����/libraries/zf_components/seekfree_assistant.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\Libraries\doc" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\zf_components" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\sdk\Core" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\sdk\Ld" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\sdk\Peripheral" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\sdk\Startup" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\project\user\inc" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\zf_common" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\zf_device" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\project\code" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_components/seekfree_assistant_interface.o: X:/8-CodeProjects/1.MCU/CH32V307-PlayGround-GitRepo/7.DMA_����/libraries/zf_components/seekfree_assistant_interface.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\Libraries\doc" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\zf_components" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\sdk\Core" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\sdk\Ld" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\sdk\Peripheral" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\sdk\Startup" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\project\user\inc" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\zf_common" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\zf_device" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\project\code" -I"X:\8-CodeProjects\1.MCU\CH32V307-PlayGround-GitRepo\7.DMA_����\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

