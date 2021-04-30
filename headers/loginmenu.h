#ifndef LOGINMENU_H
#define LOGINMENU_H

#include <QMainWindow>
#include <QDialog>
#include <QWidget>

namespace Ui {
class LoginMenu;
}

class LoginMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginMenu(QWidget *parent = nullptr);
    ~LoginMenu();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::LoginMenu *ui;
    QWidget *parent;
};

#endif // LOGINMENU_H
