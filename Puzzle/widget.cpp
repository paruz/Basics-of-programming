#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <ctime>
#include <QElapsedTimer>
#include <QFile>
#include <QTextStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->Button44->hide(); //Прячет кнопку, которая стоит в 4 строке и в 4 столбце.
    ui->ButtonSaveResult->hide();
    ui->ButtonShowResult->hide();
    ui->time->hide();
    ui->textEdit->hide();
}
bool flag11, flag12, flag13, flag14, flag21, flag22, flag23, flag24, flag31, flag32, flag33, flag34, flag41, flag42, flag43, flag44 = true;
//Каждый флаг привязан к определённой кнопе, где первая цифра - это номер строчки, а вторая - номер столбца этой кнопки.
//Если flag = true - это значит, что в данный момент вместо кнопки пустота.

QString str11, str12, str13, str14, str21, str22, str23, str24, str31, str32, str33, str34, str41, str42, str43;
//Каждая переменная привязана к определённой кнопе, где первая цифра - это номер строчки, а вторая - номер столбца этой кнопки.
//Они хранят текстовое значение каждой кнопки.

bool flag3x3;
//Переменная, которая помогает определить 3 на 3 или 4 на 4 игровое поле. Если flag3x3 = true, значит 3 на 3, если false, значит 4 на 4.

QElapsedTimer timer1;
bool flag_check_time;
Widget::~Widget()
{
    delete ui;
}

void Widget::on_Button11_clicked() //Срабатывает, если нажали на кнопку, которая стоит в первой строке и в первом столбце. Аналогично и для других кнопок
{
    if (flag12) //Если справа от этой кнопки пустое пространство.
    {
        ui->Button12->setText(ui->Button11->text()); //Кнопка, которая стоит справа принимает значение левой кнопки.
        flag12 = false; //Это значит, что кнопка, которая стоит в первой строке и во втором столбце теперь видна.
        ui->Button12->show(); //Делает кнопку видимой
        ui->Button11->hide(); //Делает кнопку невидимой
        flag11 = true; //Это значит, что кнопка, которая стоит в первой строке и в первом столбце теперь невидимая.
    }

    if (flag21) // Всё аналогично, только теперь кнопка находится не справа, а снизу.
    {
        ui->Button21->setText(ui->Button11->text());
        flag21 = false;
        ui->Button21->show();
        ui->Button11->hide();
        flag11 = true;
    }
}

void Widget::on_Button12_clicked() // Следующие функции будут работат аналагично.
{
    if (flag11)
    {
        ui->Button11->setText(ui->Button12->text());
        flag11 = false;
        ui->Button11->show();
        ui->Button12->hide();
        flag12 = true;
    }

    if (flag13)
    {
        ui->Button13->setText(ui->Button12->text());
        flag13 = false;
        ui->Button13->show();
        ui->Button12->hide();
        flag12 = true;
    }

    if (flag22)
    {
        ui->Button22->setText(ui->Button12->text());
        flag22 = false;
        ui->Button22->show();
        ui->Button12->hide();
        flag12 = true;
    }
}

void Widget::on_Button13_clicked()
{
    if (flag12)
    {
        ui->Button12->setText(ui->Button13->text());
        flag12 = false;
        ui->Button12->show();
        ui->Button13->hide();
        flag13 = true;
    }

    if (flag14)
    {
        ui->Button14->setText(ui->Button13->text());
        flag14 = false;
        ui->Button14->show();
        ui->Button13->hide();
        flag13 = true;
    }

    if (flag23)
    {
        ui->Button23->setText(ui->Button13->text());
        flag23 = false;
        ui->Button23->show();
        ui->Button13->hide();
        flag13 = true;
    }
}

void Widget::on_Button14_clicked()
{
    if (flag13)
    {
        ui->Button13->setText(ui->Button14->text());
        flag13 = false;
        ui->Button13->show();
        ui->Button14->hide();
        flag14 = true;
    }

    if (flag24)
    {
        ui->Button24->setText(ui->Button14->text());
        flag24 = false;
        ui->Button24->show();
        ui->Button14->hide();
        flag14 = true;
    }
}

void Widget::on_Button21_clicked()
{
    if (flag11)
    {
        ui->Button11->setText(ui->Button21->text());
        flag11 = false;
        ui->Button11->show();
        ui->Button21->hide();
        flag21 = true;
    }

    if (flag22)
    {
        ui->Button22->setText(ui->Button21->text());
        flag22 = false;
        ui->Button22->show();
        ui->Button21->hide();
        flag21 = true;
    }

    if (flag31)
    {
        ui->Button31->setText(ui->Button21->text());
        flag31 = false;
        ui->Button31->show();
        ui->Button21->hide();
        flag21 = true;
    }
}

