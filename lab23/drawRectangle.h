//
// Created by home on 20.4.22.
//

#ifndef LAB23_DRAWRECTANGLE_H
#define LAB23_DRAWRECTANGLE_H


#include <vector>
#include "dot.h"
#include "figure.h"

class drawRectangle {
public:
    static void draw(std::vector<dot> *dots, figure figure, int width, RGB lineColor, RGB fillColor);
};


#endif //LAB23_DRAWRECTANGLE_H
