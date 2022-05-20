#include "ellipsecreator.h"

ellipseCreator::ellipseCreator()
{
    figureType = "Ellipse";
}

IFigure *ellipseCreator::create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType)
{
    return new Ellipse(point1, point2, lineColor, fillColor, width, figureType);
}
