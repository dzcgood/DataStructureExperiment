// Copyright (c) 2020 邓智超.20192121026.师范一班 All rights reserved.
// Copyright (c) 2020 邓智超.20192121026.师范一班 All rights reserved.
// Copyright (c) 2020 邓智超.20192121026.师范一班 All rights reserved.

//该文件是学生数据类的定义文件
#pragma once
#ifndef _studentData_h_
#define _studentData_h_
#include"student.h"
//
//接下来是studentData类的定义，其作用是通过链表形式组建文件数据
//并对数据进行添加、删除、插入、查找、读取、写入等等操作
//
class studentData
{
private:
	student* first;
public:
	string fileName;//文件名
	void establish();//新建健康表
	void readData();// 读取文件，生成链表
	void writeData();//写入文件，更新内容
	student* add();//添加信息
	bool del();//删除信息
	student* change();//修改信息
	student* searchNum(string n,int flag);//按学号查找信息，flag为0时返回目标节点地址，flag为1时，返回前一个结点地址
	student* searchName(string n);
	bool list();//输出所有信息
	bool rank();//排序
	~studentData();//析构函数，写入文件，更新内容，释放链表空间
	bool insert();//插入
};
#endif