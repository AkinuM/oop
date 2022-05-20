#ifndef TRAPEZIODCREATOR_H
#define TRAPEZIODCREATOR_H

#include "plugin_global.h"
#include "../lab23/creators/icreator.h"
#include "../lab23/figures/line.h"
#include "trapezoid.h"

class PLUGIN_EXPORT trapeziodCreator : public ICreator
{
    Q_OBJECT
    Q_INTERFACES(ICreator)
    Q_PLUGIN_METADATA(IID "com.mysoft.Application.icreator" FILE "icreator.json")
public:
    trapeziodCreator();
    IFigure * create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType) override;
};

#endif // TRAPEZIODCREATOR_H
