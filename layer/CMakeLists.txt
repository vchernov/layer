set(SOURCES
    core/Context.h
    core/Context.cpp
    core/OpenGL.h
    core/OpenGL.cpp
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

set(LIBRARIES
    ${SDL2_LIBRARIES}
)
set(DEFINITIONS
    ${SDL2_DEFINITIONS}
)

if (LAYER_FONT)
    set(SOURCES ${SOURCES}
        font/FontContext.h
        font/FontContext.cpp
    )
    set(LIBRARIES ${LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
    )
    set(DEFINITIONS ${DEFINITIONS}
        ${SDL2_TTF_DEFINITIONS}
    )
endif()

add_library(layer ${SOURCES})
target_link_libraries(layer ${LIBRARIES})
target_compile_options(layer PUBLIC ${DEFINITIONS})

install(TARGETS layer DESTINATION lib)

