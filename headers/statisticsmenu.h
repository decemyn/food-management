#ifndef STATISTICSMENU_H
#define STATISTICSMENU_H

#include "headers/basewindow.h"
#include "headers/statisticsinterface.h"
#include <QDate>
#include <QMainWindow>

namespace Ui {
class StatisticsMenu;
}

class StatisticsMenu : public QMainWindow {
  Q_OBJECT

public:
  explicit StatisticsMenu(QWidget *parent = nullptr,
                          Ui::BaseWindow *ui_parent = nullptr);
  ~StatisticsMenu();

protected:
  void closeEvent(QCloseEvent *event) override;

  void showEvent(QShowEvent *event) override;

private slots:
  void on_pushButton_show_daily_stats_clicked();

private:
  Ui::StatisticsMenu *ui;
  Ui::BaseWindow *ui_parent;

  void UiPopulateMostProfitableDay();

  void UiPopulateMostSoldProduct();

  void UiPopulateSelectedDateSales(QDate);
};

#endif // STATISTICSMENU_H
