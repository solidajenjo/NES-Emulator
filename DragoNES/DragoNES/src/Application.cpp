#include "Application.h"
#include "Module.h"
#include "CPU6502.h"
#include "Gui.h"
#include <iostream>


Application::Application()
{
	modules.push_back(new CPU6502());
	modules.push_back(new Gui());
}


Application::~Application()
{
}

bool Application::Update()
{
	bool status = false;

	switch (applicationState) {
	case ApplicationState::START:
		for (std::list<Module*>::iterator it = modules.begin(); it != modules.end(); ++it)
		{
			status = status || (*it)->Start();
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
		for (std::list<Module*>::iterator it = modules.begin(); it != modules.end(); ++it)
		{
			status = status || (*it)->Update();
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
