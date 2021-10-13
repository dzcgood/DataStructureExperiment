#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>

namespace Ui {
class listWidget;
}

class listWidget : public QWidget
{
    Q_OBJECT

public:
    explicit listWidget(QWidget *parent = nullptr);
    ~listWidget();
signals:
    void display(int number);
private slots:
    void on_returnButton_clicked();
    void on_listingButton_clicked();
    void on_addButton_clicked();
    void on_changeButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_insertButton_clicked();
    void on_rankButton_clicked();
    void on_readButton_clicked();
    void on_searchButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
private:
    Ui::listWidget *ui;
};

#endif // LISTWIDGET_H
