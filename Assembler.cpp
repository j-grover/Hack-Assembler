#include "Assembler.h"
using namespace std;

Assembler::Assembler() 
{
	// Set map with predfined symbols
	symboltable.setMap();
}

void Assembler::firstPass(string command, int address) 
{
	string currentSymbol;

	// Add L_COMMAND to symbol table 
	if (parser.commandType(command) == "L_COMMAND") {
		currentSymbol = parser.symbol(command);
		symboltable.addEntry(currentSymbol, address);
	}
}

void Assembler::secondPass(string command)
{
	// Assemble A instruction 
	if (parser.commandType(command) == "A_COMMAND") {
		buildACommand(command);
	}

	// Assemble C instruction
	else if (parser.commandType(command) == "C_COMMAND") {
	buildCCommand(command);
	} 

	// Nothing to be assembled
	else {
	}
}

void Assembler::buildACommand(string command)
{
	// RAM address starts at address 16
	static int RAMAddress = 16;
	string symbol = parser.symbol(command);
	int mappedValue;

	// Symbol is decimal
	if (isdigit(symbol[0])) {
		mappedValue = atoi(symbol.c_str());
	}
	else {
		// Symbol found in symbol table
		if (symboltable.contains(symbol)) {
			mappedValue = symboltable.getAddress(symbol);
		}
		// Add symbol to symbol table
		else {
			symboltable.addEntry(symbol, RAMAddress);
			mappedValue = RAMAddress++;
		}
	}

	// Converts int -> 15 bit binary
	bitset<15> binary = bitset<15> (mappedValue); 
	cout << "0" << binary << endl; 
}

void Assembler::buildCCommand(string command)
{
	// Retrieves assembly commands
	string destCommand = parser.dest(command);
	string compCommand = parser.comp(command);
	string jumpCommand = parser.jump(command);

	// Assemble C instruction as a string  
	string instruction = "111";
	instruction.append(code.comp(compCommand));
	instruction.append(code.dest(destCommand));
	instruction.append(code.jump(jumpCommand));

	cout << instruction << endl;
}