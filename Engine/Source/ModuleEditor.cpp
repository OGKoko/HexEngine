#include "Globals.h"
#include "Application.h"
#include "ModuleEditor.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "Timer.h"
#include "SDL.h"
#include "Timer.h"
/*#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"*/


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
	//fpsList.reserve(FPS_BUFFER);
	//clockList.reserve(FPS_BUFFER);

	return true;
}

update_status ModuleEditor::PreUpdate()
{/*
	//Begin new ImGui Frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();//App->window->window
	ImGui::NewFrame();
	*/
	return UPDATE_CONTINUE;
}

// Called every draw update
update_status ModuleEditor::Update()
{/*
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
	//ImGui::End();*/

	return UPDATE_CONTINUE;
}
/*
void ModuleEditor::DrawParentMenu()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("Tools"))
		{

			if (ImGui::MenuItem("Performance"))
			{
				isFPSTab = true;
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Help"))
		{

			if (ImGui::MenuItem("About"))
			{
				isAbtWin = true;
			}
			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();
	}/*
	ImGui::EndMainMenuBar();*/
	// End Drawing Main Menu Bar:
	/*bool winShow = true;
	ImGui::ShowDemoWindow(&winShow);
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	;
	//}
	ImGui::End();
}

*/
/*
void ModuleEditor::DrawAboutMenu()
{
	ImGui::Begin("About", &isAbtWin);

	ImGui::AlignTextToFramePadding();
	ImGui::TextWrapped(TITLE);
	ImGui::Separator();

	ImGui::TextWrapped("\n");
	ImGui::TextWrapped("GIT Repo");
	ImGui::Separator();
	if (ImGui::Button("PRESS HERE", ImVec2(ImGui::GetContentRegionAvailWidth(), 0)))
	{
		OpenLink(REPO_URL);
	}

	ImGui::TextWrapped("\n");
	ImGui::TextWrapped("Author(s)");
	ImGui::Separator();
	ImGui::TextWrapped("Enrique Imbert-Bouchard Nadal");
	ImGui::TextWrapped("\n");
	ImGui::End();
}
*/
/*
void ModuleEditor::InitializeImGui()
{

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();


	ImGui_ImplSDL2_InitForOpenGL(App->window->window, App->renderer->context);
	ImGui_ImplOpenGL3_Init(GLVER);

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	//ImGui::End();
}*/
/*
void ModuleEditor::DrawFPSMenu()
{
	if (!isFPSTab)
	{
		if (!fpsList.empty())
		{
			clockList.clear();
		}

		if (!clockList.empty())
		{
			clockList.clear();
		}

		return;


*/




// Called before quitting
bool ModuleEditor::CleanUp()
{/*
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
	ImGui::End();

 */
	return true;
}
