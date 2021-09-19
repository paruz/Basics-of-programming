#include "widget.h"
#include "ui_widget.h"
#include <cstdio>
#include <math.h>
#include <QRegularExpressionValidator>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label_operand1->setText("Первое слагаемое");
    ui->label_operand2->setText("Второе слагаемое");
    ui->lable_result->setText("Cумма:");
//    QRegularExpression re("[1-9]\\d{0,3}");
//    QValidator *validator = new QRegularExpressionValidator(re, this);
//    ui->operand_left->setValidator(validator);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_resultButton_clicked()
{
    QString op1, op2;
    op1 = ui->operand_left->text();
    op2 = ui->operand_right->text();


    bool ok1, ok2, flag_delenie_0, flag_koren_minus, flag_result_inf, flag_result_nan;
    double d1, d2, x;


    d1 = op1.toDouble(&ok1);
    d2 = op2.toDouble(&ok2);
    double result;

    if(ok1 && ok2)
    {
        if(ui->plus->isChecked())
        {
            result = d1+d2;
            if(isinf(result))
                flag_result_inf = true;
            if(isnan(result))
                flag_result_nan = true;
        }
        else if(ui->minus->isChecked())
        {
            result = d1-d2;
            if(isinf(result))
                flag_result_inf = true;
            if(isnan(result))
                flag_result_nan = true;
        }
        else if(ui->proizvedenie->isChecked())
        {
            result = d1*d2;
            if(isinf(result))
                flag_result_inf = true;
            if(isnan(result))
                flag_result_nan = true;

        }
        else if(ui->delenie->isChecked())
        {
            if (d2 == 0)
            {
                flag_delenie_0 = true;
            }
            else
                result = d1/d2;
                if(isinf(result))
                    flag_result_inf = true;
                if(isnan(result))
                    flag_result_nan = true;
        }
        else if(ui->koren->isChecked())
        {
            if (d1 < 0)
            {
                flag_koren_minus = true;
            }
            else
            {
                result = sqrt(d1);
                if(isinf(result))
                    flag_result_inf = true;
                if(isnan(result))
                    flag_result_nan = true;
            }
        }
        if(flag_delenie_0)
        {
            QPalette pal;
            ui->result->clear();
            ui->error->setText("На ноль делить нельзя");

            pal.setColor(QPalette::Base, QColor::fromRgb(255, 255, 255));
            ui->operand_left->setPalette(pal);

            pal.setColor(QPalette::Base, QColor::fromRgb(255, 0, 0));
            ui->operand_right->setPalette(pal);
        }
        else if(flag_koren_minus)
        {
            QPalette pal;
            ui->result->clear();
            ui->error->setText("Подкоренное выражение меньше нуля");

            pal.setColor(QPalette::Base, QColor::fromRgb(255, 0, 0));
            ui->operand_left->setPalette(pal);
        }
        else if(flag_result_inf)
        {
            QPalette pal;
            ui->result->setText("Слишком большой результат");
            ui->error->setText("");
        }
        else if(flag_result_nan)
        {
            QPalette pal;
            ui->result->setText("Слишком маленький результат");
            ui->error->setText("");
        }
        else
        {
            QString resStr = QString::number(result, 'g', 16);
            ui->result->setText(resStr);
            ui->error->clear();
            QPalette pal;
            pal.setColor(QPalette::Base, QColor::fromRgb(255, 255, 255));
            ui->operand_right->setPalette(pal);
            ui->operand_left->setPalette(pal);
            ui->label_operand1->setPalette(pal);
            ui->label_operand2->setPalette(pal);
        }
    }
    else
    {
        if(!ok1 && !ok2)
        {
            if(ui->plus->isChecked())
            {
                ui->error->setText("Оба слагаемых не число");
            }
            else if(ui->minus->isChecked())
            {
                ui->error->setText("Уменьшаемое и вычитаемое не число");
            }
            else if(ui->proizvedenie->isChecked())
            {
                ui->error->setText("Оба множителя не число");
            }
            else if(ui->delenie->isChecked())
            {
                ui->error->setText("Делимое и делитель не число");
            }
            QPalette pal;
            pal.setColor(QPalette::Base, QColor::fromRgb(255, 0, 0));
            ui->operand_left->setPalette(pal);
            ui->operand_right->setPalette(pal);
            ui->result->clear();
        }
        else if(!ok1)
        {
            QPalette pal;
            pal.setColor(QPalette::Base, QColor::fromRgb(255, 255, 255));

            if(ui->plus->isChecked())
            {
                ui->error->setText("Первое слагаемое не число");
                ui->operand_right->setPalette(pal);
            }
            else if(ui->minus->isChecked())
            {
                ui->error->setText("Уменьшаемое не число");
                ui->operand_right->setPalette(pal);
            }
            else if(ui->proizvedenie->isChecked())
            {
                ui->error->setText("Первый множитель не число");
                ui->operand_right->setPalette(pal);
            }
            else if(ui->delenie->isChecked())
            {
                ui->error->setText("Делимое не число");
                ui->operand_right->setPalette(pal);
            }
            else if(ui->koren->isChecked())
            {
                ui->error->setText("Подкоренное выражение не число");
                ui->operand_right->setPalette(pal);
            }
            pal.setColor(QPalette::Base, QColor::fromRgb(255, 0, 0));
            ui->operand_left->setPalette(pal);
            ui->result->clear();
        }
        else if(!ok2)
        {
            QPalette pal;
            pal.setColor(QPalette::Base, QColor::fromRgb(255, 255, 255));

            if(ui->plus->isChecked())
            {
                ui->error->setText("Второе слагаемое не число");
                ui->operand_left->setPalette(pal);
            }
            else if(ui->minus->isChecked())
            {
                ui->error->setText("Вычитаемое не число");
                ui->operand_left->setPalette(pal);
            }
            else if(ui->proizvedenie->isChecked())
            {
                ui->error->setText("Второй множитель не число");
                ui->operand_left->setPalette(pal);
            }
            else if(ui->delenie->isChecked())
            {
                ui->error->setText("Делитель не число");
                ui->operand_left->setPalette(pal);
            }

            pal.setColor(QPalette::Base, QColor::fromRgb(255, 0, 0));
            ui->operand_right->setPalette(pal);
            ui->result->clear();
        }
        else {
            ui->error->setText("А");
        }
    }
}

