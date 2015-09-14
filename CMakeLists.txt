cmake_minimum_required(VERSION 2.8)

project(layer)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR})
find_package(SDL2 REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIRS}
)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
endif()

add_subdirectory(layer)

option(LAYER_BUILD_EXAMPLES "Build example programs" OFF)

if (LAYER_BUILD_EXAMPLES)
    find_package(OpenGL)
    add_subdirectory(examples)
endif()

install(DIRECTORY layer
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

