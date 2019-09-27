#include "CPU6502.h"
#include <iostream>

//TODO:Rember the 16 NES roms header

CPU6502::CPU6502()
{
}


CPU6502::~CPU6502()
{
}

bool CPU6502::Start()
{
	std::cout << "Starting CPU6502 module." << std::endl;
	return true;
}
