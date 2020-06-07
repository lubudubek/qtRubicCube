#include "mgrview.h"
#include "View/mainwindow.h"
#include "View/mainwidget.h"
#include "qdebug.h"

MgrView::MgrView(QObject *parent,
                 MainWidget& widget,
                 MainWindow& window) :
    QObject(parent),
    m_mainWidget(widget),
    m_window(window)
{
    qDebug() << "MgrView construct";
    connect(&m_window, &MainWindow::xRotationChanged,
        &widget, &MainWidget::onXRotationChanged);
    connect(&m_window, &MainWindow::yRotationChanged,
        &widget, &MainWidget::onYRotationChanged);
}
