#ifndef STATISTICSMENU_H
#define STATISTICSMENU_H

#include <QMainWindow>

namespace Ui {
class StatisticsMenu;
}

class StatisticsMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit StatisticsMenu(QWidget *parent = nullptr);
    ~StatisticsMenu();

private:
    Ui::StatisticsMenu *ui;
};

#endif // STATISTICSMENU_H
