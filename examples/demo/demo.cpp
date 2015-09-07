#include <iostream>

#include "../../layer/core/Context.h"
#include "../../layer/core/InitError.h"

#include "DemoApp.h"

int main(int argc, char** argv) {
    std::cout << "start" << std::endl;

    try {
        layer::Context context;

        DemoApp app;
        app.run();
    } catch (layer::InitError& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "end" << std::endl;
    return 0;
}
