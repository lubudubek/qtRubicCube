#include "mgrview.h"
#include "View/mainwindow.h"
#include "View/mainwidget.h"
#include "qdebug.h"
#include "Model/camera.h"


MgrView::MgrView(QObject *parent,
                 MainWidget& widget,
                 MainWindow& window,
                 Camera& camera,
                 Cube& cube) :
    QObject(parent),
    m_mainWidget(widget),
    m_window(window),
    m_camera(camera),
    m_cube(cube)
{
    qDebug() << "MgrView construct";
    connect(&m_window, &MainWindow::xRotationChanged,
            &camera, &Camera::onAngleXChanged);
    connect(&m_window, &MainWindow::yRotationChanged,
            &camera, &Camera::onAngleYChanged);
    connect(&m_window, &MainWindow::zFarChanged,
            &camera, &Camera::onZFarChanged);
    connect(&m_window, &MainWindow::zNearChanged,
            &camera, &Camera::onZNearChanged);
    connect(&m_window, &MainWindow::fovChanged,
            &camera, &Camera::onFovChanged);
    connect(&m_window, &MainWindow::zTransitionChanged,
            &camera, &Camera::onZTranslationChanged);
    connect(&m_mainWidget, &MainWidget::openGlInitialized,
            &m_cube, &Cube::initCubeGeometry);
    connect(&m_mainWidget, &MainWidget::updateCube,
            &m_cube, &Cube::UpdateUniforms);
}
