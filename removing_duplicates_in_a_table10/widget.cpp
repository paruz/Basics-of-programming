#include "widget.h"
#include "ui_widget.h"
#include <cstdlib>
#include <ctime>
#include <QElapsedTimer>

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
    }
}
void Widget::on_plus_clicked()
{
    int n = ui->tableWidget->rowCount();
    if (n < 1000000)
    ui->tableWidget->setRowCount(n+1);
    ui->tableWidget->setItem(n, 0, new QTableWidgetItem(""));
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
    if (ok and number_int > 0 and number_int <= 1000000)
    {
        QPalette pal;
        pal.setColor(QPalette::Base, Qt::white);
        ui->input_rows->setPalette(pal);
        ui->error->setText("");
        ui->tableWidget->setRowCount(1);
        int rows=ui->input_rows->text().toInt();
        QString str;
        double *mass = new double[rows];;
        srand(time(0) * time(0));
        for(int i=0;i<rows;i++){
            mass[i]=rand();
        }
        table_sort(mass, rows);
        delete[] mass;
        ui->output_avg->setText("");
        ui->output_max->setText("");
        ui->output_min->setText("");
    }
    else
    {
        QPalette pal;
        pal.setColor(QPalette::Base, Qt::red);
        ui->input_rows->setPalette(pal);
        ui->error->setText("Нужно ввести натуральное число от 1 до 1000000");
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
    ui->output_find->setText("");
    ui->output_count->setText("");
    ui->output_method->setText("");
    ui->delete_count->setText("");
}

void Widget::on_pushButton_min_clicked()
{
    int rows = ui->tableWidget->rowCount();
    double *mass = new double[rows];
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
    delete[] mass;
}

void Widget::on_pushButton_max_clicked()
{
    int rows = ui->tableWidget->rowCount();
    double *mass = new double[rows];
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
    delete[] mass;
}

void Widget::on_pushButton_avg_clicked()
{
    int rows = ui->tableWidget->rowCount();
    double *mass = new double[rows];
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
    delete[] mass;
}
bool flag_warning = false;
void Widget::on_pushButton_sort_clicked()
{
    int rows = ui->tableWidget->rowCount();
    double *mass2 = new double[rows];
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
//        double start_time =  clock(); // начальное время
        QPalette pal;
        pal.setColor(QPalette::Base, Qt::white);
        ui->error->setPalette(pal);
        ui->error->setText("");
        double *mass = new double[rows];
        for(int i=0;i<rows;i++)
        {
            bool ok1;
            mass[i] = ui->tableWidget->item(i, 0)->text().toDouble(&ok1);
        }
        pal.setColor(QPalette::Base, Qt::white);
        ui->warning->setPalette(pal);
        ui->warning->setText("");
        if(ui->button_bubble->isChecked())
        {
            if(flag_warning or rows <= 50000)
            {
                bubble(mass,rows);
                QPalette pal;
                pal.setColor(QPalette::Base, Qt::white);
                ui->warning->setPalette(pal);
                ui->warning->setText("");
                flag_warning = false;
            }
            else if(rows > 50000)
            {
                QPalette pal;
                pal.setColor(QPalette::Base, Qt::yellow);
                ui->warning->setPalette(pal);
                ui->warning->setText("Будет очень долго. Уверены?");
                flag_warning = true;
            }
        }
        else if(ui->button_fast->isChecked())
            fast1(mass, 0, rows-1);
        else if(ui->button_comb->isChecked())
            comb(mass,rows);
        else if(ui->button_gnome->isChecked())
        {
            if(flag_warning or rows <= 50000)
            {
                gnome(mass,rows);
                QPalette pal;
                pal.setColor(QPalette::Base, Qt::white);
                ui->warning->setPalette(pal);
                ui->warning->setText("");
                flag_warning = false;
            }
            else if(rows > 50000)
            {
                QPalette pal;
                pal.setColor(QPalette::Base, Qt::yellow);
                ui->warning->setPalette(pal);
                ui->warning->setText("Будет очень долго. Уверены?");
                flag_warning = true;
            }
        }
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
        delete[] mass;
    }
    else {
        QPalette pal;
        pal.setColor(QPalette::Base, Qt::red);
        ui->error->setPalette(pal);
        ui->error->setText("Сортирует только числа.");
    }
    delete[] mass2;
}
void Widget::timee(long long start_time, long long end_time)
{
    long long search_time = end_time - start_time;
    QString time_str = QString::number((double)search_time / 1000.0);
    if(time_str == "0")
        ui->time->setText("Моментально");
    else
        ui->time->setText(time_str + " мкс");
}
void Widget::bubble(double mass[], int rows)
{
    QElapsedTimer timer;
    timer.start();
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
    long long elapsed = timer.nsecsElapsed();
    timee(0, elapsed);
    table_sort(mass, x);
}
///







