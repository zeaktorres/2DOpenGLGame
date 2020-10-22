#include "Grid.h"
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