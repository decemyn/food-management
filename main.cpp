#include "headers/basewindow.h"
#include "headers/loginmenu.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  BaseWindow w;
  w.show();
  return a.exec();
}
