#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sign_up_menu.h"

MainWindow::MainWindow(bank *bank1, bank *bank2, bank *bank3, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->bank1 = bank1;
    this->bank2 = bank2;
    this->bank3 = bank3;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bank1_clicked()
{
    hide();
    sign_up_menu su_menu(bank1);
    su_menu.setModal(1);
    su_menu.exec();
}

void MainWindow::on_bank2_clicked()
{
    hide();
    sign_up_menu su_menu(bank2);
    su_menu.setModal(1);
    su_menu.exec();
}

void MainWindow::on_bank3_clicked()
{
    hide();
    sign_up_menu su_menu(bank3);
    su_menu.setModal(1);
    su_menu.exec();
}
