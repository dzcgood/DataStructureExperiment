#ifndef INSERTWIDGET_H
#define INSERTWIDGET_H

#include <QWidget>

namespace Ui {
class insertWidget;
}

class insertWidget : public QWidget
{
    Q_OBJECT

public:
    explicit insertWidget(QWidget *parent = nullptr);
    ~insertWidget();
signals:
    void display(int number);
private slots:
    void on_returnButton_clicked();
    void on_insertingButton_clicked();
    void on_addButton_clicked();
    void on_changeButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_listButton_clicked();
    void on_rankButton_clicked();
    void on_readButton_clicked();
    void on_searchButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
private:
    Ui::insertWidget *ui;
};

#endif // INSERTWIDGET_H
