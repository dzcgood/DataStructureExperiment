//�ļ�����randomData.cpp
//�����ܣ������������ݲ��洢��randomData.dat�ļ���
//���ߣ����ǳ�
//���ڣ�2020.12.05
//�汾��2.0
#include"studentDataBase.h"
#include"student.h"
#include<string>
#include<fstream>
#include<iostream>

//����ֵ����
//�������ܣ���������������ݣ���д�뵽randomData.dat�ļ���
void emergeData()
{
    student* p;
    ofstream outfile("randomData.dat", ios::binary);
    if (!outfile)
    {
        cout << "open error" << endl;
        abort();
    }
    cout << "�������ɣ����Ժ󡭡�" << endl;
    for (int i = 0; i <= 1000000; i++)
    {
        p = new student;
        sprintf_s(p->number, "%d",rand()%1000000);//���������������ת�����ַ�����
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
    cout << "���ɳɹ���" << endl;
}
