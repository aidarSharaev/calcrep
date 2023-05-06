#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QDoubleValidator>
#include <QMessageBox>
#include "graphwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void getDEValue(QVector<int>& arr);

private:
  Ui::MainWindow *ui;

  QPushButton* btn[23];
  QPushButton* btn2[12];

  QWidget* wgt;
  QWidget* wgt2;

  QGridLayout* qbl;
  QGridLayout* qbl2;

  QLineEdit* text;
  QLineEdit* text2[5];

  QFont* font;
  QFont* font2;

  QString mainStr;
  QString* values;

  QDoubleValidator* v;

  QVector<int> argList;

  GraphWindow* graphWindow;

  bool checkString(QPushButton* pbtn);
  int whatIsIt(QString arg);

  enum RtrnVal {NUMBER = 0, PM, OPER, DOT, ODZ, OPEN_BR, CLOSE_BR, TRIGO, IKS};

  static int bracketCounter;
  static int xCounter;
  static short flag;
  static void bracketUp() {++bracketCounter;};
  static void bracketDown() {--bracketCounter;};

  void operator<<(QVector<int> vec);

signals:
  void set_text(QString);
  void deleteText(QString);
  void calculator(QString);

private slots:
  void change();
  void deleteSymbol();
  void goToCalc();
  void calcX();
  void windowCreate();

};

#endif // MAINWINDOW_H
