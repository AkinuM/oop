#ifndef LINECREATOR_H
#define LINECREATOR_H
#include "icreator.h"
#include "figures/line.h"

class lineCreator : public ICreator
{
public:
    lineCreator();
    IFigure * create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType) override;
};

#endif // LINECREATOR_H
