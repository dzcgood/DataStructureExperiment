#include "listwidget.h"
#include "ui_listwidget.h"
#include"student.h"
#include"QMessageBox"
#include"mainwidget.h"
extern student*first;
extern QString fileName;
extern int sum;

listWidget::listWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listWidget)
{
    ui->setupUi(this);
}

listWidget::~listWidget()
{
    delete ui;
}

void listWidget::on_returnButton_clicked()
{
    emit display(0);
}

void listWidget::on_addButton_clicked()
{
    emit display(1);
}

void listWidget::on_changeButton_clicked()
{
    emit display(2);
}

void listWidget::on_insertButton_clicked()
{
    emit display(3);
}

void listWidget::on_delButton_clicked()
{
    emit display(4);
}

void listWidget::on_readButton_clicked()
{
    emit display(5);
}

void listWidget::on_writeButton_clicked()
{
    emit display(6);
}

void listWidget::on_rankButton_clicked()
{
    emit display(7);
}

void listWidget::on_searchButton_clicked()
{
    emit display(8);
}

void listWidget::on_establishButton_clicked()
{
    emit display(10);
}

void listWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

void listWidget::on_listingButton_clicked()
{
    //若链表为空
    if(first==0)
        QMessageBox::about(NULL, "反馈", "信息为空");
    //若不为空
    else
    {
        student *current=first;
        int i=0;
        while(current!=0)
        {
            //设置列数为5
            ui->tableWidget->setColumnCount(5);
            QStringList headerLabels;
            //设置列名称
            headerLabels << tr("姓名") << tr("学号") << tr("性别") << tr("出生日期") << tr("健康");
            ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            //设置行数为sum
            ui->tableWidget->setRowCount(sum);
            //输出
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(current->getName()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(current->getNumber()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(current->getGender()));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(current->getBirthday()));
            ui->tableWidget->setItem(i++, 4, new QTableWidgetItem(current->getHealthCondition()));
            current=current->next;
        }
    }
}
