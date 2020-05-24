#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent) :
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
