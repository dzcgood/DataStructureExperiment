#ifndef READWIDGET_H
#define READWIDGET_H

#include <QWidget>
#include"student.h"
namespace Ui {
class readWidget;
}

class readWidget : public QWidget
{
    Q_OBJECT

public:
    explicit readWidget(QWidget *parent = nullptr);
    ~readWidget();

private:
    Ui::readWidget *ui;
private slots:
    void on_returnButton_clicked();
    void on_addButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_outputButton_clicked();
    void on_readMinStudentButton_clicked();
    void on_readingButton_clicked();
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

#endif // READWIDGET_H
