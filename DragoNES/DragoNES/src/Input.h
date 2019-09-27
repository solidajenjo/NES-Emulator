#ifndef __INPUT_H_
#define __INPUT_H_

#include "Module.h"
class Input : public Module
{
public:
	Input();
	~Input();

	bool PreUpdate() override;
};

#endif