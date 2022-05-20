#include "factory.h"

IFigure* factory::createFigure(std::vector<ICreator*> figureCreators, QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType)
{
    for (auto creator : figureCreators){
        if (creator->getFigureType() == figureType){
            return creator->create(point1, point2, lineColor, fillColor, width, figureType);
        }
    }
}
