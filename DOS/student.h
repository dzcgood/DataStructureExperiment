//文件名：student.h
//程序功能：student结构体的声明和其相关函数的实现
//          以姓名、学号、电话号码为关键字的三棵辅助二叉搜索树结点结构体的声明
//作者：邓智超
//日期：2020.12.05
//版本：2.0
#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//学生结点，包含学生的所有信息
struct student
{
	//学号、姓名、出生日期、性别、电话和地址
	char number[15];//学号
	char name[10];//姓名
	char birthday[12];//出生日期
	char gender[8];//性别
	char phoneNumber[15];//电话
	char address[20];//地址
	student* leftChild = NULL;
	student* rightChild = NULL;
	bool isDeleted=0;//判断是否被删除 若已经删除，则isDeleted值为1
	friend ostream& operator<<(ostream& out, student stu)//重载输出
	{
		out << setw(15) << stu.number;
		out << setw(10) << stu.name;
		out << setw(12) << stu.birthday;
		out << setw(8) << stu.gender;
		out << setw(15) << stu.phoneNumber;
		out << setw(20) << stu.address;
		return out;
	}
	friend istream& operator>>(istream& in, student& stu)//重载输入
	{
		in >> stu.number;
		if (stu.number[0] == '#')//表示输入结束
			return in;
		else
			in >> stu.name >> stu.birthday >> stu.gender >> stu.phoneNumber >> stu.address;
		return in;
	}
	void operator=(student* p2)//重载=
	{
		strcpy_s(this->number, p2->number);
		strcpy_s(this->name, p2->name);
		strcpy_s(this->birthday, p2->birthday);
		strcpy_s(this->gender, p2->gender);
		strcpy_s(this->phoneNumber, p2->phoneNumber);
		strcpy_s(this->address, p2->address);
	}
};

//以姓名构建的搜索二叉树结点
//用于构建辅助结构
struct nameTreeNode
{
	char name[10];//姓名
	student* pointer = 0;//指向二叉树中的结点
	nameTreeNode* leftChild = 0;
	nameTreeNode* rightChild = 0;
};



//以学号构建的搜索二叉树结点
//用于构建辅助结构
struct numberTreeNode
{
	char number[15];//学号
	student* pointer = 0;//指向二叉树中的结点
	numberTreeNode* leftChild = 0;
	numberTreeNode* rightChild = 0;
};


//以电话号码构建的搜索二叉树结点
//用于构建辅助结构
struct phoneNumTreeNode
{
	char phoneNumber[15];//电话号码
	student* pointer = 0;//指向二叉树中的结点
	phoneNumTreeNode* leftChild = 0;
	phoneNumTreeNode* rightChild = 0;
};
#endif