#include "delwidget.h"
#include "ui_delwidget.h"
#include"QMessageBox"
extern student*root;
extern nameTreeNode* nameTree;
extern numberTreeNode* numberTree;
extern phoneNumTreeNode* phoneNumTree;
extern long long int sum;
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


//返回值：指向目标结点的指针
//函数功能：按学号查询信息
//函数参数：前者为numberTree的根节点，后者为待查询的学号
student* delWidget::searchNum(numberTreeNode*root,QString num)
{
    if (root == 0)return 0;
    else if (root->number>num)return searchNum(root->leftChild, num);
    else if (root->number<num)return searchNum(root->rightChild, num);
    else return root->pointer;
}

//返回值：指向目标结点的指针
//函数功能：按姓名查询信息
//函数参数：前者为nameTree的根节点，后者为待查询的姓名
student* delWidget::searchName(nameTreeNode*root,QString name)
{
    if (root == 0)return 0;
    else if (root->name>name)return searchName(root->leftChild, name);
    else if (root->name<name)return searchName(root->rightChild, name);
    else return root->pointer;
}

//返回值：指向目标结点的指针
//函数功能：按电话号码查询信息
//函数参数：前者为phoneNumTree的根节点，后者为待查询的电话号码
student* delWidget::searchPhoneNum(phoneNumTreeNode*root,QString phoneNum)
{
    if (root == 0)return 0;
    else if (root->phoneNumber>phoneNum)return searchPhoneNum(root->leftChild, phoneNum);
    else if (root->phoneNumber< phoneNum)return searchPhoneNum(root->rightChild, phoneNum);
    else return root->pointer;
}



//返回值：逻辑值0或1
//函数功能：按照学号，将目标结点的isDeleted属性置为1
//函数参数：待删除的学号
bool delWidget::delByNum(QString num)//删除(搜索树按学号删除)
{
    student* p = searchNum(numberTree, num);//此时p是目标结点
    if (p)
    {
        p->isDeleted = true;
        sum--;
        QMessageBox::about(NULL, "提示", "删除成功！");
        return 1;
    }
    else
        QMessageBox::about(NULL, "提示", "未找到相关信息！");
    return 0;
}

//返回值：逻辑值0或1
//函数功能：按照姓名，将目标结点的isDeleted属性置为1
//函数参数：待删除的姓名
bool delWidget::delByName(QString name)//删除(搜索树按姓名删除)
{
    student* p = searchName(nameTree, name);//此时p是目标结点
    if (p)
    {
        p->isDeleted = true;
        sum--;
        QMessageBox::about(NULL, "提示", "删除成功！");
        return 1;
    }
    else
        QMessageBox::about(NULL, "提示", "未找到相关信息！");
    return 0;
}

//返回值：逻辑值0或1
//函数功能：按照电话号码，将目标结点的isDeleted属性置为1
//函数参数：待删除的电话号码
bool delWidget::delByPhoneNum(QString phoneNum)//删除(搜索树按电话号码删除)
{
    student* p = searchPhoneNum(phoneNumTree, phoneNum);//此时p是目标结点
    if (p)
    {
        p->isDeleted = true;
        sum--;
        QMessageBox::about(NULL, "提示", "删除成功！");
        return 1;
    }
    else
        QMessageBox::about(NULL, "提示", "未找到相关信息！");
    return 0;
}

void delWidget::on_returnButton_clicked()
{
    emit display(0);
}
void delWidget::on_addButton_clicked()
{
    emit display(1);
}
void delWidget::on_delingButton_clicked()
{
    if(ui->nameBox->isChecked())
    {
        QString name=ui->nameLineEdit->text();
        delByName(name);
        ui->nameLineEdit->clear();
    }
    else if(ui->numberBox->isChecked())
    {
        QString number=ui->numberLineEdit->text();
        delByNum(number);
        ui->numberLineEdit->clear();
    }
    else if(ui->phoneNumberBox->isChecked())
    {
        QString phoneNumber=ui->phoneNumberLineEdit->text();
        delByPhoneNum(phoneNumber);
        ui->phoneNumberLineEdit->clear();
    }
    else
    {
        QMessageBox::about(NULL, "提示", "请勾选相关的选项！");
    }
}
void delWidget::on_establishButton_clicked()
{
    emit display(3);
}
void delWidget::on_outputButton_clicked()
{
    emit display(4);
}
void delWidget::on_readMinStudentButton_clicked()
{
    emit display(5);
}
void delWidget::on_readButton_clicked()
{
    emit display(6);
}

void delWidget::on_searchNameButton_clicked()
{
    emit display(7);
}
void delWidget::on_searchNumButton_clicked()
{
    emit display(8);
}
void delWidget::on_searchPhoneNumButton_clicked()
{
    emit display(9);
}
void delWidget::on_writeButton_clicked()
{
    emit display(10);
}
void delWidget::on_exitButton_clicked()
{
    QApplication::exit();
}
