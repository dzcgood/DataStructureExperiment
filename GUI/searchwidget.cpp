#include "searchwidget.h"
#include "ui_searchwidget.h"
#include"student.h"
#include <QMessageBox>
#include <QDebug>
#include"mainwidget.h"
extern student*first;
extern QString fileName;

searchWidget::searchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchWidget)
{
    ui->setupUi(this);
}

searchWidget::~searchWidget()
{
    delete ui;
}

void searchWidget::on_returnButton_clicked()
{
    emit display(0);
}

void searchWidget::on_addButton_clicked()
{
    emit display(1);
}

void searchWidget::on_changeButton_clicked()
{
    emit display(2);
}

void searchWidget::on_insertButton_clicked()
{
    emit display(3);
}
void searchWidget::on_delButton_clicked()
{
    emit display(4);
}

void searchWidget::on_readButton_clicked()
{
    emit display(5);
}

void searchWidget::on_writeButton_clicked()
{
    emit display(6);
}

void searchWidget::on_rankButton_clicked()
{
    emit display(7);
}

void searchWidget::on_listButton_clicked()
{
    emit display(9);
}

void searchWidget::on_establishButton_clicked()
{
    emit display(10);
}

void searchWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

void searchWidget::on_searchingButton_clicked()
{
    //将用户输入的学号由numberLineEdit取出
    QString number = ui->numberLineEdit->text();
    student *current=first;
    //若链表为空。输出提示
    if(first==0)
    {
        QMessageBox::about(NULL, "output", "no information");
        ui->numberLineEdit->clear();
        return;
    }
    //判断有无目标节点
    while(current->getNumber()!=number)
    {
        current=current->next;
        if(current==0)break;
    }
    //若无，输出提示
    if(current==0)
    {
        QMessageBox::about(NULL, "output", "no information");
        ui->numberLineEdit->clear();
        return;
    }
    else
    {
        //设置列数为5
        ui->tableWidget->setColumnCount(5);
        QStringList headerLabels;
        //设置列名称
        headerLabels << tr("姓名") << tr("学号") << tr("性别") << tr("出生日期") << tr("健康") ;
        ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //设置行数为1
        ui->tableWidget->setRowCount(1);
        //输出
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(current->getName()));
        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(current->getNumber()));
        ui->tableWidget->setItem(0, 2, new QTableWidgetItem(current->getGender()));
        ui->tableWidget->setItem(0, 3, new QTableWidgetItem(current->getBirthday()));
        ui->tableWidget->setItem(0, 4, new QTableWidgetItem(current->getHealthCondition()));
        ui->numberLineEdit->clear();
    }
}
