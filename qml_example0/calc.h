#ifndef CALC_H
#define CALC_H

#include <QObject>


// Вычисление функции нормального распределения и её аргумента
class Calc : public QObject
{
    Q_OBJECT

    // Для того чтобы QML код мог изменять значения полей требуется указать названия
    // соответствующих методов  (READ - получить значение поля, WRITE - ...)
    // NOTIFY - название согнала вызываемого при изменении значения
    Q_PROPERTY(double pvalue READ pvalue WRITE setPvalue NOTIFY pvalueChanged)
    Q_PROPERTY(double z READ z WRITE setZ NOTIFY zChanged)

    double _z;
    double _p;

public:
    explicit Calc(QObject *parent = nullptr);
    double pvalue() const;  // значение функции распределения
    double z() const;       // значение аргумента функции распределения

    void setPvalue(double p1);
    void setZ(double z1);

signals:
    void pvalueChanged();
    void zChanged();
};

#endif // CALC_H
