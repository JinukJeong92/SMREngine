#include "gui_imgui.h"
#include "ImGui/ImGuiExtension.h"
#include "ImGui/Implementation/ImGui_RHI.h"
#include "ImGui/Implementation/imgui_impl_sdl2.h"
#include "Logging/Log.h"

//= NAMESPACES =====
using namespace std;
//==================

Gui_imgui::Gui_imgui()
{
	ImGui::CreateContext();

    // configure ImGui
    ImGuiIO& io                      = ImGui::GetIO();
    io.ConfigFlags                  |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags                  |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags                  |= ImGuiConfigFlags_ViewportsEnable;
    io.ConfigFlags                  |= ImGuiConfigFlags_NoMouseCursorChange; // cursor visibility is handled by the engine
    io.ConfigWindowsResizeFromEdges  = true;
    io.ConfigViewportsNoTaskBarIcon  = true;
    io.ConfigViewportsNoDecoration   = true; // borderless child windows but with ImGui min, max and close buttons
    io.IniFilename                   = "editor.ini";

    Spartan::Log::WriteFInfo("editor.ini not yet");

    Spartan::Log::WriteFInfo("load font not yet");

    //// load font
    //string dir_fonts = Spartan::ResourceCache::GetResourceDirectory(Spartan::ResourceDirectory::Fonts) + "/";
    //io.Fonts->AddFontFromFileTTF((dir_fonts + "Calibri.ttf").c_str(), k_font_size * Spartan::Window::GetDpiScale());
    //io.FontGlobalScale = k_font_scale;

    // initialise ImGui backends
    SP_ASSERT_MSG(ImGui_ImplSDL2_Init(), "Failed to initialize ImGui's SDL backend");
}

Gui_imgui::~Gui_imgui()
{
}

void Gui_imgui::Shutdown()
{
    if (ImGui::GetCurrentContext())
    {
        Spartan::Log::WriteFInfo("ImGui::RHI::shutdown() not yet");
        //ImGui::RHI::shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
    }
}
