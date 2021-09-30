#include "widget.h"
#include "ui_widget.h"
#include <QIntValidator>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->name_output->hide();
    ui->health->hide();
    ui->label_health->hide();
    ui->attack->hide();
    ui->label_attack->hide();
    ui->mana->hide();
    ui->label_mana->hide();
    ui->speed->hide();
    ui->label_speed->hide();
    ui->character_class->hide();
    ui->label_character_class->hide();

    QValidator *validator = new QIntValidator(1,10,this);
    ui->strength->setValidator(validator);
    ui->agility->setValidator(validator);
    ui->mind->setValidator(validator);
    ui->luck->setValidator(validator);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setColor(int vslue, QLineEdit *edit)

{
    if (vslue < 1)
        edit->setStyleSheet("background: red;");
    else if (vslue < 5)
        edit->setStyleSheet("background: orange;");
    else if (vslue < 8)
        edit->setStyleSheet("background: yellow;");
    else if (vslue < 11)
        edit->setStyleSheet("background: green;");
    else
        edit->setStyleSheet("background: red;");
}
//void Widget::setColor(int vslue)

//{
//    if (vslue < 1)
//        ui->strength->setStyleSheet("background: red;");
//    else if (vslue < 5)
//        ui->strength->setStyleSheet("background: orange;");
//    else if (vslue < 8)
//        ui->strength->setStyleSheet("background: yellow;");
//    else if (vslue < 11)
//        ui->strength->setStyleSheet("background: green;");
//    else
//        ui->strength->setStyleSheet("background: red;");
//}
void Widget::doit()
{
    QString sila_text, lovkost_text, intelekt_text, udacha_text, ochki_text;
    int sila, lovkost, intelekt, udacha, ochki;

    sila_text = ui->strength->text();
    lovkost_text = ui->agility->text();
    intelekt_text = ui->mind->text();
    udacha_text = ui->luck->text();
    ochki_text = ui->points->text();

    sila = sila_text.toInt();
    lovkost = lovkost_text.toInt();
    intelekt = intelekt_text.toInt();
    udacha = udacha_text.toInt();
    ochki = ochki_text.toInt();

    setColor(sila, ui->strength);
    setColor(lovkost, ui->agility);
    setColor(intelekt, ui->mind);
    setColor(udacha, ui->luck);

//    setColor(sila);
//    setColor(lovkost);
//    setColor(intelekt);
//    setColor(udacha);



//    if (sila < 1)
//        ui->strength->setStyleSheet("background: red;");
//    else if (sila < 5)
//        ui->strength->setStyleSheet("background: orange;");
//    else if (sila < 8)
//        ui->strength->setStyleSheet("background: yellow;");
//    else if (sila < 11)
//        ui->strength->setStyleSheet("background: green;");
//    else
//        ui->strength->setStyleSheet("background: red;");

//    if (lovkost < 1)
//        ui->agility->setStyleSheet("background: red;");
//    else if (lovkost < 5)
//        ui->agility->setStyleSheet("background: orange;");
//    else if (lovkost < 8)
//        ui->agility->setStyleSheet("background: yellow;");
//    else if (lovkost < 11)
//        ui->agility->setStyleSheet("background: green;");
//    else
//        ui->agility->setStyleSheet("background: red;");

//    if (intelekt < 1)
//        ui->mind->setStyleSheet("background: red;");
//    else if (intelekt < 5)
//        ui->mind->setStyleSheet("background: orange;");
//    else if (intelekt < 8)
//        ui->mind->setStyleSheet("background: yellow;");
//    else if (intelekt < 11)
//        ui->mind->setStyleSheet("background: green;");
//    else
//        ui->mind->setStyleSheet("background: red;");

//    if (udacha < 1)
//        ui->luck->setStyleSheet("background: red;");
//    else if (udacha < 5)
//        ui->luck->setStyleSheet("background: orange;");
//    else if (udacha < 8)
//        ui->luck->setStyleSheet("background: yellow;");
//    else if (udacha < 11)
//        ui->luck->setStyleSheet("background: green;");
//    else
//        ui->luck->setStyleSheet("background: red;");

    ochki_text = ui->strength->text();
    ochki = sila_text.toInt();
    ochki = 20 - sila - lovkost - intelekt - udacha;
    QString resStr = QString::number(ochki);
    ui->points->setText(resStr);

}
void Widget::on_strength_textChanged(const QString &arg1)
{
    doit();
}

void Widget::on_agility_textChanged(const QString &arg1)
{
    doit();
}

void Widget::on_mind_textChanged(const QString &arg1)
{
    doit();
}

void Widget::on_luck_textChanged(const QString &arg1)
{
    doit();
}

