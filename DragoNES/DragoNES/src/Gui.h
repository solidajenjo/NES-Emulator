#ifndef __GUI_H_
#define __GUI_H_

#include "Module.h"
#include "imgui-1.73/imgui.h"

class Gui :	public Module
{
public:
	Gui();
	~Gui();

	bool PreUpdate() override;
	bool Update() override;
	bool Start() override;

	ImGuiIO io;
};

#endif