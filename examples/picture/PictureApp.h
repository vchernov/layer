#pragma once

#include "../../layer/core/App.h"
#include "../../layer/window/AcceleratedWindow2D.h"
#include "../../layer/core/Texture.h"

class PictureApp : public layer::App {
public:
    PictureApp(const std::string& pictureFileName);

protected:
    void update() override;

private:
    std::unique_ptr<layer::AcceleratedWindow2D> window;
    std::unique_ptr<layer::Texture> image;
};
