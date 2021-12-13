#pragma once
#include "Module.h"
#include "il.h"
#include "ilu.h"
#include "glew/glew-2.1.0/include/GL/glew.h"
#include <string>

class Application;

class ModuleTexture : public Module
{
public:
	ModuleTexture();
	~ModuleTexture();

	bool Init();
	bool CleanUp();


	Texture TextureLoader(const char* filePath);
	void TextLinker(unsigned id, unsigned GLindx = GL_TEXTURE0);
	void TextDetacher(unsigned GLindx = GL_TEXTURE0);
	unsigned GetTexture(Texture* texture) { return texture->id; }
private:
	unsigned int LoadImg(const char* path);
	
};


//that will be translated as the material

struct Texture
{
	unsigned id;
	bool isLoaded = false;
	std::string texturePath;
	unsigned textureWidth;
	unsigned textureHeight;
};


