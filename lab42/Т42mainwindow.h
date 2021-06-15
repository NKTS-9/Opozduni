#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSql>

#include <string>

namespace Ui {

class MainWindow;

}

class MainWindow : public QMainWindow

{

Q_OBJECT

public:

explicit MainWindow(QWidget *parent = nullptr);

~MainWindow();

private slots:

void on_allDataViewButton_clicked();

void on_numberOfSec_clicked();

void on_pushButtonRem_clicked();

void on_pushButtonAdd_clicked();

void on_action_triggered();

void sort(int a, int b);

void on_NameAZ_clicked();

void on_NameZA_clicked();

void on_OrdNumAZ_clicked();

void on_OrdNumZA_clicked();

void on_Cost09_clicked();

void on_Cost09_2_clicked();

void on_Year09_clicked();

void on_Year90_clicked();

private:

Ui::MainWindow *ui;

QSqlDatabase m_db;

QSqlQuery* query;

QSqlTableModel* model;

bool isClicked;

};

#endif // MAINWINDOW_H
