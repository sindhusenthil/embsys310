#include <stdio.h>

extern void swapCharsAsm(char* arg1, char* arg2);

int main()
{ 
    char char1 = 'A'; 
    char char2 = 'B'; 
    
    swapCharsAsm(&char1, &char2);  
    
    printf("swapping complete\n");
    
    
  return 0;
}

