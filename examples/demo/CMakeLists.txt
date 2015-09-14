add_executable(demo
    demo.cpp
    DemoApp.h
    DemoApp.cpp
)

target_include_directories(demo PUBLIC
    ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(demo
    layer
    ${OPENGL_LIBRARIES}
)

