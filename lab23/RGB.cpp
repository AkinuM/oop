#include "RGB.h"

int RGB::getR() const {
    return r;
}

void RGB::setR(int r) {
    RGB::r = r;
}

int RGB::getG() const {
    return g;
}

void RGB::setG(int g) {
    RGB::g = g;
}

int RGB::getB() const {
    return b;
}

void RGB::setB(int b) {
    RGB::b = b;
}

RGB::RGB(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

RGB::RGB() {

}
