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
