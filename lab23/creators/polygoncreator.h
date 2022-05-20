#ifndef POLYGONCREATOR_H
#define POLYGONCREATOR_H
#include "icreator.h"
#include "figures/polygon.h"

class polygonCreator : public ICreator
{
public:
    polygonCreator();
    IFigure * create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType) override;
};

#endif // POLYGONCREATOR_H
