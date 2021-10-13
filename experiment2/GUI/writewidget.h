#ifndef WRITEWIDGET_H
#define WRITEWIDGET_H
#include"student.h"
#include <QWidget>

namespace Ui {
class writeWidget;
}

class writeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit writeWidget(QWidget *parent = nullptr);
    ~writeWidget();

private:
    Ui::writeWidget *ui;
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
    void on_searchPhoneNumButton_clicked();
    void on_writingButton_clicked();
    void on_exitButton_clicked();
signals:
    void display(int number);
};

#endif // WRITEWIDGET_H
