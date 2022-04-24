#include "line.h"

Line::Line(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width)
{
    this->point1 = point1;
    this->point2 = point2;
    this->lineColor = lineColor;
    this->fillColor = fillColor;
    this->width = width;
}

QGraphicsItem* Line::draw()
{
    QPen pen;
    pen.setColor(lineColor);
    pen.setWidth(width);
    QGraphicsLineItem* line = new QGraphicsLineItem(point1.x(), point1.y(), point2.x(), point2.y());
    line->setPen(pen);
    return line;
}
