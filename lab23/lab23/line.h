#ifndef LINE_H
#define LINE_H

#pragma once
#include "ifigure.h"
#include <vector>
#include <QPen>

class Line : public IFigure
{
public:
    Line(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width);
    QGraphicsItem* draw() override;
};

#endif // LINE_H
