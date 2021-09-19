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
    void on_operand1_activated(int index);

    void on_operand2_activated(int index);

    void on_operation_activated(int index);

    void calculate();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
