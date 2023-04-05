#include "graphwindow.h"
#include "ui_graphwindow.h"


GraphWindow::GraphWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphWindow)
{
    ui->setupUi(this);
    ui->widget->xAxis->setRange(-4, 5);
    ui->widget->yAxis->setRange(-4, 7);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    ui->widget->addGraph();
    ui->widget->graph()->addData(x, y);
    ui->widget->replot();

}

GraphWindow::~GraphWindow()
{
    delete ui;
}

