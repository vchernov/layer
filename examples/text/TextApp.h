#pragma once

#include "../../layer/core/App.h"
#include "../../layer/window/Window2D.h"

#include "../../layer/font/Font.h"

class TextApp : public layer::App {
public:
    TextApp(const std::string& fontFileName);

protected:
    void update() override;

private:
    std::shared_ptr<layer::Window2D> window;
    std::shared_ptr<layer::Font> font;
};
