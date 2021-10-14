#ifndef ESTABLISH_H
#define ESTABLISH_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
namespace Ui {
class establish;
}

class establish : public QWidget
{
    Q_OBJECT

public:
    explicit establish(QWidget *parent = nullptr);
    ~establish();
signals:
    void display(int number);
private slots:
    void on_returnButton_clicked();
    void on_establishingButton_clicked();
    void on_addButton_clicked();
    void on_changeButton_clicked();
    void on_delButton_clicked();
    void on_insertButton_clicked();
    void on_listButton_clicked();
    void on_rankButton_clicked();
    void on_readButton_clicked();
    void on_searchButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
private:
    Ui::establish *ui;
};

#endif // ESTABLISH_H

