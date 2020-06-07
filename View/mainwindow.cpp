#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "View/mainwidget.h"

MainWindow::MainWindow(QWidget *parent, MainWidget& wg) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(&wg);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_xRotation_sliderMoved(int position)
{
    emit xRotationChanged(position);
}

void MainWindow::on_yRotation_valueChanged(int value)
{
    emit yRotationChanged(value);
}
