#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "student.h"

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    setWindowTitle("学生通讯录管理系统 by 邓智超 20192121026");
    setFixedSize(692,682);
    ui->setupUi(this);
    menuwidget=new menuWidget;
    addwidget=new addWidget;
    delwidget=new delWidget;
    establishwidget=new establishWidget;
    outputwidget=new outputWidget;
    readminstudent=new readMinStudent;
    readwidget=new readWidget;
    searchnamewidget=new searchNameWidget;
    searchnumwidget=new searchNumWidget;
    searchphonenumwidget=new searchPhoneNumWidget;
    writewidget=new writeWidget;
    stackLayout=new QStackedLayout;
    stackLayout->addWidget(menuwidget);
    stackLayout->addWidget(addwidget);
    stackLayout->addWidget(delwidget);
    stackLayout->addWidget(establishwidget);
    stackLayout->addWidget(outputwidget);
    stackLayout->addWidget(readminstudent);
    stackLayout->addWidget(readwidget);
    stackLayout->addWidget(searchnamewidget);
    stackLayout->addWidget(searchnumwidget);
    stackLayout->addWidget(searchphonenumwidget);
    stackLayout->addWidget(writewidget);
    setLayout(stackLayout);
    connect(menuwidget,&menuWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(addwidget,&addWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(delwidget,&delWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(establishwidget,&establishWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(outputwidget,&outputWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(readminstudent,&readMinStudent::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(readwidget,&readWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(searchnamewidget,&searchNameWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(searchnumwidget,&searchNumWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(searchphonenumwidget,&searchPhoneNumWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
    connect(writewidget,&writeWidget::display,stackLayout,&QStackedLayout::setCurrentIndex);
}

mainWidget::~mainWidget()
{
    delete ui;
}

int main(int argc,char*argv[])
{
    QApplication app(argc,argv);
    mainWidget m;
    m.setWindowTitle("学生通讯录管理系统 by 邓智超 20192121026");
    m.show();
    return app.exec();
}
