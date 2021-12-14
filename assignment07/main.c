#include <stdint.h>
#include "delay.h"
#include "stm32l475xx.h"
#include "stm32l4xx_it.h"


#define DELAY_DURATION  1000  // defined in milliseconds i.e 5000 milliseconds

#define SYS_CLOCK_HZ 4000u  // Default clock after startup -> setting it up to trigger every millisecond

void SysTick_Initialize(void);

int globalcounter = 0;

// ******With using CMSIS code *- Blinking PA5 LED ********************
#if 1

void main(void) {
 
  // Enabling clock to Peripheral
   RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;   // RCC->AHB2ENR means the value contained in address of RCC_AHB2ENR
   
   // Set Bit 11:10 to 01 // To enable PA5 as output
   GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
   GPIOA->MODER |= GPIO_MODER_MODE5_0;
  
   
     // Enabling clock to Peripheral
   RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;   // RCC->AHB2ENR means the value contained in address of RCC_AHB2ENR
   
   // Set Bit 11:10 to 01 // To enable PA5 as output
   GPIOB->MODER &= ~GPIO_MODER_MODE14_1;
   GPIOB->MODER |= GPIO_MODER_MODE14_0;
   
   
    SysTick_Initialize();
   
    while(1)
    {   
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(DELAY_DURATION);
        
        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(DELAY_DURATION);
    } 
    
  
return;
}
#endif


void SysTick_Initialize(void){
    SysTick->LOAD = SYS_CLOCK_HZ - 1;    // 
    SysTick->VAL = 0x0;                   // clears the value register
    SysTick->CTRL = 0x7;                  //
}

void SysTick_Handler(void){
  globalcounter--;
  //GPIOA->ODR ^= GPIO_ODR_OD14;
  //GPIOB->ODR ^= GPIO_ODR_OD14;
}


