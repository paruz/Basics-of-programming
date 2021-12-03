#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
    void on_Button11_clicked();
    void on_Button12_clicked();
    void on_Button13_clicked();
    void on_Button14_clicked();
    void on_Button21_clicked();
    void on_Button22_clicked();
    void on_Button23_clicked();
    void on_Button24_clicked();
    void on_Button31_clicked();
    void on_Button32_clicked();
    void on_Button33_clicked();
    void on_Button34_clicked();
    void on_Button41_clicked();
    void on_Button42_clicked();
    void on_Button43_clicked();
    void on_Button44_clicked();

    void on_win_clicked();

    void on_create_clicked();

    void on_help_clicked();

    void timer(bool flag);

    void on_ButtonSaveResult_clicked();

    void on_ButtonShowResult_clicked();

private:
    Ui::Widget *ui;
    QString file_path;
};

#endif // WIDGET_H
