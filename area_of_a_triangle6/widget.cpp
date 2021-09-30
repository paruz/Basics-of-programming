#include "widget.h"
#include "ui_widget.h"
#include <QDoubleValidator>
#include <math.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QValidator *validator = new QDoubleValidator(-1.79769e+308, 1.79769e+308, 16);
    ui->x_1->setValidator(validator);
    ui->x_2->setValidator(validator);
    ui->x_3->setValidator(validator);
    ui->y_1->setValidator(validator);
    ui->y_2->setValidator(validator);
    ui->y_3->setValidator(validator);
}
Widget::~Widget()
{
    delete ui;
}
void Widget::on_pushButton_S_clicked()
{
    QString ox1 = ui->x_1->text(), oy1 = ui->y_1->text(), ox2 = ui->x_2->text(), oy2 = ui->y_2->text(), ox3 = ui->x_3->text(), oy3 = ui->y_3->text();
    bool okx1, okx2, okx3, oky1, oky2, oky3;
    double x1 = ox1.toDouble(&okx1), y1 = oy1.toDouble(&oky1), x2 = ox2.toDouble(&okx2), y2 = oy2.toDouble(&oky2), x3 = ox3.toDouble(&okx3), y3 = oy3.toDouble(&oky3);
    double result;
    result = (abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1))) / 2; // Формула площади Гаусса
    if (ox1 == "" or ox2 == "" or ox3 == "" or oy1 == "" or oy2 == "" or oy3 == "")
    {
        ui->error->setText("Нельзя оставлять пустое поле");
        ui->output->setText("");
    }
    else if (!okx1)
    {
        ui->error->setText("X1 не входит в диапозон чисел");
        ui->output->setText("");
    }
    else if (!okx2)
    {
        ui->error->setText("X2 не входит в диапозон чисел");
        ui->output->setText("");
    }
    else if (!okx3)
    {
        ui->error->setText("X3 не входит в диапозон чисел");
        ui->output->setText("");
    }
    else if (!oky1)
    {
        ui->error->setText("Y1 не входит в диапозон чисел");
        ui->output->setText("");
    }
    else if (!oky2)
    {
        ui->error->setText("Y2 не входит в диапозон чисел");
        ui->output->setText("");
    }
    else if (!oky3)
    {
        ui->error->setText("Y3 не входит в диапозон чисел");
        ui->output->setText("");
    }
    else
    {
        if(isinf(result))
            ui->output->setText("Слишком большой результат");
//        else if(isnan(result))
//            ui->output->setText("Слишком маленький результат");
        else
        {
            QString resStr = QString::number(result, 'g', 16);
            ui->output->setText(resStr);
            ui->error->setText("");
        }
    }
}
void Widget::on_pushButton_P_clicked()
{
    QString ox1 = ui->x_1->text(), oy1 = ui->y_1->text(), ox2 = ui->x_2->text(), oy2 = ui->y_2->text(), ox3 = ui->x_3->text(), oy3 = ui->y_3->text();
    bool okx1, okx2, okx3, oky1, oky2, oky3;
    double x1 = ox1.toDouble(&okx1), y1 = oy1.toDouble(&oky1), x2 = ox2.toDouble(&okx2), y2 = oy2.toDouble(&oky2), x3 = ox3.toDouble(&okx3), y3 = oy3.toDouble(&oky3);
    double result;
    double ab, bc, ac;
    ab = sqrt((x2 - x1)*(x2 - x1)+(y2-y1)*(y2-y1));
    bc = sqrt((x3 - x1)*(x3 - x1)+(y3-y1)*(y3-y1));
    ac = sqrt((x3 - x2)*(x3 - x2)+(y3-y2)*(y3-y2));
    result = ab + bc + ac;
    if (ox1 == "" or ox2 == "" or ox3 == "" or oy1 == "" or oy2 == "" or oy3 == "")
    {
        ui->error->setText("Нельзя оставлять пустое поле");
        ui->output->setText("");
    }
    else if (!okx1)
    {
        ui->error->setText("X1 не входит в диапозон чисел");
        ui->output->setText("");
    }
    else if (!okx2)
    {
        ui->error->setText("X2 не входит в диапозон чисел");
        ui->output->setText("");
    }
    else if (!okx3)
    {
        ui->error->setText("X3 не входит в диапозон чисел");
        ui->output->setText("");
    }
    else if (!oky1)
    {
        ui->error->setText("Y1 не входит в диапозон чисел");
        ui->output->setText("");
    }
    else if (!oky2)
    {
        ui->error->setText("Y2 не входит в диапозон чисел");
        ui->output->setText("");
    }
    else if (!oky3)
    {
        ui->error->setText("Y3 не входит в диапозон чисел");
        ui->output->setText("");
    }
    else
    {
        if(isinf(result))
            ui->output->setText("Слишком большой результат");
//        else if(isnan(result))
//            ui->output->setText("Слишком маленький результат");
        else
        {
            QString resStr = QString::number(result, 'g', 16);
            ui->output->setText(resStr);
            ui->error->setText("");
        }
    }
}
