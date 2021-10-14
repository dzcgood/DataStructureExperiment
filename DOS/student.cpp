// Copyright (c) 2020 邓智超.20192121026.师范一班 All rights reserved.
//文件名称: student.cpp
//模块功能说明:该文件是student类的实现文件，具体功能请查看student.h文件注释
//当前版本号:version 3.0
//作者:邓智超
//修改者:邓智超
//完成日期:2020/10/25
//版本历史信息:
//              version 1.0:完成基本系统功能的开发 时间：2020/10/23
//              version 2.0:相关系统bug的修改      时间：2020/10/24
//              version 3.0:优化用户交互界面       时间：2020/10/25
//
#include"student.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//构造函数，将所有属性初始化为""
student::student()
{
	name = "";
	number = "";
	gender = "";
	dateOfBirth = "";
	healthCondition = "";
}


//返回姓名
string student::getName()
{
	return name;
}


//返回出生日期
string student::getDateOfBirth()
{
	return dateOfBirth;
}


//返回性别
string student::getGender()
{
	return gender;
}


//返回健康状况
string student::getHealthCondition()
{
	return healthCondition;
}


//返回学号
string student::getNumber()
{
	return number;
}


////"添加"成员，将对象的各个属性赋值为函数参数的内容
bool student::addStudent(string n, string num, string g, string dOB, string hC)
{
	name=n;
	number = num;
	dateOfBirth = dOB;
	gender = g;
	healthCondition = hC;
	return 1;
}


//对student类重载<<运算符，便于输出
ostream& operator <<(ostream& out, student& student1)//重载<<
{
	cout << setw(8) << student1.name;
	cout << setw(13) << student1.number;
	cout << setw(6) << student1.gender;
	cout << setw(16) << student1.dateOfBirth;
	cout << setw(10) << student1.healthCondition;
	return out;
}

//交换两个对象的数据
void student::exchange(student& w2)
{
	string temp1;
	temp1 = this->name;//交换姓名
	this->name = w2.name;
	w2.name = temp1;
	temp1 = this->number;//交换学号
	this->number = w2.number;
	w2.number = temp1;
	temp1 = this->gender;//交换性别
	this->gender = w2.gender;
	w2.gender = temp1;
	temp1 = this->dateOfBirth;//交换出生日期
	this->dateOfBirth = w2.dateOfBirth;
	w2.dateOfBirth = temp1;
	temp1 = this->healthCondition;//交换健康状况
	this->healthCondition = w2.healthCondition;
	w2.healthCondition = temp1;
}