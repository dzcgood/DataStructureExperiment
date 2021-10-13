// Copyright (c) 2020 邓智超.20192121026.师范一班 All rights reserved.
//文件名称: studentData.cpp
//模块功能说明:该文件是studentData类的实现文件，具体功能请查看studentData.h文件注释
//当前版本号:version 3.0
//作者:邓智超
//修改者:邓智超
//完成日期:2020/10/25
//版本历史信息:
//              version 1.0:完成基本系统功能的开发 时间：2020/10/23
//              version 2.0:相关系统bug的修改      时间：2020/10/24
//              version 3.0:优化用户交互界面       时间：2020/10/25
//
#include"studentData.h"
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;


//建立新的文件表，根据用户输入，确定文件名
void studentData::establish()
{
	cout << "请输入健康表名称：" << endl;
	cin >> fileName;
	fileName = fileName + ".dat";
	cout << "建立成功！！" << endl << endl;
}


//读取文件，构建链表
//若文件为空，报错
//每次读入五个字符串，分别赋值给姓名，学号，性别，出生日期，健康状况，之后通过头插入建链
void studentData::readData()
{
	fstream file;
	string fileName1;
	cout << "请输入要读取的文件名:" << endl;
	cin >> fileName1;
	file.open(fileName1 + ".dat", ios::in);
	string name;
	string number;
	string gender;
	string dateOfBirth;
	string healthCondition;
	while (1)
	{
		file >> name >> number >> gender >> dateOfBirth >> healthCondition;
		if (!file)break;
		student* p = new student;
		p->addStudent(name, number, gender, dateOfBirth, healthCondition);
		p->next = first;//头插入方式，可以避免判断链表是否为空
		first = p;
	}
	file.close();
	if (first == 0)
	{
		cout << "ERROR：该文件为空！！" << endl << endl;
		return;
	}
	else cout << "读取成功！！" << endl << endl;
	list();//输出所有信息，函数实现在后面
}


//写入文件
//若fileName为空，则先让用户输入要存储的文件名
//若链表为空，报错
//按姓名，学号，性别，出生日期，健康状况写入文件
void studentData::writeData()
{
	if (fileName == "")
	{
		cout << "请输入要存入的文件名：" << endl;
		cin >> fileName;
		fileName = fileName + ".dat";
	}
	student* current = first;
	if (first == 0)
	{
		cout << "ERROR：链表为空，无法写入，请输入数据！！" << endl;
		return;
	}
	fstream file;
	file.open(fileName, ios::out);
	while (current != 0)
	{
		file << current->getName() << " " << current->getNumber() << " " << current->getGender() << " "
			<< current->getDateOfBirth() << " " << current->getHealthCondition() << " ";
		current = current->next;
	}
	file.close();
	cout << "写入数据成功！!" << endl << endl;
}


////输出列表时作为标题
void title()
{
	cout << setw(8) << "姓名";
	cout << setw(13) << "学号";
	cout << setw(6) << "性别";
	cout << setw(16) << "出生日期";
	cout << setw(10) << "健康状况";
	cout << endl;
}


//输出所有信息
//若链表为空，报错
//此处已经对student类重载了<<操作符，直接用<<输出对象信息即可
bool studentData::list()
{
	cout << endl << endl;
	if (first == 0)cout << "ERROR：信息库为空，无相关信息！" << endl;

	else
	{
		title();
		student* current = first;
		while (current != 0)
		{
			cout << *current << endl;
			current = current->next;
		}
	}
	cout << endl << endl;
	return 1;
}


//按照学号查找结点位置，返回值是地址
//若flag==0，返回目标节点地址
//若flag==1，返回目标节点前一个节点的地址，便于插入和删除
student* studentData::searchNum(string n, int flag)
{
	student* current = first;
	student* prenode = 0;
	while (current != 0 && current->getNumber() != n)
	{
		prenode = current;
		current = current->next;
	}
	if (current == 0)//没有查到信息
	{
		return 0;
	}
	else if (flag == 0 || current == first)return current;//返回目标节点地址
	else return prenode;//返回目标节点地址的前一个地址
}


//按照姓名查找，直接返回目标节点地址
//实现思路与学号查找类似
student* studentData::searchName(string n)
{

	student* current = first;
	student* prenode = 0;
	while (current != 0 && current->getName() != n)
	{
		prenode = current;
		current = current->next;
	}
	if (current == 0)//未查到信息
	{
		return 0;
	}
	return current;//返回目标节点地址
}


