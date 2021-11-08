int counter = 0;

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIO_A_BASE 0x48000000

#define GPIO_MODER  (*((unsigned int*)0x48000000))

#define GPIO_ODR    (*((unsigned int*)(GPIO_A_BASE + 0x14)))


//------------------------------
void dot() {
  counter = 0; 
  // LED ON
  GPIO_ODR = 0x00000020;
  while (counter < 100000) {
   counter++;
  } 
  // LED OFF
  GPIO_ODR = 0x00000000;
  counter = 0; 
  while (counter < 100000) {
  counter++;
  } 
return;    
}

//-----------------------------
void dash() {
  counter = 0; 
  // LED ON
  GPIO_ODR = 0x00000020;
  while (counter < 1000000) {
   counter++;
  } 
  // LED OFF
  GPIO_ODR = 0x00000000;
  counter = 0; 
  while (counter < 100000) {
  counter++;
  } 
return;    
}

//-----------------------------
void delay() {
counter = 0; 
GPIO_ODR = 0x00000000;
while (counter < 1000000) {
counter++; 
}
return;
}

//------------------------------
  
int main()
{
  // writing a value of 1 to 0x4002104C to enable clock for GPIOA --> 0x0000.0001
  RCC_AHB2ENR = 0x00000001;
  
  // ---- set GPIO port to be an output
  // Address (GPIO A) -0x4800.0000 GPIO_MODER - GPIOA - MODE[5][01]  --> 0x0000.0400
  GPIO_MODER = 0x00000400;
  
  //S 
  dot();
  dot();
  dot();
  
  delay();
  
  //I
  dot();
  dot();
  
  
  delay();
   
  //N
  dash();
  dot();
  
  delay();
  
  //D
  dash();
  dot();
  dot();
  
  delay();
  
  //H
  dot();
  dot();
  dot();
  dot();
  
  delay();
  
  //U
  dot();
  dot();
  dash();
  
  delay();
  

  return 0;
}
  
  
  

