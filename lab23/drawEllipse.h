//
// Created by home on 20.4.22.
//

#ifndef LAB23_DRAWELLIPSE_H
#define LAB23_DRAWELLIPSE_H


#include <vector>
#include "RGB.h"
#include "figure.h"
#include "dot.h"
#include "cmath"

class drawEllipse {
public:
    static void draw(std::vector<dot> *dots, figure figure, int width, RGB lineColor, RGB fillColor);
};


#endif //LAB23_DRAWELLIPSE_H
