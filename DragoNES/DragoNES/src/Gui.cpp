#include "Gui.h"
#include "Render.h"
#include "Application.h"
#include "CPU6502.h"
#include "imgui-1.73/imgui_impl_sdl.h"
#include "imgui-1.73/imgui_impl_opengl3.h"
#include <iostream>
#include <sstream>


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
	if (ImGui::Begin("Assembler", &d))
	{
		ImGui::Text("Hello from another window!");		
	}
	ImGui::End();
	if (ImGui::Begin("PRG ROM", &d))
	{
		unsigned i = 0u;
		std::stringstream ss;
		for (const unsigned char c : App->cpu->PRG_ROM) {	//TODO: This is so slow		
			if (c < 0x10)
				ss << '0';
			ss << std::hex << (unsigned int)c << "  ";
			++i;
			if (i == 16u) {
				ImGui::Text(ss.str().c_str());
				ss.str("");
				i = 0u;
			}			
		}
	}
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
