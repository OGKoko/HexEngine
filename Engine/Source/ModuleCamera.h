#pragma once
#include "Module.h"
#include "MathGeoLib/Geometry/Frustum.h"

class ModuleCamera : public Module
{
public:
	ModuleCamera();
	~ModuleCamera();
	

	bool Init();

	virtual update_status PreUpdate();
	virtual update_status Update();
	virtual update_status PostUpdate();
	

	bool CleanUp();
private:
	Frustum fr;
	float4x4 model, view, proj;
};