void Widget::on_Button22_clicked()
{
    if (flag12)
    {
        ui->Button12->setText(ui->Button22->text());
        flag12 = false;
        ui->Button12->show();
        ui->Button22->hide();
        flag22 = true;
    }

    if (flag21)
    {
        ui->Button21->setText(ui->Button22->text());
        flag21 = false;
        ui->Button21->show();
        ui->Button22->hide();
        flag22 = true;
    }

    if (flag23)
    {
        ui->Button23->setText(ui->Button22->text());
        flag23 = false;
        ui->Button23->show();
        ui->Button22->hide();
        flag22 = true;
    }

    if (flag32)
    {
        ui->Button32->setText(ui->Button22->text());
        flag32 = false;
        ui->Button32->show();
        ui->Button22->hide();
        flag22 = true;
    }
}

void Widget::on_Button23_clicked()
{
    if (flag13)
    {
        ui->Button13->setText(ui->Button23->text());
        flag13 = false;
        ui->Button13->show();
        ui->Button23->hide();
        flag23 = true;
    }

    if (flag22)
    {
        ui->Button22->setText(ui->Button23->text());
        flag22 = false;
        ui->Button22->show();
        ui->Button23->hide();
        flag23 = true;
    }

    if (flag24)
    {
        ui->Button24->setText(ui->Button23->text());
        flag24 = false;
        ui->Button24->show();
        ui->Button23->hide();
        flag23 = true;
    }

    if (flag33)
    {
        ui->Button33->setText(ui->Button23->text());
        flag33 = false;
        ui->Button33->show();
        ui->Button23->hide();
        flag23 = true;
    }
}

void Widget::on_Button24_clicked()
{
    if (flag14)
    {
        ui->Button14->setText(ui->Button24->text());
        flag14 = false;
        ui->Button14->show();
        ui->Button24->hide();
        flag24 = true;
    }

    if (flag23)
    {
        ui->Button23->setText(ui->Button24->text());
        flag23 = false;
        ui->Button23->show();
        ui->Button24->hide();
        flag24 = true;
    }

    if (flag34)
    {
        ui->Button34->setText(ui->Button24->text());
        flag34 = false;
        ui->Button34->show();
        ui->Button24->hide();
        flag24 = true;
    }
}

void Widget::on_Button31_clicked()
{
    if (flag21)
    {
        ui->Button21->setText(ui->Button31->text());
        flag21 = false;
        ui->Button21->show();
        ui->Button31->hide();
        flag31 = true;
    }

    if (flag32)
    {
        ui->Button32->setText(ui->Button31->text());
        flag32 = false;
        ui->Button32->show();
        ui->Button31->hide();
        flag31 = true;
    }

    if (flag41)
    {
        ui->Button41->setText(ui->Button31->text());
        flag41 = false;
        ui->Button41->show();
        ui->Button31->hide();
        flag31 = true;
    }
}

void Widget::on_Button32_clicked()
{
    if (flag22)
    {
        ui->Button22->setText(ui->Button32->text());
        flag22 = false;
        ui->Button22->show();
        ui->Button32->hide();
        flag32 = true;
    }

    if (flag31)
    {
        ui->Button31->setText(ui->Button32->text());
        flag31 = false;
        ui->Button31->show();
        ui->Button32->hide();
        flag32 = true;
    }

    if (flag33)
    {
        ui->Button33->setText(ui->Button32->text());
        flag33 = false;
        ui->Button33->show();
        ui->Button32->hide();
        flag32 = true;
    }

    if (flag42)
    {
        ui->Button42->setText(ui->Button32->text());
        flag42 = false;
        ui->Button42->show();
        ui->Button32->hide();
        flag32 = true;
    }
}

void Widget::on_Button33_clicked()
{
    if (flag23)
    {
        ui->Button23->setText(ui->Button33->text());
        flag23 = false;
        ui->Button23->show();
        ui->Button33->hide();
        flag33 = true;
    }

    if (flag32)
    {
        ui->Button32->setText(ui->Button33->text());
        flag32 = false;
        ui->Button32->show();
        ui->Button33->hide();
        flag33 = true;
    }

    if (flag34)
    {
        ui->Button34->setText(ui->Button33->text());
        flag34 = false;
        ui->Button34->show();
        ui->Button33->hide();
        flag33 = true;
    }
    if (flag43)
    {
        ui->Button43->setText(ui->Button33->text());
        flag43 = false;
        ui->Button43->show();
        ui->Button33->hide();
        flag33 = true;
    }
}

