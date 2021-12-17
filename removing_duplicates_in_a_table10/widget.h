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

    //void fast(double mass[], int low, int high);

    void comb(double mass[], int rows);

    void gnome(double mass[], int rows);

    void monkey(double mass[], int rows);

    bool isSorted(double mass[], int rows);

    void shuffle(double mass[], int rows);

    void timee(long long start_time, long long end_time);

    int partition(double numbers[], int aL, int aR);

    void fast1(double a[],int start,int end);
    void fast(double a[],int start,int end);
    void on_pushButton_find_clicked();

    void on_pushButton_delete_clicked();

    void swap(double &aA, double &aB);

    void on_save_clicked();

    void on_open_clicked();

    int row_count();

private:
    Ui::Widget *ui;
    QString file_path;
};

#endif // WIDGET_H
