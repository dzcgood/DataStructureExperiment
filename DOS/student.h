// Copyright (c) 2020 邓智超.20192121026.师范一班 All rights reserved.
// Copyright (c) 2020 邓智超.20192121026.师范一班 All rights reserved.
// Copyright (c) 2020 邓智超.20192121026.师范一班 All rights reserved.

//该文件是student类的定义文件
#pragma once
#ifndef _student_h_
#define _student_h_
#include<string>
using namespace std;
//
//以下是student类的定义，其主要作用是存储每一个学生的各项数据
//
class student
{
private:
	string name;//姓名
	string number;//学号
	string dateOfBirth;//出生日期
	string gender;//性别
	string healthCondition;//健康状况
public:
	student* next;//指向下一节点
	student();//构造函数，初始化信息
	string getName();//返回姓名
	string getDateOfBirth();//返回出生日期
	string getGender();//返回性别
	string getHealthCondition();//返回健康状况
	string getNumber();//返回学号
	bool addStudent(string n, string num, string g,string dOB, string hC);//添加，将某对象的属性赋值
	//                                                                      形参分别代表姓名，学号，性别，出生日期，健康状况
	friend ostream& operator <<(ostream& out, student& student1);//重载<<
	void exchange(student& w2);//交换两个对象的数据，运用选择排序的时候便于交换数据
};
#endif