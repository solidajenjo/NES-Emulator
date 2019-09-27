#ifndef __RENDER_H_
#define __RENDER_H_

#include "Module.h"
#include <memory>

#include "SDL2/SDL.h"


class Render :	public Module
{
public:
	Render();
	~Render();

	bool Start() override;
	bool PostUpdate() override;
	bool Close() override;

	SDL_Window* window;
	SDL_GLContext gl_context;
};

#endif