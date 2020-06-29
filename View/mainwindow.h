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
    void on_xRotation_valueChanged(int position);
    void on_yRotation_valueChanged(int value);

    void on_fovCamera_valueChanged(int value);
    void on_zNearCamera_valueChanged(int value);
    void on_zFarCamera_valueChanged(int value);

    void on_zTransition_valueChanged(int value);

signals:
    void xRotationChanged(int position);
    void yRotationChanged(int position);
    void fovChanged(float position);
    void zNearChanged(int position);
    void zFarChanged(int position);
    void zTransitionChanged(int position);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
