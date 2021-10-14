#ifndef STUDENT_H
#define STUDENT_H
#include<QString>
#include<iostream>
#include<QQueue>

//学生结点，包含学生的所有信息
struct student
{
    //学号、姓名、出生日期、性别、电话和地址
    QString number;//学号
    QString name;//姓名
    QString birthday;//出生日期
    QString gender;//性别
    QString phoneNumber;//电话
    QString address;//地址
    student* leftChild = NULL;
    student* rightChild = NULL;
    bool isDeleted=false;//判断是否被删除 若已经删除，则isDeleted值为1
};

//以姓名构建的搜索二叉树结点
//用于构建辅助结构
struct nameTreeNode
{
    QString name;//姓名
    student* pointer = 0;//指向二叉树中的结点
    nameTreeNode* leftChild = 0;
    nameTreeNode* rightChild = 0;
};



//以学号构建的搜索二叉树结点
//用于构建辅助结构
struct numberTreeNode
{
    QString number;//学号
    student* pointer = 0;//指向二叉树中的结点
    numberTreeNode* leftChild = 0;
    numberTreeNode* rightChild = 0;
};


//以电话号码构建的搜索二叉树结点
//用于构建辅助结构
struct phoneNumTreeNode
{
    QString phoneNumber;//电话号码
    student* pointer = 0;//指向二叉树中的结点
    phoneNumTreeNode* leftChild = 0;
    phoneNumTreeNode* rightChild = 0;
};


#endif
