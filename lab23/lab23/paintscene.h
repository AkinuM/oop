#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <factory.h>

class paintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintScene(int *figureType, QObject *parent = 0);
    ~paintScene();

private:
    QPointF previousPoint;
    bool isSecond;
    std::vector<std::unique_ptr<IFigure>> figures;
    std::vector<std::unique_ptr<IFigure>> tempFigures;
    QColor lineColor;
    QColor fillColor;
    int width;
    int *figureType;

private:
    void updateScene();
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PAINTSCENE_H
