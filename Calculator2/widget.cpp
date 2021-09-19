#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label_operand1->setText("Первое слагаемое");
    ui->label_operand2->setText("Второе слагаемое");
    ui->lable_result->setText("Cумма:");
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

    bool ok1, ok2, flag1;
    long long d1, d2;


    d1 = op1.toInt(&ok1);
    d2 = op2.toInt(&ok2);
    long long result;
    if(ok1 && ok2)
    {
        if(ui->plus->isChecked())
        {
            result = d1+d2;
        }
        else if(ui->minus->isChecked())
        {
            result = d1-d2;
        }
        else if(ui->proizvedenie->isChecked())
        {
            result = d1*d2;
        }
        else if(ui->delenie->isChecked())
        {
            if (d2 == 0)
            {
                flag1 = true;
            }
            else
                result = d1/d2;
        }
        if(flag1)
        {
            QPalette pal;
            ui->result->clear();
            ui->error->setText("На ноль делить нельзя");

            pal.setColor(QPalette::Base, QColor::fromRgb(255, 255, 255));
            ui->operand_left->setPalette(pal);

            pal.setColor(QPalette::Base, QColor::fromRgb(255, 0, 0));
            ui->operand_right->setPalette(pal);
        }
        else
        {
            QString resStr = QString::number(result);
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
    }
}

void Widget::on_minus_toggled(bool checked)
{
    if(checked)
    {
        ui->label_operand1->setText("Уменьшаемое");
        ui->label_operand2->setText("Вычитаемое");
        ui->lable_result->setText("Разность:");
    }
}

void Widget::on_proizvedenie_toggled(bool checked)
{
    if(checked)
    {
        ui->label_operand1->setText("Первый множитель");
        ui->label_operand2->setText("Второй множитель");
        ui->lable_result->setText("Произведение:");
    }
}

void Widget::on_delenie_toggled(bool checked)
{
    if(checked)
    {
        ui->label_operand1->setText("Делимое");
        ui->label_operand2->setText("Делитель");
        ui->lable_result->setText("Частное:");
    }
}
