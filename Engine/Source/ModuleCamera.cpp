#include "ModuleCamera.h"


#define DEGTORAD pi/180

ModuleCamera::ModuleCamera()
{
}
bool ModuleCamera::Init()
{
	
	fr.SetKind(FrustumSpaceGL, FrustumRightHanded);
	fr.SetViewPlaneDistances(0.1f, 200.0f);
	fr.SetHorizontalFovAndAspectRatio(DEGTORAD * 90, 1.3f);
	
	fr.SetPos(float3(0.0f, 1.0f, -2.0f));
	fr.SetFront(float3::unitZ);
	fr.SetUp(float3::unitY);
	
	float4x4 projectionGL = fr.ProjectionMatrix().Transposed();
	
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(*projectionGL.v);
	
	return true;
}
update_status ModuleCamera::PreUpdate()
{

	return update_status();
}
update_status ModuleCamera::Update()
{
	return update_status();
}
update_status ModuleCamera::PostUpdate()
{
	return update_status();
}
bool ModuleCamera::CleanUp()
{
	return false;
}
ModuleCamera::~ModuleCamera()
{
}
