//
// Created by home on 20.4.22.
//

#include "paint.h"
#include "drawEllipse.h"

std::vector<dot> paint::dots;
std::vector<dot> paint::tempDots;
RGB paint::lineColor = *new RGB(0, 0, 0);
RGB paint::fillColor = *new RGB(1, 1, 1);
int paint::width = 3;
int paint::figureType = 1;
bool paint::isSecond;
int paint::firstx;
int paint::firsty;
std::list<int> paint::undoHistory;
std::list<int> paint::redoHistory;
std::vector<dot> paint::redoDots;

void paint::display(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    for (unsigned int i = 0; i < dots.size(); i++) {
        glPointSize(dots[i].getWidth());
        glBegin(GL_POINTS);
        glColor3f(dots[i].getColor().getR(), dots[i].getColor().getG(), dots[i].getColor().getB());
        glVertex2i(dots[i].getX(), dots[i].getY());
        glEnd();
    }
    for (unsigned int i = 0; i < tempDots.size(); i++) {
        glPointSize(tempDots[i].getWidth());
        glBegin(GL_POINTS);
        glColor3f(tempDots[i].getColor().getR(), tempDots[i].getColor().getG(), tempDots[i].getColor().getB());
        glVertex2i(tempDots[i].getX(), tempDots[i].getY());
        glEnd();
    }
    glutSwapBuffers();
}

void paint::clear() {
    dots.clear();
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void paint::undo() {
    if (undoHistory.back() != dots.size() && redoHistory.back() != dots.size()) {
        redoHistory.push_back(dots.size());
    }
    int numRemove = dots.size() - undoHistory.back();
    for (int i = 0; i < numRemove; i++) {
        redoDots.push_back(dots.back());
        dots.pop_back();
    }
    redoHistory.push_back(undoHistory.back());
    undoHistory.pop_back();
}

void paint::redo() {
    undoHistory.push_back(redoHistory.back());
    redoHistory.pop_back();
    int numRemove = redoHistory.back() - dots.size();
    for (int i = 0; i < numRemove; i++) {
        dots.push_back(redoDots.back());
        redoDots.pop_back();
    }
}

void paint::mouse(int bin, int state, int x, int y) {
    if (bin == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (figureType == 1) {
            undoHistory.push_back(dots.size());
            drawDot::draw(&dots, *new dot(x, 850 - y, width, lineColor));
        }
        else {
            if (!isSecond) {
                firstx = x;
                firsty = y;
                isSecond = true;
            }
            else {
                undoHistory.push_back(dots.size());
                if (figureType == 2){
                    drawLine::draw(&dots, *new figure(firstx, firsty, x, y), width, lineColor);
                    isSecond = false;
                }
                else if (figureType == 3){
                    drawRectangle::draw(&dots, *new figure(firstx, firsty, x, y), width, lineColor, fillColor);
                    isSecond = false;
                }
                else if (figureType == 4){
                    drawEllipse::draw(&dots, *new figure(firstx, 850 - firsty, x, 850 - y), width, lineColor, fillColor);
                    isSecond = false;
                }
                else if (figureType == 5){
                    drawLine::draw(&dots, *new figure(firstx, firsty, x, y), width, lineColor);
                    firstx = x;
                    firsty = y;
                }
            }
        }
    }
}

void paint::motion(int x, int y) {
    if (figureType == 1) {
        drawDot::draw(&dots, *new dot(x, 850 - y, width, lineColor));
    }
}

void paint::passiveMotion(int x, int y) {
    tempDots.clear();
    if (isSecond){
        if (figureType == 2 || figureType == 5) {
            drawLine::draw(&tempDots, *new figure(firstx, firsty, x, y), width, lineColor);
        }
        else if (figureType == 3){
            drawRectangle::draw(&tempDots, *new figure(firstx, firsty, x, y), width, lineColor, fillColor);
        }
        else if (figureType == 4){
            drawEllipse::draw(&tempDots, *new figure(firstx, 850 - firsty, x, 850 - y), width, lineColor, fillColor);
        }
    }
}

void paint::processMainMenu(int value) {
    switch (value) {
        case 1:
            clear();
            break;
        case 2:
            undo();
            break;
        case 3:
            redo();
            break;
    }
}

void paint::processWidthMenu(int value) {
    isSecond = false;
    width = value;
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
}

void paint::processColorMenu(int value) {
    isSecond = false;

    switch (value) {
        case 1:
            lineColor.setR(1);
            lineColor.setG(0);
            lineColor.setB(0);
            break;
        case 2:
            lineColor.setR(0);
            lineColor.setG(1);
            lineColor.setB(0);
            break;
        case 3:
            lineColor.setR(0);
            lineColor.setG(0);
            lineColor.setB(1);
            break;
    }
}

void paint::processFillColorMenu(int value) {
    isSecond = false;

    switch (value) {
        case 0:
            fillColor.setR(1);
            fillColor.setG(1);
            fillColor.setB(1);
            break;
        case 1:
            fillColor.setR(1);
            fillColor.setG(0);
            fillColor.setB(0);
            break;
        case 2:
            fillColor.setR(0);
            fillColor.setG(1);
            fillColor.setB(0);
            break;
        case 3:
            fillColor.setR(0);
            fillColor.setG(0);
            fillColor.setB(1);
            break;
    }
}

void paint::processFigureMenu(int value) {
    figureType = value;
    isSecond = false;
}

void paint::createOurMenu() {
    int colorMenu = glutCreateMenu(processColorMenu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);

    int fillColorMenu = glutCreateMenu(processFillColorMenu);
    glutAddMenuEntry("None", 0);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);

    int widthMenu = glutCreateMenu(processWidthMenu);
    glutAddMenuEntry("5px", 5);
    glutAddMenuEntry("10px", 10);
    glutAddMenuEntry("15px", 15);
    glutAddMenuEntry("20px", 20);

    int figureMenu = glutCreateMenu(processFigureMenu);
    glutAddMenuEntry("Point", 1);
    glutAddMenuEntry("Line", 2);
    glutAddMenuEntry("Rectangle", 3);
    glutAddMenuEntry("Ellipse", 4);
    glutAddMenuEntry("Polyline", 5);

    int main_id = glutCreateMenu(processMainMenu);
    glutAddSubMenu("Color", colorMenu);
    glutAddSubMenu("Fill color", fillColorMenu);
    glutAddSubMenu("Width", widthMenu);
    glutAddSubMenu("Figures", figureMenu);
    glutAddMenuEntry("Clear", 1);
    glutAddMenuEntry("Undo", 2);
    glutAddMenuEntry("Redo", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void paint::init() {
    /* background color */
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(lineColor.getR(), lineColor.getG(), lineColor.getB());

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 850, 0.0, 850);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void paint::FPS(int val) {
    glutPostRedisplay();
    glutTimerFunc(0, FPS, 0);
}

void paint::callbackInit() {
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutPassiveMotionFunc(passiveMotion);
    glutTimerFunc(17, FPS, 0);
}
