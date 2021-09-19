#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->output->setText("ИСТИНА");
    this->setStyleSheet("QWidget#Widget{ background: green;} QWidget { border-radius: 5px;} ");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_operand1_activated(int index)
{
    calculate();
}

void Widget::on_operand2_activated(int index)
{
    calculate();
}

void Widget::on_operation_activated(int index)
{
    calculate();
}

void Widget::calculate()
{
    int index1 = ui->operand1->currentIndex(), index2 = ui->operand2->currentIndex(), index3 = ui->operation->currentIndex();
    bool operand1, operand2, output = false;

    ui->operand1->show();

    if (index1 == 0)
        operand1 = true;
    else
        operand1 = false;

    operand1 = (index1 == 0);

    if (index2 == 0)
        operand2 = true;
    else
        operand2 = false;

    if (index3 == 0)
        output = operand1 and operand2;

    if (index3 == 1)
        output = operand1 or operand2;

    if (index3 == 2)
        output = (not operand1) or operand2;

    if (index3 == 3)
        output = operand1 != operand2;

    if (index3 == 4)
        output = operand1 == operand2;

    if (index3 == 5){
        ui->operand1->hide();
        output = not operand2;
    }

    if(output){
        ui->output->setText("ИСТИНА");
        this->setStyleSheet("background: green; border-radius: 25px;");
        ui->operand1->setStyleSheet("background: white");
        ui->operand2->setStyleSheet("background: white");
        ui->operation->setStyleSheet("background: white");
        ui->output->setStyleSheet("background: white");

    }
    else {
        ui->output->setText("ЛОЖЬ");
        this->setStyleSheet("background: red; border-radius: 5px;");
        ui->operand1->setStyleSheet("background: white");
        ui->operand2->setStyleSheet("background: white");
        ui->operation->setStyleSheet("background: white");
        ui->output->setStyleSheet("background: white");
    }
}
