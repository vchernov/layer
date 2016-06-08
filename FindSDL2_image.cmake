if (CMAKE_COMPILER_IS_GNUCXX)
    find_package(PkgConfig)
    pkg_check_modules(SDL2_IMAGE QUIET SDL2_image)
endif()

find_path(SDL2_IMAGE_INCLUDE_DIR
    SDL_image.h
    HINTS ${SDL2_IMAGE_INCLUDEDIR} ${SDL2_IMAGE_INCLUDE_DIRS}
)

find_library(SDL2_IMAGE_LIBRARY
    NAMES SDL2_image
    HINTS ${SDL2_IMAGE_LIBDIR} ${SDL2_IMAGE_LIBRARY_DIRS}
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2_image DEFAULT_MSG
    SDL2_IMAGE_INCLUDE_DIR
    SDL2_IMAGE_LIBRARY
)

