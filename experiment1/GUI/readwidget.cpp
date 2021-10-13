#include "readwidget.h"
#include "ui_readwidget.h"
#include"student.h"
#include"QMessageBox"
#include"QFile"
#include"QTextStream"
#include"mainwidget.h"
extern student*first;
extern QString fileName;
extern int sum;

readWidget::readWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::readWidget)
{
    ui->setupUi(this);
}

readWidget::~readWidget()
{
    delete ui;
}

void readWidget::on_returnButton_clicked()
{
    emit display(0);
}

void readWidget::on_addButton_clicked()
{
    emit display(1);
}

void readWidget::on_changeButton_clicked()
{
    emit display(2);
}

void readWidget::on_insertButton_clicked()
{
    emit display(3);
}

void readWidget::on_delButton_clicked()
{
    emit display(4);
}

void readWidget::on_writeButton_clicked()
{
    emit display(6);
}

void readWidget::on_rankButton_clicked()
{
    emit display(7);
}

void readWidget::on_searchButton_clicked()
{
    emit display(8);
}

void readWidget::on_listButton_clicked()
{
    emit display(9);
}

void readWidget::on_establishButton_clicked()
{
    emit display(10);
}

void readWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

void readWidget::on_readingButton_clicked()
{
    //将用户输入的文件由nameLineEdit取出
    QString name = ui->nameLineEdit->text();
    name=name+".txt";
    QFile file(name);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    //以只读方式打开文本文件
    QString number;
    QString gender;
    QString birthday;
    QString healthCondition;
    if(!file.isOpen())
    {
        //文件打开失败
        QMessageBox::about(NULL, "output", "fail to open the file");
        return ;
    }
    student*p;
    QTextStream in(&file);
    while(!in.atEnd())
    {
        //读到文件结尾
        in>> name >> number >> gender >> birthday >> healthCondition;
        p=new student;
        p->setName(name);
        p->setNumber(number);
        p->setGender(gender);
        p->setBirthday(birthday);
        p->setHealthCondition(healthCondition);
        p->next = first;//头插入方式，可以避免判断链表是否为空
        first = p;
        sum++;
    }
    file.close();
    //因为文件会多读取一行，所以将最后一次读取的内容删除
    student *q=first;
    first=first->next;
    delete q;
    sum--;
    //若链表为空，输出提示
    if (first == 0)
    {
        QMessageBox::about(NULL, "output", "error:no information in the txt");
        return;
    }
    QMessageBox::about(NULL, "output", "success");
    student *current=first;
    int i=0;
    while(current!=0)
    {
        //设置每行五列
        ui->tableWidget->setColumnCount(5);
        QStringList headerLabels;
        //设置列名称
        headerLabels << tr("姓名") << tr("学号") << tr("性别") << tr("出生日期") << tr("健康状况") ;
        ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //设置行数为数据总数
        ui->tableWidget->setRowCount(sum);//sum行数据
        //输出
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(current->getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(current->getNumber()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(current->getGender()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(current->getBirthday()));
        ui->tableWidget->setItem(i++, 4, new QTableWidgetItem(current->getHealthCondition()));
        current=current->next;
    }
}