void Widget::on_Button34_clicked()
{
    if (flag24)
    {
        ui->Button24->setText(ui->Button34->text());
        flag24 = false;
        ui->Button24->show();
        ui->Button34->hide();
        flag34 = true;
    }

    if (flag33)
    {
        ui->Button33->setText(ui->Button34->text());
        flag33 = false;
        ui->Button33->show();
        ui->Button34->hide();
        flag34 = true;
    }
    if (flag44)
    {
        ui->Button44->setText(ui->Button34->text());
        flag44 = false;
        ui->Button44->show();
        ui->Button34->hide();
        flag34 = true;
        ui->Button34->setText(ui->Button24->text());
    }
}

void Widget::on_Button41_clicked()
{
    if (flag31)
    {
        ui->Button31->setText(ui->Button41->text());
        flag31 = false;
        ui->Button31->show();
        ui->Button41->hide();
        flag41 = true;
    }

    if (flag42)
    {
        ui->Button42->setText(ui->Button41->text());
        flag42 = false;
        ui->Button42->show();
        ui->Button41->hide();
        flag41 = true;
    }
}

void Widget::on_Button42_clicked()
{
    if (flag32)
    {
        ui->Button32->setText(ui->Button42->text());
        flag32 = false;
        ui->Button32->show();
        ui->Button42->hide();
        flag42 = true;
    }

    if (flag41)
    {
        ui->Button41->setText(ui->Button42->text());
        flag41 = false;
        ui->Button41->show();
        ui->Button42->hide();
        flag42 = true;
    }

    if (flag43)
    {
        ui->Button43->setText(ui->Button42->text());
        flag43 = false;
        ui->Button43->show();
        ui->Button42->hide();
        flag42 = true;
    }
}

void Widget::on_Button43_clicked()
{
    if (flag33)
    {
        ui->Button33->setText(ui->Button43->text());
        flag33 = false;
        ui->Button33->show();
        ui->Button43->hide();
        flag43 = true;
    }

    if (flag42)
    {
        ui->Button42->setText(ui->Button43->text());
        flag42 = false;
        ui->Button42->show();
        ui->Button43->hide();
        flag43 = true;
    }

    if (flag44)
    {
        ui->Button44->setText(ui->Button43->text());
        flag44 = false;
        ui->Button44->show();
        ui->Button43->hide();
        flag43 = true;
        ui->Button43->setText(ui->Button42->text());
    }
}

void Widget::on_Button44_clicked()
{
    if (flag34)
    {
        ui->Button34->setText(ui->Button44->text());
        flag34 = false;
        ui->Button34->show();
        ui->Button44->hide();
        flag44 = true;
    }

    if (flag43)
    {
        ui->Button43->setText(ui->Button44->text());
        flag43 = false;
        ui->Button43->show();
        ui->Button44->hide();
        flag44 = true;

    }
}


void Widget::on_win_clicked() //Проверка на победу игрока
{
    if (flag3x3) // если поле 3 на 3
    {
        if(ui->Button11->text() == "1" and ui->Button12->text() == "2" and ui->Button13->text() == "3" and
           ui->Button21->text() == "4" and ui->Button22->text() == "5" and ui->Button23->text() == "6" and
           ui->Button31->text() == "7" and ui->Button32->text() == "8") // Значение каждой кнопки сравнивается с выигрышным значением
        {
            QMessageBox msgBox; // объявление msgBox
            msgBox.setText("Молодец!     "); // в появившемся окне пишется текст "Молодец!"
            msgBox.exec(); // окно закрывается, после нажатия пользователь кнопки "ок"
            bool flag = false;
            timer(flag);
        }
        else
        {
            QMessageBox msgBox; // объявление msgBox
            msgBox.setText("Ещё нет.     "); // в появившемся окне пишется текст "Ещё нет."
            msgBox.exec(); // окно закрывается, после нажатия пользователь кнопки "ок"
        }
    }
    else // если поле 4 на 4
    {
        if(ui->Button11->text() == "1" and ui->Button12->text() == "2" and ui->Button13->text() == "3" and ui->Button14->text() == "4" and
           ui->Button21->text() == "5" and ui->Button22->text() == "6" and ui->Button23->text() == "7" and ui->Button24->text() == "8" and
           ui->Button31->text() == "9" and ui->Button32->text() == "10" and ui->Button33->text() == "11" and ui->Button34->text() == "12" and
           ui->Button41->text() == "13" and ui->Button42->text() == "14" and ui->Button43->text() == "15") // Значение каждой кнопки сравнивается с выигрышным значением
        {
            QMessageBox msgBox; // объявление msgBox
            msgBox.setText("Молодец!     "); // в появившемся окне пишется текст "Молодец!"
            msgBox.exec(); // окно закрывается, после нажатия пользователь кнопки "ок"
            bool flag = false;
            timer(flag);
        }
        else
        {
            QMessageBox msgBox; // объявление msgBox
            msgBox.setText("Ещё нет.     "); // в появившемся окне пишется текст "Ещё нет."
            msgBox.exec(); // окно закрывается, после нажатия пользователь кнопки "ок"
        }
    }
}

