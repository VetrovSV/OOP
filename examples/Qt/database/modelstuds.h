#ifndef MODELSTUDS_H
#define MODELSTUDS_H

#include <QStandardItemModel>

/// Модель. Хранит и обрабатывает данные
class ModelStuds : public QStandardItemModel{
    // QStandardItemModel уже умеет хранить данные в табличной форме
    // обратиться к ячейке item(i,j), setItem(i,j, <QStandardItem*> )
    // ячейка -- это указатель но объект типа QStandardItem
        // QStandardItem содержит данные и настройки их отображения

public:
    ModelStuds();

    /// добавляет строку со случайными данными
    void add_random_row_simple();
    /// добавляет строку со случайными данными; задаёт свойства отображения некоторых ячеек
    void add_random_row();

    bool save(const QString& filename);
    bool open(const QString &filename);

    // для примера: сортировка по первой колонке
    void sort_names();

};

#endif // MODELSTUDS_H
