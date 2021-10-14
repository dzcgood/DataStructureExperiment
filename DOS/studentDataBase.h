//文件名：studentDataBase.h
//程序功能：studentDataBase类的声明，该类的功能是实现对二叉树的各项操作
//作者：邓智超
//日期：2020.12.05
//版本：2.0
#pragma once
#ifndef STUDENTDATABASE_H_
#define STUDENTDATABASE_H_
#include<string>
#include<iostream>
#include"student.h"
using namespace std;


class studentDataBase
{
private:
    void previsit(student* root);//前序输出
    void midvisit(student* root);//中序输出
    void behvisit(student* root);//后序输出
public:
    student* root;//根结点
    studentDataBase();//构造函数
	void createTree();//新建
    student* searchNum(numberTreeNode*root,char num[]);//按学号查找
    student* searchName(nameTreeNode*root,char name[]);//按姓名查找
    student* searchPhoneNum(phoneNumTreeNode*root,char phoneNum[]);//按电话查询
    bool delByNum(char num[]);//按学号删除
    bool delByName(char name[]);//按姓名删除
    bool delByPhoneNum(char phoneNum[]);//按电话删除
    bool insertByNum(student* p, numberTreeNode*& root1);//在学号数插入
    bool insertByName(student* p, nameTreeNode*& root1);//在姓名树插入
    bool insertByPhoneNum(student* p, phoneNumTreeNode*& root1);//在电话树插入
    void insert(student* p, student*& root);//在二叉树插入
    void getYoungest(student*root);//输出年龄最小学生信息
    void output();//输出学生信息
    void readFile(string fileName);//读入
    void writeFile(string fileName);//写入
    void deleteTree(student* root);//释放四棵树的空间
};
#endif

