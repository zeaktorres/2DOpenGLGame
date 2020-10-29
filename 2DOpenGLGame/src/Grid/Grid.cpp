#include "Grid.h"
#include <iostream>
void Grid::drawRectangle(Point topLeft, Point bottemRight, std::vector<int> colorOfSquare) {
    glColor3ub(colorOfSquare.at(0), colorOfSquare.at(1), colorOfSquare.at(2));
    glBegin(GL_QUADS);
    glVertex2f(topLeft.x, topLeft.y); // top left
    glVertex2f(bottemRight.x, topLeft.y); // top right 
    glVertex2f(bottemRight.x, bottemRight.y); // bottom right
    glVertex2f(topLeft.x, bottemRight.y); // bottom left
    glEnd();
}

void Grid::init(float MAXDISTANCE, float ROWS, float COLUMNS, float SPACING, std::vector<int> COLORS) {
    this->maxX = ROWS;
    this->maxY = COLUMNS;
    Point* rectangleTopleft;
    Point* rectangleBottomRight;
    std::vector<int>* colorOfSquare;
    std::vector<Square*>* squares = new std::vector<Square*>();
    for (float ii = MAXDISTANCE * 2 / ROWS; ii <= MAXDISTANCE * 2; ii += MAXDISTANCE * 2 / ROWS) {
        for (float i = MAXDISTANCE * 2 / COLUMNS; i <= MAXDISTANCE * 2; i += MAXDISTANCE * 2 / COLUMNS) {
            rectangleBottomRight = new Point(-MAXDISTANCE + i - SPACING, -MAXDISTANCE + ii - SPACING);
            rectangleTopleft = new Point(-MAXDISTANCE + SPACING + i - (MAXDISTANCE * 2 / COLUMNS), -MAXDISTANCE + SPACING + ii - (MAXDISTANCE * 2 / ROWS));
            colorOfSquare = new std::vector<int>{ COLORS.at(0), COLORS.at(1), COLORS.at(2) };
            squares->push_back(new Square(rectangleTopleft, rectangleBottomRight, colorOfSquare));
        }
        grid.insert(grid.begin(), squares);
        squares = new std::vector<Square*>();
    }
}
void Grid::draw() {
    for (std::vector<Square*>* row : grid) {
        for (Square* square : *row) {
            drawRectangle(*square->getTopLeft(), *square->getBottemRight(), *square->getColors());
        }
    }
}
void Grid::changeColor(int row, int column, std::vector<int> * colors) {
    this->grid.at(row)->at(column)->changeColor(colors);
}

Point Grid::getPointFromXposYPos(double xPos, double yPos, int WINDOW_LENGTH, int WINDOW_WIDTH) {
    Point* topLeft;
    Point * bottomRight;
    std::vector<int>* myV = new std::vector<int>{ 0, 255, 255 };
    double xMin, xMax, yMin, yMax;
    int columnN = 0;
    int rowN = this->getMaxY() - 1;
    xPos -= WINDOW_WIDTH / 2;
    yPos -= WINDOW_LENGTH / 2;
    xPos = xPos / (WINDOW_WIDTH / 2);
    yPos = yPos / (WINDOW_LENGTH / 2);
    for (std::vector<Square*>* row : grid) {
        for (Square* square : *row) {
            topLeft = square->getTopLeft();
            bottomRight = square->getBottemRight();

            xMin = topLeft->x;
            xMax = bottomRight->x;
            yMax = bottomRight->y;
            yMin = topLeft->y;
            
            if (xMin < xPos && xMax > xPos && yMin < yPos && yMax > yPos) {
                return Point(rowN, columnN);
            }
            columnN++;
        }
        columnN = 0;
        rowN--;
    }
    return Point(-1, -1);
}