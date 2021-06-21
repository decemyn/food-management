#include "headers/statisticsmenu.h"
#include "ui_statisticsmenu.h"

StatisticsMenu::StatisticsMenu(QWidget *parent, Ui::BaseWindow *ui_parent)
    : QMainWindow(parent), ui(new Ui::StatisticsMenu) {
  ui->setupUi(this);
  this->ui_parent = ui_parent;
}

StatisticsMenu::~StatisticsMenu() { delete ui; }

void StatisticsMenu::showEvent(QShowEvent *event) {
  this->UiPopulateMostProfitableDay();
  this->UiPopulateMostSoldProduct();
}

void StatisticsMenu::closeEvent(QCloseEvent *event) {
  this->ui_parent->pushButton->setEnabled(true);
  this->ui_parent->pushButton_2->setEnabled(true);
}

void StatisticsMenu::UiPopulateMostProfitableDay() {
  this->ui->label_most_profitable_day->setText(
      QString::fromStdString(StatisticsInterface::GetMostProfitableDay()));
}

void StatisticsMenu::UiPopulateMostSoldProduct() {
  Product *MostSoldProduct = StatisticsInterface::GetMostSoldProduct();
  if (MostSoldProduct != nullptr) {
    this->ui->label_most_sold_prod->setText(QString::fromStdString(
        "Nume: " + MostSoldProduct->getProductName() +
        " | ID:" + std::to_string(MostSoldProduct->getID())));
  } else {
    this->ui->label_most_sold_prod->setText("Nu există vânzări înregistrate!");
  }
}

void StatisticsMenu::on_pushButton_show_daily_stats_clicked() {
  this->UiPopulateSelectedDateSales(this->ui->calendarWidget->selectedDate());
}

void StatisticsMenu::UiPopulateSelectedDateSales(QDate CurrentDate) {
  this->ui->comboBox_sold_products->clear();
  this->ui->groupBox_daily_stats->setEnabled(true);
  this->ui->label_statistic_date->setText(CurrentDate.toString("dd/MM/yyyy"));
  std::vector<Product *> SoldProductsFromDateArray =
      StatisticsInterface::GetSoldProductsByDate(
          CurrentDate.toString("dd/MM/yyyy").toStdString());
  if (SoldProductsFromDateArray.size()) {
    for (auto Product : SoldProductsFromDateArray) {
      this->ui->comboBox_sold_products->addItem(
          QString::fromStdString(Product->getProductName()) +
          " ID:" + QString::fromStdString(std::to_string(Product->getID())));
    }
    this->ui->label_profit->setText(QString::fromStdString(
        std::to_string(StatisticsInterface::GetProfitFromProductArray(
            SoldProductsFromDateArray))));
    this->ui->label_cifra_afaceri->setText(QString::fromStdString(
        std::to_string(StatisticsInterface::GetProfitFromProductArray(
                           SoldProductsFromDateArray) *
                       4)));
  } else {
    this->ui->comboBox_sold_products->addItem("Nu există produse vândute");
    this->ui->label_profit->setText("----");
    this->ui->label_cifra_afaceri->setText("----");
  }
}
