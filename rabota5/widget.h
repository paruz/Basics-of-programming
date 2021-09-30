#ifndef WIDGET_H
#define WIDGET_H

#include <QLineEdit>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_strength_textChanged(const QString &arg1);

    void on_agility_textChanged(const QString &arg1);

    void on_mind_textChanged(const QString &arg1);

    void on_luck_textChanged(const QString &arg1);

    void on_man_toggled(bool checked);

    void on_woman_toggled(bool checked);

    void on_gender_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void doit();

    void setColor(int vslue, QLineEdit *edit);

   // void setColor(int vslue);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
