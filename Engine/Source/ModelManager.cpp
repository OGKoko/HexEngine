#include "ModelManager.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleCamera.h"
#include "ModuleShader.h"

ModelManager::ModelManager()
{
}

ModelManager::~ModelManager()
{
}

void ModelManager::CleanUp()
{
	if (isLoaded)
	{
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		isLoaded = false;
	}
}


void ModelManager::LoadMesh(const aiMesh* fbx)
{
	textureID = fbx->mMaterialIndex;
	LoadVBO(fbx);
	LoadEBO(fbx);
	CreateVAO();
	isLoaded = true;

}

void ModelManager::Draw(const std::vector<Texture>& modelTextures)
{
	if (isLoaded) {
		unsigned pID = 0;// = App->shader->GetId();

		const float4x4& view = App->camera->ViewMatrix();
		const float4x4& proj = App->camera->ViewProjMatrix();
		float4x4 model = float4x4::identity;

		glUseProgram(pID);
		glUniformMatrix4fv(glGetUniformLocation(pID, "model"), 1, GL_TRUE, (const float*)&model);
		glUniformMatrix4fv(glGetUniformLocation(pID, "view"), 1, GL_TRUE, (const float*)&view);
		glUniformMatrix4fv(glGetUniformLocation(pID, "proj"), 1, GL_TRUE, (const float*)&proj);

		glEnable(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, modelTextures[textureID].id); 

		glUniform1i(glGetUniformLocation(pID, "diffuse"), 0);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, idCount, GL_UNSIGNED_INT, nullptr);
		glDisable(GL_TEXTURE_2D);


	}

}


void ModelManager::LoadVBO(const aiMesh* fbx)
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	vtxNum = fbx->mNumVertices;
	unsigned vertex_size = (sizeof(float) * 3 + sizeof(float) * 3 + sizeof(float) * 2);
	unsigned buffer_size = vertex_size * vtxNum;

	std::vector<vtxMapping> vtx;
	vtx.reserve(vtxNum);

	for (int i = 0; i < vtxNum; i++)
	{
		vtxMapping vx;
		vx.normal = float3(fbx->mNormals[i].x, fbx->mNormals[i].y, fbx->mNormals[i].z);
		vx.pos = float3(fbx->mVertices[i].x, fbx->mVertices[i].y, fbx->mVertices[i].z);
		vx.uvs = float2(fbx->mTextureCoords[0][i].x, fbx->mTextureCoords[0][i].y);
		vtx.push_back(vx);
	}
	glBufferData(GL_ARRAY_BUFFER, sizeof(vtxMapping) * vtxNum, &vtx[0], GL_STATIC_DRAW);
	vtx.clear();
	LOG("VBO LOADED")

}

void ModelManager::LoadEBO(const aiMesh* fbx)
{
	idCount = fbx->mNumFaces;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	unsigned* indx = (unsigned*)(glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY));
	for (unsigned i = 0; i < fbx->mNumFaces; i++)
	{
		assert(fbx->mFaces[i].mNumIndices == 3);
		*(indx++) = fbx->mFaces[i].mIndices[0];
		*(indx++) = fbx->mFaces[i].mIndices[1];
		*(indx++) = fbx->mFaces[i].mIndices[2];
	}
	glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
	LOG("EBO LOADED")
}

void ModelManager::CreateVAO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(float) * 3 * vtxNum));

	LOG("VAO LOADED");
}


