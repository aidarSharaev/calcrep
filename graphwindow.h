#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVector>

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();

private:
    Ui::GraphWindow *ui;
    QVector <double> x;
    QVector <double> y;
//    QPushButton* qpb;
//    QCustomPlot* qcp;
//    QWidget* wgt;
};

#endif // GRAPHWINDOW_H
