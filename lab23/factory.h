#ifndef FACTORY_H
#define FACTORY_H

#pragma once
#include <memory>
#include <creators/linecreator.h>
#include <creators/rectanglecreator.h>
#include <creators/ellipsecreator.h>
#include <creators/polygoncreator.h>

class factory
{
public:
    static IFigure* createFigure(std::vector<ICreator*> figureCreators, QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType);
};

#endif // FACTORY_H
