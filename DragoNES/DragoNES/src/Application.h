#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include <list>

class Module;

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


	
};

#endif