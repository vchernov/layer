cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(layer)

option(LAYER_IMAGE "Add image loading support" OFF)
option(LAYER_FONT "Add font support" OFF)
option(LAYER_BUILD_EXAMPLES "Build example programs" OFF)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

if (LAYER_IMAGE)
    find_package(SDL2_image REQUIRED)
    include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
endif()

if (LAYER_FONT)
    find_package(SDL2_ttf REQUIRED)
    include_directories(${SDL2_TTF_INCLUDE_DIRS})
endif()

add_subdirectory(layer)

if (LAYER_BUILD_EXAMPLES)
    find_package(OpenGL)
    add_subdirectory(examples)
endif()

install(DIRECTORY layer
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)
