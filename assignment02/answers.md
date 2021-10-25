Answers:

1. 0x7FFFFFFF:
	a) -2147483648
	b) 0x80000000
	c) N = 1 & V = 1.
           This is because after addition it made the most significant bit of counter as 1.
           We declared our counter as an int (signed integer). Because the value 2147483648 exceeds the range of a signed 4 byte, an overflow occurs and changes the sign.
	   The debugger thinks of it has a negative number - 2s complement

2. 0xFFFFFFFF:
	a) 0
	b) Z = 1 & C = 1. Value of counter is 0 so the zero flag condition (Z) gets set. On adding counter value (0xFFFFFFFF) to 0X00000001
           we get a carry of 1.

3. 0x7FFFFFFF unsigned int:
	a) 2147483648
	b) N = 1 & V = 1. ADDS tells processor to monitor side effects of the addition and reflect on the ASPR. Processor does not know if its signed
           or unsigned int. It makes sense to C language but not to the processor, in the hardware it just gets flagged. User needs to interpret accordingly here its ignored

4. 0xFFFFFFFF unsigned int:
	a) 0
	b) Flags set in APSR: Z = 1 & C = 1. Value of counter is 0 so the zero flag condition (Z) gets set. On adding counter value (0xFFFFFFFF) to 0X00000001
           we get a carry of 1

5. counter variable outside of main
	a) The variable can be accessed inside any of the functions defined for the program
	b) no
	c) Watch window
	4) 0x20000000 - stored in RAM

6.
	a) 5
	b) counter variable was stored in memory 0x20000000. Pointer was pointing to the same address space.
           So deferencing the pointer and incrementing it was incrementing the counter variable

7. Evaluation Board
	a) 0x20000000
	b) RAM
	c) 5



