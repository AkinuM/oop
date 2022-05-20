#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "figures/ifigure.h"
#include <QGraphicsView>
#include <paintscene.h>
#include <QPluginLoader>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_actionLine_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionRed_triggered();

    void on_actionGreen_triggered();

    void on_actionBlue_triggered();

    void on_action3_triggered();

    void on_action6_triggered();

    void on_action9_triggered();

    void on_action12_triggered();

    void on_actionRed_2_triggered();

    void on_actionGreen_2_triggered();

    void on_actionBlue_2_triggered();

    void on_actionEllipse_triggered();

    void on_actionRectangle_triggered();

    void on_actionPolygon_triggered();

    void on_actionPolyline_triggered();

    void slotSetFigureType();

    void on_pushButton_3_clicked();

    void save();

    void load();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    paintScene *scene;
    std::string figureType;
    QString selectedFigure;
    QString prevFigure;
};
#endif // MAINWINDOW_H
