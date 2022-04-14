#ifndef FLOATNUMBERITEM_H
#define FLOATNUMBERITEM_H

#include <QStandardItem>

class FloatNumberItem : public QStandardItem
{
public:
    FloatNumberItem();
    FloatNumberItem(const QString &text );

    QVariant data(int role = Qt::UserRole + 1) const override;
};

#endif // FLOATNUMBERITEM_H
