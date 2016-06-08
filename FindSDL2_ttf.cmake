if (CMAKE_COMPILER_IS_GNUCXX)
    find_package(PkgConfig)
    pkg_check_modules(SDL2_TTF QUIET SDL2_ttf)
endif()

find_path(SDL2_TTF_INCLUDE_DIR
    SDL_ttf.h
    HINTS ${SDL2_TTF_INCLUDEDIR} ${SDL2_TTF_INCLUDE_DIRS}
)

find_library(SDL2_TTF_LIBRARY
    NAMES SDL2_ttf
    HINTS ${SDL2_TTF_LIBDIR} ${SDL2_TTF_LIBRARY_DIRS}
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2_ttf DEFAULT_MSG
    SDL2_TTF_INCLUDE_DIR
    SDL2_TTF_LIBRARY
)

