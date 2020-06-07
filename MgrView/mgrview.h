#ifndef MGRVIEW_H
#define MGRVIEW_H

#include <QObject>

class MainWidget;
class MainWindow;

class MgrView : public QObject
{
    Q_OBJECT
public:
    explicit MgrView(QObject *parent,
                     MainWidget& widget,
                     MainWindow& engine);

signals:

public slots:

private:
    MainWidget& m_mainWidget;
    MainWindow& m_window;
};

#endif // MGRVIEW_H
