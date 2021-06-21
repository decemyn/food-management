#include "headers/statisticsmenu.h"
#include "ui_statisticsmenu.h"

StatisticsMenu::StatisticsMenu(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::StatisticsMenu) {
  ui->setupUi(this);
}

StatisticsMenu::~StatisticsMenu() { delete ui; }
