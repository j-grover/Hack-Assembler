#include "SymbolTable.h"
using namespace std;

void SymbolTable::setMap()
{
	// RAM address 0 to 4
	symbolTable.insert(pair<string, int>("SP",   0x0000));
	symbolTable.insert(pair<string, int>("LCL",  0x0001));
	symbolTable.insert(pair<string, int>("ARG",  0x0002));
	symbolTable.insert(pair<string, int>("THIS", 0x0003));
	symbolTable.insert(pair<string, int>("THAT", 0x0004));

	// Add R0-R15
	for (int i = 0; i < 16; i++) {
		stringstream ss;
		ss << "R" << i;
		string label = ss.str();
		symbolTable.insert(pair<string, int>(label, i));
	}

	// Screen and keyboard
	symbolTable.insert(pair<string, int>("SCREEN", 0x4000));
	symbolTable.insert(pair<string, int>("KBD",    0x6000));
}

void SymbolTable::addEntry(string symbol, int address)
{
	// Add symbol, address to table
	symbolTable.insert(pair<string, int>(symbol, address));
}

bool SymbolTable::contains(string symbol)
{
	// Iterator to element
	map<string, int>::iterator it = symbolTable.find(symbol);

	// Symbol found
	if (it != symbolTable.end()) {
		return true;
	}
	// Symbol not found
	else {
		return false;
	}
}

int SymbolTable::getAddress(string symbol)
{
	// Iterator to element
	map<string, int>::iterator it = symbolTable.find(symbol);

	// Symbol found
	if (it != symbolTable.end()) {
		return (it -> second);
	}
	// Symbol not found
	else {
		return -1;
	}
}