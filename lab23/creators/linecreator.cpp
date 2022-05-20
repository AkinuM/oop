#include "linecreator.h"

lineCreator::lineCreator()
{
    figureType = "Line";
}

IFigure *lineCreator::create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType)
{
    return new Line(point1, point2, lineColor, fillColor, width, figureType);
}
