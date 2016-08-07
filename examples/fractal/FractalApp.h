#pragma once

#include "../../layer/core/App.h"
#include "../../layer/window/Window2D.h"
#include "../../layer/time/FpsCounter.h"

class FractalApp : public layer::App {
public:
    FractalApp();

protected:
    void update() override;

private:
    const char* windowTitle = "Fractal";

    std::unique_ptr<layer::Window2D> window;
    layer::FpsCounter fpsCounter;
};
