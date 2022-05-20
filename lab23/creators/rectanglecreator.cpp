#include "rectanglecreator.h"

rectangleCreator::rectangleCreator()
{
    figureType = "Rectangle";
}

IFigure *rectangleCreator::create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType)
{
    return new Rectangle(point1, point2, lineColor, fillColor, width, figureType);
}
