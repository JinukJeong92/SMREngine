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

add_executable(${PROJECT_NAME} ${GFILES})

include_directories(src/runtime)
include_directories(src/gui)
include_directories(src/runtime/Core)
include_subdirectories_depth1(${CURRENT_DIR} third_party)

# set .lib or .a
set(BUILD_SHARED_LIBS FALSE)

# freetype
add_subdirectory("external/freetype")
set_property(TARGET freetype PROPERTY FOLDER "ThirdParty")

# sdl2
add_subdirectory("external/sdl")
set_property(TARGET sdl_headers_copy PROPERTY FOLDER "ThirdParty")
set_property(TARGET SDL2 PROPERTY FOLDER "ThirdParty")

# if (WIN32)
#   # copy the SDL2.dll to the same folder as the executable
#   add_custom_command(
#     TARGET ${PROJECT_NAME}
#     POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:SDL2::SDL2>
#             $<TARGET_FILE_DIR:${PROJECT_NAME}>
#     VERBATIM)
# endif ()

# bullet3_src
message("Bullet3")
add_subdirectory("external/bullet3")
set_property(TARGET LinearMath PROPERTY FOLDER "bullet3")
set_property(TARGET Bullet3Common PROPERTY FOLDER "bullet3")
set_property(TARGET BulletCollision PROPERTY FOLDER "bullet3")
set_property(TARGET BulletDynamics PROPERTY FOLDER "bullet3")
set_property(TARGET BulletInverseDynamics PROPERTY FOLDER "bullet3")
set_property(TARGET BulletSoftBody PROPERTY FOLDER "bullet3")

# assimp
add_subdirectory("external/assimp")
set_property(TARGET assimp PROPERTY FOLDER "ThirdParty/assimp")
set_property(TARGET UpdateAssimpLibsDebugSymbolsAndDLLs PROPERTY FOLDER "ThirdParty/assimp")
set_property(TARGET uninstall PROPERTY FOLDER "ThirdParty/assimp")
set_property(TARGET unit PROPERTY FOLDER "ThirdParty/assimp")
set_property(TARGET zlibstatic PROPERTY FOLDER "ThirdParty/assimp")
target_compile_options(assimp PRIVATE /WX-)

# Debug Setting
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:DEBUG>)

# link library
target_link_libraries(${CMAKE_PROJECT_NAME} 
freetype
SDL2 
LinearMath
Bullet3Common
BulletCollision
BulletDynamics
BulletInverseDynamics
BulletSoftBody
assimp
zlibstatic
)

# Set Start Project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
