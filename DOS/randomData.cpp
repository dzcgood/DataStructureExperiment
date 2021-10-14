//文件名：randomData.cpp
//程序功能：产生百万数据并存储在randomData.dat文件中
//作者：邓智超
//日期：2020.12.05
//版本：2.0
#include"studentDataBase.h"
#include"student.h"
#include<string>
#include<fstream>
#include<iostream>

//返回值：无
//函数功能：随机产生百万数据，并写入到randomData.dat文件中
void emergeData()
{
    student* p;
    ofstream outfile("randomData.dat", ios::binary);
    if (!outfile)
    {
        cout << "open error" << endl;
        abort();
    }
    cout << "正在生成，请稍后……" << endl;
    for (int i = 0; i <= 1000000; i++)
    {
        p = new student;
        sprintf_s(p->number, "%d",rand()%1000000);//把随机产生的数字转换成字符数组
        sprintf_s(p->name, "%d", rand() % 100000); 
        sprintf_s(p->birthday, "%d", rand() % 10000000 + 19000000);
        sprintf_s(p->gender, "%d", rand() % 2);
        sprintf_s(p->phoneNumber, "%d", rand() % 1000000000 + 1000000000);
        sprintf_s(p->address, "%d", rand() % 10000);
        p->leftChild = 0;
        p->rightChild =0;
        outfile.write((char*)&(*p), sizeof(student));
        delete p;
    }
    outfile.close();
    cout << "生成成功！" << endl;
}
