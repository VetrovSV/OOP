#include <QFileDialog>          // библиотека для создания диалоговых окон
#include <QTextStream>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"


const QString LoremIpsum[] = {"Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat",
                       "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur",
                       "Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.",
                       "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua"
                       };


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/// загрузка содержимого файла в многострочное поле ввода textEdit
void MainWindow::on_actionopen_triggered(){
    // получение пути к домашней папке пользователя
    QString home = QDir::homePath();

    
    // функция getOpenFileName создаёт диалоговое окно для открытия существующего файла
    // Параметры: 
    // указатель на объект родительского окна
    // Заголовок окна
    // Путь к паке по умолчанию
    // Фильтр по типам файлов
    // После закрытия окна функция вернёт абсолютное имя файла, если он был выбран
    QString fileName = QFileDialog::getOpenFileName(this,
        "Open Text File", home, "Text Files (*.txt)");
    
    // Чтение из файла в многострочное поле ввода
    QFile f(fileName);
    if ( f.open(QFile::ReadOnly) ){
        QTextStream s(&f);

        ui->textEdit->setText( s.readAll() );
    }
}


/// сохранение содержимого многострочного поля ввода textEdit в файл
void MainWindow::on_actionsave_triggered(){
    // получение пути к домашней папке пользователя
    QString home = QDir::homePath();
    // QDir::currentPath() -- путь к текущей папке
    // QDir::tempPath() -- путь к системной временной папке
    // QCoreApplication::applicationDirPath() -- путь к папке с запущенной программой

    
    // функция getSaveFileName создаёт диалоговое окно для выбора имени существующего файла или ввода нового имени
    // возвращает абсолютный путь к файлу
    QString fileName = QFileDialog::getSaveFileName(nullptr,
        "Open Image", home);
    
    // запись в файл 
    QFile f(fileName);
    if ( f.open(QFile::WriteOnly) ){
        QTextStream s(&f);

        s << ui->textEdit->toPlainText();
        f.close();
    }
}


void MainWindow::on_action_exit_triggered()
{
    // TODO:
}

void MainWindow::on_actionread_only_triggered()
{
    ui->textEdit->setReadOnly( !ui->textEdit->isReadOnly() );
}


/// очистка многострочного поля ввода
void MainWindow::on_actionclear_triggered()
{
    ui->textEdit->clear();
}


/// добавляет случайный текст
void MainWindow::on_actionlorem_ipsum_triggered()
{
    QString text;
    QStringList words = LoremIpsum[rand()%4].split(" ");

    for (int i = 0; i < 5 + rand() % (words.size()); ++i) {
        text += words[ rand()%words.size()] + " ";
    }

    // ui->textEdit->append( text );        // добавление обыкновенного текста

    switch ( rand()%5 ){
        case 0: text = "<h1>" + text + "</h1>";
        case 1: text = "<code>" + text + "</code>";
        case 2: text = "<a href=#>" + text + "</a>";
    }

    ui->textEdit->insertHtml(text);         // вставка html в позицую курсора
}

void MainWindow::on_actionabout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.exec();
}

