#include "readminstudent.h"
#include "ui_readminstudent.h"
#include"student.h"
#include<QQueue>
#include<QMessageBox>
extern student*root;
extern student*MIN;
readMinStudent::readMinStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::readMinStudent)
{
    ui->setupUi(this);
}

readMinStudent::~readMinStudent()
{
    delete ui;
}
void readMinStudent::on_returnButton_clicked()
{
    emit display(0);
}
void readMinStudent::on_addButton_clicked()
{
    emit display(1);
}
void readMinStudent::on_delButton_clicked()
{
    emit display(2);
}
void readMinStudent::on_establishButton_clicked()
{
    emit display(3);
}
void readMinStudent::on_outputButton_clicked()
{
    emit display(4);
}
void readMinStudent::on_outputMinButton_clicked()
{
    QQueue<student*>stu;
    student* p = root;
    if(p==0)
    {
        QMessageBox::about(NULL,"提示","无相关信息！");
        return;
    }
    MIN=root;
    stu.enqueue(p);
    while (!stu.empty())
    {
        p = stu.dequeue();
        if (p->leftChild)stu.enqueue(p->leftChild);
        if (p->rightChild)stu.enqueue(p->rightChild);
        if (p->isDeleted==0&&p->birthday>MIN->birthday)
            MIN = root;
    }
    //接下来输出MIN
    //设置列数为6
    ui->tableWidget->setColumnCount(6);
    QStringList headerLabels;
    //设置列名称
    headerLabels << tr("姓名") << tr("学号") << tr("性别")
                 << tr("生日") << tr("电话")<<tr("地址");
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //设置行数为sum
    ui->tableWidget->setRowCount(1);
    //输出
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(p->name));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(p->number));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(p->gender));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem(p->birthday));
    ui->tableWidget->setItem(0, 4, new QTableWidgetItem(p->phoneNumber));
    ui->tableWidget->setItem(0, 5, new QTableWidgetItem(p->address));
}
void readMinStudent::on_readButton_clicked()
{
    emit display(6);
}

void readMinStudent::on_searchNameButton_clicked()
{
    emit display(7);
}
void readMinStudent::on_searchNumButton_clicked()
{
    emit display(8);
}
void readMinStudent::on_searchPhoneNumButton_clicked()
{
    emit display(9);
}
void readMinStudent::on_writeButton_clicked()
{
    emit display(10);
}
void readMinStudent::on_exitButton_clicked()
{
    QApplication::exit();
}

