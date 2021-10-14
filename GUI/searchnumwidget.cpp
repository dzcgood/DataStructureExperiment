#include "searchnumwidget.h"
#include "ui_searchnumwidget.h"
#include<QMessageBox>
extern student*root;
extern numberTreeNode* numberTree;
searchNumWidget::searchNumWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchNumWidget)
{
    ui->setupUi(this);
}

searchNumWidget::~searchNumWidget()
{
    delete ui;
}

student* searchNumWidget::searchNum(numberTreeNode*root,QString num)
{
    if (root == 0)return 0;
    else if (root->number>num)return searchNum(root->leftChild, num);
    else if (root->number<num)return searchNum(root->rightChild, num);
    else return root->pointer;
}

void searchNumWidget::on_returnButton_clicked()
{
    emit display(0);
}
void searchNumWidget::on_addButton_clicked()
{
    emit display(1);
}
void searchNumWidget::on_delButton_clicked()
{
    emit display(2);
}
void searchNumWidget::on_establishButton_clicked()
{
    emit display(3);
}
void searchNumWidget::on_outputButton_clicked()
{
    emit display(4);
}
void searchNumWidget::on_readMinStudentButton_clicked()
{
    emit display(5);
}
void searchNumWidget::on_readButton_clicked()
{
    emit display(6);
}

void searchNumWidget::on_searchNameButton_clicked()
{
    emit display(7);
}
void searchNumWidget::on_searchingNumButton_clicked()
{
    QString number=ui->numberLineEdit->text();
    if(number=="")
    {
        QMessageBox::about(NULL,"提示","请输入要删除者的学号！");
        return;
    }
    student*p=searchNum(numberTree,number);
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
        ui->numberLineEdit->clear();
    }
}
void searchNumWidget::on_searchPhoneNumButton_clicked()
{
    emit display(9);
}
void searchNumWidget::on_writeButton_clicked()
{
    emit display(10);
}
void searchNumWidget::on_exitButton_clicked()
{
    QApplication::exit();
}
