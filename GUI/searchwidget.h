#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QVector>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class searchWidget;
}

class searchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit searchWidget(QWidget *parent = nullptr);
    ~searchWidget();
signals:
    void display(int number);
private slots:
    void on_returnButton_clicked();
    void on_searchingButton_clicked();
    void on_addButton_clicked();
    void on_changeButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_insertButton_clicked();
    void on_listButton_clicked();
    void on_rankButton_clicked();
    void on_readButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
private:
    Ui::searchWidget *ui;
};

#endif // SEARCHWIDGET_H
