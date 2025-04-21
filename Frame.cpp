#include "Frame.h"

Frame::Frame(const char* WindowName, int Width, int Height)
    :WindowTitle(WindowName), WindowWidth(Width), WindowHeight(Height)
{
    InitFrame(SDL_INIT_VIDEO);
    CreateFrame( SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE);

    ApplicationMainLoop();
    TerminateApplication();
}

Frame::~Frame()
{
    
}

int Frame::InitFrame(SDL_InitFlags InitMode)
{
    if (!SDL_Init(InitMode)) {
        SDL_Log("ERROR OCCURED: ", SDL_GetError());
        return -1;
    }
}

int Frame::CreateFrame(SDL_WindowFlags WindowFlags)
{
    Window = SDL_CreateWindow(WindowTitle, WindowWidth, WindowHeight, WindowFlags);
    if (!Window) {
        std::cout << "FAILED TO CREATE WINDOW." << std::endl;
        return -1;
    }

    Renderer = SDL_CreateRenderer(Window, NULL);
    if (!Renderer) {
        std::cout << "FAILED TO CREATE THE RENDERER." << std::endl;
    }

    guiInterface.ImGuiInit(Window, Renderer);

}

void Frame::ApplicationMainLoop()
{
    bool isRunning = true;
    while (isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
            else if (event.type == SDL_EVENT_WINDOW_RESIZED) {
                SDL_GetWindowSize(Window, &newWindowWidth, &newWindowHeight);
            }
        }

        //Application Code Here
        guiInterface.ImGuiNewFrame();

        guiInterface.CreateImGuiWindow(Window, Renderer,"###id0", (bool*)0, 300, 70, newWindowWidth-350, 80, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse,"Paste Link", 90, 30,newWindowWidth-450,23, true, false);


        guiInterface.CreateImGuiWindow("###id1", (bool*)0, 50, 70, 245, newWindowHeight-120, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

        ImGui::Render();
        SDL_RenderFrame();
    }
}

void Frame::SDL_RenderFrame()
{
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), Renderer);
    SDL_RenderPresent(Renderer);
}

void Frame::TerminateApplication()
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}
