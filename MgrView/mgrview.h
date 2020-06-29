#ifndef MGRVIEW_H
#define MGRVIEW_H

#include <QObject>

class MainWidget;
class MainWindow;
class Camera;
class Cube;

class MgrView : public QObject
{
    Q_OBJECT
public:
    explicit MgrView(QObject *parent,
                     MainWidget& widget,
                     MainWindow& engine,
                     Camera& m_camera,
                     Cube& cube);

signals:

public slots:

private:
    MainWidget& m_mainWidget;
    MainWindow& m_window;
    Camera& m_camera;
    Cube& m_cube;
};

#endif // MGRVIEW_H
