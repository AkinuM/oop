//
// Created by home on 20.4.22.
//

#include "drawLine.h"
#include "drawDot.h"

void drawLine::draw(std::vector<dot> *dots, figure figure, int width, RGB lineColor) {
    bool changed = false;
    int x1 = figure.getX1();
    int y1 = figure.getY1();
    int x2 = figure.getX2();
    int y2 = figure.getY2();
    if (abs(x2 - x1) < abs(y2 - y1)) {
        int tmp1 = x1;
        x1 = y1;
        y1 = tmp1;
        int tmp2 = x2;
        x2 = y2;
        y2 = tmp2;
        changed = true;
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    int yi = 1;
    int xi = 1;
    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }
    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }
    int d = 2 * dy - dx;
    int incrE = dy * 2;
    int incrNE = 2 * dy - 2 * dx;

    int x = x1, y = y1;
    if (changed)
        drawDot::draw(dots, *new dot(y, 850 - x, width, lineColor));
    else
        drawDot::draw(dots, *new dot(x, 850 - y, width, lineColor));
    while (x != x2) {
        if (d <= 0)
            d += incrE;
        else {
            d += incrNE;
            y += yi;
        }
        x += xi;
        if (changed)
            drawDot::draw(dots, *new dot(y, 850 - x, width, lineColor));
        else
            drawDot::draw(dots, *new dot(x, 850 - y, width, lineColor));
    }
}
