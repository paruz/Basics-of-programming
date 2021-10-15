#include "widget.h"
#include "ui_widget.h"
#include <cstdlib>

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
void Widget::table_sort(double mass[],int rows)
{
    QString str;
    ui->tableWidget->setRowCount(1);
    for(int i=0;i<rows;i++)
    {
        if (i != rows - 1)
        {
            ui->tableWidget->insertRow(i+1);
        }
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(str = QString::number(mass[i])));
        //void setItem(int row, int column, QTableWidgetItem *item);
    }
}

void Widget::on_plus_clicked()
{
    int n = ui->tableWidget->rowCount();
    if (n < 999)
    ui->tableWidget->setRowCount(n+1);
}

void Widget::on_minus_clicked()
{
    int n = ui->tableWidget->rowCount();
    if (n > 1)
    ui->tableWidget->setRowCount(n-1);
}

void Widget::on_pushButton_random_clicked()
{
    QString number_String = ui->input_rows->text();
    bool ok = false;
    int number_int = number_String.toInt(&ok);
    if (ok)
    {
        ui->tableWidget->setRowCount(1);
        int rows=ui->input_rows->text().toInt();
        QString str;
        double mass[rows];
        srand(time(0) * time(0));
        for(int i=0;i<rows;i++){
            mass[i]=rand();
        }
        table_sort(mass, rows);
    }
}

void Widget::on_pushButton_clear_clicked()
{
    QString str;
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem(str = QString::number(0)));
}

void Widget::on_pushButton_min_clicked()
{

}

void Widget::on_pushButton_max_clicked()
{

}

void Widget::on_pushButton_avg_clicked()
{

}

void Widget::on_pushButton_sort_clicked()
{
    int rows=ui->tableWidget->rowCount();
    double mass[rows];
    if(ui->button_bubble->isChecked())
        bubble(mass,rows);
    else if(ui->button_fast->isChecked())
        fast(mass,rows);
    else if(ui->button_comb->isChecked())
        comb(mass,rows);


}
void Widget::bubble(double mass[], int rows)
{
    for(int i = 1; i < rows; ++i)
    {
        for(int r = 0; r < rows-i; r++)
        {
            if(mass[r] < mass[r+1])
            {
                int temp = mass[r];
                mass[r] = mass[r+1];
                mass[r+1] = temp;
            }
        }
    }
    table_sort(mass, rows);
}

void Widget::fast(double mass[], int rows)
{
    int i = 0;
    int j = rows - 1;

    double mid = mass[rows / 2];

    do
    {

        while(mass[i] < mid) {
            i++;
        }

        while(mass[j] > mid) {
            j--;
        }

        if (i <= j)
        {
            double tmp = mass[i];
            mass[i] = mass[j];
            mass[j] = tmp;

            i++;
            j--;
        }
    }
    while (i <= j);

    if(j > 0)
    {
        fast(mass, j + 1);
    }
    if (i < rows)
    {
        fast(&mass[i], rows - i);
    }
    table_sort(mass, rows);
}

void Widget::comb(double mass[], int rows)
{
    int tmp,k;
        int s=rows;
        long long cnt=0;
        while(rows>1) {
            s/=1.247f;
            if (s<1) s=1;
            k=0;
            for (int i=0; i+s<rows;++i) {
                if(mass[i]/10>mass[i+s]/10) {
                    tmp=mass[i];
                    mass[i]=mass[i+s];
                    mass[i+s]=tmp;
                    k=i;
                }
                ++cnt;
            }
            if (s==1)
                rows=k+1;
        }
    table_sort(mass, rows);
}

void Widget::gnome(double mass[], int rows)
{

}

void Widget::monkey(double mass[], int rows)
{

}
