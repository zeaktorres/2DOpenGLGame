#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>  
#include "../Point/Point.h"
#include "../Timer/Timer.h"
#include "../Grid/Grid.h"
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
	GameLogic(float MAXDISTANCE, float ROWS, float COLUMNS, float SPACING, std::vector<int> COLORS, GLFWwindow* window, int WINDOW_LENGTH, int WINDOW_WIDTH);
	~GameLogic();
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
	void appendRandomPoint();
	void play();
	void getMousePosition();
	void handleMousePosition();

};


#endif
