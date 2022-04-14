//#include <QCheckBox>
#include <QFile>

#include "floatnumberitem.h"
#include "modelstuds.h"

ModelStuds::ModelStuds(){
    // задание названий для столбцов
    this->setHorizontalHeaderLabels( {"Surname", "UML", "Model", "UI", "Controller"} );
    // setHorizontalHeaderLabels принимает QStringList
}

/// добавляет строку со случайными данными
void ModelStuds::add_random_row_simple(){
    static QString surnames[] = {"Sorokin", "Raykov", "Frolova"};       // для выбора случайных фамилий

    // для создания новой строки таблицы
    QList<QStandardItem*> row;

    // добавление нового элемента в строку (список)
    row << new QStandardItem( surnames[rand()%3] );
    //row.append( new QStandardItem( surnames[rand()%3] );              // аналогично верхней записи

    row << new QStandardItem( QString::number(     rand()%2 ) ) ;       // uml
    row << new QStandardItem( QString::number(1.0*(rand()%100)/100) );  // model
    row << new QStandardItem( QString::number(1.0*(rand()%100)/100) );  // ui
    row << new QStandardItem( QString::number(1.0*(rand()%100)/100) );  // contr

    // добавление строки в таблицу
    this->appendRow( row );
}


/// добавляет строку со случайными данными
void ModelStuds::add_random_row(){
    const unsigned n = 3;
    static QString surnames[n] = {"Ivanov", "Petrov", "Sidorov"};
    QList<QStandardItem*> *row = new QList<QStandardItem*>();

    *row << new QStandardItem( surnames[rand()%n] );
    QStandardItem *uml_checkbox = new QStandardItem();
    uml_checkbox->setCheckable(true);
    uml_checkbox->setCheckState( rand()%2 ? Qt::Checked : Qt::Unchecked );
    *row << uml_checkbox;
    QString ss;
    *row << new FloatNumberItem( QString::number(1.0*(rand()%1000)/1000));       // model
    *row << new QStandardItem( QString::number(1.0*(rand()%10)/10) );       // ui
    *row << new QStandardItem( QString::number(1.0*(rand()%10)/10) );       // contr

    row->at(2)->setTextAlignment(Qt::AlignRight);
    row->at(2)->setData("балл", Qt::ToolTipRole);
    row->at(3)->setData(QColor(255,0,0), Qt::BackgroundRole);

    this->appendRow( *row );
}


bool ModelStuds::open(const QString &filename){
    this->clear();              // очистка всех данных
    QFile f(filename);
    // открыть файл для Чтения как Текстовый
    f.open( QIODevice::ReadOnly | QIODevice::Text );
    // todo: is open?
    QTextStream fs(&f);                     // обёртка над QFile для удобной работы со строковым потоком

    QString buff;
    buff = fs.readLine();                   // чтение первой строки -- заголовка таблицы
    QStringList l = buff.split(", ");       // разбить но список строк по разделителю ", "  (см. CSV файл)

    this->setHorizontalHeaderLabels( l );   // задать заголовок

    // чтение остальных строк файла
    while ( fs.readLineInto(&buff) ){   // пока строка читается ...
        QList<QStandardItem*> row;      // для создания новой строки таблицы

        QStringList slist = buff.split(", ");

        // создание списка из QStandardItem на основе списка из QString
        for (int i = 0; i < slist.size(); i++ ){
             row << new QStandardItem( slist[i] );}

        this->appendRow(row);
    }

    f.close();
    // TODO: выдавать true если удалось прочитать данные
}

// для примера: сортировка по первой колонке
void ModelStuds::sort_names(){
    this->sort(0);
}


bool ModelStuds::save(const QString &filename)
{
    QFile f(filename);
    // открыть файл для Записи как Текстовый
    f.open( QIODevice::WriteOnly | QIODevice::Text );
    // TODO: проверка isopen

    QTextStream fs(&f);

    // запись названий столбцов
    for (int i = 0; i< this->columnCount() ;i++ ) {
        QStandardItem *it = this->takeHorizontalHeaderItem(i);
        fs << it->text() << ", ";
    }
    // TODO: не добавлять запятую после последнего элемента
    fs << "\n";

    // запись данных из таюлицы в файл
    for (unsigned i = 0; i < this->rowCount() ; i++ ) {
         for (unsigned j = 0; j < this->columnCount() ; j++ ){
            fs << this->item(i,j)->text() << ", ";
        }   // TODO: не добавлять запятую после последнего элемента

        fs << "\n";
    }

    f.close();
    // TODO: выдавать true если удалось записать
}
