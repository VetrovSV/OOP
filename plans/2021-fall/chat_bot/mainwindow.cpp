#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "chatbot.h"

#include <regex>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connect( ui->lineEdit_user, &QLineEdit::returnPressed,
//             this,              &MainWindow::on_pushButton_send_clicked );
//    AbstractChatBot *bot;
    bot = dynamic_cast<ChatBot*>(new ChatBot());

    // Добавление в динамический массив бота regex для запросов пользователя и адресов функции для их обработки
    // add_answer в AbstractChatBot не объявлен (стоит добавить?),
    // а bot -- указатель на AbstractChatBot
    // поэтому чтобы вызвать метод add_answer преобразуем (динамически) bot в указатель на ChatBot
    dynamic_cast<ChatBot*>(bot)->add_answer( std::regex("\\wello"),            &hello );
    dynamic_cast<ChatBot*>(bot)->add_answer( std::regex("calc"),               &calc );

    // "(weather)|(погода)" - weather или погода
    dynamic_cast<ChatBot*>(bot)->add_answer( std::regex("(weather)|(погода)"), &weather );

    dynamic_cast<ChatBot*>(bot)->add_answer( std::regex("ip"), &get_ip );
}

MainWindow::~MainWindow()
{
    delete ui;
    delete bot;
}

const QString &MainWindow::getUsername() const
{
    return username;
}

void MainWindow::setUsername(const QString &newUsername)
{
    username = newUsername;
}


void MainWindow::on_pushButton_send_clicked()
{
    ui->plainTextEdit_history->appendPlainText(
                this->username + " : " +
                ui->lineEdit_user->text()
                );

    std::string input = ui->lineEdit_user->text().toLower().toStdString();
    std::string answer = bot->answer( input );


    ui->plainTextEdit_history->appendPlainText(
                "bot: " + QString::fromStdString( answer )
                );
}

void MainWindow::keyPressEvent(QKeyEvent *e){

    if ((e->key() == Qt::Key_F5 ) || (e->key() == Qt::Key_F9 ))
//        if ((e->key() == Qt::Key_Return ) && e->modifiers() == Qt::CTRL)
        on_pushButton_send_clicked();

}

