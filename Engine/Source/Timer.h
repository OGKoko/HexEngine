#pragma once
#include "SDL.h"
#include "imgui.h"



const int FPS_BUFFER = 60;

class Timer
{
public:

	Timer();

	void start();
	void stop();
	void pause();
	void resume();
	float FPSCounter();

	Uint32 SDL_GetTicks();

	bool isStart();
	bool isPaused();
	float FPS();
	float getDeltaTime();
private:
	float deltaTime;
	float frameClock[FPS_BUFFER];
	unsigned int actFrame;
	float fps;
	Uint32 mStartTicks; //clock time at start
	Uint32 mPausedTicks; //clock time when paused

	bool mPaused;
	bool mStarted;

};
extern Timer* TheTimer;