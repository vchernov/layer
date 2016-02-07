#pragma once

#include "../../layer/window/Window.h"
#include "../../layer/window/WindowGL.h"
#include "../../layer/window/AcceleratedWindow2D.h"
#include "../../layer/event/EventQueue.h"

class WindowsApp {
public:
    WindowsApp();
    virtual ~WindowsApp();

    void run();

private:
    void closeWnd1();
    void closeWnd2();
    void closeWnd3();
    void closeWnd4();

    std::shared_ptr<layer::WindowGL> wnd1;
    std::shared_ptr<layer::WindowGL> wnd2;
    std::shared_ptr<layer::AcceleratedWindow2D> wnd3;
    std::shared_ptr<layer::AcceleratedWindow2D> wnd4;

    layer::EventQueue events;
};
