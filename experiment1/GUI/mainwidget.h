#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QStackedLayout>
#include"addwidget.h"
#include"changewidget.h"
#include"delwidget.h"
#include"establish.h"
#include"insertwidget.h"
#include"listwidget.h"
#include"rankwidget.h"
#include"readwidget.h"
#include"searchwidget.h"
#include"student.h"
#include"writewidget.h"
#include"menuwidget.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    QStackedLayout *stackLayout;
    addWidget *addwidget;
    changeWidget *changewidget;
    delWidget *delwidget;
    establish* establishwidget;
    insertWidget*insertwidget;
    listWidget*listwidget;
    MenuWidget*menuwidget;
    rankWidget*rankwidget;
    readWidget*readwidget;
    searchWidget*searchwidget;
    writeWidget*writewidget;
};

#endif // MAINWIDGET_H
