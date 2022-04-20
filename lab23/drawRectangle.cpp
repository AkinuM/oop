//
// Created by home on 20.4.22.
//

#include "drawRectangle.h"
#include "drawLine.h"

void drawRectangle::draw(std::vector<dot> *dots, figure figure1, int width, RGB lineColor, RGB fillColor) {
    int x1 = std::min(figure1.getX1(), figure1.getX2());
    int y1 = std::min(figure1.getY1(), figure1.getY2());
    int x2 = std::max(figure1.getX1(), figure1.getX2());
    int y2 = std::max(figure1.getY1(), figure1.getY2());
    drawLine::draw(dots, *new figure(x1, y1, x2, y1), width, lineColor);
    drawLine::draw(dots, *new figure(x2, y1, x2, y2), width, lineColor);
    drawLine::draw(dots, *new figure(x2, y2, x1, y2), width, lineColor);
    drawLine::draw(dots, *new figure(x1, y2, x1, y1), width, lineColor);
    if (fillColor.getR() != 1 || fillColor.getG() != 1 || fillColor.getB() != 1){
        for(int i = x1 + width/2; i <= x2 - width/2; i+=1){
            drawLine::draw(dots, *new figure(i, y1 + width/2, i, y2 - width/2), 1, fillColor);
        }
    }
}