void Widget::fast1(double numbers[], int left, int right)
{
  QElapsedTimer timer;
  timer.start();
  fast(numbers, left, right);
  int elapsed = timer.nsecsElapsed();
  timee(0, elapsed);
  table_sort(numbers, right + 1);
}

void Widget::fast(double numbers[], int aL, int aR)
{
    if(aR <= aL)
        return;

      int i = partition(numbers, aL, aR);
      fast(numbers, aL, i-1);
      fast(numbers, i+1, aR);
}
int Widget::partition(double numbers[], int aL, int aR)
{
  int i = aL - 1;
  int j = aR;
  double v = numbers[aR];
  for(;;)
  {
    while(numbers[++i] < v)
      ;

    while(v < numbers[--j])
      if(j == aL)
        break;

    if( i >= j)
      break;

    swap(numbers[i], numbers[j]);
  }

  swap(numbers[i], numbers[aR]);
  return i;
}




///
void Widget::swap(double &aA, double &aB)
{
  double t = aA;
  aA = aB;
  aB = t;
}

void Widget::comb(double mass[], int rows)
{
    QElapsedTimer timer;
    timer.start();
    int start_time =  clock();
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
    int end_time = clock();
    long long elapsed = timer.nsecsElapsed();
    timee(0, elapsed);
    table_sort(mass, x);
}

void Widget::gnome(double mass[], int rows)
{
    QElapsedTimer timer;
    timer.start();
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
    int end_time = clock();
    long long elapsed = timer.nsecsElapsed();
    timee(0, elapsed);
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
    QElapsedTimer timer;
    timer.start();
    int x = rows;
    while (!isSorted(mass, rows))
    {
        shuffle(mass, rows);
    }
    int end_time = clock();
    int elapsed = timer.nsecsElapsed();
    timee(0, elapsed);
    table_sort(mass, x);
}

