#ifndef LINECREATOR_H
#define LINECREATOR_H
#include "icreator.h"
#include "line.h"

class lineCreator : ICreator
{
public:
    lineCreator();
    IFigure * create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, int figureType) override;
};

#endif // LINECREATOR_H
