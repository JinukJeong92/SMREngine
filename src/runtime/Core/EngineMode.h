/*
SpartanEngine - StackMaster Robotics Engine

Copyright (C) 2024. Jinuk Jeong. All rights reserved.

This work is protected by copyright. All rights are reserved to the author. No part of this work, in whole or in part, may be reproduced, distributed, or modified for any purpose without express permission from the author.
*/


#pragma once
//= INCLUDES ===================
#include "Definitions.h"
#include <stdint.h>

enum class EngineMode : uint32_t
{
    Editor = 1 << 0,
    Physics = 1 << 1,
    Game = 1 << 2,
};

class SP_CLASS EngineFlag
{
public:
    static void AddFlag(const EngineMode flag);
    static void RemoveFlag(const EngineMode flag);
    static bool IsEqualFlag(const EngineMode flag1, const EngineMode flag2);
    static bool IsFlagSet(const EngineMode flag);
    static void ToggleFlag(const EngineMode flag);
};

     
