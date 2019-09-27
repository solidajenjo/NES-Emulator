#ifndef __CPU6502_H_
#define __CPU6502_H_

#include "Module.h"

class CPU6502 : public Module
{
public:
	CPU6502();
	~CPU6502();

	bool Start() override;
};
#endif

