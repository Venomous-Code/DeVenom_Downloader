#include "Includes.h"

int main()
{
    // 1) Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Error: %s\n", SDL_GetError());
        return -1;
    }

    // 2) Create an SDL window and renderer
    SDL_Window* window = SDL_CreateWindow(
        "DeVenom Downloader",1020,600,
        SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window,NULL);

    // 3) Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    // (Optional) Enable Keyboard Controls, Viewports, Docking, etc:
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    // io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    // 4) Initialize the SDL2 + SDL_Renderer backends
    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);

    // 5) Main loop
    bool running = true;
    while (running)
    {
        // Poll and handle SDL events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }

        // Start the Dear ImGui frame
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        // 6) Build your UI
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("FILE")) {
                ImGui::MenuItem("NEW");
                
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("EDIT")) {
                ImGui::MenuItem("UNDO");

                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("WINDOW")) {
                ImGui::MenuItem("WINDOW");

                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("ABOUT")) {
                ImGui::MenuItem("PLUG-INs");

                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

        ImGui::Begin("Hello, SDL Renderer!");
        ImGui::Text("This is Dear ImGui running on SDL2's renderer backend.");
        ImGui::End();

        // Rendering
        ImGui::Render();
        // Clear SDL2 backbuffer
        SDL_SetRenderDrawColor(renderer, 45, 45, 50, 255);
        SDL_RenderClear(renderer);
        // Render Dear ImGui’s draw data via SDL_Renderer
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(),renderer);
        // Present
        SDL_RenderPresent(renderer);
    }

    // 7) Cleanup
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
