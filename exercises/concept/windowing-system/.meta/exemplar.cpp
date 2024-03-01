#include "windowing_system.h"

namespace windowing_system {

void size::resize(int newWidth, int newHeight) {
    this->width = newWidth;
    this->height = newHeight;
}

void position::move(int newX, int newY) {
    this->x = newX;
    this->y = newY;
}

programWindow::programWindow() {
    screenSize = new size{800, 600};
    windowSize = new size{};
    windowPosition = new position{};
}
programWindow::~programWindow() {
    delete screenSize;
    delete windowSize;
    delete windowPosition;
}

void programWindow::resize(size* newSize) {
    int targetWidth{newSize->width > 1 ? newSize->width : 1};
    int maxWidth{this->screenSize->width - this->windowPosition->x};
    int newWidth{maxWidth > targetWidth ? targetWidth : maxWidth};

    int targetHeight{newSize->height > 1 ? newSize->height : 1};
    int maxHeight{this->screenSize->height - this->windowPosition->y};
    int newHeight{maxHeight > targetHeight ? targetHeight : maxHeight};

    this->windowSize->resize(newWidth, newHeight);
}
void programWindow::move(position* newPosition) {
    int targetX{newPosition->x > 0 ? newPosition->x : 0};
    int maxX{this->screenSize->width - this->windowSize->width};
    int newX{maxX > targetX ? targetX : maxX};

    int targetY{newPosition->y > 0 ? newPosition->y : 0};
    int maxY{this->screenSize->height - this->windowSize->height};
    int newY{maxY > targetY ? targetY : maxY};

    this->windowPosition->move(newX, newY);
}

void changeWindow(programWindow* window) {
    window->windowSize->resize(400, 300);
    window->windowPosition->move(100, 150);
}

}  // namespace windowing_system
