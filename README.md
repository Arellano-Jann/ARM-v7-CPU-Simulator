# Assembly-Hex-Calc

# Build Instructions
To build the program:
1. Open the terminal
2. Type `make`
3. Type `./main`
4. Type `file.txt` into the prompt. This can be any other filename too.
5. ???
6. Profit.

____
# Assignment Instructions

You are tasked with designing a machine language simulator. 
This project must be written in C or C++.
If you elect to use C++ be careful with your objects. Your code should be versatile enough to be modified for future assignments with more than one operation. 

For part 1 you must only implement the ADD operation.
You will be given a text file for input on this project; following the format discussed in the Theory section. 

An example operation will be in the form


ADD 0x12345 0x678


When the operation to be performed is addition and it is adding the two numbers 0x12345 and 0x678.
These numbers will be hexadecimal format. Recall that the prefix of hexadecimal is always ”0x” and this is not to be considered in any conversion process. You might find it useful to use the uint32t in C/C++ to store the number as an unsigned 32-bit number.


Using the provided text file as an example input. You will be tasked with creating a program that will read the command (ADD, but future projects may have more) and it will perform the addition between the two hexadecimal numbers. 

HINT: You may find it helpful to store this value in a variable, should you ever need to retrieve the information or store it in a simulated register. But this is not required for part 1. The result of the addition operation must be displayed to the terminal or build environment.

Your code should follow proper code commenting and indentation procedures.

# Operation List:
1. ADD - Add the operands 
2. AND - Do a bitwise AND of the operands 
3. ASR - Do a 1-bit arithmetic shift right on the first operand 
4. LSR - Do a 1-bit logical shift right on the first operand 
5. LSL - Do a 1-bit logical shift left on the first operand 
6. NOT - Do a bitwise NOT on the first operand 
7. ORR - Do a bitwise OR of the operands 
8. SUB - Subtract the second operand from the first operand 
9. XOR - Do a bitwise exclusive OR of the operands