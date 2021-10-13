#ifndef SEARCHNUMWIDGET_H
#define SEARCHNUMWIDGET_H

#include <QWidget>
#include"student.h"
namespace Ui {
class searchNumWidget;
}

class searchNumWidget : public QWidget
{
    Q_OBJECT

public:
    explicit searchNumWidget(QWidget *parent = nullptr);
    ~searchNumWidget();

private:
    Ui::searchNumWidget *ui;
private slots:
    void on_returnButton_clicked();
    void on_addButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_outputButton_clicked();
    void on_readMinStudentButton_clicked();
    void on_readButton_clicked();
    void on_searchNameButton_clicked();
    void on_searchingNumButton_clicked();
    void on_searchPhoneNumButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
    student* searchNum(numberTreeNode*root,QString num);
signals:
    void display(int number);
};

#endif // SEARCHNUMWIDGET_H
