#include <iostream>
#include <string> 
#include <algorithm> 
#include <cstdio>
#include <vector>

#include "Assembler.h"

using namespace std;

int main()
{
	string input;
	vector<string> inputCommand;
	int lineNo = 0;
	Assembler assembler;

	// First pass of commands
	while (getline(cin, input)) {

		if (input[0] != '/' && !input.empty()) {
			// Check for command 
			if ( (input.find(";") != string::npos) || (input.find("=") != string::npos) || (input.find("@") != string::npos)
			|| (input[0] == '(')) {

				// Remove carriage return
				if (input[input.size() - 1] == '\r') {
					input.erase(input.size()-1);
				}
				// Remove whitespace
				input.erase(remove(input.begin(), input.end(), ' '), input.end());
				// Remove comments 
				input = input.substr(0, input.find("//", 0));

				// Store commands for second pass
				inputCommand.push_back(input);

				if (input[0] != '(') {
					lineNo++;
				}
				// First pass of program
				assembler.firstPass(input, lineNo);
			}
		}
	}

	// Second pass of program
	for (int i=0; i<inputCommand.size(); i++) {
		assembler.secondPass(inputCommand[i]);
	}

	return 0;
}