#include "ModuleTexture.h"

ModuleTexture::ModuleTexture()
{
}

ModuleTexture::~ModuleTexture()
{
}

bool ModuleTexture::Init()
{
	ilInit();
	return false;
}

bool ModuleTexture::CleanUp()
{
	ilShutDown();
	return true;
}




Texture ModuleTexture::TextureLoader(const char* filePath){
	Texture tmpText;
	unsigned textureID = LoadImg(filePath);

	if (textureID != 0) {
		glGenTextures(1, &tmpText.id);
		glBindTexture(GL_TEXTURE_2D, tmpText.id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), tmpText.textureWidth = ilGetInteger(IL_IMAGE_WIDTH),
			tmpText.textureHeight = ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
			ilGetData());

		ilDeleteImages(1, &textureID);
		tmpText.isLoaded = true;
	}

	return tmpText;
	

}


	

void ModuleTexture::TextLinker(unsigned id, unsigned GLindx)
{
	glEnable(GL_TEXTURE_2D);
	glActiveTexture(GLindx);
	glBindTexture(GL_TEXTURE_2D, id);
}

void ModuleTexture::TextDetacher(unsigned GLindx)
{
	glDisable(GL_TEXTURE_2D);
}

unsigned int ModuleTexture::LoadImg(const char* path)
{
	ILuint _textureID;
	ilGenImages(1, &_textureID);
	ilBindImage(_textureID);

	if (!ilLoadImage(path)) {
		LOG(" MODULETEXT COULDNT BE LOADED");
		return 0;
	}
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	iluFlipImage();

	return _textureID;

}

