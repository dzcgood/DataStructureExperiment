#ifndef OUTPUTWIDGET_H
#define OUTPUTWIDGET_H
#include"student.h"
#include <QWidget>

namespace Ui {
class outputWidget;
}

class outputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit outputWidget(QWidget *parent = nullptr);
    ~outputWidget();

private:
    Ui::outputWidget *ui;
signals:
     void display(int number);
private slots:
    void on_returnButton_clicked();
    void on_addButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_outputingButton_clicked();
    void on_readMinStudentButton_clicked();
    void on_readButton_clicked();
    void on_searchNameButton_clicked();
    void on_searchNumButton_clicked();
    void on_searchPhoneNumButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
    void previsit(student* root);
    void midvisit(student* root);
    void behvisit(student* root);

};

#endif // OUTPUTWIDGET_H
