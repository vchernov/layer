#include <iostream>

#include "../../layer/core/Context.h"
#include "../../layer/core/InitError.h"

#include "FractalApp.h"

int main(int, char**) {
    std::cout << "start" << std::endl;

    try {
        layer::Context context;

        FractalApp app;
        app.setFrameRateLimit(60);
        app.run();
    } catch (layer::InitError& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "end" << std::endl;
    return 0;
}
