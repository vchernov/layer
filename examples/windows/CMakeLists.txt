add_executable(windows
    windows.cpp
    WindowsApp.h
    WindowsApp.cpp
    WindowEventDirectDispatcher.h
    WindowEventDirectDispatcher.cpp
)

target_link_libraries(windows
    layer
    ${OPENGL_gl_LIBRARY}
)

