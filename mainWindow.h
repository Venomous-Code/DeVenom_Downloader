#pragma once
#include "UserInterface.h"

namespace Downloader {
	class mainWindow
	{
	public:
		mainWindow();
		~mainWindow();

	private:
		
		void ClearScreen(Uint8 Red, Uint8 Blue, Uint8 Green);
		void ShutImGui();
		void EventLoop();


		//CLASS MEMBER VARIABLES
		SDL_Event event;
		SDL_Window* window;
		SDL_Renderer* renderer;
		ImDrawList* drawList;
		UserInterface Ui;
		bool done = false;
		int mainWindowWidth = 1020;
		int mainWindowHeight = 600;
	};
}

