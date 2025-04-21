#pragma once
#include "imgui.h"
#include "backends\imgui_impl_sdl3.h"
#include "backends\imgui_impl_sdlrenderer3.h"
#include <iostream>
#include <string>
#include <clip.h>
#include <SDL3\SDL.h>
#include "SimpleDownloadFunctionality.h"
class ImGui_Interface
{
public:
	ImGui_Interface();
	~ImGui_Interface();

	void ImGuiInit(SDL_Window* window, SDL_Renderer* renderer);

	void ImGuiNewFrame();

	void ImGuiTerminate();

	void CreateImGuiWindow(const char* Title, bool* isOpen, int xPos, int yPos, int sizeX, int sizeY, ImGuiWindowFlags ImGuiWindowFlag);

	void CreateImGuiWindow(SDL_Window* Window, SDL_Renderer* Renderer, const char* Title, bool* isOpen, int xPos, int yPos, int sizeX, int sizeY, ImGuiWindowFlags ImGuiWindowFlag, const char* ButtonLabel, int ButtonWidth, int ButtonHeight, int ButtonPosX, int ButtonPosY, bool PasteButton, bool FinishButton);

	void CreateButtonFunctionality(SDL_Window* Window, SDL_Renderer* Renderer, bool PasteButton, bool FinishButton);


private:
	std::string applicationClipboard = "https://www.google.com/";
	SimpleDownloadFunctionality sdf;
};

