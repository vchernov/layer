#include "WindowsApp.h"

#include <functional>

#ifdef _WIN32
#include <Windows.h>
#endif
#include <GL/gl.h>

#include "WindowEventDirectDispatcher.h"

WindowsApp::WindowsApp() {
    wnd1 = layer::Window::create<layer::WindowGL>("GL", 256, 256);
    auto wnd1EventDispatcher = std::make_shared<WindowEventDirectDispatcher>(wnd1);
    wnd1EventDispatcher->close.add(std::bind(&WindowsApp::closeWnd1, this));
    events.addDispatcher(wnd1EventDispatcher);

    wnd2 = layer::Window::create<layer::Window2D>("2D", 128, 128);
    auto wnd2EventDispatcher = std::make_shared<WindowEventDirectDispatcher>(wnd2);
    wnd2EventDispatcher->close.add(std::bind(&WindowsApp::closeWnd2, this));
    events.addDispatcher(wnd2EventDispatcher);
}

WindowsApp::~WindowsApp() {
}

void WindowsApp::run() {
    while (wnd1 || wnd2) {
        events.process();

        if (wnd1) {
            wnd1->makeCurrent();
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            wnd1->swapBuffers();
        }

        if (wnd2) {
            wnd2->setDrawColor(0, 0, 255);
            wnd2->clear();
            wnd2->swapBuffers();
        }
    }
}

void WindowsApp::closeWnd1() {
    wnd1.reset();
}

void WindowsApp::closeWnd2() {
    wnd2.reset();
}
