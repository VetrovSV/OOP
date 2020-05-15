#include <QDir>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // TODO: загрузка истории чата из файла (если такой есть)

    // Файлы можно хранить в особой папке и всегда загружать, например, последний файл
    // Пример:
    //    QDir chat_dir("chat history");
    //    QStringList files = chat_dir.entryList(); // получить список имён файлов папки chat history

}

MainWindow::~MainWindow()
{
    delete ui;

    // TODO: ваш код, сохранение истории чата в файл

}

// обработка сообщения пользователя, ответ чат-бота, вывод в окно
void MainWindow::on_pushButton_send_clicked()
{
    std::string reply = bot->reply( "" );
    // TODO: ваш код
}
