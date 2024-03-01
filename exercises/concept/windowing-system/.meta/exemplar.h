#pragma once

namespace windowing_system {

struct size {
    int width{80};
    int height{60};
    void resize(int newWidth, int newHeight);
};

struct position {
    int x;
    int y;
    void move(int newX, int newY);
};

struct programWindow {
    programWindow();
    ~programWindow();
    size* screenSize{nullptr};
    size* windowSize{nullptr};
    position* windowPosition;
    void resize(size* newSize);
    void move(position* newPosition);
};

void changeWindow(programWindow* window);

}  // namespace windowing_system