void Widget::on_create_clicked() // создание игрового поля
{
    if (ui->radioButton_easy->isChecked()) // если выбрана лёгкая сложность
    {
        flag3x3 = true;
        flag11 = false; flag12 = false; flag13 = false; flag14 = false;
        flag21 = false; flag22 = false; flag23 = false; flag24 = false;
        flag31 = false; flag32 = false; flag33 = true; flag34 = false;
        flag41 = false; flag42 = false; flag43 = false; flag44 = false;
        // Создание поля 3 на 3

        ui->Button11->show(); ui->Button12->show(); ui->Button13->show(); ui->Button14->hide();
        ui->Button21->show(); ui->Button22->show(); ui->Button23->show(); ui->Button24->hide();
        ui->Button31->show(); ui->Button32->show(); ui->Button33->hide(); ui->Button34->hide();
        ui->Button41->hide(); ui->Button42->hide(); ui->Button43->hide(); ui->Button44->hide();

        int mass[8]; // создание массива на 8 элементов
        for (int i = 0; i < 8; i++) // Заполнение массива цифрами от 1 до 8
        {
            mass[i] = i+1;
        }
        for (int i = 0; i < 8; i++) // Перемешивание массива через рандом
        {
            int temp;
            int rnd = rand() % 8;
            temp = mass[i];
            mass[i] = mass[rnd];
            mass[rnd] = temp;
        }
        ui->Button11->setText(str11 = QString::number(mass[0])); // Присвоение каждой кнопке значения элемента в массиве
        ui->Button12->setText(str12 = QString::number(mass[1]));
        ui->Button13->setText(str13 = QString::number(mass[2]));
        ui->Button21->setText(str21 = QString::number(mass[3]));
        ui->Button22->setText(str22 = QString::number(mass[4]));
        ui->Button23->setText(str23 = QString::number(mass[5]));
        ui->Button31->setText(str31 = QString::number(mass[6]));
        ui->Button32->setText(str32 = QString::number(mass[7]));
    }
    else // если выбрана средняя сложность
    {
        flag3x3 = false;
        flag11 = false; flag12 = false; flag13 = false; flag14 = false;
        flag21 = false; flag22 = false; flag23 = false; flag24 = false;
        flag31 = false; flag32 = false; flag33 = false; flag34 = false;
        flag41 = false; flag42 = false; flag43 = false; flag44 = true;
        // Создание поля 4 на 4

        ui->Button11->show(); ui->Button12->show(); ui->Button13->show(); ui->Button14->show();
        ui->Button21->show(); ui->Button22->show(); ui->Button23->show(); ui->Button24->show();
        ui->Button31->show(); ui->Button32->show(); ui->Button33->show(); ui->Button34->show();
        ui->Button41->show(); ui->Button42->show(); ui->Button43->show(); ui->Button44->hide();

        int mass[15]; // создание массива на 15 элементов
        for (int i = 0; i < 15; i++) // Заполнение массива цифрами от 1 до 15
        {
            mass[i] = i+1;
        }

        for (int i = 0; i < 15; i++) // Перемешивание массива через рандом
        {
            int temp;
            int rnd = rand() % 15;
            temp = mass[i];
            mass[i] = mass[rnd];
            mass[rnd] = temp;
        }

        ui->Button11->setText(str11 = QString::number(mass[0])); // Присвоение каждой кнопке значения элемента в массиве
        ui->Button12->setText(str12 = QString::number(mass[1]));
        ui->Button13->setText(str13 = QString::number(mass[2]));
        ui->Button14->setText(str14 = QString::number(mass[3]));
        ui->Button21->setText(str21 = QString::number(mass[4]));
        ui->Button22->setText(str22 = QString::number(mass[5]));
        ui->Button23->setText(str23 = QString::number(mass[6]));
        ui->Button24->setText(str24 = QString::number(mass[7]));
        ui->Button31->setText(str31 = QString::number(mass[8]));
        ui->Button32->setText(str32 = QString::number(mass[9]));
        ui->Button33->setText(str33 = QString::number(mass[10]));
        ui->Button34->setText(str34 = QString::number(mass[11]));
        ui->Button41->setText(str41 = QString::number(mass[12]));
        ui->Button42->setText(str42 = QString::number(mass[13]));
        ui->Button43->setText(str43 = QString::number(mass[14]));
    }
    bool flag = true;
    timer(flag);
    ui->ButtonSaveResult->hide();
    ui->ButtonShowResult->hide();
    ui->time->hide();
    ui->textEdit->hide();
}

