#ifndef ADDWIDGET_H
#define ADDWIDGET_H
#include"student.h"
#include <QWidget>

namespace Ui {
class addWidget;
}

class addWidget : public QWidget
{
    Q_OBJECT

public:
    explicit addWidget(QWidget *parent = nullptr);
    ~addWidget();

private:
    Ui::addWidget *ui;
private slots:
    void on_returnButton_clicked();
    void on_addingButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_outputButton_clicked();
    void on_readMinStudentButton_clicked();
    void on_readButton_clicked();
    void on_searchNameButton_clicked();
    void on_searchNumButton_clicked();
    void on_searchPhoneNumButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
    void insert(student* p, student* &root);
    bool insertByNum(student*p, numberTreeNode*& root1);
    bool insertByName(student*p, nameTreeNode*& root1);
    bool insertByPhoneNum(student*p, phoneNumTreeNode*& root1);
signals:
    void display(int number);
};

#endif // ADDWIDGET_H
