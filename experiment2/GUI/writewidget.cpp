#include "writewidget.h"
#include "ui_writewidget.h"
#include"QMessageBox"
#include"QFile"
#include"QTextStream"
#include"QQueue"
extern QString fileName;
extern student*root;
extern long long int sum;
writeWidget::writeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::writeWidget)
{
    ui->setupUi(this);
}

writeWidget::~writeWidget()
{
    delete ui;
}

void writeWidget::on_returnButton_clicked()
{
    emit display(0);
}
void writeWidget::on_addButton_clicked()
{
    emit display(1);
}
void writeWidget::on_delButton_clicked()
{
    emit display(2);
}
void writeWidget::on_establishButton_clicked()
{
    emit display(3);
}
void writeWidget::on_outputButton_clicked()
{
    emit display(4);
}
void writeWidget::on_readMinStudentButton_clicked()
{
    emit display(5);
}
void writeWidget::on_readButton_clicked()
{
    emit display(6);
}

void writeWidget::on_searchNameButton_clicked()
{
    emit display(7);
}
void writeWidget::on_searchNumButton_clicked()
{
    emit display(8);
}
void writeWidget::on_searchPhoneNumButton_clicked()
{
    emit display(9);
}
void writeWidget::on_writingButton_clicked()
{
    //若之前未输入文件名
    if(fileName=="")
    {
        fileName=ui->nameLineEdit->text();
        if(fileName=="")
        QMessageBox::about(NULL,"提示","请输入文件名！");
        return;
    }
    QFile file(fileName+".txt");
    //以只写的方式打开
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    if(!file.isOpen())
    {
        //如果数据文件没有打开，弹出对话框提示用户
        QMessageBox::about(NULL, "提示", "打开文件失败！");
        return;
    }
    //设置文件流
    QTextStream out(&file);
    //按照层次序遍历的方式写入文件
    out<<sum<<" ";
    QQueue<student*>stu;
    student* p = root;
    stu.enqueue(p);
    while (!stu.empty())
    {
        p = stu.dequeue();
        if (p->leftChild)stu.enqueue(p->leftChild);
        if (p->rightChild)stu.enqueue(p->rightChild);
        if(!p->isDeleted)//被删除的不写入
        {
            out<<p->number<<" "<<p->name<<" "<<p->birthday<<" "
               <<p->gender<<" "<<p->phoneNumber<<" "<<p->address<<" ";
        }
    }
    file.close();
    QMessageBox::about(NULL, "提示", "写入成功！");
}
void writeWidget::on_exitButton_clicked()
{
    QApplication::exit();
}
