#pragma once
#include <windows.h>
#include <stdio.h>


#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...);

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

// Configuration -----------

#define GLVER "#version 330"
#define REPO_URL "https://github.com/OGKoko/HexEngine"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 960
#define FULLSCREEN false
#define VSYNC true
#define TITLE "===|HexEngine|==="