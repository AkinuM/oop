#include "paintscene.h"

paintScene::paintScene(int *figureType, QObject *parent) : QGraphicsScene(parent)
{
    lineColor.setRgb(0, 0, 0);
    fillColor.setRgb(1, 1, 1);
    width = 3;
    isSecond = false;
    this->figureType = figureType;
}

paintScene::~paintScene()
{

}

void paintScene::updateScene()
{
    clear();
    for(unsigned long i = 0; i < figures.size(); i++){
        addItem(figures[i]->draw());
    }
    for(unsigned long i = 0; i < tempFigures.size(); i++){
        addItem(tempFigures[i]->draw());
    }
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (isSecond){
        figures.push_back(factory::createFigure(previousPoint, event->scenePos(), lineColor, fillColor, width, *figureType));
        updateScene();
        isSecond = false;
    }
    else{
        previousPoint = event->scenePos();
        isSecond = true;
    }


}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    tempFigures.clear();
    if(isSecond){
        tempFigures.push_back(factory::createFigure(previousPoint, event->scenePos(), lineColor, fillColor, width, *figureType));
        updateScene();
    }
}
