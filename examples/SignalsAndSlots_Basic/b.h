#ifndef B_H
#define B_H

#include <iostream>
using namespace std;

#include <QObject>

class B : public QObject
{
    Q_OBJECT
public:
    explicit B(QObject *parent = nullptr);

signals:

public slots:
    void my_slot();
};

#endif // B_H
