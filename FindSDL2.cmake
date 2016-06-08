if (CMAKE_COMPILER_IS_GNUCXX)
    find_package(PkgConfig)
    pkg_check_modules(SDL2 QUIET sdl2)
endif()

find_path(SDL2_INCLUDE_DIR
    SDL.h
    HINTS ${SDL2_INCLUDEDIR} ${SDL2_INCLUDE_DIRS}
)

find_library(SDL2_LIBRARY
    NAMES SDL2
    HINTS ${SDL2_LIBDIR} ${SDL2_LIBRARY_DIRS}
)

find_library(SDL2MAIN_LIBRARY
    NAMES SDL2main
    HINTS ${SDL2_LIBDIR} ${SDL2_LIBRARY_DIRS}
)

if (MINGW)
    set(SDL2MAIN_LIBRARY mingw32 ${SDL2MAIN_LIBRARY})
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2 DEFAULT_MSG
    SDL2_INCLUDE_DIR
    SDL2_LIBRARY
    SDL2MAIN_LIBRARY
)
