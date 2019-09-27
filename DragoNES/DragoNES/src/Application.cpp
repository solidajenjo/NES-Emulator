#include "Render.h"
#include "Application.h"
#include "Module.h"
#include "Input.h"
#include "CPU6502.h"
#include "Gui.h"
#include <iostream>

Application* App;

Application::Application()
{
	App = this;
	gui.reset(new Gui());
	cpu.reset(new CPU6502());
	render.reset(new Render());
	input.reset(new Input());

	modules.push_back(cpu.get());
	modules.push_back(render.get());
	modules.push_back(gui.get());
	modules.push_back(input.get());
}


Application::~Application()
{
}

bool Application::Update()
{
	bool status = true;

	switch (applicationState) {
	case ApplicationState::START:
		for (std::list<Module*>::iterator it = modules.begin(); it != modules.end() && status; ++it)
		{
			status = (*it)->Start();
		}
		if (status) {
			std::cout << "DragoNES start OK." << std::endl;
			applicationState = ApplicationState::RUN;
		}
		else {
			std::cout << "DragoNES start Failed." << std::endl;
			applicationState = ApplicationState::CLOSE;
		}
		break;
	case ApplicationState::RUN:
		for (std::list<Module*>::iterator it = modules.begin(); it != modules.end() && status; ++it)
		{
			status = (*it)->PreUpdate();
		}

		for (std::list<Module*>::iterator it = modules.begin(); it != modules.end() && status; ++it)
		{
			status = (*it)->Update();
		}

		for (std::list<Module*>::iterator it = modules.begin(); it != modules.end() && status; ++it)
		{
			status = (*it)->PostUpdate();
		}

		if (!status){
			std::cout << "DragoNES update Failed." << std::endl;
			applicationState = ApplicationState::CLOSE;
		}
		break;
	case ApplicationState::CLOSE:
		for (std::list<Module*>::iterator it = modules.begin(); it != modules.end(); ++it)
		{
			(*it)->Close();
		}
		if (status)
			std::cout << "DragoNES close OK." << std::endl;
		else
			std::cout << "DragoNES close Failed." << std::endl;
		break;
	}

	return status;
}
