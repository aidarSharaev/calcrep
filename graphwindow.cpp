#include "graphwindow.h"
#include "ui_graphwindow.h"
#include "polish.h"
#include <cmath>

GraphWindow::GraphWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::GraphWindow)
{
    ui->setupUi(this);
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
    ui->widget->xAxis->setRange(xMin, xMax);
    ui->widget->yAxis->setRange(yMin, yMax);
    if (!xCount) {
        stack_t* main_stack = NULL;
        buffer_t* main_buffer = NULL;
        buffer_t* sec_buffer = NULL;
        const char* input_string = qPrintable(str);
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
        delete_buff(&main_buffer);
        delete_buff(&sec_buffer);
        delete_stack(&main_stack);
    } else {
        int k = 0;
        double step{(fabs(xMax) + fabs(xMin)) / 1000};
        for (double i = xMin; i <= xMax; i += step) {
            ++k;
            if (k == 501) {
                i = 0.0;
            }
            stack_t* main_stack = NULL;
            buffer_t* main_buffer = NULL;
            buffer_t* sec_buffer = NULL;
            QString saveBuffer = str;
            QString swapVal = "(" + QString::number(i) + ")";
            saveBuffer.replace(QString("x"), QString(swapVal));
            saveBuffer.replace(QString(","), QString("."));
            const char* input_string = qPrintable(saveBuffer);
            int rslt = string_parser(input_string, &main_stack, &main_buffer, &sec_buffer);
            if (rslt || main_buffer->next) {
                ui->widget->addGraph();
                ui->widget->graph()->addData(x, y);
                ui->widget->replot();
                x.clear();
                y.clear();
            } else {
                QString string = static_cast<QString>(main_buffer->element.str);
                x.push_back(i);
                y.push_back(string.toDouble());
            }
            delete_buff(&main_buffer);
            delete_buff(&sec_buffer);
            delete_stack(&main_stack);
        }
    }
    ui->widget->addGraph();
    ui->widget->graph()->addData(x, y);
    ui->widget->replot();
}

GraphWindow::~GraphWindow()
{
    delete ui;
}

