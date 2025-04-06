#include "UserInterface.h"

Downloader::UserInterface::UserInterface()
{

}

Downloader::UserInterface::~UserInterface()
{

}

void Downloader::UserInterface::CreateImGuiPrimaryWindow0()
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(mainWindowWidth, mainWindowHeight));
    ImGui::Begin("Title here");
    ImGui::Text("This is Simple ImGui Window");
    //Vertical Separator
    //drawList = ImGui::GetWindowDrawList();
    //ImGui::SetCursorPosX(50);
    //drawList->AddLine(ImVec2(100, 10), ImVec2(100, 1000), ImColor(255,255,255),0.1f);*/
    ImGui::End();
}
