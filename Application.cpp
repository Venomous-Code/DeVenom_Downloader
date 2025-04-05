#include "Includes.h"

void ClearScreen(SDL_Renderer* mainRenderer, Uint8 Red, Uint8 Blue, Uint8 Green) {
    ImGui::Render();
    SDL_SetRenderDrawColor(mainRenderer, Red, Blue, Green, 255);
    SDL_RenderClear(mainRenderer);
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), mainRenderer);
    SDL_RenderPresent(mainRenderer);
}

void ShutDownImGui() {
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
}


int main() {

    bool done = false;

    SDL_Init(SDL_INIT_VIDEO);           

    SDL_Window* window = SDL_CreateWindow("DeVenom_Downloader",1020,600,SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED );

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);


    while (!done) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }

        //Main Program Here....
        
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();



        //Work With ImGui Stuff Here....
        ImGui::Begin("Title here");
        ImGui::Text("This is Simple ImGui Window");
        ImGui::End();



        ClearScreen(renderer, 0, 0, 0);
    }

    ShutDownImGui();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

	std::cin.get();
}