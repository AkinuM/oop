#ifndef RECTANGLECREATOR_H
#define RECTANGLECREATOR_H
#include "icreator.h"
#include "figures/rectangle.h"

class rectangleCreator : public ICreator
{
public:
    rectangleCreator();
    IFigure * create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType) override;
};

#endif // RECTANGLECREATOR_H
