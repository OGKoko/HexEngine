#pragma once
#include "Module.h"
#include "MathGeoLib/Geometry/Frustum.h"

#include "glew/glew-2.1.0/include/GL/glew.h"

class Application;


class ModuleCamera : public Module
{
public:
	ModuleCamera();
	~ModuleCamera();
	

	bool Init();

	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	
	void FrustumProp();
	void CamRot();
	void CamMovement();
	void CamOrbit();
	void LookAt();
	bool CleanUp();

	float4x4 ViewMatrix();
	float4x4 ViewProjMatrix();

	void CamManager();

private:
	Frustum fr;
	double angle = 0;
	float3 camPos, camY, camZ ;
	bool camFreeze, canOrbit;
	float ARatio, hFOV;
	
};

