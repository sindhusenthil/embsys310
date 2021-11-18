#include <assert.h>
#include "stack.h"


int main()
{ 

  // TestCases::
  int result1;
  int result2;
  int testInt;
 
  //************************************
  // Test1: Retrieve an item from an empty stack
  //************************************
  
  //Arrange
  result1 = 42;
  testInt = 3;
  stack_init();
  
  //Act
  result1 = stack_get(&testInt);
  
  //Assert
  assert(-1 == result1);
  assert(3 == testInt);  // to make sure data is not corrupted
  
    //************************************
  // Test2: Successfully retrieve an item from stack
  //************************************
  
  //Arrange
  result1 = 42;
  result2 = 42;
  testInt = 3;
  stack_init();
  
  //Act
  result1 = stack_put(7);
  result2 = stack_get(&testInt);
  
  //Assert
  assert(1 == result1);
  assert(1 == result2);
  assert(7 == testInt);
  
  //***********************************
  // Test3: Fill the stack and retrieve all items
  //************************************
  
  //Arrange:
  testInt = 3;
  stack_init();
  
  //Act
  stack_put(1);
  stack_put(2);
  stack_put(3);
  stack_put(4);
  stack_put(5);
  
  //Assert
  assert(1 == stack_get(&testInt));
  assert(5 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(4 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(3 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(2 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(1 == testInt);

  //***********************************
  // Test4: Fill the stack and putting one more item should fail
  //************************************  
  
  //Arrange
  testInt = 3;
  stack_init();
  
  //Act
  stack_put(1);
  stack_put(2);
  stack_put(3);
  stack_put(4);
  stack_put(5);

  //Assert:
  assert(-1 == stack_put(6));

  assert(1 == stack_get(&testInt));
  assert(5 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(4 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(3 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(2 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(1 == testInt);
  
  //***********************************
  // Test5: Fill the stack retrieve one item ,add one item and then retrieve all
  //************************************    
  
  //Arrange:
  testInt = 3;
  stack_init();
  
  //Act
  stack_put(1);
  stack_put(2);
  stack_put(3);
  stack_put(4);
  stack_put(5);
  
  //Assert:
  assert(1 == stack_get(&testInt));
  assert(5 == testInt); 
  
  assert(1 == stack_put(7));

  assert(1 == stack_get(&testInt));
  assert(7 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(4 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(3 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(2 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(1 == testInt);  



  //***********************************
  // Test6: Fill the stack retrieve all items. Do it twice in a row. 
  //************************************      
  
  //Arrange:
  testInt = 17;
  stack_init();
  
  //Act
  stack_put(1);
  stack_put(2);
  stack_put(3);
  stack_put(4);
  stack_put(5);

  //Assert:
  assert(1 == stack_get(&testInt));
  assert(5 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(4 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(3 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(2 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(1 == testInt);  
  
  assert(1 == stack_put(7));
  assert(1 == stack_put(8));
  assert(1 == stack_put(9));
  assert(1 == stack_put(10));
  assert(1 == stack_put(11));
      
  
  assert(-1 == stack_put(17));
  
  
  assert(1 == stack_get(&testInt));
  assert(11 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(10 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(9 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(8 == testInt);
  
  assert(1 == stack_get(&testInt));
  assert(7 == testInt);  
    
  return 0;
}
