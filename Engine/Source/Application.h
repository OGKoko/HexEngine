#pragma once

#include<list>
#include "Globals.h"
#include "Module.h"

class ModuleRender;
class ModuleWindow;
class ModuleInput;
class ModuleEditor;
class ModuleCamera;
class ModuleDebugDraw;
class ModuleTexture;
//class ModuleShader;

class Application
{
public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

public:
	ModuleRender* renderer = nullptr;
	ModuleWindow* window = nullptr;
	ModuleInput* input = nullptr;
	//ModuleShader* shader = nullptr;
	ModuleCamera* camera = nullptr;
	ModuleDebugDraw* debugDraw = nullptr;
	ModuleTexture* textures = nullptr;

	ModuleEditor* editor = nullptr;
private:

	std::list<Module*> modules;

};

extern Application* App;
