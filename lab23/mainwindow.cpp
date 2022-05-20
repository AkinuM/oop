#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    figureType = "Line";
    scene = new paintScene(&figureType, ui->comboBox);
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLine_triggered()
{
    figureType = "Line";
    scene->setIsPolyline(false);
}

void MainWindow::on_actionUndo_triggered()
{
    scene->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    scene->redo();
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    scene->setIsSelected(true);
    selectedFigure = arg1;
    auto temp = scene->getFigures();
    if(prevFigure.size() != 0 ){
        temp->at(prevFigure.toStdString().back() - '0' - 1)->setLineColor(temp->at(prevFigure.toStdString().back() - '0' - 1)->getTempLineColor());
    }
    prevFigure = selectedFigure;
    temp->at((selectedFigure.toStdString().back() - '0') - 1)->setLineColor(QColor(24,167,181));
    scene->updateScene();
}

void MainWindow::on_pushButton_clicked()
{
    if(scene->getIsSelected()){
        scene->deleteFigure(selectedFigure, &prevFigure);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(scene->getIsSelected()){
        scene->setcopy(true);
    }
}

void MainWindow::on_actionRed_triggered()
{
    scene->setLineColor(QColor(255, 0, 0));
}

void MainWindow::on_actionGreen_triggered()
{
    scene->setLineColor(QColor(0, 255, 0));
}

void MainWindow::on_actionBlue_triggered()
{
    scene->setLineColor(QColor(0, 0, 255));
}

void MainWindow::on_action3_triggered()
{
    scene->setWidth(3);
}

void MainWindow::on_action6_triggered()
{
    scene->setWidth(6);
}

void MainWindow::on_action9_triggered()
{
    scene->setWidth(9);
}

void MainWindow::on_action12_triggered()
{
    scene->setWidth(12);
}

void MainWindow::on_actionRed_2_triggered()
{
    scene->setFillColor(QColor(255, 0, 0));
}

void MainWindow::on_actionGreen_2_triggered()
{
    scene->setFillColor(QColor(0, 255, 0));
}

void MainWindow::on_actionBlue_2_triggered()
{
    scene->setFillColor(QColor(0, 0, 255));
}

void MainWindow::on_actionEllipse_triggered()
{
    figureType = "Ellipse";
    scene->setIsPolyline(false);
}

void MainWindow::on_actionRectangle_triggered()
{
    figureType = "Rectangle";
    scene->setIsPolyline(false);
}

void MainWindow::on_actionPolygon_triggered()
{
    figureType = "Polygon";
    scene->setIsPolyline(false);
}

void MainWindow::on_actionPolyline_triggered()
{
    scene->setIsPolyline(true);
    figureType = "Line";
}

void MainWindow::slotSetFigureType()
{
    QAction *action = (QAction*) sender();
    figureType = action->text().toStdString();
}

void MainWindow::on_pushButton_3_clicked()
{
    QStringList listFiles;
    QDir dir(QApplication::applicationDirPath() + "/plugins/");
    if(dir.exists())
        listFiles = dir.entryList(QStringList("*"), QDir::Files);
    for(QString str: listFiles)
    {
        QPluginLoader loader(dir.absolutePath() + "/" +str);
        QObject *pobj = 0;
        pobj = qobject_cast<QObject*>(loader.instance());
        if(!pobj)
            continue;
        ICreator* pluginObject;
        pluginObject = qobject_cast<ICreator *>(pobj);
        scene->getFigureCreators()->push_back(pluginObject);
        QAction *action = new QAction(QString::fromStdString(pluginObject->getFigureType()), this);
        ui->menuFigure->addAction(action);
        connect(action, SIGNAL(triggered()), this, SLOT(slotSetFigureType()));
    }
}

void MainWindow::save()
{
    std::string output;
    for (auto figure : *scene->getFigures()){
        output.append(std::to_string(figure->getPoint1().x()));
        output.append("\n");
        output.append(std::to_string(figure->getPoint1().y()));
        output.append("\n");

        output.append(std::to_string(figure->getPoint2().x()));
        output.append("\n");
        output.append(std::to_string(figure->getPoint2().y()));
        output.append("\n");

        output.append(std::to_string(figure->getLineColor().red()));
        output.append("\n");
        output.append(std::to_string(figure->getLineColor().green()));
        output.append("\n");
        output.append(std::to_string(figure->getLineColor().blue()));
        output.append("\n");

        output.append(std::to_string(figure->getFillColor().red()));
        output.append("\n");
        output.append(std::to_string(figure->getFillColor().green()));
        output.append("\n");
        output.append(std::to_string(figure->getFillColor().blue()));
        output.append("\n");

        output.append(std::to_string(figure->getWidth()));
        output.append("\n");

        output.append(figure->getFigureType());
        output.append("\n");
    }
    std::ofstream out("output.txt");
    out << output;
    out.close();
}

void MainWindow::load()
{
    std::ifstream fin("output.txt");

    while (fin.peek() != EOF) {
        std::string line;
        std::getline(fin, line);
        float x = std::stof(line);
        std::getline(fin, line);
        float y = std::stof(line);

        QPoint point1 = QPoint(x, y);

        std::getline(fin, line);
        x = std::stof(line);
        std::getline(fin, line);
        y = std::stof(line);

        QPoint point2 = QPoint(x, y);

        std::getline(fin, line);
        int r = std::stoi(line);
        std::getline(fin, line);
        int g = std::stoi(line);
        std::getline(fin, line);
        int b = std::stoi(line);

        QColor lineColor = QColor(r, g, b);

        std::getline(fin, line);
        r = std::stoi(line);
        std::getline(fin, line);
        g = std::stoi(line);
        std::getline(fin, line);
        b = std::stoi(line);

        QColor fillcolor = QColor(r, g, b);

        std::getline(fin, line);
        int width = std::stoi(line);

        std::getline(fin, line);
        std::string figureType = line;

        unsigned long i = 0;
        for(auto creator : *scene->getFigureCreators()){
            if(creator->getFigureType() == figureType){
                break;
            }
            i++;
        }
        if(i != scene->getFigureCreators()->size()){
            scene->getFigures()->push_back(factory::createFigure(*scene->getFigureCreators(), point1, point2, lineColor, fillcolor, width, figureType));
            scene->getComboBox()->addItem(QString("figure" + QString::number(scene->getFigures()->size())));
        }
        else{
            QMessageBox error;
            error.setWindowTitle("Error");
            error.setText("Some figures were not loaded");
            error.exec();
        }
    }
        scene->updateScene();
}

void MainWindow::on_pushButton_4_clicked()
{
    save();
}

void MainWindow::on_pushButton_5_clicked()
{
    load();
}
