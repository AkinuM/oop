#include "figure.h"

int figure::getX1() const {
    return x1;
}

void figure::setX1(int x1) {
    figure::x1 = x1;
}

int figure::getY1() const {
    return y1;
}

void figure::setY1(int y1) {
    figure::y1 = y1;
}

int figure::getX2() const {
    return x2;
}

void figure::setX2(int x2) {
    figure::x2 = x2;
}

int figure::getY2() const {
    return y2;
}

void figure::setY2(int y2) {
    figure::y2 = y2;
}

figure::figure(int x1, int y1, int x2, int y2) {
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
}
