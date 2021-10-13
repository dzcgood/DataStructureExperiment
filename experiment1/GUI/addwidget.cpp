#include "addwidget.h"
#include "ui_addwidget.h"
#include"student.h"
#include"mainwidget.h"
student *first=0;
QString fileName="";
extern int sum;

addWidget::addWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addWidget)
{
    ui->setupUi(this);
}

addWidget::~addWidget()
{
    delete ui;
}

void addWidget::on_returnButton_clicked()
{
    emit display(0);
}

void addWidget::on_changeButton_clicked()
{
    emit display(2);
}

void addWidget::on_insertButton_clicked()
{
    emit display(3);
}

void addWidget::on_delButton_clicked()
{
    emit display(4);
}

void addWidget::on_readButton_clicked()
{
    emit display(5);
}

void addWidget::on_writeButton_clicked()
{
    emit display(6);
}

void addWidget::on_rankButton_clicked()
{
    emit display(7);
}

void addWidget::on_searchButton_clicked()
{
    emit display(8);
}

void addWidget::on_listButton_clicked()
{
    emit display(9);
}

void addWidget::on_establishButton_clicked()
{
    emit display(10);
}

void addWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

void addWidget::on_addingButton_clicked()//点击addingButton后进行的操作
{
    //将用户输入的姓名、学号、性别、生日、健康状况由文本框取出
    QString name = ui->nameLineEdit->text();
    QString number = ui->numberLineEdit->text();
    QString gender = ui->genderLineEdit->text();
    QString birthday = ui->birthdayLineEdit->text();
    QString healthCondition = ui->healthConditionLineEdit->text();
    //判断用户的输入数据是否完整
    if(ui->nameLineEdit->text() == "" || ui->numberLineEdit->text() == ""
            || ui->genderLineEdit->text() == "" || ui->birthdayLineEdit->text() == ""
            || ui->healthConditionLineEdit->text() == "")
    {
        //输出提示信息
        QMessageBox::about(NULL, "output", "please fill all the blank");
        return;
    }
    //对链表遍历，判断信息是否重复
    student *current=first;
    while(first!=0&&current->getNumber()!=number)
    {
        current=current->next;
        if(current==0)break;
    }
    //若重复，输出提示信息并清空用户输入
    if(current!=0)
       {
        QMessageBox::about(NULL, "output", "information repeated");
        ui->nameLineEdit->clear();
        ui->numberLineEdit->clear();
        ui->genderLineEdit->clear();
        ui->birthdayLineEdit->clear();
        ui->healthConditionLineEdit->clear();
        return;
    }
    //若不重复，执行插入操作
    else
    {
        student *p=new student;
        p->next=first;
        first=p;
        p->setName(name);
        p->setNumber(number);
        p->setGender(gender);
        p->setBirthday(birthday);
        p->setHealthCondition(healthCondition);
        //输出提示信息
        QMessageBox::about(NULL, "output", "seccess");
        //总数加1
        sum++;
    }
    //清空文本框输入
    ui->nameLineEdit->clear();
    ui->numberLineEdit->clear();
    ui->genderLineEdit->clear();
    ui->birthdayLineEdit->clear();
    ui->healthConditionLineEdit->clear();
}

