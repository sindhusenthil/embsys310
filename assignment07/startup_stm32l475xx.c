#include "stm32l4xx_it.h"

#pragma section = "CSTACK"

void __iar_program_start(void);

void Unused_Handler(void);

int const __vector_table[] @ ".intvec" = {
   (int)__section_end("CSTACK"), // stack pointer -> SP
   (int)&__iar_program_start,     // pointer to reset vector 
   (int)&NMI_Handler,
   (int)&HardFault_Handler, 
   (int)&MemManage_Handler, 
   (int)&BusFault_Handler, 
   (int)&UsageFault_Handler, 
   0,            // Reserved
   0,
   0,
   0,
   (int)&SVC_Handler, 
   (int)&DebugMon_Handler, 
   0, 
   (int)&PendSV_Handler, 
   (int)&SysTick_Handler,
};

__weak void NMI_Handler(void)
{
while(1){
}
}

__weak void HardFault_Handler(void)
{
while(1){
}
}

__weak void MemManage_Handler(void)
{
while(1){
}
}

__weak void BusFault_Handler(void)
{
while(1){
}
}

__weak void UsageFault_Handler(void)
{
while(1){
}
}

__weak void Unused_Handler(void)
{
while(1){
}
}

#pragma weak SVC_Handler = Unused_Handler
#pragma weak DebugMon_Handler = Unused_Handler
#pragma weak PendSV_Handler = Unused_Handler
#pragma weak SysTick_Handler = Unused_Handler

