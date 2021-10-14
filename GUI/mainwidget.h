#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QStackedLayout>
#include"addwidget.h"
#include"delwidget.h"
#include"establishwidget.h"
#include"writewidget.h"
#include"outputwidget.h"
#include"readminstudent.h"
#include"readwidget.h"
#include"searchnamewidget.h"
#include"searchnumwidget.h"
#include"searchphonenumwidget.h"
#include"menuwidget.h"
namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private:
    Ui::mainWidget *ui;
    QStackedLayout *stackLayout;
    addWidget *addwidget;
    delWidget *delwidget;
    outputWidget* outputwidget;
    establishWidget*establishwidget;
    readMinStudent* readminstudent;
    readWidget*readwidget;
    searchNameWidget*searchnamewidget;
    searchNumWidget*searchnumwidget;
    searchPhoneNumWidget*searchphonenumwidget;
    writeWidget*writewidget;
    menuWidget*menuwidget;
};

#endif // MAINWIDGET_H
