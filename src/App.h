/*
SpartanEngine - StackMaster Robotics Engine

Copyright (C) 2024. Jinuk Jeong. All rights reserved.

This work is protected by copyright. All rights are reserved to the author. No part of this work, in whole or in part, may be reproduced, distributed, or modified for any purpose without express permission from the author.
*/


#pragma once
//= INCLUDES ===================
#include <memory>
#include "Core/EngineMode.h"
//==============================

class Editor;
class Gui_imgui;
namespace Spartan
{
    class Engine;
}
class App
{
public:
    App();
    ~App();

public:
    void Init(const EngineMode mode);
    void Update();
private:
    std::unique_ptr<Editor> editor;
    std::unique_ptr<Spartan::Engine> engine;
    std::unique_ptr<Gui_imgui>gui;

};
