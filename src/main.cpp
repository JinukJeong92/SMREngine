/*
SpartanEngine - StackMaster Robotics Engine

Copyright (C) 2024. Jinuk Jeong. All rights reserved.
Copyright(c) 2016-2024 Panos Karabelas

This work is protected by copyright. All rights are reserved to the author. No part of this work, in whole or in part, may be reproduced, distributed, or modified for any purpose without express permission from the author.
*/

#include "App.h"

#ifdef _MSC_VER // Windows
#pragma comment(linker, "/subsystem:windows")
#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else // Linux
int main(int argc, char** argv)
#endif
{
    // App Start
    App app;
    app.Init(EngineMode::Editor);
    app.Update();

    return 0;
}