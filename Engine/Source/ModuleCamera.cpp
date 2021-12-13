#include "ModuleCamera.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"

#include "MathGeoLib/Math/MathConstants.h"
#include "MathGeoLib.h"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#define DEGTORAD pi/180

ModuleCamera::ModuleCamera()
{
}
bool ModuleCamera::Init()
{

	FrustumProp();
	return true;
}
update_status ModuleCamera::PreUpdate()
{

	return UPDATE_CONTINUE;
}
ModuleCamera::~ModuleCamera()
{
}
update_status ModuleCamera::Update()
{
  

	return UPDATE_CONTINUE;
}
update_status ModuleCamera::PostUpdate()
{
	return UPDATE_CONTINUE;
}
void ModuleCamera::FrustumProp()
{
	ARatio = (float)(App->window->screen_surface->w) / (float)(App->window->screen_surface->h);
	hFOV = DEGTORAD * 90.0f;
	
	fr.SetKind(FrustumSpaceGL, FrustumRightHanded);
	fr.SetViewPlaneDistances(0.1f, 200.0f);
	fr.SetHorizontalFovAndAspectRatio(hFOV, ARatio);

	fr.SetPos(float3(0.0f, 3.0f, -10.0f));
	float3x3 wRot = float3x3::identity;
	fr.SetFront(wRot.WorldZ());
	fr.SetUp(wRot.WorldY());

	camPos = fr.Pos();
	float4x4 projectionGL = fr.ProjectionMatrix().Transposed();

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(*projectionGL.v);
	
	camPos = fr.Pos();
	camY = fr.Up();
	camZ = fr.Front();
}
void ModuleCamera::CamMovement()
{


}
bool ModuleCamera::CleanUp()
{
	return true;
}

float4x4 ModuleCamera::ViewMatrix()
{
	return float4x4();
}

void ModuleCamera::CamManager()
{

	
}
