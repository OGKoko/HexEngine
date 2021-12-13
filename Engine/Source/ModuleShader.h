#pragma once
#include "Module.h"
#include "Application.h"
#include "Globals.h"
#include "GL/glew.h"

class Application;

class ModuleShader : public Module
{
public:
	ModuleShader();
	~ModuleShader();

	bool Init();

	unsigned GetId() { return glId; };

	bool CleanUp();
private:
	unsigned glId; 
	char* ShaderLoader(const char* shader_path);
	unsigned ShaderCompiler(const char* source, unsigned type);
	unsigned Assembly(unsigned vtxShader, unsigned fragment_shader);
};

