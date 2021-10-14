#include "menuwidget.h"
#include "ui_menuwidget.h"

menuWidget::menuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menuWidget)
{
    ui->setupUi(this);
}

menuWidget::~menuWidget()
{
    delete ui;
}

void menuWidget::on_addButton_clicked()
{
    emit display(1);
}
void menuWidget::on_delButton_clicked()
{
    emit display(2);
}
void menuWidget::on_establishButton_clicked()
{
   emit display(3);
}
void menuWidget::on_outputButton_clicked()
{
    emit display(4);
}
void menuWidget::on_readMinStudentButton_clicked()
{
    emit display(5);
}
void menuWidget::on_readButton_clicked()
{
    emit display(6);
}

void menuWidget::on_searchNameButton_clicked()
{
    emit display(7);
}
void menuWidget::on_searchNumButton_clicked()
{
    emit display(8);
}
void menuWidget::on_searchPhoneNumButton_clicked()
{
    emit display(9);
}
void menuWidget::on_writeButton_clicked()
{
    emit display(10);
}
void menuWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

