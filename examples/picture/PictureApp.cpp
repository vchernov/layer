#include "PictureApp.h"

#include "../../layer/image/ImageUtils.h"
#include "../../layer/surface/ISurface.h"

PictureApp::PictureApp(const std::string& pictureFileName) {
    window = layer::Window::createResizable<layer::AcceleratedWindow2D>("Picture", 320, 240);

    std::unique_ptr<layer::ISurface> imageSurface = layer::ImageUtils::loadImage(pictureFileName);
    image = std::make_unique<layer::Texture>(*imageSurface, window->getRenderer());
}

void PictureApp::update() {
    window->getRenderer().clear();
    window->getRenderer().render(*image);
    window->getRenderer().present();
}
