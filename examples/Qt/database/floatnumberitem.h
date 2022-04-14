#ifndef FLOATNUMBERITEM_H
#define FLOATNUMBERITEM_H

#include <QStandardItem>

/// Ячейка с цветом зависящим от содержимого
class FloatNumberItem : public QStandardItem
{
public:
    FloatNumberItem();
    FloatNumberItem(const QString &text );

    void setData(const QVariant &value, int role = Qt::UserRole + 1) override;
};

#endif // FLOATNUMBERITEM_H
