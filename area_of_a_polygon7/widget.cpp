#include "widget.h"
#include "ui_widget.h"
#include <cmath>

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

void Widget::on_plus_clicked()
{
    int n = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(n+1);   
}

void Widget::on_minus_clicked()
{
    int n = ui->tableWidget->rowCount();
    n--;
    if (n>=3)
    ui->tableWidget->setRowCount(n);
}

void Widget::on_pushButton_S_clicked()
{
    double result_S = 0, result_P = 0;
    int n = ui->tableWidget->rowCount();
    double X[n-1], Y[n-1];
    bool flag = false;
    for (int r = 0; r < n; r++)
    {
        QTableWidgetItem *item1 = ui->tableWidget->item(r, 0);
        QTableWidgetItem *item2 = ui->tableWidget->item(r, 1);

        if(item1 != nullptr && item2 != nullptr)
        {
            // Есть обе ячейки
            QString s1 = item1->text();
            QString s2 = item2->text();
            bool ok1, ok2;
            double d1 = s1.toDouble(&ok1);
            double d2 = s2.toDouble(&ok2);
            if (ok1 and ok2)
            {
                X[r] = d1;
                Y[r] = d2;
            }
        }
    }
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        result_S += (X[j] + X[i]) * (Y[j] - Y[i]);
        for (int k = i + 2; k < n; k++)
        {
            if(check(X[i], Y[i], X[i+1], Y[i+1], X[k], Y[k], X[k+1], Y[k+1]))
            {
                flag = true;
            }
        }
        j = i;
    }
    for (int i = 0; i < n; ++i)
    {
        int j = (i+1)%n;
        result_P += sqrt((X[i] - X[j])*(X[i] - X[j]) + (Y[i] - Y[j])*(Y[i] - Y[j]));
    }
    if (flag)
    {
        ui->error->setText("Отрезки в многоугольнике пересекаются, нельзя посчитать площадь");
        ui->output_S->setText("");
    }
    else
    {
        ui->error->setText("");
        result_S = abs(result_S / 2);
        QString resStr_S = QString::number(result_S, 'g', 16);
        ui->output_S->setText(resStr_S);
    }

    QString resStr_P = QString::number(result_P, 'g', 16);
    ui->output_P->setText(resStr_P);
}

bool Widget::check(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{

    double znamenatel=(y4-y3)*(x1-x2)-(x4-x3)*(y1-y2);
    if (znamenatel == 0.0)
        return false;
    else
    {
        double chislitel_1=(x4-x2)*(y4-y3)-(x4-x3)*(y4-y2);
        double chislitel_2=(x1-x2)*(y4-y2)-(x4-x2)*(y1-y2);
        double Ua=chislitel_1/znamenatel;
        double Ub=chislitel_2/znamenatel;
        if (Ua >=0 && Ua <=1 && Ub >=0 && Ub <=1)
            return true;
        else
            return false;
    }
}
