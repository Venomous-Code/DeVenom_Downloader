#include "ImGui_Interface.h"

ImGui_Interface::ImGui_Interface()
{
}

ImGui_Interface::~ImGui_Interface()
{
}

void ImGui_Interface::ImGuiInit(SDL_Window* window, SDL_Renderer* renderer)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer3_Init(renderer);
}

void ImGui_Interface::ImGuiNewFrame()
{
	ImGui_ImplSDL3_NewFrame();
	ImGui_ImplSDLRenderer3_NewFrame();
	ImGui::NewFrame();
}

void ImGui_Interface::ImGuiTerminate()
{
	ImGui_ImplSDL3_Shutdown();
	ImGui_ImplSDLRenderer3_Shutdown();
	ImGui::DestroyContext();
}

void ImGui_Interface::CreateImGuiWindow(const char* Title, bool* isOpen, int xPos, int yPos, int sizeX, int sizeY, ImGuiWindowFlags ImGuiWindowFlag)
{
	ImGui::SetNextWindowPos(ImVec2(xPos, yPos));
	ImGui::SetNextWindowSize(ImVec2(sizeX, sizeY));
	ImGui::Begin(Title, isOpen, ImGuiWindowFlag);
	

	ImGui::End();
}

void ImGui_Interface::CreateImGuiWindow(SDL_Window* Window, SDL_Renderer* Renderer, const char* Title, bool* isOpen, int xPos, int yPos, int sizeX, int sizeY, ImGuiWindowFlags ImGuiWindowFlag, const char* ButtonLabel, int ButtonWidth, int ButtonHeight,int ButtonPosX, int ButtonPosY, bool PasteButton, bool FinishButton)
{
	ImGui::SetNextWindowPos(ImVec2(xPos, yPos));
	ImGui::SetNextWindowSize(ImVec2(sizeX, sizeY));
	ImGui::Begin(Title, isOpen, ImGuiWindowFlag);

	ImGui::SetCursorPos(ImVec2(ButtonPosX, ButtonPosY));
	if (ImGui::Button(ButtonLabel, ImVec2(ButtonWidth, ButtonHeight))) {
		CreateButtonFunctionality(Window, Renderer, PasteButton, FinishButton);
	}

	ImGui::End();
}

void ImGui_Interface::CreateButtonFunctionality(SDL_Window* Window, SDL_Renderer* Renderer, bool PasteButton, bool FinishButton)
{
	if (PasteButton) {
		clip::get_text(applicationClipboard);
		//std::cout << applicationClipboard << std::endl;
		//DropDown Button Logic Here...
		//ImGui::SliderInt("DOWNLOAD PROGRESS: ", , 0, Bytes, "%d", ImGuiSliderFlags)
	}
	else if (FinishButton) {
		SDL_DestroyRenderer(Renderer);
		SDL_DestroyWindow(Window);
		SDL_Quit();
	}
}

