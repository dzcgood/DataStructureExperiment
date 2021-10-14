#include "searchphonenumwidget.h"
#include "ui_searchphonenumwidget.h"
#include<QMessageBox>
extern student*root;
extern phoneNumTreeNode* phoneNumTree;
searchPhoneNumWidget::searchPhoneNumWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchPhoneNumWidget)
{
    ui->setupUi(this);
}

searchPhoneNumWidget::~searchPhoneNumWidget()
{
    delete ui;
}

student* searchPhoneNumWidget::searchPhoneNum(phoneNumTreeNode*root,QString phoneNum)
{
    if (root == 0)return 0;
    else if (root->phoneNumber>phoneNum)return searchPhoneNum(root->leftChild, phoneNum);
    else if (root->phoneNumber< phoneNum)return searchPhoneNum(root->rightChild, phoneNum);
    else return root->pointer;
}

void searchPhoneNumWidget::on_returnButton_clicked()
{
    emit display(0);
}
void searchPhoneNumWidget::on_addButton_clicked()
{
    emit display(1);
}
void searchPhoneNumWidget::on_delButton_clicked()
{
    emit display(2);
}
void searchPhoneNumWidget::on_establishButton_clicked()
{
    emit display(3);
}
void searchPhoneNumWidget::on_outputButton_clicked()
{
    emit display(4);
}
void searchPhoneNumWidget::on_readMinStudentButton_clicked()
{
    emit display(5);
}
void searchPhoneNumWidget::on_readButton_clicked()
{
    emit display(6);
}

void searchPhoneNumWidget::on_searchNameButton_clicked()
{
    emit display(7);
}
void searchPhoneNumWidget::on_searchNumButton_clicked()
{
    emit display(8);
}
void searchPhoneNumWidget::on_searchingPhoneNumButton_clicked()
{
    QString phoneNumber=ui->phoneNumberLineEdit->text();
    if(phoneNumber=="")
    {
        QMessageBox::about(NULL,"提示","请输入要删除者的电话！");
        return;
    }
    student*p=searchPhoneNum(phoneNumTree,phoneNumber);
    if(p==0)
    {
        QMessageBox::about(NULL,"提示","无相关信息！");
        return;
    }
    else
    {
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
        ui->phoneNumberLineEdit->clear();
    }
}
void searchPhoneNumWidget::on_writeButton_clicked()
{
    emit display(10);
}
void searchPhoneNumWidget::on_exitButton_clicked()
{
    QApplication::exit();
}
