#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
namespace Ui {
class addWidget;
}

class addWidget : public QWidget
{
    Q_OBJECT

public:
    explicit addWidget(QWidget *parent = nullptr);
    ~addWidget();

signals:
    void display(int number);
private slots:
    void on_returnButton_clicked();
    void on_addingButton_clicked();
    void on_changeButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_insertButton_clicked();
    void on_listButton_clicked();
    void on_rankButton_clicked();
    void on_readButton_clicked();
    void on_searchButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
private:
    Ui::addWidget *ui;
};

#endif // ADDWIDGET_H

