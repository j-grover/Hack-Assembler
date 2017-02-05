#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H

#include <map>
#include <string> 
#include <sstream>

// Creates and maintains symbolic labels and their numeric addresses  
class SymbolTable
{
	public:
		// Sets table with predefined symbols
		void setMap(); 

		// Adds the symbol and its addresses to the table 
		void addEntry(std::string symbol, int address);

		// Returns true if the symbol table contains the given symbol, false otherwise 
		bool contains(std::string symbol); 

		// Returns the address associated with the symbol
		int getAddress(std::string symbol); 

	private:
		std::string symbol;		// Stores the current symbol 

		int address;			// Stores the address of the current symbol

		std::map<std::string, int> symbolTable;	// Symbol table storing labels & numeric addresses
};

#endif // _SYMBOLTABLE_H