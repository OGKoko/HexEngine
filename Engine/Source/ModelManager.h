#pragma once
#include "Assimp/include/assimp/scene.h"
#include"MathGeoLib/MathGeoLib.h"
#include "ModuleTexture.h"
#include "ModuleModel.h"
#include <vector>

struct vtxMapping {
	float3 pos;
	float2 uvs;
	float3 normal;
};
class ModelManager :  public aiMesh
{
public:
	ModelManager();
	~ModelManager();
	void CleanUp();

	
	void LoadMesh(const aiMesh* fbx);
	void Draw(const std::vector<Texture>& modelTextures);

private:
	bool isLoaded = false;
	unsigned textureID, VAO, EBO, VBO, vtxNum, idCount;

	void LoadVBO(const aiMesh* fbx);
	void LoadEBO(const aiMesh* fbx);
	void CreateVAO();
};

