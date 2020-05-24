#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "mainwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MainWidget wg;
};

#endif // MAINWINDOW_H
