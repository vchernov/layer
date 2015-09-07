#pragma once

#include <memory>

#include "../../layer/event/WindowEventDispatcher.h"
#include "../../layer/window/Window.h"

class WindowEventDirectDispatcher : public layer::WindowEventDispatcher {
public:
    WindowEventDirectDispatcher(std::weak_ptr<layer::Window> window);
    virtual ~WindowEventDirectDispatcher() = default;

protected:
    void onClose(const SDL_Event& event) override;

private:
    bool isForCurrentWindow(const SDL_Event& event);

    std::weak_ptr<layer::Window> window;
};
