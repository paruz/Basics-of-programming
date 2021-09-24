#include "widget.h"
#include "ui_widget.h"
#include <QDoubleValidator>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString ox1 = ui->x_1->text(), oy1 = ui->y_1->text(), ox2 = ui->x_2->text(), oy2 = ui->y_2->text(), ox3 = ui->x_3->text(), oy3 = ui->y_3->text();
    double x1 = ox1.toDouble(), y1 = oy1.toDouble(), x2 = ox2.toDouble(), y2 = oy2.toDouble(), x3 = ox3.toDouble(), y3 = oy3.toDouble();
    double result;
    result = (abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1))) / 2;
    QString resStr = QString::number(result, 'g', 16);
    ui->output->setText(resStr);
}
