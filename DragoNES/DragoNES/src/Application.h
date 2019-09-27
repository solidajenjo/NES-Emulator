#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include <list>
#include <memory>

class Module;
class Render;
class CPU6502;
class Gui;
class Input;

class Application
{
	enum class ApplicationState {
		START,
		RUN,
		CLOSE
	};

public:
	Application();
	~Application();

	bool Update();
	
	ApplicationState applicationState = ApplicationState::START;

	
	std::list<Module*> modules;
	std::unique_ptr<CPU6502> cpu;
	std::unique_ptr<Render> render;
	std::unique_ptr<Gui> gui;
	std::unique_ptr<Input> input;
	
};

extern Application* App;

#endif