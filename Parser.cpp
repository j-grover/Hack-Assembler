#include "Parser.h"
using namespace std;

string Parser::commandType(string command) 
{
	// A_COMMAND
	if (command[0] == '@') {
		return "A_COMMAND";
	}

	// L_COMMAND
	else if (command[0] == '(') {
		return "L_COMMAND";
	}

	// C_COMMAND
	else {
		return "C_COMMAND";
	}
}

string Parser::symbol(string command)
{
	// A_COMMAND
	if (commandType(command) == "A_COMMAND") {
	return command.substr(1);
	}

	// L_COMMAND
	return command.substr(1, command.size()-2);
}

string Parser::dest(string command)
{ 
	// Dest provided
	if (command.find('=') != string::npos) {
	return command.substr(0, command.find('='));
	}

	// No dest provided
	return "";
}

string Parser::comp(string command)
{
	// No dest provided
	if (command.find('=') == string::npos) { 
		return command.substr(0, command.find(';'));
	}

	// No jump provided
	else {
		return command.substr(command.find('=') + 1);
	}
}

string Parser::jump(string command)
{ 
	// Jump provided
	if (command.find(';') != string::npos) {
		return command.substr(command.find(';') + 1);
	}

	// No jump provided
	return "";
}