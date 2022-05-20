#ifndef POLYGON_H
#define POLYGON_H

#pragma once
#include "figures/ifigure.h"
#include <vector>
#include <QPen>

class Polygon : public IFigure
{
public:
    Polygon(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType);
    QGraphicsItem* draw() override;
    int getWidth() const override;
    void setWidth(int value) override;
    QColor getLineColor() const override;
    void setLineColor(const QColor &value) override;
    QColor getTempLineColor() const override;
    void setTempLineColor(const QColor &value) override;
    QPointF getPoint1() const override;
    QPointF getPoint2() const override;
    void setPoint1(const QPointF &value) override;
    void setPoint2(const QPointF &value) override;
    std::string getFigureType() const override;
    QColor getFillColor() const override;
};

#endif // POLYGON_H
