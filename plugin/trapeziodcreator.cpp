#include "trapeziodcreator.h"

trapeziodCreator::trapeziodCreator()
{
    figureType = "Trapezoid";
}

IFigure *trapeziodCreator::create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType)
{
    return new Trapezoid(point1, point2, lineColor, fillColor, width, figureType);
}
