#ifndef READWIDGET_H
#define READWIDGET_H

#include <QWidget>

namespace Ui {
class readWidget;
}

class readWidget : public QWidget
{
    Q_OBJECT

public:
    explicit readWidget(QWidget *parent = nullptr);
    ~readWidget();
signals:
    void display(int number);
private slots:
    void on_returnButton_clicked();
    void on_readingButton_clicked();
    void on_addButton_clicked();
    void on_changeButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_insertButton_clicked();
    void on_listButton_clicked();
    void on_rankButton_clicked();
    void on_searchButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
private:
    Ui::readWidget *ui;
};

#endif // READWIDGET_H
