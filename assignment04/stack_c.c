#include "stack.h"
#define STACK_SIZE 5

// Backing store
int StackStore[STACK_SIZE];

int top = -1; // to keep track of pushes and pops

// Intitializing itnernals of the queue
void stack_init(void)
{
 top = -1;
 for (int i = 0; i < STACK_SIZE; i++){
   StackStore[i] = '\0';
 }
 return;
}

 int stack_put(int data){
 // stack is full
   if (top == (STACK_SIZE-1)){
     return -1;
   }
   
   StackStore[++top] = data; 
   
 return 1; 
}

int stack_get(int* data){

// stack is empty
  if (top == -1) {
    return -1;
  }
   
  *data = StackStore[top];
  StackStore[top] = '\0';
  top--;
  
  return 1; 
}
  
   

