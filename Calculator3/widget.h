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
    void on_resultButton_clicked();

    void on_plus_toggled(bool checked);

    void on_minus_toggled(bool checked);

    void on_proizvedenie_toggled(bool checked);
    
    void on_delenie_toggled(bool checked);
    
    void on_koren_toggled(bool checked);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
