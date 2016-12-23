#include <iostream>

#include "../../layer/core/Context.h"
#include "../../layer/core/InitError.h"
#include "GridApp.h"

int main(int, char**) {
    std::cout << "start" << std::endl;

    try {
        layer::Context context;

        GridApp app(20, 24, 32);
        app.run(30);
    } catch (layer::InitError& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "end" << std::endl;
    return 0;
}
