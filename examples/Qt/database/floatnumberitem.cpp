#include "floatnumberitem.h"

FloatNumberItem::FloatNumberItem()
{

}

FloatNumberItem::FloatNumberItem(const QString &text):QStandardItem(text){
    if (this->data(Qt::EditRole).toFloat() < 0.5)
    this->QStandardItem::setData(QColor(255,0,0), Qt::BackgroundRole);
    else
    this->QStandardItem::setData(QColor(0,255,0), Qt::BackgroundRole);
}

QVariant FloatNumberItem::data(int role) const{
//    if (role == Qt::DecorationRole){
//        if (this->data().toFloat() < 0.5)
//        return (QColor(Qt::red));
//        else return (QColor(Qt::green));
//    }
    return this->QStandardItem::data(role);
}
