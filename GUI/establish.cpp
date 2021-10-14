#include "establish.h"
#include "ui_establish.h"
#include"mainwidget.h"
extern student*first;
extern QString fileName;

establish::establish(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::establish)
{
    ui->setupUi(this);
}

establish::~establish()
{
    delete ui;
}

void establish::on_returnButton_clicked(){
    emit display(0);
}

void establish::on_addButton_clicked()
{
    emit display(1);
}

void establish::on_changeButton_clicked()
{
    emit display(2);
}

void establish::on_insertButton_clicked()
{
    emit display(3);
}

void establish::on_delButton_clicked()
{
    emit display(4);
}

void establish::on_readButton_clicked()
{
    emit display(5);
}
void establish::on_writeButton_clicked()
{
    emit display(6);
}

void establish::on_rankButton_clicked()
{
    emit display(7);
}

void establish::on_searchButton_clicked()
{
    emit display(8);
}

void establish::on_listButton_clicked()
{
    emit display(9);
}

void establish::on_exitButton_clicked()
{
    QApplication::exit();
}

void establish::on_establishingButton_clicked()
{
    fileName = ui->nameLineEdit->text();
    //将用户输入的姓名由nameLineEdit取出
    if(fileName=="")
    {
        QMessageBox::about(NULL, "output", "please fill all the blank");
    }
    else
    {
        QMessageBox::about(NULL, "output", "success");
        ui->nameLineEdit->clear();
    }
}
