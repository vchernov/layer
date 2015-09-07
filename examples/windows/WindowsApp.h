#pragma once

#include "../../layer/window/Window.h"
#include "../../layer/window/WindowGL.h"
#include "../../layer/window/Window2D.h"
#include "../../layer/event/EventQueue.h"

class WindowsApp {
public:
    WindowsApp();
    virtual ~WindowsApp();

    void run();

private:
    void closeWnd1();
    void closeWnd2();

    layer::EventQueue events;

    std::shared_ptr<layer::WindowGL> wnd1;
    std::shared_ptr<layer::Window2D> wnd2;
};
