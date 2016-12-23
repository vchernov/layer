#include "GridApp.h"

#include <functional>

#include "../../layer/event/MouseEventDispatcher.h"

GridApp::GridApp(int cellSize, int rows, int columns) : cellSize(cellSize), rows(rows), columns(columns) {
    window = layer::Window::create<layer::AcceleratedWindow2D>("Grid", columns * cellSize + 1, rows * cellSize + 1);

    auto mouseEventDispatcher = std::make_shared<layer::MouseEventDispatcher>();
    mouseEventDispatcher->mouseButtonDown.add(std::bind(&GridApp::handleMouseButtonDown, this, 
        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    events.addDispatcher(mouseEventDispatcher);
}

void GridApp::update() {
    window->getRenderer().setDrawColor(0, 0, 0);
    window->getRenderer().clear();

    window->getRenderer().setDrawColor(255, 255, 255);
    window->getRenderer().drawGrid(0, 0, cellSize, cellSize, rows, columns);

    window->getRenderer().setDrawColor(255, 0, 0);
    for (const auto& position : markers) {
        fillCell(position / columns, position % columns);
    }

    window->swapBuffers();
}

void GridApp::fillCell(int i, int j) {
    window->getRenderer().fillRect(j * cellSize + 1, i * cellSize + 1, cellSize - 1, cellSize - 1);
}

void GridApp::addMarker(int i, int j) {
    markers.insert(i * columns + j);
}

void GridApp::removeMarker(int i, int j) {
    markers.erase(i * columns + j);
}

void GridApp::handleMouseButtonDown(uint8_t button, int x, int y) {
    int i = y / cellSize;
    int j = x / cellSize;

    switch (button) {
        case SDL_BUTTON_LEFT:
            addMarker(i, j);
            break;
        case SDL_BUTTON_RIGHT:
            removeMarker(i, j);
            break;
    }
}
