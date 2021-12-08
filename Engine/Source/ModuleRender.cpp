#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleEditor.h"
#include "Globals.h"
#include "SDL.h"
#include "glew/glew-2.1.0/include/GL/glew.h"

	
ModuleRender::ModuleRender()
{
}

// Destructor
ModuleRender::~ModuleRender()
{
}

// Called before render is available
bool ModuleRender::Init()
{
	InitGlew();
	MiscLog();
	InitPipeline();
	InitOpenGL();

	SDL_GetWindowSize(App->window->window, &winWidth, &winHeight);
	/*
	float vtx_data[] = { -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f };
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo); // set vbo active
	glBufferData(GL_ARRAY_BUFFER, sizeof(vtx_data), vtx_data, GL_STATIC_DRAW);*/
	
	return true;
}

update_status ModuleRender::PreUpdate()
{/*
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));
	glDrawArrays(GL_TRIANGLES, 0, 3);*/
	
	/*
	// basic struct timer
	unsigned int lTime = 0, currentTime;
	bool quit = false;

	while (!quit) {
		currentTime = SDL_GetTicks();
		if (currentTime > lTime + 1000) {
			LOG("REPORT %d\n", currentTime);
			lTime = currentTime;
			quit = true;
		}
	}*/
	return UPDATE_CONTINUE;
}

// Called every draw update
update_status ModuleRender::Update()
{

	return UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	LOG("PUR");
	SDL_GL_SwapWindow(App->window->window);


	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");
	
	SDL_GL_DeleteContext(context);
	glDeleteBuffers(1, &vbo);

	return true;
}

void ModuleRender::WindowResized(unsigned width, unsigned height)
{
	this->winWidth = width;
	this->winHeight = height;
}

void ModuleRender::InitGlew()
{
	LOG("Creating Renderer context");
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	GLenum error = glewInit();
	context = SDL_GL_CreateContext(App->window->window);

	LOG("Using Glew %s", glewGetString(GLEW_VERSION));
}

void ModuleRender::InitPipeline()
{
	glEnable(GL_DEPTH_TEST); //	depth test
	glEnable(GL_CULL_FACE); // faceculling
	glFrontFace(GL_CCW); // correct triang facing
	glEnable(GL_SCISSOR_TEST); //scissor test
	glEnable(GL_STENCIL_TEST); //stencil test


}

void ModuleRender::InitOpenGL()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);

	
}

void ModuleRender::MiscLog()
{
	LOG("Vendor: %s", glGetString(GL_VENDOR));
	LOG("Renderer: %s", glGetString(GL_RENDERER));
	LOG("OpenGL version supported %s", glGetString(GL_VERSION));
	LOG("GLSL: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