//按照用户输入的位置，将current指针进行相应的移动，使得指针指向要插入位置的前一个指针
//若用户向插入的位置的前一个位置没有节点，则输出提醒，并默认插入到最后一个位置！
//插入信息时，要对信息是否重复进行判断
bool studentData::insert()
{
	int address;
	cout << "你想在第几个位置插入信息？" << endl;
	cin >> address;
	student* current=first;
	//将指针进行移动
	for (int i = 1; i <= address-2; i++)
	{
		current = current->next;//将指针移动到插入位置
		if (current->next == 0&&i!=address-2)
		{
			cout << "WARNING：该信息表的第" << address - 1 << "个位置没有信息，故不能在第" 
				 << address << "个位置插入信息，默认在最后位置插入！" << endl;
			break;
		}

	}
	//输入信息
	string name, number, gender, dateOfBirth, healthCondition;
	cout << "请分别输入学生的姓名，学号，性别，出生日期，健康状况" << endl;
	cin >> name >> number >> gender >> dateOfBirth >> healthCondition;
	//判断姓名是否重复
	if (searchName(name) != 0)
	{
		cout << "ERROR：姓名为" << name << "的学生已经存在！" << endl << endl << endl;
		return 0;
	}
	//判断学号是否重复
	else if (searchNum(number, 0) != 0)
	{
		cout << "ERROR：" << number << "的学生已经存在！" << endl << endl << endl;
		return 0;
	}
	student* p = new student;
	p->addStudent(name, number, gender, dateOfBirth, healthCondition);//赋值
	//插入位置是第一个节点
	if (address == 1)
	{
		p->next = first;
		first = p;
	}
	//其他情况
	else
	{
		p->next = current->next;
		current->next = p;
	}
	cout << "添加成功！！" << endl << endl;
	return 1;
}


//采用头插入方式
//插入前先判断姓名，学号是否重复
student* studentData::add()//添加信息
{
	string name, number,gender, dateOfBirth, healthCondition;
	cout << "请分别输入学生的姓名，学号，性别，出生日期，健康状况" << endl;
	cin >> name >> number >> gender >> dateOfBirth >> healthCondition;
	//判断姓名是否重复
	if (searchName(name) != 0)
	{
		cout << "ERROR：姓名为" << name << "的学生已经存在！" << endl << endl << endl;
		return first;
	}
	//判断学号是否重复
	else if (searchNum(number,0) != 0)
	{
		cout << "ERROR：学号为" << number << "的学生已经存在！" << endl << endl << endl;
		return first;
	}
	student* p = new student;
	p->addStudent(name, number, gender, dateOfBirth, healthCondition);//输入结点信息
	//插入节点
	p->next = first;
	first = p;
	cout << "添加成功！！" << endl << endl;
	return first;
}


//利用searchNum函数返回的前一节点地址，实现删除操作
bool studentData::del()//删除信息
{
	cout << "请输入要删除者的学号：" << endl;
	string number1;
	cin >> number1;
	student* p = searchNum(number1, 1);//返回前一结点地址
	if (p == 0)
	{
		cout << "ERROR：无相关信息！" << endl << endl;
		return 0;
	}
	else
	{
		//要删除的节点是表头
		if (p == first)
		{
			first = p->next;
			delete p;
		}
		//其他情况
		else
		{
			p->next = (p->next)->next;
			delete p->next;
		}
	}
	cout << "删除成功！！" << endl << endl;
	return 1;
}


//修改信息
student* studentData::change()
{
	cout << "请输入要修改者的学号：" << endl;
	string number1;
	cin >> number1;
	student* p = searchNum(number1,0);//返回目标结点地址
	if (p == 0)
	{
		cout << "ERROR：无相关信息！" << endl << endl;
		return first;
	}
	else
	{
		string condition;
		cout << "请输入修改后的学生健康状况：" << endl;
		cin >> condition;
		cout << "信息修改成功！" << endl << endl;
		p->addStudent(p->getName(), p->getNumber(), p->getGender(), p->getDateOfBirth(), condition);//刷新信息
		return first;
	}
}


//按照学号从小到大排序
//用选择排序的方法
//已经定义了exchange函数，可以用于交换两个节点的内容
bool studentData::rank()//排序
{
	if (first == 0)
	{
		cout << "ERROR：信息库为空，无法排序，请输入数据！" << endl;
		return 0;
	}
	student* p=0;
	student* q=0;
	//选择排序
	for(p=first;p!=0;p=p->next)
		for (q = p->next; q != 0; q = q->next)
			if (q->getNumber() < p->getNumber())
				p->exchange(*q);//交换数据
	cout << "已经按照学号大小排序成功！！" << endl << endl;
	list();//输出信息
	return 1;
}



//释放链表空间
studentData::~studentData()
{
	student* current;
	while (first != 0)
	{
		current = first;
		first = first->next;
		delete current;
	}
}
