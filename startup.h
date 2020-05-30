#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>

class MainWindow;
class MainWidget;
class GeometryEngine;
class MgrView;

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    void show() const;

signals:

public slots:

public:
    MainWidget& m_mainWidget;
    MainWindow& m_mainWindow;
    GeometryEngine& m_geometryEngine;
    MgrView& m_mgrView;
};

#endif // STARTUP_H
