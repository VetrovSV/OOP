#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
    this->username = ui->lineEdit->text();

    MainWindow *main_window = new MainWindow();
    main_window->setUsername( this->username );
    main_window->show();

    this->hide();
}

