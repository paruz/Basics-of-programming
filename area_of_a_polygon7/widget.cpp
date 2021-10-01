#include "widget.h"
#include "ui_widget.h"

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
    double result;
    int n = ui->tableWidget->rowCount();
    double X[n-1], Y[n-1];
    for (int r = 0; r < n; r++)
    {
        QTableWidgetItem * item1 = ui->tableWidget->item(r, 0);
        QTableWidgetItem * item2 = ui->tableWidget->item(r, 1);

        if(item1 != nullptr && item2 != nullptr)
        {
            // Есть обе ячейки
            QString s1 = item1->text();
            QString s2 = item2->text();
            bool ok1, ok2;
            double d1 = s1.toDouble(&ok1);
            double d2 = s2.toDouble(&ok2);
            double X[n-1], Y[n-1];
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
        result += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;
    }
    result = abs(result / 2);
    QString resStr = QString::number(result, 'g', 16);
    ui->output->setText(resStr);
}


void Widget::on_pushButton_P_clicked()
{

}
