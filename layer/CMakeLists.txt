add_library(layer
    core/Context.h
    core/Context.cpp
    core/InitError.h
    event/Delegate.h
    event/DelegateMap.h
    event/EventQueue.h
    event/EventQueue.cpp
    event/IEventDispatcher.h
    event/SystemEventDispatcher.h
    event/SystemEventDispatcher.cpp
    event/WindowEventDispatcher.h
    event/WindowEventDispatcher.cpp
    event/KeyboardEventDispatcher.h
    event/KeyboardEventDispatcher.cpp
    event/MouseEventDispatcher.h
    event/MouseEventDispatcher.cpp
    window/Window.h
    window/Window.cpp
    window/WindowGL.h
    window/WindowGL.cpp
    window/Window2D.h
    window/Window2D.cpp
)

target_link_libraries(layer
    ${SDL2_LIBRARIES}
)

target_compile_options(layer PUBLIC
    ${SDL2_DEFINITIONS}
)

install(TARGETS layer DESTINATION lib)

