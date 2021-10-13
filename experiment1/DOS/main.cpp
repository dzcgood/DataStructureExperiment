// Copyright (c) 2020 邓智超.20192121026.师范一班 All rights reserved.
//文件名称: main.cpp
//模块功能说明:该文件是主函数的实现文件，主要作用是作为菜单，根据使用者的指令输入调用相关的函数。
//当前版本号:version 3.0
//作者:邓智超
//修改者:邓智超
//完成日期:2020/10/25
//版本历史信息:
//              version 1.0:完成基本系统功能的开发 时间：2020/10/23
//              version 2.0:相关系统bug的修改      时间：2020/10/24
//              version 3.0:优化用户交互界面       时间：2020/10/25


#include<iostream>
#include<iomanip>
#include"student.h"
#include"studentData.h"
using namespace std;

extern void title();

int main()
{
	int input = 1;
	string num ;
	studentData WD;
	cout << endl ;
	cout << "                                            欢迎进入“学生健康管理系统”" << endl << endl;
	//当输入指令不是11时，就默认不退出系统
	while (input != 11)
	{
		cout << "------------------------------------------------------------------------------" << endl;
		cout << "  1：新建学生健康表 2：添加信息 3：插入信息 4：删除信息 5：修改健康状态" << endl << endl;
		cout << "  6：排序 7：查询 8：输出所有信息 9:读取文件 10：写入文件 11：退出系统" << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			WD.establish();//建文件
			break;
		case 2:
			WD.add();//添加
			break;
		case 3:
			WD.insert();//插入
			break;
		case 4:
			WD.del();//删除
			break;
		case 5:
			WD.change();//修改
			break;
		case 6:
			WD.rank();//排序
			break;
		case 7:
			//查询
			cout << "请输入要查找的学号：" << endl;
			cin >> num;
			if (WD.searchNum(num, 0) != 0)
			{
				cout << endl << endl;
				title();
				cout << *WD.searchNum(num, 0) << endl;
			}
			else cout << "未查到相关信息！！";
			cout << endl << endl;
			break;
		case 8:
			WD.list();//输出所有信息
			break;
		case 9:
			WD.readData();//读取问价
			break;
		case 10:
			WD.writeData();//写入文件
			break;
		case 11:
		{
			cout << "祝您生活愉快，再见！!" << endl;//退出系统
			break;
		}
		default:
			cout << "This is impossible! Please input correct orders!!!" << endl << endl;
		}
	}
	return 0;
}