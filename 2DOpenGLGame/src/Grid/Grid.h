#pragma once
#ifndef GRID_H
#define GRID_H
#include "../SquareClass/Square.h"
#include <vector>
#include <GLFW/glfw3.h>
class Grid {
private:
	std::vector<std::vector<Square*>*> grid;
public:
	void init(float MAXDISTANCE, float ROWS, float COLUMNS, float SPACING, std::vector<int> COLORS);
	void draw();
	void drawRectangle(Point topLeft, Point bottemRight, std::vector<int> colorOfSquare);
	void changeColor(int row, int column, std::vector<int> * colors);
	int getMaxX() {
		return this->maxX;
	}
	int getMaxY() {
		return this->maxY;
	}
private:
	int maxX;
	int maxY;

};
#endif