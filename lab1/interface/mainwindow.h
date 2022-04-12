#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <database.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(bank *bank1, bank *bank2, bank *bank3, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bank1_clicked();

    void on_bank2_clicked();

    void on_bank3_clicked();

private:
    Ui::MainWindow *ui;
    bank *bank1;
    bank *bank2;
    bank *bank3;
};

#endif // MAINWINDOW_H
