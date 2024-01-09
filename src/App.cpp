#include "App.h"
#include "editor/Editor.h"
#include "Core/Engine.h"
#include "gui/gui_imgui.h"
#include "window/Window.h"

App::App()
{
}

App::~App()
{
    gui->Shutdown();


    Spartan::Engine::Shutdown();
}

void App::Init(const EngineMode mode)
{    
    engine = std::make_unique<Spartan::Engine>();
    engine->Initialize();

    gui = std::make_unique<Gui_imgui>();
    if (EngineFlag::IsEqualFlag(mode, EngineMode::Editor) == false) return;

    EngineFlag::AddFlag(mode);
    editor = std::make_unique<Editor>();

    //// initialize the engine
    //Spartan::Engine::Initialize();

}

void App::Update()
{
    if (EngineFlag::IsFlagSet(EngineMode::Editor))
        editor->Tick();
}
