#ifndef IFIGURE_H
#define IFIGURE_H

#include <QGraphicsItem>

class IFigure
{
protected:
    QPointF point1;
    QPointF point2;
    QColor lineColor;
    QColor fillColor;
    int width;
public:
    virtual QGraphicsItem* draw() = 0;
    virtual ~IFigure() = default;
};

#endif // IFIGURE_H
