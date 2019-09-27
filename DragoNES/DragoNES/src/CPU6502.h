#ifndef __CPU6502_H_
#define __CPU6502_H_

#include "Module.h"
#include <string>
#include <vector>

class CPU6502 : public Module
{
public:

	struct Instruction {
		Instruction() {}
		Instruction(char op, char length, char cycles, std::string text) : op(op), length(length), cycles(cycles), text(text) {}
		char op, length, cycles, ab, cd;
		std::string text;
	};

	CPU6502();
	~CPU6502();

	bool Start() override;

	void CreateInstructionArray();
	bool LoadRom(const std::string& name);

	std::vector<Instruction> program;

private:
	Instruction instructions[256];

	unsigned PRG_ROM_size, CHR_ROM_size;
	char F6, F7, F8, F9, F10;

	bool hasTrainer;
};
#endif

