#ifndef LAB23_RGB_H
#define LAB23_RGB_H


class RGB {
private:
    int r;
    int g;
    int b;
public:
    int getR() const;

    void setR(int r);

    int getG() const;

    void setG(int g);

    int getB() const;

    void setB(int b);

    RGB(int r, int g, int b);
    RGB();
};


#endif