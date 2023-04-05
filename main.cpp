//#include "mainwindow.h"
#include "graphwindow.h"
#include <QDebug>
#include <QWidget>
#include <QApplication>
#include <QVector>
#include <QString>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  GraphWindow w;
  w.show();
  return a.exec();
}
