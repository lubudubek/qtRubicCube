#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    void show() const;

signals:

public slots:
};

#endif // STARTUP_H
