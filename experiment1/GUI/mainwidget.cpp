#include "mainwidget.h"
#include "ui_mainwidget.h"
#include<QApplication>
#include"menuwidget.h"
extern student*first;
extern QString fileName;
int sum=0;
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    setWindowTitle("学生健康管理系统 by 邓智超 20192121026");
    setFixedSize(692,682);
    ui->setupUi(this);
    addwidget=new addWidget;
    changewidget=new changeWidget;
    delwidget=new delWidget;
    establishwidget=new establish;
    insertwidget=new insertWidget;
    listwidget=new listWidget;
    menuwidget=new MenuWidget;
    rankwidget=new rankWidget;
    readwidget=new readWidget;
    searchwidget=new searchWidget;
    writewidget=new writeWidget;
    stackLayout=new QStackedLayout;
    stackLayout->addWidget(menuwidget);
    stackLayout->addWidget(addwidget);
    stackLayout->addWidget(changewidget);
    stackLayout->addWidget(insertwidget);
    stackLayout->addWidget(delwidget);
    stackLayout->addWidget(readwidget);
    stackLayout->addWidget(writewidget);
    stackLayout->addWidget(rankwidget);
    stackLayout->addWidget(searchwidget);
    stackLayout->addWidget(listwidget);
    stackLayout->addWidget(establishwidget);
    setLayout(stackLayout);
    connect(menuwidget,&MenuWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(addwidget,&addWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(changewidget,&changeWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(insertwidget,&insertWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(delwidget,&delWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(readwidget,&readWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(writewidget,&writeWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(rankwidget,&rankWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(searchwidget,&searchWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(listwidget,&listWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(establishwidget,&establish::display,stackLayout,&QStackedLayout::setCurrentIndex);
}


MainWidget::~MainWidget()
{
    delete ui;
}

 int main(int argc,char*argv[])
 {
     QApplication app(argc,argv);
     MainWidget m;
     m.setWindowTitle("学生健康管理系统 by 邓智超 20192121026");
     m.show();
     return app.exec();
 }
