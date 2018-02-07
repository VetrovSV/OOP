#ifndef A_H
#define A_H

#include <QObject>

class A : public QObject
{
    Q_OBJECT
public:
    explicit A(QObject *parent = nullptr);

signals:
    void my_signal();

public slots:
};

#endif // A_H
