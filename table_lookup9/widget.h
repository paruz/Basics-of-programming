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

    void on_pushButton_random_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_sort_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_max_clicked();

    void on_pushButton_avg_clicked();

    void table_sort(double mass[], int rows);

    void bubble(double mass[], int rows);

    void fast(double mass[], int rows);

    void comb(double mass[], int rows);

    void gnome(double mass[], int rows);

    void monkey(double mass[], int rows);

    bool isSorted(double mass[], int rows);

    void shuffle(double mass[], int rows);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
