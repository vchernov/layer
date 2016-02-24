#pragma once

#include <memory>

#include "../../layer/core/App.h"
#include "../../layer/window/Window.h"

class DemoApp : public layer::App {
public:
    DemoApp();

protected:
    void update() override;

private:
    std::shared_ptr<layer::Window> window;
};
