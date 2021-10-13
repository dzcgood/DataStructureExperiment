#ifndef SEARCHNAMEWIDGET_H
#define SEARCHNAMEWIDGET_H

#include <QWidget>
#include"student.h"
namespace Ui {
class searchNameWidget;
}

class searchNameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit searchNameWidget(QWidget *parent = nullptr);
    ~searchNameWidget();

private:
    Ui::searchNameWidget *ui;
private slots:
    void on_returnButton_clicked();
    void on_addButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_outputButton_clicked();
    void on_readMinStudentButton_clicked();
    void on_readButton_clicked();
    void on_searchingNameButton_clicked();
    void on_searchNumButton_clicked();
    void on_searchPhoneNumButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
    student* searchName(nameTreeNode*root,QString name);
signals:
    void display(int number);
};

#endif // SEARCHNAMEWIDGET_H
