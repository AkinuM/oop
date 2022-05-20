#ifndef ELLIPSECREATOR_H
#define ELLIPSECREATOR_H
#include "icreator.h"
#include "figures/ellipse.h"

class ellipseCreator : public ICreator
{
public:
    ellipseCreator();
    IFigure * create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType) override;
};

#endif // ELLIPSECREATOR_H
