cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(layer)

option(LAYER_BUILD_EXAMPLES "Build example programs." OFF)
option(LAYER_IMAGE "Add image loading support." OFF)
option(LAYER_FONT "Add font support." OFF)

add_subdirectory(layer)

if (LAYER_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
