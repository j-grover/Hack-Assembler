#ifndef _PARSER_H
#define _PARSER_H

#include <string>

// Reads an assembly language command, parses it, and provides access to the
// command's components
class Parser
{
	public:
		// Returns the type of the current command 
		std::string commandType(std::string command);

		// Returns the symbol or decimal Xxx of the current command @Xxx or (Xxx)
		std::string symbol(std::string command);

		// Returns the dest mnemonic in the current C-command 
		std::string dest(std::string command);

		// Returns the comp mnemonic in the current C-command 
		std::string comp(std::string command);

		// Returns the jump mnemonic in the current C-command 
		std::string jump(std::string command);
};

#endif // _PARSER_H