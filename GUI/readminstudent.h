#ifndef READMINSTUDENT_H
#define READMINSTUDENT_H

#include <QWidget>

namespace Ui {
class readMinStudent;
}

class readMinStudent : public QWidget
{
    Q_OBJECT

public:
    explicit readMinStudent(QWidget *parent = nullptr);
    ~readMinStudent();

private:
    Ui::readMinStudent *ui;
private slots:
    void on_returnButton_clicked();
    void on_addButton_clicked();
    void on_delButton_clicked();
    void on_establishButton_clicked();
    void on_outputButton_clicked();
    void on_outputMinButton_clicked();
    void on_readButton_clicked();
    void on_searchNameButton_clicked();
    void on_searchNumButton_clicked();
    void on_searchPhoneNumButton_clicked();
    void on_writeButton_clicked();
    void on_exitButton_clicked();
signals:
    void display(int number);
};

#endif // READMINSTUDENT_H
