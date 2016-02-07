add_subdirectory(demo)

if (OPENGL_FOUND)
    add_subdirectory(windows)
endif()

if (LAYER_FONT)
    add_subdirectory(text)
endif()

