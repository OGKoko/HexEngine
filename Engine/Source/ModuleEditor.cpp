#include "Globals.h"
#include "Application.h"
#include "ModuleEditor.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"

#include "SDL.h"

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"


ModuleEditor::ModuleEditor()
{

}

// Destructor
ModuleEditor::~ModuleEditor()
{

}

// Called before render is available
bool ModuleEditor::Init()
{
	//InitializeImGui();
	return true;
}

update_status ModuleEditor::PreUpdate()
{
	//Begin new ImGui Frame
	//ImGui_ImplOpenGL3_NewFrame();
	//ImGui_ImplSDL2_NewFrame();//App->window->window
	//ImGui::NewFrame();

	return UPDATE_CONTINUE;
}

// Called every draw update
update_status ModuleEditor::Update()
{
	bool widShown = true;
	ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_MenuBar;
	ImGui::Begin("Editor", &widShown, windowFlags);
	DrawParentMenu();
	if (isAbtWin)
	{
		DrawAboutMenu();
	}
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	return UPDATE_CONTINUE;
}

void ModuleEditor::DrawParentMenu()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("Help"))
		{
			if (ImGui::MenuItem("About"))
			{
				isAbtWin = true;
			}
			ImGui::EndMenu();  //fin del bloque help
		}
				ImGui::EndMainMenuBar();
	}

	if (ImGui::BeginMenu("Help")) //empieza el nuevo bloque Help
	{
		if (ImGui::MenuItem("About")) //creacion panel abt
		{
			isAbtWin = true;
		}
		ImGui::EndMenu(); // fin del bloque help
	}
	// End Drawing Main Menu Bar:
	//ImGui::EndMainMenuBar();
	/*bool winShow = true;
	ImGui::ShowDemoWindow(&winShow);
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	;*/
	//}
	//ImGui::End();
}



void ModuleEditor::DrawAboutMenu()
{

	ImGui::Begin("About", &isAbtWin);

	ImGui::AlignTextToFramePadding();
	ImGui::TextWrapped("HexEngine");
	ImGui::Separator();
	ImGui::TextWrapped("Noone scapes from HexEngine magnificiency.\n");
	ImGui::Separator();
	ImGui::TextWrapped("\n Comissions at: eimbertupc@gmail.com or @koko.wav on IG.\n");

	ImGui::TextWrapped("\n Done by: Enrique Imbert-Bouchard Nadal \n");
	ImGui::Separator();

	ImGui::End();
}

void ModuleEditor::InitializeImGui()
{

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();


	ImGui_ImplSDL2_InitForOpenGL(App->window->window, App->renderer->context);
	ImGui_ImplOpenGL3_Init("#version 330");

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();//App->window->window
	ImGui::NewFrame();

	//ImGui::End();
}






// Called before quitting
bool ModuleEditor::CleanUp()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::End();
	ImGui::DestroyContext();

	return true;
}
