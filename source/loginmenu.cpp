#include "headers/loginmenu.h"
#include "ui_loginmenu.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QtGui>

LoginMenu::LoginMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginMenu)
{
    ui->setupUi(this);
    this->parent = parent;
    parent->hide();


}

void LoginMenu::closeEvent(QCloseEvent *event){
    this->parent->show();

}



LoginMenu::~LoginMenu()
{
    delete ui;
}
