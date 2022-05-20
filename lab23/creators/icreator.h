#ifndef ICreator_H
#define ICreator_H
#include "../figures/ifigure.h"

class ICreator : public QObject
{
protected:
    std::string figureType;
public:
    virtual ~ICreator() = default;
    virtual IFigure* create(QPointF point1, QPointF point2, QColor lineColor, QColor fillColor, int width, std::string figureType) = 0;
    std::string getFigureType() const{
        return figureType;
    };
};

Q_DECLARE_INTERFACE(ICreator, "com.mysoft.Application.icreator")

#endif // ICreator_H
