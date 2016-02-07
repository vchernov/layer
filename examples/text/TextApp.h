#pragma once

#include <memory>

#include "../../layer/event/EventQueue.h"
#include "../../layer/window/Window2D.h"

#include "../../layer/font/Font.h"

class TextApp {
public:
    TextApp(const std::string& fontFileName);
    virtual ~TextApp();

    void run();
    void quit();

private:
    bool running = false;
    layer::EventQueue events;
    std::shared_ptr<layer::Window2D> window;
    std::shared_ptr<layer::Font> font;
};
