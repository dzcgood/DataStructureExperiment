#ifndef CHANGEWIDGET_H
#define CHANGEWIDGET_H

#include <QWidget>

namespace Ui {
class changeWidget;
}

class changeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit changeWidget(QWidget *parent = nullptr);
    ~changeWidget();
signals:
    void display(int number);
private slots:
    void on_returnButton_clicked();
    void on_changingButton_clicked();
    void on_addButton_clicked();
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
    Ui::changeWidget *ui;
};

#endif // CHANGEWIDGET_H
