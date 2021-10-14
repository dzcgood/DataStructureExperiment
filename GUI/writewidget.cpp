#include "writewidget.h"
#include "ui_writewidget.h"
#include"student.h"
#include"QTextStream"
#include"mainwidget.h"
extern student*first;
extern QString fileName;

writeWidget::writeWidget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::writeWidget)
{
    ui->setupUi(this);
}

writeWidget::~writeWidget()
{
    delete ui;
}

void writeWidget::on_returnButton_clicked(){
    emit display(0);
}

void writeWidget::on_addButton_clicked()
{
    emit display(1);
}

void writeWidget::on_changeButton_clicked()
{
    emit display(2);
}

void writeWidget::on_insertButton_clicked()
{
    emit display(3);
}

void writeWidget::on_delButton_clicked()
{
    emit display(4);
}

void writeWidget::on_readButton_clicked()
{
    emit display(5);
}

void writeWidget::on_rankButton_clicked()
{
    emit display(7);
}

void writeWidget::on_searchButton_clicked()
{
    emit display(8);
}

void writeWidget::on_listButton_clicked()
{
    emit display(9);
}

void writeWidget::on_establishButton_clicked()
{
    emit display(10);
}

void writeWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

void writeWidget::on_writingButton_clicked()
{
    //若之前未输入文件名
    if(fileName=="")
    {
        fileName=ui->nameLineEdit->text();
        if(fileName=="")
        QMessageBox::about(NULL,"output","请输入文件名");
        return;
    }
    QFile file(fileName+".txt");
    //以只写的方式打开
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    if(!file.isOpen())
    {
        //如果数据文件没有打开，弹出对话框提示用户
        QMessageBox::about(NULL, "output", "fail to open the txt");
        return;
    }
    //设置文件流
    QTextStream out(&file);
    student *current=first;
    //遍历链表，写入数据
    while(current!=0)
    {
        out <<current->getName()<< " " <<current->getNumber() <<
            " " <<current->getGender()<< " " << current->getBirthday()
            << " " << current->getHealthCondition()<<" ";
        current=current->next;
    }
    file.close();
    QMessageBox::about(NULL, "output", "success");
}
