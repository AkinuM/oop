//
// Created by home on 20.4.22.
//

#include "drawEllipse.h"

void drawEllipse::draw(std::vector<dot> *dots, figure figure, int width, RGB lineColor, RGB fillColor) {
    long halfHeight = abs(figure.getY1() - figure.getY2()) / 2;
    long halfWidth = abs(figure.getX1() - figure.getX2()) / 2;

    long center_x = std::min(figure.getX1(), figure.getX2()) + halfWidth;
    long center_y = std::min(figure.getY1(), figure.getY2()) + halfHeight;

    long hh = halfHeight * halfHeight;
    long ww = halfWidth * halfWidth;
    long hhww = hh * ww;
    long x0 = halfWidth;
    long dx = 0;

    long hh_1 = (halfHeight - width) * (halfHeight- width);
    long ww_1 = (halfWidth - width) * (halfWidth - width);
    long hhww_1 = hh_1 * ww_1;

    long border_x;
    for (int y = 1; y <= halfHeight; y += 3) {
        int x1 = x0 - (dx - 100);
        for (; x1 > 0; x1 -= 3) {
            if (x1 * x1 * hh + y * y * ww <= hhww) {
                break;
            }

        }

        for (border_x = x1; border_x > 0; border_x -= 2) {
            if (border_x * border_x * hh + y * y * ww <= hhww_1) {
                break;
            }

        }
        dx = x0 - x1;
        x0 = x1;

        for (int x = -x0; x <= x0; x++) {
            if (x <= -border_x || x >= border_x) {
                dots->push_back(*new dot(center_x + x, center_y - y, width, lineColor));
                dots->push_back(*new dot(center_x + x, center_y + y, width, lineColor));
                continue;
            }
            if (fillColor.getR() != 1 || fillColor.getG() != 1 || fillColor.getB() != 1){
                dots->push_back(*new dot(center_x + x, center_y - y, width, fillColor));
                dots->push_back(*new dot(center_x + x, center_y + y, width, fillColor));
            }
        }
    }
}
