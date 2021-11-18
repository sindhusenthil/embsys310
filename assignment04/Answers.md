
### Answers:


#1

a. It allows you to write in one bit granularity. bit[0] inside 0x4002104C gets a value of 1 by writing 1 to alias address 0x42420980.
We can store data directly into the address using alias bit banding. 

Assembly code: 
MOVS R0, #1
LDR.N R1, [PC, #0x40]              # loading the bit band address into R1
STR R0, [R1]                       # storing R0 i.e 1 into the bit band address, thus modifying bit[0] of 0x4002104C to 1


b. It only allows you to write in one byte granularity. 
We need to read the data in the address, modify and write it. 

Assembly code:
LDR.N R0, [PC, #0x44]              # loads address RCC_AHB2ENR i.e 0x4002104C to R0
LDR   R1, [R0]                     # R1 reads contents of R0 i.e RCC_AHB2ENR
ORRS.W R1, R1, #1                  # R1 = R1 + 0x1
STR R1, [R0]                       # storing value of R1 to RCC_AHB2ENR


#2

a. Arguments to func1(0,1,2,3,4):
4 is stored into R0
R0 i.e 4 is stored to the stack replacing value of 0 from R7
3 is stored into R3
2 is stored into R2
1 is stored into R1
0 is stored into R0

 
b.It pushed Link Register value (pointing to the next instruction in main()) and R7 i.e 0 onto the stack. 
Not sure why it pushed R7 value when it wasn't be used in the code...
 
c. Inside Func1:
Value of R4 i.e 0 is pushed onto the stack 
R4 gets the value of SP + 4 which is equal to 4 the value we initially stored onto stack from R0
R0 adds with R1, R2, R3 and R4 to produce the sum 
In the end we pop the value of R4 i.e 0 that we initially stored


d.Link register and PC values are all popped out reducing the stack pointer
As we add to the stack the SP moves to a lower address - Stack growing towards lower addresses