void Widget::on_plus_toggled(bool checked)
{
    if(checked)
    {
        ui->label_operand1->setText("Первое слагаемое");
        ui->label_operand2->setText("Второе слагаемое");
        ui->lable_result->setText("Cумма:");
        ui->operand_right->setEnabled(true);
    }
}

void Widget::on_minus_toggled(bool checked)
{
    if(checked)
    {
        ui->label_operand1->setText("Уменьшаемое");
        ui->label_operand2->setText("Вычитаемое");
        ui->lable_result->setText("Разность:");
        ui->operand_right->setEnabled(true);
    }
}

void Widget::on_proizvedenie_toggled(bool checked)
{
    if(checked)
    {
        ui->label_operand1->setText("Первый множитель");
        ui->label_operand2->setText("Второй множитель");
        ui->lable_result->setText("Произведение:");
        ui->operand_right->setEnabled(true);
    }
}

void Widget::on_delenie_toggled(bool checked)
{
    if(checked)
    {
        ui->label_operand1->setText("Делимое");
        ui->label_operand2->setText("Делитель");
        ui->lable_result->setText("Частное:");
        ui->operand_right->setEnabled(true);
    }
}

void Widget::on_koren_toggled(bool checked)
{
    if(checked)
    {
        ui->label_operand1->setText("Подкоренное выражение");
        ui->label_operand2->setText("Степень корня:");
        QPalette pal;
        pal.setColor(QPalette::Base, QColor::fromRgb(255, 255, 255));
        ui->operand_right->setPalette(pal);
        ui->operand_right->setText("2");
        ui->lable_result->setText("Результат:");
        ui->operand_right->setEnabled(false);
    }
}
