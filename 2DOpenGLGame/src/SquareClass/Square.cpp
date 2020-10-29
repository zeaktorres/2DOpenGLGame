#include "Square.h"

Square::Square(Point topLeft, Point bottemRight, std::vector<int> colors)
{
	this->topLeft = topLeft;
	this->bottemRight = bottemRight;
	this->colors = colors;
}

Point Square::getTopLeft()
{
	return this->topLeft;
}

Point Square::getBottemRight()
{
	return this->bottemRight;
}

std::vector<int> Square::getColors()
{
	return this->colors;
}

void Square::changeColor(std::vector<int> color) {
	this->colors = color;
}
