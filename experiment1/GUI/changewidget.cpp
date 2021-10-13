#include "changewidget.h"
#include "ui_changewidget.h"
#include"student.h"
#include"QMessageBox"
#include"mainwidget.h"
extern student*first;
extern QString fileName;

changeWidget::changeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changeWidget)
{
    ui->setupUi(this);
}

changeWidget::~changeWidget()
{
    delete ui;
}

void changeWidget::on_returnButton_clicked(){
    emit display(0);
}

void changeWidget::on_addButton_clicked()
{

    emit display(1);
}

void changeWidget::on_insertButton_clicked()
{
    emit display(3);
}

void changeWidget::on_delButton_clicked()
{
    emit display(4);
}

void changeWidget::on_readButton_clicked()
{
    emit display(5);
}

void changeWidget::on_writeButton_clicked()
{
    emit display(6);
}

void changeWidget::on_rankButton_clicked()
{
    emit display(7);
}

void changeWidget::on_searchButton_clicked()
{
    emit display(8);
}

void changeWidget::on_listButton_clicked()
{
    emit display(9);
}

void changeWidget::on_establishButton_clicked()
{
    emit display(10);
}

void changeWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

void changeWidget::on_changingButton_clicked()
{
    //判断用户是否输入完整
    if(ui->numberLineEdit->text() == ""|| ui->healthConditionLineEdit->text() == "")
    {
        //输出提示信息
        QMessageBox::about(NULL, "output", "please fill all the blank");
        //清空用户输入
        ui->numberLineEdit->clear();
        ui->healthConditionLineEdit->clear();
        return;
    }
    //将用户输入的学号和新的健康状况由输入文本框取出
    QString number = ui->numberLineEdit->text();
    QString healthCondition = ui->healthConditionLineEdit->text();
    student *current=first;
    //若链表为空，输出提示
    if(first==0)
    {
        QMessageBox::about(NULL, "output", "no information");
        ui->numberLineEdit->clear();
        ui->healthConditionLineEdit->clear();
        return;
    }
    //判断目标节点是否存在
    while(current->getNumber()!=number)
    {
        current=current->next;
        if(current==0)break;
    }
    //若不存在，输出提示
    if(current==0)
    {
        QMessageBox::about(NULL, "output", "no information");
        ui->numberLineEdit->clear();
        ui->healthConditionLineEdit->clear();
        return;
    }
    //若存在，执行修改操作
    else
    {
        current->setHealthCondition(healthCondition);
        QMessageBox::about(NULL, "output", "success");
        //清空输入
        ui->numberLineEdit->clear();
        ui->healthConditionLineEdit->clear();
    }
}
