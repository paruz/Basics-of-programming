#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QFont>
#include <QColor>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_action_create_triggered()
{
    file_path="";
    ui->textEdit->setText("");
}

void MainWindow::on_action_open_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Открыть");
    QFile file (file_name);
    file_path = file_name;
    file.open(QFile::ReadOnly);
    QTextStream inputData(&file);
    QString fileText = inputData.readAll();
    ui->textEdit->setHtml(fileText);
    int name_length = file_name.size() - file_name.lastIndexOf("/") - 1;
    setWindowTitle(file_name.right(name_length));
    file.close();
}

void MainWindow::on_action_save_triggered()
{
   QFile file(file_path);
   if(!file.open(QFile::WriteOnly | QFile::Text))
   {
       QString file_name = QFileDialog::getSaveFileName(this, "Сохранить как", "", " (*.html);;All Files (*)");
       QFile file (file_name);
       file_path = file_name;
       QTextStream writeData(&file);
       QString fileText = ui->textEdit->toHtml();
       writeData << fileText;
       file.close();
   }
   else
   {
       QTextStream writeData(&file);
       QString fileText = ui->textEdit->toPlainText();
       writeData << fileText;
       file.close();
   }
}

void MainWindow::on_action_save_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Сохранить как", "", " (*.html);;All Files (*)");
    QFile file (file_name);
    file_path = file_name;
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream writeData(&file);
    QString fileText = ui->textEdit->toHtml();
    writeData << fileText;
    file.close();
}

void MainWindow::on_action_undo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_action_redo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_action_cut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_action_copy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_action_paste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_action_delete_triggered()
{
    ui->textEdit->clear();
}

void MainWindow::on_action_select_all_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_action_font_triggered()
{
    QFontDialog *fontDialog = new QFontDialog();
    fontDialog->setCurrentFont(ui->textEdit->currentFont());
    fontDialog->show();
    if(fontDialog->exec() == QFontDialog::Accepted)
    {
        ui->textEdit->setFont(fontDialog->selectedFont());
    }
}

void MainWindow::on_action_colour_triggered()
{
    QColorDialog *colorDialog = new QColorDialog();
    colorDialog->setCurrentColor(ui->textEdit->textColor());
    colorDialog->show();
    if(colorDialog->exec() == QColorDialog::Accepted)
    {
        ui->textEdit->setTextColor(colorDialog->selectedColor());
    }
}
