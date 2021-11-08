
  int counter = 0;

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIO_A_BASE 0x48000000

#define GPIO_MODER  (*((unsigned int*)0x48000000))

#define GPIO_ODR    (*((unsigned int*)(GPIO_A_BASE + 0x14)))

int main() {
    
  // writing a value of 1 to 0x4002104C to enable clock for GPIOA --> 0x0000.0001
  RCC_AHB2ENR = 0x00000001;
  
  // ---- set GPIO port to be an output
  // Address (GPIO A) -0x4800.0000 GPIO_MODER - GPIOA - MODE[5][01]  --> 0x0000.0400
  GPIO_MODER = 0x00000400;
   
  while(1) {
  
  // ----- LED ON 
  // Address (GPIO A) with offset 0x14 0x48000014 - GPIO_ODR - 5 --> 0x0000.0020
  counter = 0; 
  
  while (counter < 100000) {
   counter++;
  }
  
  // Using XOR operator to toggle
  GPIO_ODR ^= 0x00000020;
  
  }
  
  return 0;
}
  
  
  

