nothing:
	@echo Chose something

# compile program    
all: myassembler

# myassembler is made by linking object files together 
myassembler: Parser.o Code.o Assembler.o SymbolTable.o
	g++ Parser.o Code.o Assembler.o SymbolTable.o main.cpp -o myassembler

# Parser.o object file recompile if Parser.cpp or Parser.h change     
Parser.o: Parser.cpp Parser.h
	g++ -c Parser.cpp -o Parser.o

# Code.o object file recompile if Code.cpp or Code.h change
Code.o: Code.cpp Code.h
	g++ -c Code.cpp -o Code.o

# Assembler.o object file recompile if Assembler.cpp or Assembler.h change
Assembler.o: Assembler.cpp Assembler.h
	g++ -c Assembler.cpp -o Assembler.o
	
# SymbolTable.o object file recompile if SymbolTablede.cpp or SymbolTable.h change
SymbolTable.o: SymbolTable.cpp SymbolTable.h
	g++ -c SymbolTable.cpp -o SymbolTable.o
	
# clean removes all object files and the compiled executable 
clean:
	rm -f *.o myassembler   