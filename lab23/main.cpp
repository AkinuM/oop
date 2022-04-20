#include "paint.h"

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(850, 850);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Paint");
    paint::callbackInit();
    paint::init();
    paint::createOurMenu();
    glutMainLoop();
    return (0);
}