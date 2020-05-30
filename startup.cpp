#include "startup.h"
#include "View/mainwindow.h"
#include "View/mainwidget.h"
#include "MgrView/mgrview.h"
#include "geometryengine.h"

Startup::Startup() :
  QObject(),
  m_mainWidget(*new MainWidget()),
  m_mainWindow(*new MainWindow(nullptr, m_mainWidget)),
  m_geometryEngine(*new GeometryEngine()),
  m_mgrView(*new MgrView())
{
    connect(&m_mainWidget, &MainWidget::openGlInitialized,
            &m_geometryEngine, &GeometryEngine::initCubeGeometry);
}

void Startup::show() const
{
    m_mainWindow.show();
}
