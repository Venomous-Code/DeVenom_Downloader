#pragma once
#include <iostream>
#include <string>
#include "SDL3\SDL.h"
#include "imgui.h"
#include "backends\imgui_impl_sdl3.h"
#include "backends\imgui_impl_sdlrenderer3.h"


namespace Downloader {
	class UserInterface
	{
	public:
		UserInterface();
		~UserInterface();
		
		void CreateImGuiPrimaryWindow0();
	
	private:
		int mainWindowWidth = 1020;
		int mainWindowHeight = 600;
	};
}
