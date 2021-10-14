#ifndef ESTABLISHWIDGET_H
#define ESTABLISHWIDGET_H

#include <QWidget>
#include"student.h"
namespace Ui {
class establishWidget;
}

class establishWidget : public QWidget
{
    Q_OBJECT

public:
    explicit establishWidget(QWidget *parent = nullptr);
    ~establishWidget();

private:
    Ui::establishWidget *ui;
private slots:
    void on_returnButton_clicked();
    void on_addButton_clicked();
    void on_delButton_clicked();
    void on_establishingButton_clicked();
    void on_outputButton_clicked();
    void on_readMinStudentButton_clicked();
    void on_readButton_clicked();
    void on_searchNameButton_clicked();
    void on_searchNumButton_clicked();
    void on_searchPhoneNumButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
    void deleteTrees();
    void deleteNameTree(nameTreeNode* root);
    void deleteNumberTree(numberTreeNode* root);
    void deletePhoneNumTree(phoneNumTreeNode* root);
    void deleteTree(student* root);
signals:
    void display(int number);
};

#endif // ESTABLISHWIDGET_H
