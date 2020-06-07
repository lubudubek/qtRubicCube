#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include "mainwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent, MainWidget& wg);
    ~MainWindow();

private slots:
    void on_xRotation_sliderMoved(int position);

    void on_yRotation_valueChanged(int value);

signals:
    void xRotationChanged(int position);
    void yRotationChanged(int position);

private:
    Ui::MainWindow *ui;
    GeometryEngine engine;
};

#endif // MAINWINDOW_H
