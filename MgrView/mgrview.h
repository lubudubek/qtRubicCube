#ifndef MGRVIEW_H
#define MGRVIEW_H

#include <QObject>

class MgrView : public QObject
{
    Q_OBJECT
public:
    explicit MgrView(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MGRVIEW_H
