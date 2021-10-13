#ifndef DELWIDGET_H
#define DELWIDGET_H

#include <QWidget>

namespace Ui {
class delWidget;
}

class delWidget : public QWidget
{
    Q_OBJECT

public:
    explicit delWidget(QWidget *parent = nullptr);
    ~delWidget();
signals:
    void display(int number);
private slots:
    void on_returnButton_clicked();
    void on_delingButton_clicked();
    void on_addButton_clicked();
    void on_changeButton_clicked();
    void on_establishButton_clicked();
    void on_insertButton_clicked();
    void on_listButton_clicked();
    void on_rankButton_clicked();
    void on_readButton_clicked();
    void on_searchButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
private:
    Ui::delWidget *ui;
};

#endif // DELWIDGET_H
