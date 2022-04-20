#ifndef LAB23_FIGURE_H
#define LAB23_FIGURE_H


#include "RGB.h"

class figure {
public:
    figure(int x1, int y1, int x2, int y2);

    int getX1() const;

    void setX1(int x1);

    int getY1() const;

    void setY1(int y1);

    int getX2() const;

    void setX2(int x2);

    int getY2() const;

    void setY2(int y2);


private:
    int x1;
    int y1;
    int x2;
    int y2;
};


#endif
