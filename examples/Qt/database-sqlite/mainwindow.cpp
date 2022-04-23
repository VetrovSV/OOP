#include <QFileDialog>
#include <QSqlQuery>
#include <QtSql/QSqlRecord>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // включить сортировку по клику на загловок таблицы
    ui->tableView->setSortingEnabled(true);

    // объект для соединения с БД (файловыми и серверными)
    db = QSqlDatabase::addDatabase("QSQLITE");          // создание объекта, который работает именно с SQLite -- файловой БД

    // относительный путь из каталога сборки в папку с исходниками
    // TODO: хранить файл БД в каталоге сборки
    db.setDatabaseName("../database-sqlite/studs_db.sqlite");
    // если файла не существует, то он будет создан.
    // но для дальнейшей работы model нужно создать таблицу

    if (!db.open()){
        qDebug() << "OpenDB: Error";}

    // создание модели для хранения о обработки данных
    model = new QSqlTableModel(this, db);

// создание таблицы
//   // объект для выполнения SQL запросов
//   QSqlQuery query = QSqlQuery(db);
//   // создание таблицы
//   query.exec("create table students\
//(\
//    id         integer\
//        constraint table_name_pk\
//            primary key autoincrement,\
//    name       text not null,\
//    UML        real,\
//    Model      real,\
//    ui         real,\
//    Controller real\
//);");



    // имя существующей таблицы
    model->setTable("students");

    model->select();        // нужно вручную вызывать чтение всех данныех из БД


    // Связывание объекта с табличными данными  -- модели, на основе QStandardItemModel
    // и таблицы на форме -- представления, QTableView (не путать с QTableWidget);
    ui->tableView->setModel(model);
    // все изменения таблице будут автоматически вносится в модель (но не в файл!) и наоборот
}

MainWindow::~MainWindow()
{
    delete ui;
    model->submitAll();     // записать все изменения перед закрытием программы
    db.close();
}

/// добавление случайной строки в таблицу
void MainWindow::on_pushButton_add_rnd_clicked(){
    // после добавления таблица автоматически отобразит новые данные
//    model.add_random_row();
}

void MainWindow::on_pushButton_add_rnd_simple_clicked(){
    QSqlRecord record = model->record();

    // TODO: вынести в отдельный класс?
    QString names[] = {"Sorokin", "Raykov", "Frolova"};
    // данные не добавятся, если insert не корректный
    record.setValue("Name",       names[rand()%3] );
    record.setValue("UML",        QVariant(1.0/(rand()%10+1)) );
    record.setValue("Model",      QVariant(1.0/(rand()%10+1)) );
    record.setValue("Controller", QVariant(1.0/(rand()%10+1)) );
    record.setValue("UI",         QVariant(1.0/(rand()%10+1)) );

    model->insertRecord(-1, record);            // -1  вставка в конец

    model->select();
}

/// сохранение данных в файл (CSV)
void MainWindow::on_actionSave_triggered(){
    model->submitAll(); // записывает все изменения из БД в файл
}

// TODO: SaveAs
// QFileDialog dialog;

/// загрузка данных из CSV файла в модель
void MainWindow::on_actionOpen_triggered(){
// TODO: Open
// QFileDialog dialog;

}


