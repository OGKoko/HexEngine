#pragma once
#include "SDL.h"
class Timer
{
public:
	Timer();

	void start();
	void stop();
	void pause();
	void resume();

	Uint32 SDL_GetTicks();

	bool isStart();
	bool isPaused();

private:
	Uint32 mStartTicks; //clock time at start
	Uint32 mPausedTicks; //clock time when paused

	bool mPaused;
	bool mStarted;
};

