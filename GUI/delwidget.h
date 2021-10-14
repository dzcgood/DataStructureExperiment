#ifndef DELWIDGET_H
#define DELWIDGET_H

#include <QWidget>
#include"student.h"
namespace Ui {
class delWidget;
}

class delWidget : public QWidget
{
    Q_OBJECT

public:
    explicit delWidget(QWidget *parent = nullptr);
    ~delWidget();

private:
    Ui::delWidget *ui;
private slots:
    void on_returnButton_clicked();
    void on_addButton_clicked();
    void on_delingButton_clicked();
    void on_establishButton_clicked();
    void on_outputButton_clicked();
    void on_readMinStudentButton_clicked();
    void on_readButton_clicked();
    void on_searchNameButton_clicked();
    void on_searchNumButton_clicked();
    void on_searchPhoneNumButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
    student* searchNum(numberTreeNode*root,QString num);
    student* searchName(nameTreeNode*root,QString name);
    student* searchPhoneNum(phoneNumTreeNode*root,QString phoneNum);
    bool delByNum(QString num);
    bool delByName(QString name);
    bool delByPhoneNum(QString phoneNum);
signals:
    void display(int number);
};

#endif // DELWIDGET_H
