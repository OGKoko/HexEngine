#pragma once
#include "ModelManager.h"
#include "Assimp/include/assimp/scene.h"
#include <vector>

class ModuleModel
{
public:
	ModuleModel();
	~ModuleModel();

	void Draw();
	void LoadModel(const char* file_name);
	void CleanUp();

	const float3 GetModelPos() const;

private:

	void LoadTextures(const aiScene* scene);

	std::vector<Texture> textures;
	std::vector<ModelManager> meshes;
	float4x4 matrix = float4x4::identity;
	void LoadMesh(const aiScene* scene);


	bool isFBXLoaded = false;
};

