#pragma once

#include "../../layer/core/App.h"
#include "../../layer/window/WindowGL.h"
#include "../../layer/window/AcceleratedWindow2D.h"

class WindowsApp : public layer::App {
public:
    WindowsApp();

protected:
    void update() override;

private:
    void closeWnd1();
    void closeWnd2();
    void closeWnd3();
    void closeWnd4();

    std::shared_ptr<layer::WindowGL> wnd1;
    std::shared_ptr<layer::WindowGL> wnd2;
    std::shared_ptr<layer::AcceleratedWindow2D> wnd3;
    std::shared_ptr<layer::AcceleratedWindow2D> wnd4;
};
