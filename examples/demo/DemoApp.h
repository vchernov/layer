#pragma once

#include <memory>

#include "../../layer/event/EventQueue.h"
#include "../../layer/window/Window.h"

class DemoApp {
public:
    DemoApp();
    virtual ~DemoApp();

    void run();
    void quit();

private:
    bool running = false;
    layer::EventQueue events;
    std::shared_ptr<layer::Window> window;
};
