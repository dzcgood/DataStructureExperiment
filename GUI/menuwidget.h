#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>

namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr);
    ~MenuWidget();

private:
    Ui::MenuWidget *ui;
private slots:
    void on_addButton_clicked();
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
signals:
    void display(int number);
};

#endif // MENUWIDGET_H
