#include "menuwidget.h"
#include "ui_menuwidget.h"
#include"addwidget.h"
using namespace std;
MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
}

MenuWidget::~MenuWidget()
{
    delete ui;
}

void MenuWidget::on_addButton_clicked()
{
    emit display(1);
}

void MenuWidget::on_changeButton_clicked()
{
    emit display(2);
}

void MenuWidget::on_insertButton_clicked()
{
    emit display(3);
}

void MenuWidget::on_delButton_clicked()
{
    emit display(4);
}

void MenuWidget::on_readButton_clicked()
{
    emit display(5);
}
void MenuWidget::on_writeButton_clicked()
{
    emit display(6);
}
void MenuWidget::on_rankButton_clicked()
{
    emit display(7);
}

void MenuWidget::on_searchButton_clicked()
{
    emit display(8);
}

void MenuWidget::on_listButton_clicked()
{
    emit display(9);
}

void MenuWidget::on_establishButton_clicked()
{
    emit display(10);
}

void MenuWidget::on_exitButton_clicked()
{
    QApplication::exit();
}
