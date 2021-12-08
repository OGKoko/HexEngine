#pragma once
#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void WindowResized(unsigned width, unsigned height);
	void InitGlew();
	void InitPipeline();
	void InitOpenGL();
	void MiscLog();
	void* context;

	//inline Model* getModel() const { return model; }
private:
	

	int winWidth = SCREEN_WIDTH;
	int winHeight = SCREEN_HEIGHT;

	unsigned vbo;


};
