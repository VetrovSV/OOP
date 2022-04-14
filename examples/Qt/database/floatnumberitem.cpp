#include "floatnumberitem.h"

FloatNumberItem::FloatNumberItem(){

}

FloatNumberItem::FloatNumberItem(const QString &text):
    QStandardItem(text)                                 // вызов конструктора базового класса
{
}

/// переопределённый метод изменения данных: при изменении меняет цвет фона в зависимости от значения
void FloatNumberItem::setData(const QVariant &value, int role){

    // вызов метода базовго класса
    this->QStandardItem::setData(value, role);

    // проверка значения (Qt::EditRole -- значение отображаемое при редактировании)
    if (this->data(Qt::EditRole).toFloat() < 0.5)
        // раскраска фона
        this->QStandardItem::setData(QColor(255,0,0), Qt::BackgroundRole);
    else
        // раскраска фона
        this->QStandardItem::setData(QColor(0,255,0), Qt::BackgroundRole);

    // вызов сигнала об изменении данных; нужно чтобы элементы интерфеса перерисовали ячейку
    emit emitDataChanged();
}


