#pragma once
#include <iostream>
#include <string>
//#include "imgui.h"
//#include "backends\imgui_impl_sdl3.h"
//#include "backends\imgui_impl_sdlrenderer3.h"
//#include <SDL3\SDL.h>
#include <spdlog\spdlog.h>
#include <zoe\zoe.h>
//#include <clip.h>
#include <array>
#include <cmath>
#include "ImGui_Interface.h"

class Frame
{
public:
	Frame(const char* WindowTitle, int WindowWidth, int WindowHeight);
	~Frame();
	
private:

	int InitFrame(SDL_InitFlags InitMode);
	int CreateFrame(SDL_WindowFlags WindowFlags);

	void ApplicationMainLoop();
	void SDL_RenderFrame();
	void TerminateApplication();


	SDL_Window* Window;
	SDL_Renderer* Renderer;
	const char* WindowTitle; 
	int WindowWidth; 
	int WindowHeight;

	int newWindowWidth = 0;
	int newWindowHeight = 0;

	ImGui_Interface guiInterface;

};

