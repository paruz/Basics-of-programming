#include "widget.h"
#include "ui_widget.h"
#include <cstdlib>
#include <ctime>

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
    ui->time->setText("");
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
    if (ok and number_int > 0)
    {
        QPalette pal;
        pal.setColor(QPalette::Base, Qt::white);
        ui->input_rows->setPalette(pal);
        ui->error->setText("");
        ui->tableWidget->setRowCount(1);
        int rows=ui->input_rows->text().toInt();
        QString str;
        double mass[rows];
        srand(time(0) * time(0));
        for(int i=0;i<rows;i++){
            mass[i]=rand();
        }
        table_sort(mass, rows);
        ui->output_avg->setText("");
        ui->output_max->setText("");
        ui->output_min->setText("");
    }
    else
    {
        QPalette pal;
        pal.setColor(QPalette::Base, Qt::red);
        ui->input_rows->setPalette(pal);
        ui->error->setText("Нужно ввести натуральное число от 1 до 999");
    }
}

void Widget::on_pushButton_clear_clicked()
{
    QString str;
    QPalette pal;
    pal.setColor(QPalette::Base, Qt::white);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem(str = QString::number(0)));
    ui->output_avg->setText("");
    ui->output_max->setText("");
    ui->output_min->setText("");
    ui->warning->setPalette(pal);
    ui->warning->setText("");
    ui->error->setPalette(pal);
    ui->warning->setText("");
    ui->time->setText("");
}

void Widget::on_pushButton_min_clicked()
{
    int rows = ui->tableWidget->rowCount();
    double mass[rows];
    for(int i=0;i<rows;i++)
    {
        bool ok1;
        mass[i] = ui->tableWidget->item(i, 0)->text().toDouble(&ok1);
    }
    double min = mass[0];
    for(int i = 1; i<rows; i++)
    {
        if(min > mass[i])
            min = mass[i];
    }
    ui->output_min->setText(QString::number(min, 'g', 16));
}

void Widget::on_pushButton_max_clicked()
{
    int rows = ui->tableWidget->rowCount();
    double mass[rows];
    for(int i=0;i<rows;i++)
    {
        bool ok1;
        mass[i] = ui->tableWidget->item(i, 0)->text().toDouble(&ok1);
    }
    double max = mass[0];
    for(int i = 1; i<rows; i++)
    {
        if(max < mass[i])
            max = mass[i];
    }
    ui->output_max->setText(QString::number(max, 'g', 16));
}

void Widget::on_pushButton_avg_clicked()
{
    int rows = ui->tableWidget->rowCount();
    double mass[rows];
    for(int i=0;i<rows;i++)
    {
        bool ok1;
        mass[i] = ui->tableWidget->item(i, 0)->text().toDouble(&ok1);
    }
    double avg = mass[0];
    for(int i = 1; i<rows; i++)
    {
        avg += mass[i];
    }
    ui->output_avg->setText(QString::number(avg / rows, 'g', 16));
}
bool flag_warning = false;
void Widget::on_pushButton_sort_clicked()
{
    int rows = ui->tableWidget->rowCount();
    double mass2[rows];
    QString number_str;
    double row_number;
    bool ok, flag = true;
    for(int i=0;i<rows;i++){
        number_str = ui->tableWidget->item(i,0)->text();
        row_number = number_str.toDouble(&ok);
        mass2[i]=row_number;
        if(!ok or number_str == "")
        {
            flag=false;
            ui->tableWidget->item(i,0)->setBackground(Qt::red);
        }
        else
        {
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        }
    }

    if (flag)
    {
        double start_time =  clock(); // начальное время
        QPalette pal;
        pal.setColor(QPalette::Base, Qt::white);
        ui->error->setPalette(pal);
        ui->error->setText("");
        double mass[rows];
        for(int i=0;i<rows;i++)
        {
            bool ok1;
            mass[i] = ui->tableWidget->item(i, 0)->text().toDouble(&ok1);
        }
        pal.setColor(QPalette::Base, Qt::white);
        ui->warning->setPalette(pal);
        ui->warning->setText("");
        if(ui->button_bubble->isChecked())
            bubble(mass,rows);
        else if(ui->button_fast->isChecked())
            fast(mass,rows);
        else if(ui->button_comb->isChecked())
            comb(mass,rows);
        else if(ui->button_gnome->isChecked())
            gnome(mass,rows);
        else if(ui->button_monkey->isChecked())
        {
            if(flag_warning or rows <= 10)
            {
                monkey(mass,rows);
                QPalette pal;
                pal.setColor(QPalette::Base, Qt::white);
                ui->warning->setPalette(pal);
                ui->warning->setText("");
                flag_warning = false;
            }
            else if(rows > 10)
            {
                QPalette pal;
                pal.setColor(QPalette::Base, Qt::yellow);
                ui->warning->setPalette(pal);
                ui->warning->setText("Будет очень долго. Уверены?");
                flag_warning = true;
            }
        }
        if(flag_warning)
        {
            ui->time->setText("");
        }
        else
        {
        double end_time = clock(); // конечное время
        double search_time = end_time - start_time;
        QString time_str = QString::number(search_time, 'g', 16);
        if(time_str == "0")
            ui->time->setText("Моментально");
        else
            ui->time->setText(time_str);
        }
    }
    else {
        QPalette pal;
        pal.setColor(QPalette::Base, Qt::red);
        ui->error->setPalette(pal);
        ui->error->setText("Сортирует только числа.");
    }
}
void Widget::bubble(double mass[], int rows)
{
    int x = rows;
    for(int i = 1; i < rows; ++i)
    {
        for(int r = 0; r < rows-i; r++)
        {
            if(mass[r] > mass[r+1])
            {
                double temp = mass[r];
                mass[r] = mass[r+1];
                mass[r+1] = temp;
            }
        }
    }
    table_sort(mass, x);
}

void Widget::fast(double mass[], int rows)
{
    int x = rows;
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
    table_sort(mass, x);
}

void Widget::comb(double mass[], int rows)
{
    int x = rows;
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
    table_sort(mass, x);
}

void Widget::gnome(double mass[], int rows)
{
    int index = 0;
    int x = rows;
        while (index < rows) {
            if (index == 0)
                index++;
            if (mass[index] >= mass[index - 1])
                index++;
            else {
                double temp;
                temp = mass[index];
                mass[index] = mass[index - 1];
                mass[index - 1] = temp;

                index--;
            }
        }
    table_sort(mass, x);
}


bool Widget::isSorted(double mass[], int rows)
{
    while (--rows >= 1)
        if (mass[rows] < mass[rows - 1])
            return false;
    return true;
}

void Widget::shuffle(double mass[], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        double temp;
        int rnd = rand() % rows;
        temp = mass[i];
        mass[i] = mass[rnd];
        mass[rnd] = temp;
    }
}

void Widget::monkey(double mass[], int rows)
{
    int x = rows;
    while (!isSorted(mass, rows))
    {
        shuffle(mass, rows);
    }
    table_sort(mass, x);
}
