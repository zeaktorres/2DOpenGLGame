#include "Timer.h"
void Timer::start(Grid* squareGrid, std::vector<Point> pattern) {
        auto f = [squareGrid, pattern, this]() {
            this->setRunning(true);
            int x = 0;
            int y = 0;
            int maxX = squareGrid->getMaxX();
            int maxY = squareGrid->getMaxY();
            for (Point point : pattern) {
                std::vector<int> blue = std::vector<int>{ 0, 0, 255 };
                std::vector<int> white = std::vector<int>{ 255, 255, 255 };
                squareGrid->changeColor(point.x, point.y, blue);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                squareGrid->changeColor(point.x, point.y, white);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                y += 1;
            }
            this->setRunning(false);
        };
    std::thread th1(f);
    th1.detach();
};

void Timer::quickChange(Grid* squareGrid, Point point, std::vector<int> color) {
    auto f = [squareGrid, point, this, color]() {
        this->setRunning(true);
        int x = 0;
        int y = 0;
        int maxX = squareGrid->getMaxX();
        int maxY = squareGrid->getMaxY();
        std::vector<int> white = std::vector<int>{ 255, 255, 255 };
        squareGrid->changeColor(point.x, point.y, color);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        squareGrid->changeColor(point.x, point.y, white);
        this->setRunning(false);
    };
    std::thread th1(f);
    th1.detach();
};