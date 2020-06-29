#include "startup.h"
#include "View/mainwindow.h"
#include "View/mainwidget.h"
#include "MgrView/mgrview.h"
#include "Model/camera.h"

Startup::Startup() :
  QObject(),
  m_camera(*new Camera()),
  m_mainWidget(*new MainWidget(nullptr, m_camera)),
  m_mainWindow(*new MainWindow(nullptr, m_mainWidget)),
  m_cube(m_cubeFactory.createCube()),
  m_mgrView(*new MgrView(nullptr, m_mainWidget, m_mainWindow, m_camera, *m_cube))
{

}

void Startup::show() const
{
    m_mainWindow.show();
}
