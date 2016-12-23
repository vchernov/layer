add_subdirectory(demo)
add_subdirectory(grid)
add_subdirectory(fractal)

if (OPENGL_FOUND)
    add_subdirectory(windows)
endif()

if (LAYER_IMAGE)
    add_subdirectory(picture)
endif()

if (LAYER_FONT)
    add_subdirectory(text)
endif()

