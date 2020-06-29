#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "View/mainwidget.h"

MainWindow::MainWindow(QWidget *parent, MainWidget& wg) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(&wg);
    emit xRotationChanged(5);
    emit yRotationChanged(30);
    emit zNearChanged(2);
    emit zFarChanged(30);
    emit zTransitionChanged(-15);
    emit fovChanged(45);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_xRotation_valueChanged(int position)
{
    emit xRotationChanged(position);
}

void MainWindow::on_yRotation_valueChanged(int value)
{
    emit yRotationChanged(value);
}

void MainWindow::on_fovCamera_valueChanged(int value)
{
    ui->lcdFov->display(value);
    emit fovChanged(value);
}

void MainWindow::on_zNearCamera_valueChanged(int value)
{
    ui->lcdZNear->display(value);
    emit zNearChanged(value);
}

void MainWindow::on_zFarCamera_valueChanged(int value)
{
    ui->lcdZFar->display(value);
    emit zFarChanged(value);
}

void MainWindow::on_zTransition_valueChanged(int value)
{
    ui->lcdZTrans->display(value);
    emit zTransitionChanged(value);
}
