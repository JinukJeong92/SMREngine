# Copyright (C) 2024. Jinuk Jeong. All rights reserved.
#
# This work is protected by copyright. All rights are reserved to the author. No part of this work, in whole or in part, may be reproduced, distributed, or modified for any purpose without express permission from the author.
#

cmake_minimum_required(VERSION 3.16)

project(SMREngine)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

include(src/cmake/define.cmake)
include(src/cmake/function.cmake)

get_filename_component(CURRENT_DIR ${CMAKE_CURRENT_LIST_FILE} DIRECTORY)
find_subdirectories(${CURRENT_DIR} src)
find_files("")

include_directories(src/runtime)
include_directories(src/gui)
include_directories(src/runtime/Core)
include_subdirectories_depth1(${CURRENT_DIR} third_party)

add_subdirectory("external/freetype")
add_subdirectory("external/sdl")

add_executable(${PROJECT_NAME} ${GFILES})

set_property(TARGET freetype PROPERTY FOLDER "ThirdParty")
set_property(TARGET sdl_headers_copy PROPERTY FOLDER "ThirdParty")
set_property(TARGET SDL2 PROPERTY FOLDER "ThirdParty")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:DEBUG>)
target_link_libraries(${CMAKE_PROJECT_NAME} SDL2 freetype)


if (WIN32)
  # copy the SDL2.dll to the same folder as the executable
  add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:SDL2::SDL2>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    VERBATIM)
endif ()

