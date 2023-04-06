#include "graphwindow.h"
#include "ui_graphwindow.h"
#include "polish.h"

GraphWindow::GraphWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::GraphWindow)
{
    ui->setupUi(this);
//    /xMax = yMax = xMin = yMin = 0;

}

void GraphWindow::plot(QString* values, int xCount, QString str)
{
    for (int i = 0; i < 4; i++) {
        if (values[i].isEmpty() && !(i % 2)) values[i] = "-1000000.00";
        else if (values[i].isEmpty()) values[i] = "1000000.00";
    }
    xMin = values[0].toDouble();
    xMax = values[1].toDouble();
    yMin = values[2].toDouble();
    yMax = values[3].toDouble();
    qDebug() << str;
    ui->widget->xAxis->setRange(xMin, xMax);
    ui->widget->yAxis->setRange(yMin, yMax);
    stack_t* main_stack = NULL;
    buffer_t* main_buffer = NULL;
    buffer_t* sec_buffer = NULL;
    const char* input_string = qPrintable(str);
    if (!xCount) {
        int rslt = string_parser(input_string, &main_stack, &main_buffer, &sec_buffer);
        if (rslt || main_buffer->next) {
        } else {
            QString string = static_cast<QString>(main_buffer->element.str);
            x.push_back(xMin);
            x.push_back(xMax);
            y.push_back(string.toDouble());
            y.push_back(string.toDouble());
            ui->widget->addGraph();
            ui->widget->graph()->addData(x, y);
            ui->widget->replot();
        }
    } else {
       int rslt = string_parser(input_string, &main_stack, &main_buffer, &sec_buffer);
       if (rslt || main_buffer->next) {

       } else {
           QString string = static_cast<QString>(main_buffer->element.str);
           x.push_back(xMin);
           x.push_back(xMax);
           y.push_back(string.toDouble());
           y.push_back(string.toDouble());
       }
    }
    delete_buff(&main_buffer);
    delete_buff(&sec_buffer);
    delete_stack(&main_stack);

}

GraphWindow::~GraphWindow()
{
    delete ui;
}

