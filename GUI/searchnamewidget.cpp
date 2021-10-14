#include "searchnamewidget.h"
#include "ui_searchnamewidget.h"
#include<QString>
#include<QMessageBox>
extern student*root;
extern nameTreeNode* nameTree;
extern long long int sum;
searchNameWidget::searchNameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchNameWidget)
{
    ui->setupUi(this);
}

searchNameWidget::~searchNameWidget()
{
    delete ui;
}

student* searchNameWidget::searchName(nameTreeNode*root,QString name)
{
    if (root == 0)return 0;
    else if (root->name>name)return searchName(root->leftChild, name);
    else if (root->name<name)return searchName(root->rightChild, name);
    else return root->pointer;
}

void searchNameWidget::on_returnButton_clicked()
{
    emit display(0);
}
void searchNameWidget::on_addButton_clicked()
{
    emit display(1);
}
void searchNameWidget::on_delButton_clicked()
{
    emit display(2);
}
void searchNameWidget::on_establishButton_clicked()
{
    emit display(3);
}
void searchNameWidget::on_outputButton_clicked()
{
    emit display(4);
}
void searchNameWidget::on_readMinStudentButton_clicked()
{
    emit display(5);
}
void searchNameWidget::on_readButton_clicked()
{
    emit display(6);
}

void searchNameWidget::on_searchingNameButton_clicked()
{
    QString name=ui->nameLineEdit->text();
    if(name=="")
    {
        QMessageBox::about(NULL,"提示","请输入要删除者的姓名！");
        return;
    }
    student*p=searchName(nameTree,name);
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
        ui->nameLineEdit->clear();
    }
}
void searchNameWidget::on_searchNumButton_clicked()
{
    emit display(8);
}
void searchNameWidget::on_searchPhoneNumButton_clicked()
{
    emit display(9);
}
void searchNameWidget::on_writeButton_clicked()
{
    emit display(10);
}
void searchNameWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

