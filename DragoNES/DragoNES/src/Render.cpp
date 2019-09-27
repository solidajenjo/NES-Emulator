#include "Render.h"
#include "Application.h"
#include "Gui.h"
#include "imgui-1.73/imgui_impl_opengl3.h"
#include "imgui-1.73/imgui_impl_sdl.h"
#include <GL/glew.h> 
#include "Globals.h"  
#include <iostream>

Render::Render()
{
}


Render::~Render()
{
}

bool Render::Start()
{
	std::cout << "Starting Render module." << std::endl;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
	{
		printf("Error: %s\n", SDL_GetError());
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	window = SDL_CreateWindow("DracoNES emulator V0.01", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
	gl_context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, gl_context);
	SDL_GL_SetSwapInterval(1); // Enable vsync
	
	if (glewInit() != GLEW_OK)
		return false;

	return true;
}

bool Render::PostUpdate()
{
	ImGui::Render();
	glViewport(0, 0, (int)App->gui->io.DisplaySize.x, (int)App->gui->io.DisplaySize.y);
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(window);
	return true;
}

bool Render::Close()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return true;
}
