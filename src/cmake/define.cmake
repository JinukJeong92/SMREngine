set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

set(GFILES)
set(GDIRECTORY)

# VKB_WARNINGS_AS_ERRORS
add_compile_definitions(VKB_WARNINGS_AS_ERRORS=OFF)

# SDL2_DISABLE_SDL2MAIN
option(SDL2_DISABLE_SDL2MAIN "Disable SDL2main" ON)

# SDL2_DISABLE_UNINSTALL
option(SDL2_DISABLE_UNINSTALL "Disable uninstall target" ON)

# SDL_TEST
option(SDL_TEST "Enable SDL tests" OFF)

# SDL_SHARED
option(SDL_SHARED "Build SDL as a shared library" ON)

# SDL_STATIC
option(SDL_STATIC "Build SDL as a static library" OFF)

# USE_DOUBLE_PRECISION
option(USE_DOUBLE_PRECISION "Use double precision" ON)
