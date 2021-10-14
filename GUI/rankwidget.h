#ifndef RANKWIDGET_H
#define RANKWIDGET_H

#include <QWidget>

namespace Ui {
class rankWidget;
}

class rankWidget : public QWidget
{
    Q_OBJECT

public:
    explicit rankWidget(QWidget *parent = nullptr);
    ~rankWidget();
signals:
    void display(int number);
private slots:
    void on_returnButton_clicked();
    void on_rankingButton_clicked();
    void on_addButton_clicked();
    void on_changeButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_insertButton_clicked();
    void on_listButton_clicked();
    void on_readButton_clicked();
    void on_searchButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
private:
    Ui::rankWidget *ui;
};

#endif // RANKWIDGET_H
