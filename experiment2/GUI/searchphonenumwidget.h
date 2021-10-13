#ifndef SEARCHPHONENUMWIDGET_H
#define SEARCHPHONENUMWIDGET_H

#include <QWidget>
#include"student.h"
namespace Ui {
class searchPhoneNumWidget;
}

class searchPhoneNumWidget : public QWidget
{
    Q_OBJECT

public:
    explicit searchPhoneNumWidget(QWidget *parent = nullptr);
    ~searchPhoneNumWidget();

private:
    Ui::searchPhoneNumWidget *ui;
private slots:
    void on_returnButton_clicked();
    void on_addButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_outputButton_clicked();
    void on_readMinStudentButton_clicked();
    void on_readButton_clicked();
    void on_searchNameButton_clicked();
    void on_searchNumButton_clicked();
    void on_searchingPhoneNumButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
    student* searchPhoneNum(phoneNumTreeNode*root,QString phoneNum);
signals:
    void display(int number);
};

#endif // SEARCHPHONENUMWIDGET_H
