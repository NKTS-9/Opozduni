#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlRecord>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QSQLITE"); //соединение объекта БД с СУБД
    m_db.setDatabaseName("myDB");//определение имени БД
    query = new QSqlQuery(m_db);//создание объекта для запроса
    if(!m_db.open())
    throw "can't open database";// проверка на ошибку при открытии или создании БД
    if(!m_db.tables().contains("Order"))// если в базе не сущ. Таблица Order,то создание таблицы Order и заполнение данными
    {
        query->clear();// очистка запроса
        query->exec("CREATE TABLE Tech (ID INTEGER PRIMARY KEY, Name VARCHAR, OrdNum VARCHAR, Cost INTEGER,Year VARCHAR);");//исполнение запроса на добавление записи
        query->clear();
        query->exec("INSERT INTO Tech (ID, Name, OrdNum, Cost, Year) VALUES (1,'Ignatov A','3N-31251',15000,'12.12.2025');");
        query->clear();
        query->exec("INSERT INTO Tech (ID, Name, OrdNum, Cost, Year) VALUES (2,'Pilenko B','2C-00200',25000,'12.05.2014');");
    }
    model = new QSqlTableModel(this,m_db);// создание редактируемой модели БД

    model->setTable("Tech");// создание модели таблицы Order
    model->select();// заполнение модели данными

    model->setEditStrategy(QSqlTableModel::OnFieldChange);//выбор стратегии,сохранение изменений в БД, сохранение происходит при переходе к другому полю

    ui->tableView->setModel(model);// соединение модели и ее табличного представления в форме
    ui->NameAZ->setVisible(false);
    ui->NameZA->setVisible(false);
    ui->OrdNumAZ->setVisible(false);
    ui->OrdNumZA->setVisible(false);
    ui->Cost09->setVisible(false);
    ui->Cost09_2->setVisible(false);
    ui->Year09->setVisible(false);
    ui->Year90->setVisible(false);
    isClicked=false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete query;
    delete model;
}

void MainWindow::on_allDataViewButton_clicked()
{
    model->setSort(0,Qt::AscendingOrder);
    model->setFilter("");
    model->select();
    ui->tableView->setModel(model);
    for(int i=1;i<ui->tableView->model()->rowCount();i++)
        ui->tableView->setRowHidden(i,false);
    QMessageBox::information(nullptr,"Action","All data");

}

void MainWindow::on_numberOfSec_clicked()
{
    double all = 0;
    query->exec("SELECT SUM(Cost) FROM Tech");
    query->first();
    all = query->value(0).toInt();
    QString a;
    a.setNum(all);
    QMessageBox::information(nullptr,"Action",a);
}

void MainWindow::on_pushButtonRem_clicked()
{
    if(ui->lineEditID->text().isEmpty())
    return;
    QString id = ui->lineEditID->text();
    query->clear();
    query->exec(tr("DELETE FROM Tech WHERE ID=")+id);
    model->select();
    ui->lineEditID->clear();
}

void MainWindow::on_pushButtonAdd_clicked()
{
    if(ui->lineEditname->text().isEmpty()||ui->lineEditOrdNum->text().isEmpty()||ui->lineEditID->text().isEmpty()||ui->lineEditCost->text().isEmpty()||ui->lineEdityear->text().isEmpty())
    { QMessageBox::information(nullptr," ","Please enter all values!");
        return;
    }
    QString id = ui->lineEditID->text();
    QString surname = ui->lineEditname->text();
    QString university = ui->lineEditOrdNum->text();
    QString faculty = ui -> lineEditCost -> text();
    QString course = ui -> lineEdityear -> text();
    QString buf = tr("INSERT INTO Tech (ID, Name, OrdNum, Cost, Year) VALUES (")+id+tr(",'")
    +surname+tr("','")+university+tr("','")+faculty+tr("',")+course+tr(");");
    query->clear();
    query->exec(buf);
    model->select();
    ui->lineEditID->clear();
    ui->lineEdityear->clear();
    ui->lineEditCost->clear();
    ui->lineEditname->clear();
    ui->lineEditOrdNum->clear();
}

void MainWindow::on_action_triggered()
{
    if(!isClicked)
    {
        ui->NameAZ->setVisible(true);
        ui->NameZA->setVisible(true);
        ui->OrdNumAZ->setVisible(true);
        ui->OrdNumZA->setVisible(true);
        ui->Cost09->setVisible(true);
        ui->Cost09_2->setVisible(true);
        ui->Year09->setVisible(true);
        ui->Year90->setVisible(true);
        isClicked=true;
    }
    else if(isClicked)
    {
        ui->NameAZ->setVisible(false);
        ui->NameZA->setVisible(false);
        ui->OrdNumAZ->setVisible(false);
        ui->OrdNumZA->setVisible(false);
        ui->Cost09->setVisible(false);
        ui->Cost09_2->setVisible(false);
        ui->Year09->setVisible(false);
        ui->Year90->setVisible(false);
        isClicked=false;
    }
}

void MainWindow::sort(int a, int b)
{
    if (b==1)
    {
        model->setSort(a,Qt::AscendingOrder);
        model->select();// заполнение модели данными
        ui->tableView->setModel(model);// соединение модели и ее табличного представления в форме
    }
    if (b==2)
    {
        model->setSort(a,Qt::DescendingOrder);
        model->select();
        ui->tableView->setModel(model);
    }
}

void MainWindow::on_NameAZ_clicked(){sort(1,1);}

void MainWindow::on_NameZA_clicked(){sort(1,2);}

void MainWindow::on_OrdNumAZ_clicked(){sort(2,1);}

void MainWindow::on_OrdNumZA_clicked(){sort(2,2);}

void MainWindow::on_Cost09_clicked(){sort(3,1);}

void MainWindow::on_Cost09_2_clicked(){sort(3,2);}

void MainWindow::on_Year09_clicked(){sort(4,1);}

void MainWindow::on_Year90_clicked(){sort(4,2);}

