#include "WindowsApp.h"

#include <functional>

#ifdef _WIN32
#include <Windows.h>
#endif
#include <GL/gl.h>

#include "SelectiveWindowEventDispatcher.h"

WindowsApp::WindowsApp() {
    wnd1 = layer::Window::create<layer::WindowGL>("GL 1", 256, 256);
    auto wnd1EventDispatcher = std::make_shared<SelectiveWindowEventDispatcher>(wnd1);
    wnd1EventDispatcher->close.add(std::bind(&WindowsApp::closeWnd1, this));
    events.addDispatcher(wnd1EventDispatcher);

    wnd2 = layer::Window::create<layer::WindowGL>("GL 2", 256, 256);
    auto wnd2EventDispatcher = std::make_shared<SelectiveWindowEventDispatcher>(wnd2);
    wnd2EventDispatcher->close.add(std::bind(&WindowsApp::closeWnd2, this));
    events.addDispatcher(wnd2EventDispatcher);

    wnd3 = layer::Window::create<layer::AcceleratedWindow2D>("2D 1", 256, 256);
    auto wnd3EventDispatcher = std::make_shared<SelectiveWindowEventDispatcher>(wnd3);
    wnd3EventDispatcher->close.add(std::bind(&WindowsApp::closeWnd3, this));
    events.addDispatcher(wnd3EventDispatcher);

    wnd4 = layer::Window::create<layer::AcceleratedWindow2D>("2D 2", 256, 256);
    auto wnd4EventDispatcher = std::make_shared<SelectiveWindowEventDispatcher>(wnd4);
    wnd4EventDispatcher->close.add(std::bind(&WindowsApp::closeWnd4, this));
    events.addDispatcher(wnd4EventDispatcher);
}

void WindowsApp::update() {
    if (wnd1) {
        wnd1->makeCurrent();
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        wnd1->swapBuffers();
    }

    if (wnd2) {
        wnd2->makeCurrent();
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        wnd2->swapBuffers();
    }

    if (wnd3) {
        wnd3->setDrawColor(0, 0, 255);
        wnd3->clear();
        wnd3->swapBuffers();
    }

    if (wnd4) {
        wnd4->setDrawColor(255, 255, 255);
        wnd4->clear();
        wnd4->swapBuffers();
    }
}

void WindowsApp::closeWnd1() {
    wnd1.reset();
    if (!wnd2 && !wnd3 && !wnd4) {
        stop();
    }
}

void WindowsApp::closeWnd2() {
    wnd2.reset();
    if (!wnd1 && !wnd3 && !wnd4) {
        stop();
    }
}

void WindowsApp::closeWnd3() {
    wnd3.reset();
    if (!wnd1 && !wnd2 && !wnd4) {
        stop();
    }
}

void WindowsApp::closeWnd4() {
    wnd4.reset();
    if (!wnd1 && !wnd2 && !wnd3) {
        stop();
    }
}