void Widget::on_man_toggled(bool checked)
{
    bool flag_man, flag_women;
    flag_man = true;
    flag_women = false;
}

void Widget::on_woman_toggled(bool checked)
{
    bool flag_man, flag_women;
    flag_man = false;
    flag_women = true;
}

void Widget::on_gender_currentIndexChanged(int index)
{

}

void Widget::on_pushButton_clicked()
{
    ui->name_output->hide();
    ui->health->hide();
    ui->label_health->hide();
    ui->attack->hide();
    ui->label_attack->hide();
    ui->mana->hide();
    ui->label_mana->hide();
    ui->speed->hide();
    ui->label_speed->hide();
    ui->character_class->hide();
    ui->label_character_class->hide();

    QString sila_text, lovkost_text, intelekt_text, udacha_text, ochki_text;
    QString ataka_text, zdorovie_text, mana_text, skorost_text;
    int sila, lovkost, intelekt, udacha, ochki, zdorovie, ataka, mana, skorost, index_gender;

    sila_text = ui->strength->text();
    lovkost_text = ui->agility->text();
    intelekt_text = ui->mind->text();
    udacha_text = ui->luck->text();
    ochki_text = ui->points->text();


    sila = sila_text.toInt();
    lovkost = lovkost_text.toInt();
    intelekt = intelekt_text.toInt();
    udacha = udacha_text.toInt();
    ochki = ochki_text.toInt();

    QString ime;
    ime = ui->name_input->text();
    if (ime == "")
        ui->error->setText("Имя не введено");
    else if (ochki > 0)
        ui->error->setText("Нужно потратить все очки");
    else if (ochki < 0)
        ui->error->setText("Потрачено слишком много очков");
    else if (((sila == 0) or (lovkost == 0) or (intelekt == 0) or (udacha == 0)) or ((sila > 10) or (lovkost > 10) or (intelekt > 10) or (udacha > 10)))
        ui->error->setText("Нужно ввести от 1 до 10");
    else
    {
        ui->error->setText("");
        ui->name_output->show();
        ui->health->show();
        ui->label_health->show();
        ui->attack->show();
        ui->label_attack->show();
        ui->mana->show();
        ui->label_mana->show();
        ui->speed->show();
        ui->label_speed->show();
        ui->character_class->show();
        ui->label_character_class->show();

        zdorovie = 10*(5*udacha + 3*intelekt + 2*sila + lovkost);
        ataka = 5*sila + 3*lovkost + 2*udacha + intelekt;
        mana = 5*intelekt + 3*udacha + 2*lovkost + sila;
        skorost = 5*lovkost + 3*sila + 2*intelekt + udacha;

        index_gender = ui->gender->currentIndex();
        if (index_gender == 0)
        {
            zdorovie = zdorovie + 100;
            ataka = ataka + 10;
            mana = mana + 10;
            skorost = skorost + 10;
        }
        else if (index_gender % 2 == 0)
        {
            zdorovie = zdorovie + 30;
            ataka = ataka + 16;
            mana = mana + 2;
            skorost = skorost + 15;
        }
        else if (index_gender % 2 == 1)
        {
            zdorovie = zdorovie + 150;
            ataka = ataka + 3;
            mana = mana + 16;
            skorost = skorost + 2;
        }
        if (ui->man->isChecked())
        {
            if ((zdorovie/10 >= ataka) and (zdorovie/10 >= mana) and (zdorovie/10 >= skorost))
                ui->character_class->setText("Воин");
            else if((ataka >= zdorovie/10) and (ataka >= mana) and (ataka >= skorost))
                ui->character_class->setText("Лучник");
            else if((mana >= zdorovie/10) and (mana >= ataka) and (mana >= skorost))
                ui->character_class->setText("Волшебник");
            else
                ui->character_class->setText("Призыватель");
        }
        else
        {
            if ((zdorovie/10 >= ataka) and (zdorovie/10 >= mana) and (zdorovie/10 >= skorost))
                ui->character_class->setText("Воительница");
            else if((ataka >= zdorovie/10) and (ataka >= mana) and (ataka >= skorost))
                ui->character_class->setText("Лучница");
            else if((mana >= zdorovie/10) and (mana >= ataka) and (mana >= skorost))
                ui->character_class->setText("Волшебница");
            else
                ui->character_class->setText("Призывательница");
        }
        zdorovie_text = QString::number(zdorovie);
        ui->health->setText(zdorovie_text);
        ataka_text = QString::number(ataka);
        ui->attack->setText(ataka_text);
        mana_text = QString::number(mana);
        ui->mana->setText(mana_text);
        skorost_text = QString::number(skorost);
        ui->speed->setText(skorost_text);
        ui->name_output->setText("Привет " + ime);
        ui->pushButton->setText("Применить изменения");
    }
}
