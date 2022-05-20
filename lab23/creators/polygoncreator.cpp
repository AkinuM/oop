#include "polygoncreator.h"

polygonCreator::polygonCreator()
{
    figureType = "Polygon";
}

IFigure *polygonCreator::create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType)
{
    return new Polygon(point1, point2, lineColor, fillColor, width, figureType);
}
