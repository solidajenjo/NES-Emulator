#ifndef __CPU6502_H_
#define __CPU6502_H_

#include "Module.h"
#include <string>

class CPU6502 : public Module
{
public:

	struct Instruction {
		Instruction() {}
		Instruction(char op, char length, char cycles, std::string text) : op(op), length(length), cycles(cycles), text(text) {}
		char op, length, cycles;
		std::string text;
	};

	CPU6502();
	~CPU6502();

	bool Start() override;

	void CreateInstructionArray();

private:
	Instruction instructions[256];
};
#endif

