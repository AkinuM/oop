#ifndef LAB23_DOT_H
#define LAB23_DOT_H


#include "RGB.h"

class dot {
public:
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getWidth() const;

    void setWidth(int width);

    const RGB &getColor() const;

    void setColor(const RGB &color);

private:
    int x;
    int y;
    int width;
    RGB color;
public:
    dot(int x, int y, int width, RGB color);
};


#endif
