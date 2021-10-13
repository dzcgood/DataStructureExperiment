#include "delwidget.h"
#include "ui_delwidget.h"
#include"student.h"
#include"QMessageBox"
#include"mainwidget.h"
extern student*first;
extern QString fileName;
extern int sum;

delWidget::delWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delWidget)
{
    ui->setupUi(this);
}

delWidget::~delWidget()
{
    delete ui;
}

void delWidget::on_returnButton_clicked(){
    emit display(0);
}

void delWidget::on_addButton_clicked()
{
    emit display(1);
}

void delWidget::on_changeButton_clicked()
{
    emit display(2);
}

void delWidget::on_insertButton_clicked()
{
    emit display(3);
}

void delWidget::on_readButton_clicked()
{
    emit display(5);
}

void delWidget::on_writeButton_clicked()
{
    emit display(6);
}

void delWidget::on_rankButton_clicked()
{
    emit display(7);
}

void delWidget::on_searchButton_clicked()
{
    emit display(8);
}

void delWidget::on_listButton_clicked()
{
    emit display(9);
}

void delWidget::on_establishButton_clicked()
{
    emit display(10);
}

void delWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

void delWidget::on_delingButton_clicked()
{
    //将用户输入的学号由numberLineEdit取出
    QString number = ui->numberLineEdit->text();
    student *current=first;
    //链表为空，则输出提示
    if(first==0)
    {
        QMessageBox::about(NULL, "output", "no information");
        ui->numberLineEdit->clear();
        return;
    }
    //判断有无目标信息
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
    //若有，执行删除操作
    else
    {
        //头节点为目标节点
        if(current==first)
        {
            first=first->next;
            delete current;
        }
        //目标节点不是头节点
        else
        {
           student *prenode=first;
           //获取目标节点的前一节点
           while((prenode->next)->getNumber()!=number)
               prenode=prenode->next;
           prenode->next=current->next;
           delete current;
        }
         QMessageBox::about(NULL, "output","success!");
         //总数减1
         sum--;
    }
}
