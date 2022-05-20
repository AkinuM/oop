#include "trapezoid.h"

Trapezoid::Trapezoid(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType)
{
    this->point1 = point1;
    this->point2 = point2;
    this->lineColor = lineColor;
    this->fillColor = fillColor;
    this->width = width;
    tempLineColor = lineColor;
    this->figureType = figureType;
}

QGraphicsItem* Trapezoid::draw()
{
    QPen pen;
    pen.setColor(lineColor);
    pen.setWidth(width);
    QPointF upper_point, low_point;
    QPointF right_point, left_point;
    if (point1.y() > point2.y()) {
        upper_point = point1;
        low_point = point2;
    } else {
        upper_point = point2;
        low_point = point1;
    }

    if (point1.x() > point2.x()) {
        left_point = point2;
        right_point = point1;
    } else {
        left_point = point1;
        right_point = point2;
    }
    QPointF point1, point2, point3, point4;
    point1.setX((right_point.x() - left_point.x()) / 4 + left_point.x());
    point2.setX(-(right_point.x() - left_point.x()) / 4 + right_point.x());
    point1.setY(upper_point.y());
    point2.setY(upper_point.y());
    point3.setX(right_point.x());
    point3.setY(low_point.y());
    point4.setX(left_point.x());
    point4.setY(low_point.y());
    QVector<QPointF> qpoints;
    qpoints << point1;
    qpoints << point2;
    qpoints << point3;
    qpoints << point4;
    QGraphicsPolygonItem* trapezoid = new QGraphicsPolygonItem(QPolygonF(qpoints));
    trapezoid->setPen(pen);
    if(fillColor != QColor(1, 1, 1)){
        trapezoid->setBrush(QBrush(fillColor));
    }
    return trapezoid;
}

int Trapezoid::getWidth() const
{
    return width;
}

void Trapezoid::setWidth(int value)
{
    width = value;
}

QColor Trapezoid::getLineColor() const
{
    return lineColor;
}

void Trapezoid::setLineColor(const QColor &value)
{
    lineColor = value;
}

QColor Trapezoid::getTempLineColor() const
{
    return tempLineColor;
}

void Trapezoid::setTempLineColor(const QColor &value)
{
    tempLineColor = value;
}

QPointF Trapezoid::getPoint2() const
{
    return point2;
}

QPointF Trapezoid::getPoint1() const
{
    return point1;
}

void Trapezoid::setPoint2(const QPointF &value)
{
    point2 = value;
}

void Trapezoid::setPoint1(const QPointF &value)
{
    point1 = value;
}

QColor Trapezoid::getFillColor() const
{
    return fillColor;
}

std::string Trapezoid::getFigureType() const
{
    return figureType;
}
