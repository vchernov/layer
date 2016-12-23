#pragma once

#include <unordered_set>

#include "../../layer/core/App.h"
#include "../../layer/window/AcceleratedWindow2D.h"

class GridApp : public layer::App {
public:
    GridApp(int cellSize, int rows, int columns);

protected:
    void update() override;

private:
    void fillCell(int i, int j);

    void addMarker(int i, int j);
    void removeMarker(int i, int j);

    void handleMouseButtonDown(uint8_t button, int x, int y);

    std::unique_ptr<layer::AcceleratedWindow2D> window;

    int cellSize;
    int rows;
    int columns;

    std::unordered_set<int> markers;
};
