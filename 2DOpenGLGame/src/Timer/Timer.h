#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <memory>
#include <functional>
#include <set>
#include <iterator>
#include <cassert>
#include <thread>
#include "../Grid/Grid.h"
class Timer
{
private:
    bool running = false;
public:
    void start(Grid* squareGrid, std::vector<Point> pattern);
    void quickChange(Grid* squareGrid, Point point, std::vector<int> color);
    bool getRunning() { return this->running; };
    void setRunning(bool running) { this->running = running; };
};
#endif