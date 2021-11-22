#pragma once

#include "Module.h"
#include "Globals.h"

class ModuleEditor : public Module
{
public:
	ModuleEditor();
	~ModuleEditor();

	bool Init();
	update_status PreUpdate();
	update_status Update();

	void DrawParentMenu();
	void DrawAboutMenu();
	bool CleanUp();
private:

	bool isDemoWin = false;
	bool isAbtWin = false;
};