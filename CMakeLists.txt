cmake_minimum_required(VERSION 2.8)

project(layer)

option(LAYER_BUILD_EXAMPLES "Build example programs" ON)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
    
    include(FindPkgConfig)
    pkg_search_module(SDL2 REQUIRED sdl2)
endif()

include_directories(
    ${SDL2_INCLUDE_DIRS}
)

add_subdirectory(layer)

if (LAYER_BUILD_EXAMPLES)
    find_package(OpenGL)
    add_subdirectory(examples)
endif()

install(DIRECTORY layer
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

