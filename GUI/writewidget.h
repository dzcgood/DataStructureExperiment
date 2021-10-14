#ifndef WRITEWIDGET_H
#define WRITEWIDGET_H
#include"QMessageBox"
#include <QWidget>
#include"student.h"
#include"QFile"
extern student *first;
namespace Ui {
class writeWidget;
}

class writeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit writeWidget(QWidget *parent = nullptr);
    ~writeWidget();
signals:
    void display(int number);
private slots:
    void on_returnButton_clicked();
    void on_writingButton_clicked();
    void on_addButton_clicked();
    void on_changeButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_insertButton_clicked();
    void on_listButton_clicked();
    void on_rankButton_clicked();
    void on_readButton_clicked();
    void on_searchButton_clicked();
    void on_exitButton_clicked();
private:
    Ui::writeWidget *ui;
};

#endif // WRITEWIDGET_H

