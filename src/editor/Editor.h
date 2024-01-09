/*
SpartanEngine - StackMaster Robotics Engine

Copyright (C) 2024. Jinuk Jeong. All rights reserved.
Copyright(c) 2016-2024 Panos Karabelas

This work is protected by copyright. All rights are reserved to the author. No part of this work, in whole or in part, may be reproduced, distributed, or modified for any purpose without express permission from the author.
*/


#pragma once

//= INCLUDES ===================
#include <vector>
#include <memory>
#include "RHI/RHI_Definitions.h"
//#include "Widgets/Widget.h"
//==============================

class Editor
{
public:
    Editor();
    ~Editor();

    void Tick();

    //template<typename T>
    //T* GetWidget()
    //{
    //    for (const auto& widget : m_widgets)
    //    {
    //        if (T* widget_t = dynamic_cast<T*>(widget.get()))
    //        {
    //            return widget_t;
    //        }
    //    }

    //    return nullptr;
    //}

private:
    void BeginWindow();

    bool m_editor_begun = false;
    //std::vector<std::shared_ptr<Widget>> m_widgets;
};
