#include "Input.h"
#include "Application.h"
#include "Render.h"
#include "SDL2/SDL.h"
#include "imgui-1.73/imgui.h"
#include "imgui-1.73/imgui_impl_sdl.h"

Input::Input()
{
}

Input::~Input()
{
}

bool Input::PreUpdate()
{
	SDL_Event event;
	bool close = false;
	while (SDL_PollEvent(&event))
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		if (event.type == SDL_QUIT)
			close = true;
		if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(App->render->window))
			close = true;
	}
	return !close;
}
