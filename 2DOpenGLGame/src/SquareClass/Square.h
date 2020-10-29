#ifndef SQUARE_H
#define SQUARE_H
#include<vector>
#include "../Point/Point.h"
class Square {
	private: 
		Point topLeft;
		Point bottemRight;
		std::vector<int> colors;
	public:
		Square(Point topLeft, Point bottemRight, std::vector<int> color);
		Point getTopLeft();
		Point getBottemRight();
		std::vector<int> getColors();
		void changeColor(std::vector<int> color);
};



#endif