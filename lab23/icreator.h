#ifndef ICreator_H
#define ICreator_H
#include "ifigure.h"

class ICreator
{
protected:
    int figureType;
public:
    virtual IFigure* create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, int figureType);
};

#endif // ICreator_H
