set(SOURCES
    core/Context.h
    core/Context.cpp
    core/OpenGL.h
    core/OpenGL.cpp
    core/InitError.h
    core/IllegalArgumentException.h
    core/LoadingFailedException.h
    core/Renderer.h
    core/Renderer.cpp
    core/Texture.h
    core/Texture.cpp
    core/App.h
    core/App.cpp
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
    window/AcceleratedWindow2D.h
    window/AcceleratedWindow2D.cpp
    window/Window2D.h
    window/Window2D.cpp
    time/Time.h
    time/Time.cpp
    time/Clock.h
    time/Clock.cpp
    surface/ISurface.h
    surface/SurfaceWrapper.h
    surface/SurfaceWrapper.cpp
    surface/Surface.h
    surface/Surface.cpp
)

set(LIBRARIES
    ${SDL2MAIN_LIBRARY} ${SDL2_LIBRARY}
)

if (LAYER_IMAGE)
    set(SOURCES ${SOURCES}
        image/ImageContext.h
        image/ImageContext.cpp
    )
    set(LIBRARIES ${LIBRARIES}
        ${SDL2_IMAGE_LIBRARY}
    )
endif()

if (LAYER_FONT)
    set(SOURCES ${SOURCES}
        font/FontContext.h
        font/FontContext.cpp
        font/Font.h
        font/Font.cpp
        font/SolidFont.h
        font/SolidFont.cpp
        font/ShadedFont.h
        font/ShadedFont.cpp
        font/BlendedFont.h
        font/BlendedFont.cpp
    )
    set(LIBRARIES ${LIBRARIES}
        ${SDL2_TTF_LIBRARY}
    )
endif()

add_library(layer ${SOURCES})
target_link_libraries(layer ${LIBRARIES})
target_compile_options(layer PUBLIC ${SDL2_CFLAGS_OTHER})

install(TARGETS layer DESTINATION lib)
