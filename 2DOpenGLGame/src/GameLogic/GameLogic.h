#pragma once
#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>  
#include "../Point/Point.h"
#include "../Timer/Timer.h"
#include "../Grid/Grid.h"
#include "../Mouse/Mouse.h"
#include <iostream>

enum class States {User, TimerMode};

class GameLogic {
private:
	int WINDOW_LENGTH;
	int WINDOW_WIDTH;
	bool running = false;
	States state = States::TimerMode;
	std::vector<Point> pattern = std::vector<Point>();
	Timer gameTimer = Timer();
	Grid* squareGrid = new Grid();
	GLFWwindow* window;
	int numberOfClicks = 0;
public:
	GameLogic(float MAXDISTANCE, float ROWS, float COLUMNS, float SPACING, std::vector<int> COLORS, GLFWwindow * window, int WINDOW_LENGTH, int WINDOW_WIDTH) {
		srand(time(NULL));
		squareGrid->init(MAXDISTANCE, ROWS, COLUMNS, SPACING, COLORS);
		this->window = window;
		setMouseCallBack(window);
		this->WINDOW_LENGTH = WINDOW_LENGTH;
		this->WINDOW_WIDTH = WINDOW_WIDTH;
	}
	bool getRunning() {
		return this->running;
	}
	void start() {
		this->running = true;
	}
	void end() {
		this->running = false;
	}
	void setStateToUser() {
		this->state = States::User;
	}
	void setStateToTimer() {
		this->state = States::TimerMode;
	}
	void displayPattern() {
		gameTimer.start(this->squareGrid, this->pattern);
	}
	void appendRandomPoint() {
		int xRand = rand() % this->squareGrid->getMaxX();
		int yRand = rand() % this->squareGrid->getMaxY();
		Point randomPoint = Point(xRand, yRand);
		pattern.push_back(randomPoint);
	}
	void play() {
		if (this->running == 1) {
			// Displaying Pattern
			if (this->state == States::TimerMode) {
				this->numberOfClicks = 0;
				if (this->gameTimer.getRunning() == 0) {
					this->appendRandomPoint();
					this->displayPattern();
					this->setStateToUser();
				}
			}

			// User Selecting
			if (this->state == States::User) {
				getMousePosition();
			}

			squareGrid->draw();
		}
	}
	void getMousePosition() {
		if (numberOfClicks == this->pattern.size() && this->gameTimer.getRunning() == false) {
			this->setStateToTimer();
			return;
		}
		if (clicked == true) {
			clicked = false;
			if (numberOfClicks != this->pattern.size() ){
				handleMousePosition();
			}
		}
	}
	void handleMousePosition() {
		std::vector<int> * blue = new std::vector<int>{ 0, 0, 255 };
		std::vector<int>* red = new std::vector<int>{ 255, 0, 0 };
		Point squarePressed = this->squareGrid->getPointFromXposYPos(xpos, ypos, this->WINDOW_LENGTH, this->WINDOW_WIDTH);
		if (squarePressed.x != -1) {
			if (int(squarePressed.x) == int(pattern.at(numberOfClicks).x) && int(squarePressed.y) == int(pattern.at(numberOfClicks).y)) {
				this->numberOfClicks++;
				this->gameTimer.quickChange(this->squareGrid, squarePressed, blue);
			}
			else {
				this->gameTimer.quickChange(this->squareGrid, squarePressed, red);
			}
		}
	}

};


#endif
