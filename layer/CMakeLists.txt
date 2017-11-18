add_library(layer
    core/Context.h core/Context.cpp
    core/OpenGL.h core/OpenGL.cpp
    core/InitError.h
    core/IllegalArgumentException.h
    core/LoadingFailedException.h
    core/Renderer.h core/Renderer.cpp
    core/Texture.h core/Texture.cpp
    core/App.h core/App.cpp
    event/Delegate.h
    event/DelegateMap.h
    event/EventQueue.h event/EventQueue.cpp
    event/IEventDispatcher.h
    event/SystemEventDispatcher.h event/SystemEventDispatcher.cpp
    event/WindowEventDispatcher.h event/WindowEventDispatcher.cpp
    event/KeyboardEventDispatcher.h event/KeyboardEventDispatcher.cpp
    event/MouseEventDispatcher.h event/MouseEventDispatcher.cpp
    window/Window.h window/Window.cpp
    window/WindowGL.h window/WindowGL.cpp
    window/AcceleratedWindow2D.h window/AcceleratedWindow2D.cpp
    window/Window2D.h window/Window2D.cpp
    time/Time.h time/Time.cpp
    time/Clock.h time/Clock.cpp
    time/FpsCounter.h time/FpsCounter.cpp
    surface/ISurface.h
    surface/SurfaceWrapper.h surface/SurfaceWrapper.cpp
    surface/Surface.h surface/Surface.cpp
)

target_compile_features(layer PUBLIC cxx_std_14)
target_link_libraries(layer ${SDL2_LIBRARIES})

if (LAYER_IMAGE)
    target_sources(layer PRIVATE
        image/ImageContext.h image/ImageContext.cpp
        image/ImageUtils.h image/ImageUtils.cpp
    )
    target_link_libraries(layer ${SDL2_IMAGE_LIBRARIES})
endif()

if (LAYER_FONT)
    target_sources(layer PRIVATE
        font/FontContext.h font/FontContext.cpp
        font/Font.h font/Font.cpp
        font/SolidFont.h font/SolidFont.cpp
        font/ShadedFont.h font/ShadedFont.cpp
        font/BlendedFont.h font/BlendedFont.cpp
    )
    target_link_libraries(layer ${SDL2_TTF_LIBRARIES})
endif()

install(TARGETS layer DESTINATION lib)
