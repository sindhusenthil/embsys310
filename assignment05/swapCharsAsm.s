/*******************************************************************************
File name       : aqrAsm.s
Description     : Assembly language function for square
*******************************************************************************/   

    PUBLIC swapCharsAsm       // Exports symbols to other modules
                        // Making sqrAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables.
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.

// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : sqrAsm
Description     : Calls C code to print a string; 
                  computes the square of its input argument
C Prototype     : int sqrAsm(val)
                : Where val is the value to calculate it's square
Parameters      : R0: integer val
Return value    : R0
*******************************************************************************/  
  


swapCharsAsm
    //PUSH {R0, R1, LR}  // pushing R0 ,R1 and LR onto stack  , SP points to top of stack i.e R0 
    // performing swap operation
    LDRB R2, [R0] // storing value of first char variable into a temp register R2
    LDRB R3, [R1] // storing value of second char variable into a temp register R3
    STRB R3, [R0] // storing  R3 i.e value of second char variable into R0
    STRB R2, [R1] // storing R2 i.e value of first char variable into R1

    BX LR  // branching back to link register to continue rest of operations in main
    END

