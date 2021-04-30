#ifndef BASEWINDOW_H
#define BASEWINDOW_H
#include <QMainWindow>
#include <QPixmap>
#include "headers/loginmenu.h"
QT_BEGIN_NAMESPACE
namespace Ui { class BaseWindow; }
QT_END_NAMESPACE

class BaseWindow : public QMainWindow
{
    Q_OBJECT

public:
    BaseWindow(QWidget *parent = nullptr);
    ~BaseWindow();

private slots:
    void on_pushButton_clicked();

private:

    Ui::BaseWindow *ui;

};
#endif // BASEWINDOW_H
