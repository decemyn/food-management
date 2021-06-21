#ifndef PRODUCTDETAILS_H
#define PRODUCTDETAILS_H

#include <QMainWindow>

namespace Ui {
class ProductDetails;
}

class ProductDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProductDetails(QWidget *parent = nullptr);
    ~ProductDetails();

private:
    Ui::ProductDetails *ui;
};

#endif // PRODUCTDETAILS_H
