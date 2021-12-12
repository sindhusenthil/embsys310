#include <stdint.h>
#include "delay.h"
#include "stm32l475xx.h"




// ******With using CMSIS code *- Blinking PA5 LED ********************
#if 1

volatile int counter = 0; 

void main(void) {
 
  // Enabling clock to Peripheral
   RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
   
   // Set Bit 11:10 to 01 // To enable PA5 ass output
   GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
   GPIOA->MODER |= GPIO_MODER_MODE5_0;
  
     while (1) {
       GPIOA->ODR |= GPIO_ODR_OD5;
       delay(100000);
       
       GPIOA->ODR &= ~GPIO_ODR_OD5;
       delay(100000);
     }
  
return;
}


#endif






// ***** Without using CMSIS ***************************
#if 0 
// Global Variable Definitions 

int counter = 0;

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIO_A_BASE 0x48000000

#define GPIO_MODER  (*((unsigned int*)(GPIO_A_BASE + 0x00)))

#define GPIO_ODR    (*((unsigned int*)(GPIO_A_BASE + 0x14)))

// ***********************************************************

int main() { 
  // writing a value of 1 to 0x4002104C to enable clock for GPIOA --> 0x0000.0001
  RCC_AHB2ENR |= 0x00000001;
  
  // using bitband method::
  //*((unsigned int*)(0x42000000 + (0x2104C * 32) + (0*4))) = 0x1;
  
  // ---- set GPIO port to be an output
  // Address (GPIO A) -0x4800.0000 GPIO_MODER - GPIOA - MODE[5][01]  --> 0x0000.0400
  GPIO_MODER &= 0xFFFFF7FF;
  
  while(1) {
      // ----- LED ON 
      // Address (GPIO A) with offset 0x14 0x48000014 - GPIO_ODR - 5 --> 0x0000.0020
      GPIO_ODR = 0x00000020;
      counter = 0;
      while (counter < 100000) {
       counter++;
      } 
      // ----- LED OFF - 0x0
      GPIO_ODR = 0x00000000;
      counter = 0;
      while (counter < 100000) {
       counter++;
      } 
  }

  
 return 0;
}

#endif