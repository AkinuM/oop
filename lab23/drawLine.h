#ifndef LAB23_DRAWLINE_H
#define LAB23_DRAWLINE_H


#include <vector>
#include "figure.h"
#include "dot.h"
#include "cmath"


class drawLine {
public:
    static void draw(std::vector<dot> *dots, figure figure, int width, RGB lineColor);
};


#endif
