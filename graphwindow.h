#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QLineEdit>
#include <QCloseEvent>
#include <QDebug>
#include <QPushButton>

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();
		void plot(QStringList values, int xCount, QString str);

private:
    Ui::GraphWindow *ui;
    QVector <double> x;
    QVector <double> y;
		QPushButton* backk;

    double xMax;
    double yMax;
    double yMin;
		double xMin;
};

#endif // GRAPHWINDOW_H
