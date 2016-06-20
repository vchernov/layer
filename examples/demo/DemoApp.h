#pragma once

#include "../../layer/core/App.h"
#include "../../layer/window/AcceleratedWindow2D.h"

class DemoApp : public layer::App {
public:
    DemoApp();

protected:
    void update() override;

private:
    std::unique_ptr<layer::AcceleratedWindow2D> window;
};
