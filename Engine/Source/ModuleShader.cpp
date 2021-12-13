#include "ModuleShader.h"

ModuleShader::ModuleShader()
{
}

ModuleShader::~ModuleShader()
{
}

bool ModuleShader::Init()
{
	
	unsigned int fragmentShaderID = ShaderCompiler(ShaderLoader("fragment.glsl"), GL_FRAGMENT_SHADER);

	glId = Assembly(vtxShaderID, fragmentShaderID);

	glUseProgram(glId);
	glDeleteShader(vtxShaderID);
	glDeleteShader(fragmentShaderID);
	unsigned int vtxShaderID = ShaderCompiler(ShaderLoader("vertex.glsl"), GL_VERTEX_SHADER);
	

	return true;
}

bool ModuleShader::CleanUp()
{
	glDeleteProgram(glId);
	return true;
}

char* ModuleShader::ShaderLoader(const char* shader_path)
{
	return nullptr;
}

unsigned ModuleShader::ShaderCompiler(const char* source, unsigned type)
{
	return 0;
}

	
char* ModuleShader::ShaderLoader(const char* shaderPath)
{
	char* data = nullptr;
	FILE* file = nullptr;
	fopen_s(&file, shaderPath, "rb");
	
		fseek(file, 0, SEEK_END); 
		int size = ftell(file);
		data = (char*)malloc(size + 1); 
		fseek(file, 0, SEEK_SET); 
		fread(data, 1, size, file);
		data[size] = 0; 
		fclose(file);
	
	return data;
}
	

unsigned ModuleShader::ShaderCompiler(const char* source, unsigned type)
{
	unsigned shaderId = glCreateShader(type);
	glShaderSource(shaderId, 1, &source, 0);
	glCompileShader(shaderId);
	int res = GL_FALSE;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &res);
	if (res == GL_FALSE)
	{
		int len = 0;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &len);
		if (len > 0)
		{
			int written = 0;
			char* info = (char*)malloc(len);
			glGetShaderInfoLog(shaderId, len, &written, info);
			free(info);
		}
	}
	return shaderId;
}


unsigned ModuleShader::Assembly(unsigned vtxShader, unsigned fragShader)
{
	unsigned id = glCreateProgram();
	glAttachShader(id, vtxShader);
	glAttachShader(id, fragShader);
	glLinkProgram(id);
	int res;
	glGetProgramiv(id, GL_LINK_STATUS, &res);
	if (res == GL_FALSE)
	{
		int len = 0;
		glGetProgramiv(id, GL_INFO_LOG_LENGTH, &len);
		if (len > 0)
		{
			int written = 0;
			char* info = (char*)malloc(len);
			glGetProgramInfoLog(id, len, &written, info);
			free(info);
		}
	}
	glDeleteShader(vtxShader);
	glDeleteShader(fragShader);
	return id;
}

