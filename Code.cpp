#include "Code.h"
using namespace std;

string Code::dest(string mnemonic)
{
	bitset<3> destBinary;
	bitset<3> m_dest(string("001"));    // Destination of Memory[A]
	bitset<3> d_dest(string("010"));    // Destination of D register
	bitset<3> a_dest(string("100"));    // Destination of A register

	// If destination contains Memory[A]
	if (mnemonic.find('M') != string::npos) {
		destBinary ^= m_dest;
	}

	// If destination contains D register
	if (mnemonic.find('D') != string::npos) {
		destBinary ^= d_dest;
	}

	// If destination contains A register
	if (mnemonic.find('A') != string::npos) {
		destBinary ^= a_dest;
	}

	string s_dest = destBinary.to_string();
	return s_dest;
}

string Code::comp(string mnemonic)
{
	string s_comp;

	// Set a-bit to 1
	if (mnemonic.find('M') != string::npos) {
		replace(mnemonic.begin(), mnemonic.end(), 'M', 'A');
		s_comp.append("1");
	}
	// Set a-bit to 0
	else {
		s_comp.append("0");
	}

	// Assigns string s_comp binary code of comp mnemonic
	if (mnemonic == "0")		s_comp.append("101010");
	else if (mnemonic == "1")	s_comp.append("111111");
	else if (mnemonic == "-1")	s_comp.append("111010");
	else if (mnemonic == "D")	s_comp.append("001100");
	else if (mnemonic == "A")	s_comp.append("110000");
	else if (mnemonic == "!D")	s_comp.append("001101");
	else if (mnemonic == "!A")	s_comp.append("110001");
	else if (mnemonic == "-D")	s_comp.append("001111");
	else if (mnemonic == "-A")	s_comp.append("110011");
	else if (mnemonic == "D+1")	s_comp.append("011111");
	else if (mnemonic == "A+1")	s_comp.append("110111");
	else if (mnemonic == "D-1")	s_comp.append("001110");
	else if (mnemonic == "A-1")	s_comp.append("110010");
	else if (mnemonic == "D+A")	s_comp.append("000010");
	else if (mnemonic == "D-A")	s_comp.append("010011");
	else if (mnemonic == "A-D")	s_comp.append("000111");
	else if (mnemonic == "D&A")	s_comp.append("000000");
	else	s_comp.append("010101");

	return s_comp; 
}

string Code::jump(string mnemonic)
{
	string s_jump;

	// Assigns string s_jump binary code of s_jump mnemonic
	if (mnemonic == "JGT")		s_jump.append("001");
	else if (mnemonic == "JEQ")	s_jump.append("010");
	else if (mnemonic == "JGE")	s_jump.append("011");
	else if (mnemonic == "JLT")	s_jump.append("100");
	else if (mnemonic == "JNE")	s_jump.append("101");
	else if (mnemonic == "JLE")	s_jump.append("110");
	else if (mnemonic == "JMP")	s_jump.append("111");
	else	s_jump.append("000");

	return s_jump; 
}