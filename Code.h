#ifndef _CODE_H
#define _CODE_H

#include <bitset>
#include <string>
#include <algorithm>

// Translates Hack assembly language mnemonics into binary codes
class Code
{
	public:
		// Returns the binary code of the dest mnemonic
		std::string dest(std::string mnemonic);

		// Returns the binary code of the comp mnemonic
		std::string comp(std::string mnemonic);

		// Returns the binary code of the jump mnemonic
		std::string jump(std::string mnemonic);
};

#endif // _CODE_H