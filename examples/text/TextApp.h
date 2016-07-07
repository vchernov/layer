#pragma once

#include <string>
#include <vector>

#include "../../layer/core/App.h"
#include "../../layer/window/Window2D.h"
#include "../../layer/font/Font.h"

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

    std::string fontFileName;
    int fontSize;
    std::vector<std::string> lines;

    std::unique_ptr<layer::Window2D> window;
    std::unique_ptr<layer::Font> font;
};