void Widget::on_help_clicked() // Помощь пользователю, меняет местами два нижних элемента
{
    QString tmp;
    if (flag3x3 and !flag31 and !flag32) // Если поле 3 на 3 и нижние элементы не скрыты
    {
        tmp = ui->Button31->text();
        ui->Button31->setText(ui->Button32->text());
        ui->Button32->setText(tmp);
    }
    else if(!flag3x3 and !flag42 and !flag43) // Если поле 4 на 4 и нижние элементы не скрыты
    {
        tmp = ui->Button42->text();
        ui->Button42->setText(ui->Button43->text());
        ui->Button43->setText(tmp);
    }
    else // Если нижние элементы скрыты
    {
        QMessageBox msgBox;
        msgBox.setText("Помощь пока не нужна, попробуй сам     ");
        msgBox.exec();
    }
}
void Widget::timer(bool flag)
{
    if (flag)
    {
        timer1.start();
        flag_check_time = true;
    }

    if (!flag and flag_check_time)
    {
        ui->ButtonSaveResult->show();
        ui->ButtonShowResult->show();
        ui->time->show();
        long long elapsed = timer1.nsecsElapsed();
        long long time = elapsed/1e9;
        QString elapsed_str;
        if(time / 60 > 0)
        {
            int time_sec = time % 60;
            int time_min = time / 60;
            QString time_sec_str = QString::number(time_sec);
            QString time_min_str = QString::number(time_min);
            ui->time->setText(time_min_str + " мин " + time_sec_str + " сек");
        }
        else
        {
            QString time_sec_str = QString::number(time);
            ui->time->setText(time_sec_str + " сек");
        }
        flag_check_time = false;
    }
}
void Widget::on_ButtonSaveResult_clicked()
{
    if (flag3x3)
    {
        QFile file("C:/Qt/results_3x3.txt");
        file.open(QFile::WriteOnly | QFile::ReadOnly | QFile::Text);
        QTextStream writeData(&file);
        QString fileText = writeData.readAll();
        fileText = ui->name->text() + ", Время: " + ui->time->text() + "\n";
        writeData << fileText;
        file.flush();
        file.close();
        ui->ButtonSaveResult->hide();
    }
    else
    {
        QFile file("C:/Qt/results_4x4.txt");
        file.open(QFile::WriteOnly | QFile::ReadOnly | QFile::Text);
        QTextStream writeData(&file);
        QString fileText = writeData.readAll();
        fileText = ui->name->text() + ", Время: " + ui->time->text() + "\n";
        writeData << fileText;
        file.flush();
        file.close();
        ui->ButtonSaveResult->hide();
    }
}

void Widget::on_ButtonShowResult_clicked()
{
    if (flag3x3)
    {
        QFile file("C:/Qt/results_3x3.txt");
        file.open(QFile::WriteOnly | QFile::ReadOnly | QFile::Text);
        QTextStream writeData(&file);
        QString fileText = writeData.readAll();
        ui->textEdit->show();
        ui->textEdit->setText(fileText);
    }
    else
    {
        QFile file("C:/Qt/results_4x4.txt");
        file.open(QFile::WriteOnly | QFile::ReadOnly | QFile::Text);
        QTextStream writeData(&file);
        QString fileText = writeData.readAll();
        ui->textEdit->show();
        ui->textEdit->setText(fileText);
    }
}
