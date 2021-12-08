#pragma once

#include "Module.h"
#include "Globals.h"
#include <vector>

class ModuleEditor : public Module
{
public:
	ModuleEditor();
	~ModuleEditor();

	bool Init();
	update_status PreUpdate();
	update_status Update();

	/*void DrawParentMenu();
	void DrawAboutMenu();
	void InitializeImGui();
	void DrawFPSMenu();*/
	bool CleanUp();

private:
	bool isFPSTab = false;
	bool isDemoWin = false;
	bool isAbtWin = false;
	std::vector<float> fpsList;
	std::vector<float> clockList;
};
inline void OpenLink(const char* link)
{
	ShellExecute(NULL, "open", link, NULL, NULL, SW_SHOWNORMAL);
}