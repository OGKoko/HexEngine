#include "Timer.h"

Timer::Timer()
{
	mStartTicks = 0;
	mPausedTicks = 0;

	mPaused = false;
	mStarted = false;
}

void Timer::start()
{
	mStarted = true;
	mPaused = false;

	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void Timer::stop()
{
	mStarted = false;
	mPaused = false;
	mStartTicks = 0;
	mPausedTicks = 0;
}

void Timer::pause()
{
	if (mStarted && !mPaused) {
		mPaused = true;

		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}

void Timer::resume()
{
	if (mStarted && mPaused) {
		mPaused = false;

		mStartTicks = SDL_GetTicks() - mPausedTicks;
		mPausedTicks = 0;
	}
}

float Timer::FPSCounter()
{
	{
		float sum = 0.0f;
		for (size_t i = 0; i < FPS_BUFFER; ++i)
		{
			sum += frameClock[i];
		}

		if (actFrame < FPS_BUFFER)
		{
			return 1.0f / (sum * 1000 / (float)actFrame);
		}

		return 1.0f / (sum * 1000 * (1.0f/FPS_BUFFER));
	}

}

Uint32 Timer::SDL_GetTicks()
{
	Uint32  time = 0;
	if (mStarted)
		if (mPaused)
			time = mPausedTicks;
		else {
			time = SDL_GetTicks() - mStartTicks;
		}
	return time;
}

bool Timer::isStart()
{
	
	return mStarted;
}

bool Timer::isPaused()
{
	return mPaused && mStarted;
}

float Timer::FPS() 
{
	return fps;
}

float Timer::getDeltaTime() 
{

	return deltaTime*(1.0f/1000.0f);
};
