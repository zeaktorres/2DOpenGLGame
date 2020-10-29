#include "GameLogic.h"
#include "../Mouse/Mouse.h"
GameLogic::GameLogic(float MAXDISTANCE, float ROWS, float COLUMNS, float SPACING, std::vector<int> COLORS, GLFWwindow* window, int WINDOW_LENGTH, int WINDOW_WIDTH)
{
	srand(time(NULL));
	squareGrid->init(MAXDISTANCE, ROWS, COLUMNS, SPACING, COLORS);
	this->window = window;
	setMouseCallBack(window);
	this->WINDOW_LENGTH = WINDOW_LENGTH;
	this->WINDOW_WIDTH = WINDOW_WIDTH;
}

void GameLogic::appendRandomPoint()
{
	int xRand = rand() % this->squareGrid->getMaxX();
	int yRand = rand() % this->squareGrid->getMaxY();
	Point randomPoint = Point(xRand, yRand);
	pattern.push_back(randomPoint);
}

void GameLogic::play()
{
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

void GameLogic::getMousePosition()
{
	if (numberOfClicks == this->pattern.size() && this->gameTimer.getRunning() == false) {
		this->setStateToTimer();
		return;
	}
	if (clicked == true) {
		clicked = false;
		if (numberOfClicks != this->pattern.size()) {
			handleMousePosition();
		}
	}
}

void GameLogic::handleMousePosition()
{
	std::vector<int> blue = std::vector<int>{ 0, 0, 255 };
		std::vector<int> red = std::vector<int>{ 255, 0, 0 };
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

GameLogic::~GameLogic() {
	delete this->squareGrid;
}
