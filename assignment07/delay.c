#include "delay.h"

extern int globalcounter; 
void delay(unsigned int delayInMilliseconds)
{
  
   globalcounter = delayInMilliseconds;
   
   while (globalcounter > 0){
     
   }
}