cmake_minimum_required(VERSION 2.8)

project(layer)

option(LAYER_IMAGE "Add image loading support" OFF)
option(LAYER_FONT "Add font support" OFF)
option(LAYER_BUILD_EXAMPLES "Build example programs" OFF)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR})

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

