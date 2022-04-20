//
// Created by home on 20.4.22.
//

#include "dot.h"

dot::dot(int x, int y, int width, RGB color) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->color = color;
}

int dot::getX() const {
    return x;
}

void dot::setX(int x) {
    dot::x = x;
}

int dot::getY() const {
    return y;
}

void dot::setY(int y) {
    dot::y = y;
}

int dot::getWidth() const {
    return width;
}

void dot::setWidth(int width) {
    dot::width = width;
}

const RGB &dot::getColor() const {
    return color;
}

void dot::setColor(const RGB &color) {
    dot::color = color;
}
