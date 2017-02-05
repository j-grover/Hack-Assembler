#ifndef _ASSEMBLER_H
#define _ASSEMBLER_H

#include <iostream>
#include <string>
#include <bitset>
#include <cctype>

#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"

// Assembles commands into Hack Machine code and writes to standard output
class Assembler
{
	public:
		// Constructs Assembler object and sets symbol table
		Assembler();

		// Adds label entries to the symbol table
		void firstPass(std::string command, int address);

		// Adds variables to symbol table, assembles commmands and
		// writes them to standard output
		void secondPass(std::string command);

	private:
		// Builds A instructions and writes code to standard output
		void buildACommand(std::string command);

		// Builds C instructions and writes code to standard output
		void buildCCommand(std::string command);

		Parser parser;		// Parser object to read commands

		Code code;			// Code object translate C instructions

		SymbolTable symboltable;	// SymbolTable object to handle symbols
};

#endif // _ASSEMBLER_H