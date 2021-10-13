#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>

namespace Ui {
class menuWidget;
}

class menuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit menuWidget(QWidget *parent = nullptr);
    ~menuWidget();

private:
    Ui::menuWidget *ui;
private slots:
    void on_addButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_outputButton_clicked();
    void on_readMinStudentButton_clicked();
    void on_readButton_clicked();
    void on_searchNameButton_clicked();
    void on_searchNumButton_clicked();
    void on_searchPhoneNumButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
signals:
    void display(int number);
};

#endif // MENUWIDGET_H