void Widget::on_pushButton_find_clicked()
{
    int rows = ui->tableWidget->rowCount();
    int h = 0;
    double *mass2 = new double[rows];
    QString number_str;
    double row_number;
    bool ok1, ok2, flag = true;
    for(int i=0;i<rows;i++){
        number_str = ui->tableWidget->item(i,0)->text();
        row_number = number_str.toDouble(&ok1);
        mass2[i]=row_number;
        if(!ok1 or number_str == "")
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
        double *mass = new double[rows];
        double *ans = new double[rows];
        double key;
        int count = 0;
        QString key_str;
        key_str = ui->input_find->text();
        key = key_str.toDouble(&ok2);
        for(int i=0;i<rows;i++)
        {
            bool ok1;
            mass[i] = ui->tableWidget->item(i, 0)->text().toDouble(&ok1);
        }
        if(ok2)
        {
            bool flag_sort = true;
            for (int i=0; i < rows - 1; i++)
                {
                     if (mass[i] > mass[i + 1])
                     {
                        flag_sort = false;
                        break;
                     }
                }
            if(flag_sort)
            {
                bool flag = false;
                int l = 0;
                int r = rows - 1;
                int mid;

                while ((l <= r) && (flag != true))
                {
                    mid = (l + r) / 2;

                    if (mass[mid] == key)
                        flag = true;
                    if (mass[mid] > key)
                        r = mid - 1;
                    else
                        l = mid + 1;
                }
                if (flag)
                {
                    QString ans_str;
                    ui->output_find->setText("");
                    ui->output_method->setText("Бинарный");
                    bool flag_check = false;
                    QElapsedTimer timer;
                    timer.start();
                    for (int i = mid - 1; i >= 0; i--)
                        {
                             if (mass[i] < mass[mid])
                             {
                                break;
                             }
                             else
                             {
                                 ans_str = QString::number(1 + i);
                                 if(i == mid - 1)
                                 {
                                     ui->output_find->insert(ans_str);
                                     ui->tableWidget->item(i,0)->setBackgroundColor(Qt::green);
                                     flag_check = true;
                                 }
                                 else
                                 {
                                    ui->output_find->insert(", " + ans_str);
                                    ui->tableWidget->item(i,0)->setBackgroundColor(Qt::green);
                                 }
                                 count++;
                             }
                        }
                    ans_str = QString::number(mid + 1);
                    ui->tableWidget->item(mid,0)->setBackgroundColor(Qt::green);
                    if(flag_check)
                        ui->output_find->insert(", " + ans_str);
                    else
                        ui->output_find->insert(ans_str);
                    for (int i=mid+1; i < rows; i++)
                        {
                             if (mass[mid] < mass[i])
                             {
                                ui->tableWidget->scrollToItem(ui->tableWidget->item(mid,0));
                                break;
                             }
                             else
                             {
                                 ans_str = QString::number(1 + i);
                                 ui->output_find->insert(", " + ans_str);
                                 ui->tableWidget->item(i,0)->setBackgroundColor(Qt::green);
                                 ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
                                 count++;
                             }
                        }
                    int elapsed = timer.nsecsElapsed();
                    timee(0, elapsed);
                    QString count_str = QString::number(count+1);
                    ui->output_count->setText(count_str);


                }
                else
                {
                    ui->output_find->setText("Не найдено");
                    ui->output_count->setText("");
                    ui->output_method->setText("");
                }
                ui->error->setText("");
            }
            else
            {
                QElapsedTimer timer;
                timer.start();
                for (int i = 0; i < rows; i++)
                {
                    if (mass[i] == key)
                    {
                      ui->tableWidget->item(i,0)->setBackgroundColor(Qt::green);
                      ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
                      ans[h] = i+1;
                      h++;
                    }
                }

                if(h != 0)
                {
                    QString ans_str;
                    ui->output_find->setText("");
                    for (int i = 0; i < h; i++)
                    {
                        ans_str = QString::number(ans[i]);
                        if(i == 0)
                        ui->output_find->insert(ans_str);
                        else
                        ui->output_find->insert(", " + ans_str);
                    }
                ui->error->setText("");
                }
                else
                {
                    ui->output_find->setText("Не найдено");
                    ui->output_count->setText("");
                    ui->output_method->setText("");
                    ui->error->setText("");
                }
                int elapsed = timer.nsecsElapsed();
                timee(0, elapsed);
                count = h;
                QString count_str = QString::number(count);
                ui->output_count->setText(count_str);
                ui->output_method->setText("Линейный");
            }
        delete [] mass;
        delete [] ans;
        }
        else
        {
            ui->output_find->setText("");
            ui->output_count->setText("");
            ui->output_method->setText("");
            ui->error->setText("Не число");
        }
    }
    delete [] mass2;
}

void Widget::on_pushButton_delete_clicked()
{
    QElapsedTimer timer;
    timer.start();
    double *mass;
    double *temp;
    bool flag = true, flag_sort = true;
    QString number_str;
    int rows = ui->tableWidget->rowCount();
    mass = new double[rows];
    for(int i=0;i<rows;i++)
    {
        bool ok1;
        mass[i] = ui->tableWidget->item(i, 0)->text().toDouble(&ok1);
        number_str = ui->tableWidget->item(i,0)->text();
        if(!ok1 or number_str == "")
        {
            flag=false;
            ui->tableWidget->item(i,0)->setBackground(Qt::red);
        }
        else
        {
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        }
    }
    if(flag)
    {
        bool flag_sort = true;
        for (int i=0; i < rows - 1; i++)
            {
                 if (mass[i] > mass[i + 1])
                 {
                    flag_sort = false;
                    break;
                 }
            }
        if(flag_sort)
        {
            ui->error->setText("");
            temp = new double[rows];
            int k = 0;
            for (int i=0; i<rows-1; i++)
                if (mass[i] != mass[i+1])
                {
                    temp[k++] = mass[i];
                }
                temp[k++] = mass[rows-1];
                for (int i=0; i<k; i++)
                {
                    mass[i] = temp[i];
                }
            int delete_count_per = rows - k;
            rows = k;
            int elapsed = timer.nsecsElapsed();
            timee(0, elapsed);
            table_sort(mass, rows);
            QString delete_count_str = QString::number(delete_count_per);
            ui->delete_count->setText(delete_count_str);
            delete temp;
            delete mass;
        }
        else
        {
            ui->error->setText("Нельзя удалить дубликаты в неотсортированной таблице");
        }
    }
    else
    {
        ui->error->setText("В таблице присутствуют не числа");
    }
}
