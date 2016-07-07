#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <type_traits>

#include <SDL.h>

namespace layer {

class Window {
public:
    Window(const std::string& title, int width, int height, uint32_t flags);
    virtual ~Window();

    template<class T>
    static std::unique_ptr<T> create(const std::string& title, int width, int height) {
        static_assert(std::is_base_of<Window, T>::value, "T must be derived from Window");
        return std::make_unique<T>(title, width, height);
    }

    template<class T>
    static std::unique_ptr<T> createResizable(const std::string& title, int width, int height) {
        static_assert(std::is_base_of<Window, T>::value, "T must be derived from Window");
        return std::make_unique<T>(title, width, height, SDL_WINDOW_RESIZABLE);
    }

    template<class T>
    static std::unique_ptr<T> createFullscreen(const std::string& title, int width, int height) {
        static_assert(std::is_base_of<Window, T>::value, "T must be derived from Window");
        return std::make_unique<T>(title, width, height, SDL_WINDOW_FULLSCREEN);
    }

    template<class T>
    static std::unique_ptr<T> createFullscreen(const std::string& title, int displayIndex = 0) {
        static_assert(std::is_base_of<Window, T>::value, "T must be derived from Window");
        SDL_DisplayMode mode;
        SDL_GetCurrentDisplayMode(displayIndex, &mode);
        return std::make_unique<T>(title, mode.w, mode.h, SDL_WINDOW_FULLSCREEN);
    }

    uint32_t getWindowId() const;

    void setSize(int width, int height);

    virtual void swapBuffers() = 0;

protected:
    SDL_Window* window;
};

}
