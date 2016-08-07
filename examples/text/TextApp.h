#pragma once

#include <vector>

#include "../../layer/core/App.h"
#include "../../layer/window/Window2D.h"
#include "../../layer/font/Font.h"
#include "../../layer/time/FpsCounter.h"

class TextApp : public layer::App {
public:
    TextApp(const std::string& fontFileName, int fontSize);

    void addLine(const std::string& text);

    void setSolidFont();
    void setBlendedFont();
    void setShadedFont();

protected:
    void update() override;

private:
    void updateWindowSize();

    const char* windowTitle = "Text";

    std::string fontFileName;
    int fontSize;
    std::vector<std::string> lines;

    std::unique_ptr<layer::Window2D> window;
    layer::FpsCounter fpsCounter;
    std::unique_ptr<layer::Font> font;
};
