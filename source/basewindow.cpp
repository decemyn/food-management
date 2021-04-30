#include "ui_basewindow.h"
#include "headers/basewindow.h"
#include "headers/loginmenu.h"

BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BaseWindow)
{
    ui->setupUi(this);

}

BaseWindow::~BaseWindow()
{
    delete ui;
}


void BaseWindow::on_pushButton_clicked()
{
    // creating a new instance
    LoginMenu *login = new LoginMenu(this);
    login->show(); // this is how to display a new window



}


