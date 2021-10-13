#include "rankwidget.h"
#include "ui_rankwidget.h"
#include"student.h"
#include"QMessageBox"
#include"mainwidget.h"
extern student*first;
extern QString fileName;
extern int sum;

rankWidget::rankWidget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::rankWidget)
{
    ui->setupUi(this);
}

rankWidget::~rankWidget()
{
    delete ui;
}

void rankWidget::on_returnButton_clicked()
{
    emit display(0);
}

void rankWidget::on_addButton_clicked()
{
    emit display(1);
}

void rankWidget::on_changeButton_clicked()
{
    emit display(2);
}

void rankWidget::on_insertButton_clicked()
{
    emit display(3);
}

void rankWidget::on_delButton_clicked()
{
    emit display(4);
}

void rankWidget::on_readButton_clicked()
{
    emit display(5);
}

void rankWidget::on_writeButton_clicked()
{
    emit display(6);
}

void rankWidget::on_searchButton_clicked()
{
    emit display(8);
}

void rankWidget::on_listButton_clicked()
{
    emit display(9);
}

void rankWidget::on_establishButton_clicked()
{
    emit display(10);
}
void rankWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

void rankWidget::on_rankingButton_clicked()
{
    //判断链表是否为空
    if (first == 0)
    {
        QMessageBox::about(NULL, "反馈", "ERROR：信息库为空，无法排序，请输入数据！");
        return ;
    }
    student* p=0;
    student* q=0;
    //选择排序
    for(p=first;p!=0;p=p->next)
        for (q = p->next; q != 0; q = q->next)
        {
            //若勾选倒叙按钮
            if(ui->checkBox->isChecked())
            {
                if (q->getNumber() > p->getNumber())
                    p->exchange(*q);//交换数据
            }
            //若未勾选
            else
            {
                if (q->getNumber() < p->getNumber())
                    p->exchange(*q);//交换数据
            }
        }
    QMessageBox::about(NULL, "反馈", "排序成功");
    student *current=first;
    int i=0;
    //输出链表内容
    while(current!=0)
    {
        //设置列数为5
        ui->tableWidget->setColumnCount(5);
        QStringList headerLabels;
        //设置列名称
        headerLabels << tr("姓名") << tr("学号") << tr("性别") << tr("出生日期") << tr("健康") ;
        ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //设置行数为sum
        ui->tableWidget->setRowCount(sum);
        //输出
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(current->getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(current->getNumber()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(current->getGender()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(current->getBirthday()));
        ui->tableWidget->setItem(i++,4, new QTableWidgetItem(current->getHealthCondition()));
        current=current->next;
    }
}
