# Hack Assembler
Machine language assembler for the Hack Assembly Language.

## Description
The assembler takes a program file written in the Hack Assembly Language (.asm) and assembles it into binary machine code (Hack Machine Language). The assembled machine code program is written to a file which is given the extension .hack.

The assembler makes use of two passes of the input file. The first pass adds the label entries to a symbol table. The second pass adds the variables to the symbol table, substitutes the symbols with their memory addresses and genrates binary code writing it to standard output.

The following components make up the Assembler:

- Assembler: Assembles commands into Hack Machine code and writes to standard output
- Code: Translates Hack assembly language mnemonics into binary codes
- Parser: Reads an assembly language command, parses it, and provides access to the command's components
- SymbolTable: Creates and maintains symbolic labels and their numeric addresses 
- main: Runs the first and second pass, handles input

## Running the program
```
$ make all
$ ./myassembler < Input.asm > Output.hack
```
Input.asm refers to the program file to be assembled. Output.hack is optional, will contain the binary machine code.

## Test Example
Rect.asm
```
// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/06/rect/Rect.asm

// Draws a rectangle at the top-left corner of the screen.
// The rectangle is 16 pixels wide and R0 pixels high.

   @0
   D=M
   @INFINITE_LOOP
   D;JLE 
   @counter
   M=D
   @SCREEN
   D=A
   @address
   M=D
(LOOP)
   @address
   A=M
   M=-1
   @address
   D=M
   @32
   D=D+A
   @address
   M=D
   @counter
   MD=M-1
   @LOOP
   D;JGT
(INFINITE_LOOP)
   @INFINITE_LOOP
   0;JMP
```
Rect.hack
```
0000000000000000
1111110000010000
0000000000010111
1110001100000110
0000000000010000
1110001100001000
0100000000000000
1110110000010000
0000000000010001
1110001100001000
0000000000010001
1111110000100000
1110111010001000
0000000000010001
1111110000010000
0000000000100000
1110000010010000
0000000000010001
1110001100001000
0000000000010000
1111110010011000
0000000000001010
1110001100000001
0000000000010111
1110101010000111
```
