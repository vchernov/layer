#include "PictureApp.h"

#include "../../layer/image/ImageUtils.h"
#include "../../layer/surface/ISurface.h"

#include <algorithm>
#include <time.h>

PictureApp::PictureApp(const std::vector<std::string>& imageFileNames) {
    window = layer::Window::createResizable<layer::AcceleratedWindow2D>("Picture", 0, 0);

    int biggestWidth = 0;
    int biggestHeight = 0;

    for (const auto& fn : imageFileNames) {
        std::unique_ptr<layer::ISurface> imageSurface = layer::ImageUtils::loadImage(fn);
        auto image = std::make_shared<layer::Texture>(*imageSurface, window->getRenderer());
        images.push_back(image);

        if (imageSurface->getWidth() > biggestWidth) {
            biggestWidth = imageSurface->getWidth();
        }
        if (imageSurface->getHeight() > biggestHeight) {
            biggestHeight = imageSurface->getHeight();
        }
    }

    window->setSize(biggestWidth, biggestHeight);

    std::sort(images.begin(), images.end(),
        [](const std::shared_ptr<layer::Texture>& a, const std::shared_ptr<layer::Texture>& b) -> bool {
        int aw, ah, bw, bh;
        a->getSize(aw, ah);
        b->getSize(bw, bh);
        return (aw * ah) > (bw * bh);
    });

    seed = static_cast<int>(time(nullptr));
}

void PictureApp::update() {
    window->getRenderer().clear();
    
    if (!images.empty()) {
        window->getRenderer().render(*images[0]);

        int wndWidth, wndHeight;
        window->getSize(wndWidth, wndHeight);

        srand(seed);
        for (size_t i = 1; i < images.size(); i++) {
            auto img = images[i];

            int imgWidth = 0, imgHeight = 0;
            img->getSize(imgWidth, imgHeight);

            if (imgWidth < wndWidth && imgHeight < wndHeight) {
                int x = rand() % (wndWidth - imgWidth);
                int y = rand() % (wndHeight - imgHeight);
                window->getRenderer().render(*img, x, y, imgWidth, imgHeight);
            }
        }
    }

    window->getRenderer().present();
}
