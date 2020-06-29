#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>
#include "Model/cubefactory.h"
#include <memory>
#include "Model/cube.h"

class MainWindow;
class MainWidget;
class MgrView;
class Camera;
//class Cube;

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    void show() const;

signals:

public slots:

public:
    CubeFactory m_cubeFactory;
    Camera& m_camera;
    MainWidget& m_mainWidget;
    MainWindow& m_mainWindow;
    std::unique_ptr<Cube> m_cube;
    MgrView& m_mgrView;
};

#endif // STARTUP_H
