#include "mainWindow.h"

Downloader::mainWindow::mainWindow()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("DeVenom_Downloader", mainWindowWidth, mainWindowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, NULL);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);


    while (!done) {

        EventLoop();

        //Main Program Here....

        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        //Work With ImGui Stuff Here....
        Ui.CreateImGuiPrimaryWindow0();


        ClearScreen(0, 0, 0);
    }

    ShutImGui();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

Downloader::mainWindow::~mainWindow()
{
}

void Downloader::mainWindow::ClearScreen(Uint8 Red, Uint8 Blue, Uint8 Green)
{
    ImGui::Render();
    SDL_SetRenderDrawColor(renderer, Red, Blue, Green, 255);
    SDL_RenderClear(renderer);
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
    SDL_RenderPresent(renderer);
}

void Downloader::mainWindow::ShutImGui()
{
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
}

void Downloader::mainWindow::EventLoop()
{
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            done = true;
        }
    }
}
