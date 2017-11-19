cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(layer)

option(LAYER_BUILD_EXAMPLES "Build example programs." OFF)
option(LAYER_IMAGE "Add image loading support." OFF)
option(LAYER_FONT "Add font support." OFF)

add_subdirectory(layer)

if (LAYER_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

install(DIRECTORY layer
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)
