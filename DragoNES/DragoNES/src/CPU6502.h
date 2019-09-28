#ifndef __CPU6502_H_
#define __CPU6502_H_

#include "Module.h"
#include <string>
#include <vector>

class CPU6502 : public Module
{
public:

	typedef unsigned char uchar;

	struct Instruction {
		Instruction() {}
		Instruction(char op, char length, char cycles, std::string text) : op(op), length(length), cycles(cycles), text(text) {}
		char op, length, cycles, ab, cd;
		std::string text;
	};

	uchar F6, F7, F8, F9, F10;

	CPU6502();
	~CPU6502();

	bool Start() override;

	void CreateInstructionArray();
	bool LoadRom(const std::string& name);

	std::vector<Instruction> program;
	Instruction instructions[256];

	std::vector<uchar> PRG_ROM;
	unsigned PRG_ROM_size, CHR_ROM_size;

	uchar mapper;
	
};
#endif

