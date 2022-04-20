//
// Created by home on 20.4.22.
//

#ifndef LAB23_PAINT_H
#define LAB23_PAINT_H


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <vector>
#include <list>
#include "dot.h"
#include "drawDot.h"
#include "drawLine.h"
#include "drawRectangle.h"

class paint {
private:
    static std::vector<dot> dots;
    static std::vector<dot> tempDots;
    static RGB lineColor;
    static RGB fillColor;
    static int width;
    static int figureType;
    static bool isSecond;
    static int firstx;
    static int firsty;
    static std::list<int> undoHistory;
    static std::list<int> redoHistory;
    static std::vector<dot> redoDots;
public:
    static void display();
    static void clear();
    static void undo();
    static void redo();
    static void mouse(int bin, int state, int x, int y);
    static void motion(int x, int y);
    static void passiveMotion(int x, int y);
    static void processMainMenu(int value);
    static void processWidthMenu(int value);
    static void processColorMenu(int value);
    static void processFillColorMenu(int value);
    static void processFigureMenu(int value);
    static void createOurMenu();
    static void init();
    static void FPS(int val);
    static void callbackInit();
};


#endif //LAB23_PAINT_H
