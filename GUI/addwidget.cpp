#include "addwidget.h"
#include "ui_addwidget.h"
#include "student.h"
#include"QMessageBox"
student*root;//主树根结点
nameTreeNode* nameTree;//姓名树根结点
numberTreeNode* numberTree;//学号树根结点
phoneNumTreeNode* phoneNumTree;//电话树根结点
student* MIN;//存储年龄最小的学生结点地址
long long int sum=0;
QString fileName="";
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


//返回值：无
//函数功能：以层次序遍历的方式，将目标结点插入到二叉树当中
//函数参数：前者为目标结点地址，后者为二叉树的根地址
void addWidget::insert(student* p, student* &root)
{
    sum++;
    if (root == 0)
        root = p;
    else
    {
        QQueue<student*>stu;
        stu.enqueue(root);
        student* temp;
        while (!stu.empty())
        {
            temp = stu.dequeue();
            if (temp->leftChild != 0)
                stu.enqueue(temp->leftChild);
            else//说明将在此结点的左子树插入
            {
                temp->leftChild = p;
                break;
            }
            if (temp->rightChild != 0)
                stu.enqueue(temp->rightChild);
            else//说明将在此结点的右子树插入
            {
                temp->rightChild = p;
                break;
            }
        }
    }
}

//返回值：无
//函数功能：以学号为关键字，将目标结点插入到学号树中
//函数参数：前者为目标结点地址，后者为学号树的根地址
bool addWidget::insertByNum(student*p, numberTreeNode*& root1)
{
    if (root1 == 0)
    {
        root1 = new numberTreeNode;
        root1->number =p->number;
        root1->pointer = p;//使得辅助结点的pointer成员指向目标结点
        return true;
    }
    else if (p->number<root1->number) return insertByNum(p, root1->leftChild);
    else if (p->number>root1->number) return insertByNum(p, root1->rightChild);
    else return false;
}

//返回值：无
//函数功能：以姓名为关键字，将目标结点插入到姓名树中
//函数参数：前者为目标结点地址，后者为姓名树的根地址
bool addWidget::insertByName(student* p, nameTreeNode*& root1)
{
    if (root1 == 0)
    {
        root1 = new nameTreeNode;
        root1->name=p->name;
        root1->pointer = p;//使得辅助结点的pointer成员指向目标结点
        return true;
    }
    else if (p->name<root1->name)return insertByName(p, root1->leftChild);
    else if (p->name>root1->name)return insertByName(p, root1->rightChild);
    else return false;
}

//返回值：无
//函数功能：以电话为关键字，将目标结点插入到电话树中
//函数参数：前者为目标结点地址，后者为电话树的根地址
bool addWidget::insertByPhoneNum(student* p, phoneNumTreeNode*& root1)
{
    if (root1 == 0)
    {
        root1 = new phoneNumTreeNode;
        root1->phoneNumber=p->phoneNumber;
        root1->pointer = p;//使得辅助结点的pointer成员指向目标结点
        return true;
    }
    else if (p->phoneNumber<root1->phoneNumber)return insertByPhoneNum(p, root1->leftChild);
    else if (p->phoneNumber>root1->phoneNumber)return insertByPhoneNum(p, root1->rightChild);
    else return false;
}

void addWidget::on_addingButton_clicked()
{
    //将用户输入的姓名、学号、性别、生日、健康状况由文本框取出
    QString name=ui->nameLineEdit->text();
    QString number = ui->numberLineEdit->text();
    QString gender = ui->genderLineEdit->text();
    QString birthday = ui->birthdayLineEdit->text();
    QString address = ui->addressLineEdit->text();
    QString phoneNumber=ui->phoneNumLineEdit->text();
    //判断用户的输入数据是否完整
    if(ui->nameLineEdit->text() == "" || ui->numberLineEdit->text() == ""
            || ui->genderLineEdit->text() == "" || ui->birthdayLineEdit->text() == ""
            || ui->phoneNumLineEdit->text() == ""||ui->addressLineEdit->text()=="")
    {
        //输出提示信息
        QMessageBox::about(NULL, "提示", "请填写所有信息！");
        return;
    }
    student *p=new student;
    p->name=name;
    p->number=number;
    p->gender=gender;
    p->birthday=birthday;
    p->address=address;
    p->phoneNumber=phoneNumber;
    //输出提示信息
    QMessageBox::about(NULL, "提示", "添加成功！");
    //清空文本框输入
    ui->nameLineEdit->clear();
    ui->numberLineEdit->clear();
    ui->genderLineEdit->clear();
    ui->birthdayLineEdit->clear();
    ui->phoneNumLineEdit->clear();
    ui->addressLineEdit->clear();
    //插入四棵树
    insert(p,root);
    insertByNum(p,numberTree);
    insertByName(p,nameTree);
    insertByPhoneNum(p,phoneNumTree);
}
void addWidget::on_delButton_clicked()
{
    emit display(2);
}
void addWidget::on_establishButton_clicked()
{
    emit display(3);
}
void addWidget::on_outputButton_clicked()
{
    emit display(4);
}
void addWidget::on_readMinStudentButton_clicked()
{
    emit display(5);
}
void addWidget::on_readButton_clicked()
{
    emit display(6);
}

void addWidget::on_searchNameButton_clicked()
{
    emit display(7);
}
void addWidget::on_searchNumButton_clicked()
{
    emit display(8);
}
void addWidget::on_searchPhoneNumButton_clicked()
{
    emit display(9);
}
void addWidget::on_writeButton_clicked()
{
    emit display(10);
}
void addWidget::on_exitButton_clicked()
{
    QApplication::exit();
}
