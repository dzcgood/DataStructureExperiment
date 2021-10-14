#include "readwidget.h"
#include "ui_readwidget.h"
#include"QFile"
#include"QMessageBox"
#include"QTextStream"
extern QString fileName;
extern student*root;
extern nameTreeNode* nameTree;
extern numberTreeNode* numberTree;
extern phoneNumTreeNode* phoneNumTree;
extern student* MIN;
extern long long int sum;
readWidget::readWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::readWidget)
{
    ui->setupUi(this);
}

readWidget::~readWidget()
{
    delete ui;
}
//返回值：无
//函数功能：以层次序遍历的方式，将目标结点插入到二叉树当中
//函数参数：前者为目标结点地址，后者为二叉树的根地址
void readWidget::insert(student* p, student* &root)
{
    if (root == 0)
        root = p;
    else
    {
        QQueue<student*>stu;
        stu.enqueue(root);
        student* temp;
        while (!stu.empty())
        {
            temp = stu.dequeue();
            if (temp->leftChild != 0)
                stu.enqueue(temp->leftChild);
            else//说明将在此结点的左子树插入
            {
                temp->leftChild = p;
                break;
            }
            if (temp->rightChild != 0)
                stu.enqueue(temp->rightChild);
            else//说明将在此结点的右子树插入
            {
                temp->rightChild = p;
                break;
            }
        }
    }
}

//返回值：无
//函数功能：以学号为关键字，将目标结点插入到学号树中
//函数参数：前者为目标结点地址，后者为学号树的根地址
bool readWidget::insertByNum(student*p, numberTreeNode*& root1)
{
    if (root1 == 0)
    {
        root1 = new numberTreeNode;
        root1->number =p->number;
        root1->pointer = p;//使得辅助结点的pointer成员指向目标结点
        return true;
    }
    else if (p->number<root1->number) return insertByNum(p, root1->leftChild);
    else if (p->number>root1->number) return insertByNum(p, root1->rightChild);
    else return false;
}

//返回值：无
//函数功能：以姓名为关键字，将目标结点插入到姓名树中
//函数参数：前者为目标结点地址，后者为姓名树的根地址
bool readWidget::insertByName(student* p, nameTreeNode*& root1)
{
    if (root1 == 0)
    {
        root1 = new nameTreeNode;
        root1->name=p->name;
        root1->pointer = p;//使得辅助结点的pointer成员指向目标结点
        return true;
    }
    else if (p->name<root1->name)return insertByName(p, root1->leftChild);
    else if (p->name>root1->name)return insertByName(p, root1->rightChild);
    else return false;
}

//返回值：无
//函数功能：以电话为关键字，将目标结点插入到电话树中
//函数参数：前者为目标结点地址，后者为电话树的根地址
bool readWidget::insertByPhoneNum(student* p, phoneNumTreeNode*& root1)
{
    if (root1 == 0)
    {
        root1 = new phoneNumTreeNode;
        root1->phoneNumber=p->phoneNumber;
        root1->pointer = p;//使得辅助结点的pointer成员指向目标结点
        return true;
    }
    else if (p->phoneNumber<root1->phoneNumber)return insertByPhoneNum(p, root1->leftChild);
    else if (p->phoneNumber>root1->phoneNumber)return insertByPhoneNum(p, root1->rightChild);
    else return false;
}

void readWidget::on_returnButton_clicked()
{
    emit display(0);
}
void readWidget::on_addButton_clicked()
{
    emit display(1);
}
void readWidget::on_delButton_clicked()
{
    emit display(2);
}
void readWidget::on_establishButton_clicked()
{
    emit display(3);
}
void readWidget::on_outputButton_clicked()
{
    emit display(4);
}
void readWidget::on_readMinStudentButton_clicked()
{
    emit display(5);
}
void readWidget::on_readingButton_clicked()
{
    if(ui->millionBox->isChecked())
        fileName="million.txt";
    else
    {
        //将用户输入的文件由nameLineEdit取出
        fileName = ui->nameLineEdit->text();
        fileName=fileName+".txt";
    }
    QFile file(fileName);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    //以只读方式打开文本文件
    QString number;
    QString name;
    QString birthday;
    QString gender;
    QString phoneNumber;
    QString address;
    if(!file.isOpen())
    {
        //文件打开失败
        QMessageBox::about(NULL, "提示", "打开文件失败！");
        return ;
    }
    student*p;
    QTextStream in(&file);
    in>>sum;
    int i=0;
    for(int j=0;j<sum;j++)
    {
        //读到文件结尾
        in>> number >> name >> birthday >> gender >> phoneNumber >> address;
        p=new student;
        p->number=number;
        p->name=name;
        p->birthday=birthday;
        p->gender=gender;
        p->phoneNumber=phoneNumber;
        p->address=address;
        p->isDeleted=false;
        p->leftChild=NULL;
        p->rightChild=NULL;
        //接下来插入四棵树
        insert(p,root);
        insertByNum(p,numberTree);
        insertByName(p,nameTree);
        insertByPhoneNum(p,phoneNumTree);
        //接下来将读取到的信息输出
        //设置列数为6
        ui->tableWidget->setColumnCount(6);
        QStringList headerLabels;
        //设置列名称
        headerLabels << tr("姓名") << tr("学号") << tr("性别")
                     << tr("生日") << tr("电话")<<tr("地址");
        ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //设置行数为sum
        ui->tableWidget->setRowCount(sum);
        //输出
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(p->name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(p->number));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(p->gender));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(p->birthday));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(p->phoneNumber));
        ui->tableWidget->setItem(i++, 5, new QTableWidgetItem(p->address));
    }
    file.close();
    //若链表为空，输出提示
    if (root == 0)
    {
        QMessageBox::about(NULL, "提示", "文件中无信息！");
        return;
    }
    QMessageBox::about(NULL, "提示", "读取成功！");
}

void readWidget::on_searchNameButton_clicked()
{
    emit display(7);
}
void readWidget::on_searchNumButton_clicked()
{
    emit display(8);
}
void readWidget::on_searchPhoneNumButton_clicked()
{
    emit display(9);
}
void readWidget::on_writeButton_clicked()
{
    emit display(10);
}
void readWidget::on_exitButton_clicked()
{
    QApplication::exit();
}

