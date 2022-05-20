#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "../lab23/figures/ifigure.h"
#include <vector>
#include <QPen>

class Trapezoid : public IFigure
{
public:
    Trapezoid(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType);
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

#endif // TRAPEZOID_H
