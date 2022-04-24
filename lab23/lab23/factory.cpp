#include "factory.h"

std::unique_ptr<IFigure> factory::createFigure(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, int figureType)
{
    switch(figureType){
    case 1:
        return std::unique_ptr<IFigure>(new Line(point1, point2, lineColor, fillColor, width));
        break;
    }
}
