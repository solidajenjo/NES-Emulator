#include "Gui.h"
#include "Render.h"
#include "Application.h"
#include "imgui-1.73/imgui_impl_sdl.h"
#include "imgui-1.73/imgui_impl_opengl3.h"
#include <iostream>

Gui::Gui()
{

}


Gui::~Gui()
{
}

bool Gui::PreUpdate()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame(App->render->window);
	ImGui::NewFrame();
	return true;
}

bool Gui::Update()
{
	bool d;
	ImGui::Begin("Another Window", &d);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
	ImGui::Text("Hello from another window!");
	if (ImGui::Button("Close Me"))
		d = false;
	ImGui::End();

	ImGui::Render();
	return true;
}

bool Gui::Start()
{
	std::cout << "Starting Gui module." << std::endl;
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	io = ImGui::GetIO(); (void)io;

	ImGui::StyleColorsDark();

	if (!ImGui_ImplSDL2_InitForOpenGL(App->render->window, App->render->gl_context))
	{
		std::cout << "Failed to init ImGUI." << std::endl;
	}
	if (!ImGui_ImplOpenGL3_Init("#version 330"))
	{
		std::cout << "Failed to init ImGUI OpenGL context." << std::endl;
	}
	return true;
}
