#include "insertwidget.h"
#include "ui_insertwidget.h"
#include"student.h"
#include"QMessageBox"
#include"mainwidget.h"
extern student*first;
extern QString fileName;
extern int sum;

insertWidget::insertWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insertWidget)
{
    ui->setupUi(this);
}

insertWidget::~insertWidget()
{
    delete ui;
}

void insertWidget::on_returnButton_clicked()
{
    emit display(0);
}

void insertWidget::on_addButton_clicked()
{
    emit display(1);
}

void insertWidget::on_changeButton_clicked()
{
    emit display(2);
}

void insertWidget::on_delButton_clicked()
{
    emit display(4);
}

void insertWidget::on_readButton_clicked()
{
    emit display(5);
}

void insertWidget::on_writeButton_clicked()
{
    emit display(6);
}

void insertWidget::on_rankButton_clicked()
{
    emit display(7);
}

void insertWidget::on_searchButton_clicked()
{
    emit display(8);
}

void insertWidget::on_listButton_clicked()
{
    emit display(9);
}

void insertWidget::on_establishButton_clicked()
{
    emit display(10);
}

void insertWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

void insertWidget::on_insertingButton_clicked()
{
    //将用户输入由文本框取出
    QString number = ui->numberLineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString gender = ui->genderLineEdit->text();
    QString birthday = ui->birthdayLineEdit->text();
    QString healthCondition = ui->healthConditionLineEdit->text();
    if(ui->addressLineEdit->text()==""||ui->nameLineEdit->text() == "" || ui->numberLineEdit->text() == ""
            || ui->genderLineEdit->text() == "" || ui->birthdayLineEdit->text() == ""
            || ui->healthConditionLineEdit->text() == "")
    {
        //输出提示信息
        QMessageBox::about(NULL, "output", "please fill all the blank");
        return;
    }
    //判断是否重复
    student *current=first;
    while(current->getNumber()!=number)
    {
        current=current->next;
        if(current==0)break;
    }
    //若重复，输出提示
    if(current!=0)
    {
        QMessageBox::about(NULL, "output", "information repeated");
        ui->numberLineEdit->clear();
        return;
    }
    //若链表为空，直接插入
    if(first==0)
    {
       student*p=new student;
       //赋值
       p->setName(name);
       p->setNumber(number);
       p->setGender(gender);
       p->setBirthday(birthday);
       p->setHealthCondition(healthCondition);
       first=p;
       first->next=0;
    }
    //将用户输入的位置由取出
    int address = ui->addressLineEdit->text().toInt();
    current=first;
    //将指针移动到待插入位置
    for (int i = 1; i <= address-2; i++)
    {
        current = current->next;
        if (current->next == 0&&i!=address-2)
        {
            //若链表长度小于用户输入
            QMessageBox::about(NULL, "output", "length error,it'll be added at last address");
            break;
        }
    }
    //执行插入操作
    student* p = new student;
    //赋值
    p->setName(name);
    p->setNumber(number);
    p->setGender(gender);
    p->setBirthday(birthday);
    p->setHealthCondition(healthCondition);
    //直接插入头节点
    if(address==1)
    {
        p->next=first;
        first=p;
    }
    //节点前后连接
    else
    {
        p->next = current->next;
        current->next = p;
    }
    QMessageBox::about(NULL,"output","success");
    //清空输入
    ui->nameLineEdit->clear();
    ui->numberLineEdit->clear();
    ui->genderLineEdit->clear();
    ui->birthdayLineEdit->clear();
    ui->healthConditionLineEdit->clear();
    ui->addressLineEdit->clear();
    sum++;
}
