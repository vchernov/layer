add_executable(windows
    windows.cpp
    WindowsApp.h
    WindowsApp.cpp
    SelectiveWindowEventDispatcher.h
    SelectiveWindowEventDispatcher.cpp
)

target_include_directories(windows PUBLIC
    ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(windows
    layer
    ${OPENGL_LIBRARIES}
)

