#pragma once

#include <memory>

#include "../../layer/event/WindowEventDispatcher.h"
#include "../../layer/window/Window.h"

class SelectiveWindowEventDispatcher : public layer::WindowEventDispatcher {
public:
    SelectiveWindowEventDispatcher(std::weak_ptr<layer::Window> window);
    ~SelectiveWindowEventDispatcher() = default;

protected:
    void onClose(const SDL_Event& event) override;

private:
    bool isForCurrentWindow(const SDL_Event& event);

    std::weak_ptr<layer::Window> window;
};
