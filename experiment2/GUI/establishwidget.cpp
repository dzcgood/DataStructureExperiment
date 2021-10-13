#include "establishwidget.h"
#include "ui_establishwidget.h"
#include"QMessageBox"
extern QString fileName;
extern student*root;
extern nameTreeNode* nameTree;
extern numberTreeNode* numberTree;
extern phoneNumTreeNode* phoneNumTree;
extern student* MIN;
extern long long int sum;
establishWidget::establishWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::establishWidget)
{
    ui->setupUi(this);
}

establishWidget::~establishWidget()
{
    delete ui;
}
//返回值：无
//函数功能：释放姓名树的空间
//函数参数：姓名树的根地址
void establishWidget::deleteNameTree(nameTreeNode* root)
{
    if (root == 0)return;
    else
    {
        deleteNameTree(root->leftChild);
        deleteNameTree(root->rightChild);
        delete root;
    }
}

//返回值：无
//函数功能：释放学号树的空间
//函数参数：学号树的根地址
void establishWidget::deleteNumberTree(numberTreeNode* root)
{
    if (root == 0)return;
    else
    {
        deleteNumberTree(root->leftChild);
        deleteNumberTree(root->rightChild);
        delete root;
    }
}

//返回值：无
//函数功能：释放电话树的空间
//函数参数：电话树的根地址
void establishWidget::deletePhoneNumTree(phoneNumTreeNode* root)
{
    if (root == 0)return;
    else
    {
        deletePhoneNumTree(root->leftChild);
        deletePhoneNumTree(root->rightChild);
        delete root;
    }
}

//返回值：无
//函数功能：释放二叉树的空间
//函数参数：二叉树的根地址
void establishWidget::deleteTree(student* root)
{
    if (root == 0)return;
    else
    {
        deleteTree(root->leftChild);
        deleteTree(root->rightChild);
        delete root;
    }
}



void establishWidget::deleteTrees()
{
    deleteTree(root);
    deleteNameTree(nameTree);
    deleteNumberTree(numberTree);
    deletePhoneNumTree(phoneNumTree);
    root=0;
    nameTree=0;
    numberTree=0;
    phoneNumTree=0;
    sum=0;
}
void establishWidget::on_returnButton_clicked()
{
    emit display(0);
}
void establishWidget::on_addButton_clicked()
{
    emit display(1);
}
void establishWidget::on_delButton_clicked()
{
    emit display(2);
}
void establishWidget::on_establishingButton_clicked()
{
    deleteTrees();//释放空间并将sum置为0
    fileName = ui->nameLineEdit->text();
    //将用户输入的姓名由nameLineEdit取出
    if(fileName=="")
    {
        QMessageBox::about(NULL, "提示", "请输入你要创建的通讯录名称！");
    }
    else
    {
        QMessageBox::about(NULL, "提示", "创建成功！");
        ui->nameLineEdit->clear();
    }

}
void establishWidget::on_outputButton_clicked()
{
    emit display(4);
}

void establishWidget::on_readMinStudentButton_clicked()
{
    emit display(5);
}
void establishWidget::on_readButton_clicked()
{
    emit display(6);
}

void establishWidget::on_searchNameButton_clicked()
{
    emit display(7);
}
void establishWidget::on_searchNumButton_clicked()
{
    emit display(8);
}
void establishWidget::on_searchPhoneNumButton_clicked()
{
    emit display(9);
}
void establishWidget::on_writeButton_clicked()
{
    emit display(10);
}
void establishWidget::on_exitButton_clicked()
{
    QApplication::exit();
}
