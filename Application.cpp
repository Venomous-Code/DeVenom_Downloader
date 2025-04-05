#include "Includes.h"

int main() {
	
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("DeVenom Downloader", 640, 480, SDL_WINDOW_BORDERLESS );


	if (!window) { std::cout << "SDL3 FAILED TO CREATE WINDOW." << std::endl; }

	std::cin.get();
}