#ifndef MYTHREA_H
#define MYTHREA_H

#include <QObject>
#include <QThread>

class myThrea : public QObject, public QThread
{
    Q_OBJECT
public:
    explicit myThrea(QObject *parent = nullptr);

signals:

};

#endif // MYTHREA_H
