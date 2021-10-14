#include "outputwidget.h"
#include "ui_outputwidget.h"
#include"QMessageBox"
extern student*root;//主树根结点
extern long long int sum;
outputWidget::outputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::outputWidget)
{
    ui->setupUi(this);
}

outputWidget::~outputWidget()
{
    delete ui;
}

int i=0;//用于计数
//函数功能：前序输出信息
void outputWidget::previsit(student* root)
{
    if (root == 0)
        return;
    else
    {
        if(!root->isDeleted)
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
            ui->tableWidget->setRowCount(sum);
            //输出
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(root->name));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(root->number));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(root->gender));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(root->birthday));
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(root->phoneNumber));
            ui->tableWidget->setItem(i++, 5, new QTableWidgetItem(root->address));
        }
        previsit(root->leftChild);
        previsit(root->rightChild);
    }
}

//返回值：无
//函数功能：中序输出信息
void outputWidget::midvisit(student* root)
{
    if (root == 0)
        return;
    else
    {
        midvisit(root->leftChild);
        if(!root->isDeleted)
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
            ui->tableWidget->setRowCount(sum);
            //输出
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(root->name));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(root->number));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(root->gender));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(root->birthday));
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(root->phoneNumber));
            ui->tableWidget->setItem(i++, 5, new QTableWidgetItem(root->address));
        }
        midvisit(root->rightChild);
    }
}

//返回值：无
//函数功能：后序输出信息
void outputWidget::behvisit(student* root)
{
    if (root == 0)
        return;
    else
    {
        behvisit(root->leftChild);
        behvisit(root->rightChild);
        if(!root->isDeleted)
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
            ui->tableWidget->setRowCount(sum);
            //输出
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(root->name));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(root->number));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(root->gender));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(root->birthday));
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(root->phoneNumber));
            ui->tableWidget->setItem(i++, 5, new QTableWidgetItem(root->address));
        }
    }
}

void outputWidget::on_returnButton_clicked()
{
    emit display(0);
}
void outputWidget::on_addButton_clicked()
{
    emit display(1);
}
void outputWidget::on_delButton_clicked()
{
    emit display(2);
}
void outputWidget::on_establishButton_clicked()
{
    emit display(3);
}
void outputWidget::on_outputingButton_clicked()
{
    //若链表为空
    if(root==0)
    {
        QMessageBox::about(NULL, "反馈", "信息为空！");
        return;
    }
    //若不为空
    if(ui->pre->isChecked())
    {
        previsit(root);
    }
    else if(ui->mid->isChecked())
    {
        midvisit(root);
    }
    else if(ui->beh->isChecked())
        behvisit(root);
    else
        QMessageBox::about(NULL, "提示", "请勾选输出顺序！");
    i=0;//恢复i的值
}
void outputWidget::on_readMinStudentButton_clicked()
{
    emit display(5);
}
void outputWidget::on_readButton_clicked()
{
    emit display(6);
}

void outputWidget::on_searchNameButton_clicked()
{
    emit display(7);
}
void outputWidget::on_searchNumButton_clicked()
{
    emit display(8);
}
void outputWidget::on_searchPhoneNumButton_clicked()
{
    emit display(9);
}
void outputWidget::on_writeButton_clicked()
{
    emit display(10);
}
void outputWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

