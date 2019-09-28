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

	struct Flag6 {
		char mapper : 4, ignoreMirroring : 1, trainer : 1, batteryPGR_RAM : 1, mirroring : 1;
	};

	struct Flag7 {
		char mapper : 4, nes2_0 : 2, playChoice_10 : 1, VS_Unisystem : 1;
	};

	struct Flag8 {
		char PRG_RAM_size;
	};

	struct Flag9 {
		char reserved : 7, TV_system : 1;
	};

	struct Flag10 {
		char reserved : 2, busConflicts:1, PRG_RAM:1, TV_system : 2;
	};

	Flag6 F6;
	Flag7 F7;
	Flag8 F8;
	Flag9 F9;
	Flag10 F10;

	CPU6502();
	~CPU6502();

	bool Start() override;

	void CreateInstructionArray();
	bool LoadRom(const std::string& name);

	std::vector<Instruction> program;
	Instruction instructions[256];

	std::vector<unsigned char> PRG_ROM;
	unsigned PRG_ROM_size, CHR_ROM_size;
	
};
#endif

