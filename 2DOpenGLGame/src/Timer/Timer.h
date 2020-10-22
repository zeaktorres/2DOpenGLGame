#ifndef TIMER_H
#define TIMER_H
#pragma once
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
public:
    void init(Grid* squareGrid) {
        auto f = [squareGrid]() {
            int x = 0;
            int y = 0;
            int maxX = squareGrid->getMaxX();
            int maxY = squareGrid->getMaxY();
            while (true) {
                if (y == maxY) {
                    y = 0;
                    x += 1;
                    if (x == maxX) {
                        y += 1;
                        x = 0;
                    }
                }
                std::vector<int>* blue = new std::vector<int>{ 0, 0, 255 };
                std::vector<int>* white = new std::vector<int>{ 255, 255, 255 };
                squareGrid->changeColor(x, y, blue);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                squareGrid->changeColor(x, y, white);
                y += 1;
            }
        };
        std::thread th1(f);
        th1.detach();
    }
};
#endif