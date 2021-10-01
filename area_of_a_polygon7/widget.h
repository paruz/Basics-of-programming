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
    void on_plus_clicked();

    void on_minus_clicked();

    void on_pushButton_S_clicked();

    void on_pushButton_P_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
