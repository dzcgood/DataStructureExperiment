//�ļ�����student.h
//�����ܣ�student�ṹ�������������غ�����ʵ��
//          ��������ѧ�š��绰����Ϊ�ؼ��ֵ����ø����������������ṹ�������
//���ߣ����ǳ�
//���ڣ�2020.12.05
//�汾��2.0
#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//ѧ����㣬����ѧ����������Ϣ
struct student
{
	//ѧ�š��������������ڡ��Ա𡢵绰�͵�ַ
	char number[15];//ѧ��
	char name[10];//����
	char birthday[12];//��������
	char gender[8];//�Ա�
	char phoneNumber[15];//�绰
	char address[20];//��ַ
	student* leftChild = NULL;
	student* rightChild = NULL;
	bool isDeleted=0;//�ж��Ƿ�ɾ�� ���Ѿ�ɾ������isDeletedֵΪ1
	friend ostream& operator<<(ostream& out, student stu)//�������
	{
		out << setw(15) << stu.number;
		out << setw(10) << stu.name;
		out << setw(12) << stu.birthday;
		out << setw(8) << stu.gender;
		out << setw(15) << stu.phoneNumber;
		out << setw(20) << stu.address;
		return out;
	}
	friend istream& operator>>(istream& in, student& stu)//��������
	{
		in >> stu.number;
		if (stu.number[0] == '#')//��ʾ�������
			return in;
		else
			in >> stu.name >> stu.birthday >> stu.gender >> stu.phoneNumber >> stu.address;
		return in;
	}
	void operator=(student* p2)//����=
	{
		strcpy_s(this->number, p2->number);
		strcpy_s(this->name, p2->name);
		strcpy_s(this->birthday, p2->birthday);
		strcpy_s(this->gender, p2->gender);
		strcpy_s(this->phoneNumber, p2->phoneNumber);
		strcpy_s(this->address, p2->address);
	}
};

//�������������������������
//���ڹ��������ṹ
struct nameTreeNode
{
	char name[10];//����
	student* pointer = 0;//ָ��������еĽ��
	nameTreeNode* leftChild = 0;
	nameTreeNode* rightChild = 0;
};



//��ѧ�Ź������������������
//���ڹ��������ṹ
struct numberTreeNode
{
	char number[15];//ѧ��
	student* pointer = 0;//ָ��������еĽ��
	numberTreeNode* leftChild = 0;
	numberTreeNode* rightChild = 0;
};


//�Ե绰���빹�����������������
//���ڹ��������ṹ
struct phoneNumTreeNode
{
	char phoneNumber[15];//�绰����
	student* pointer = 0;//ָ��������еĽ��
	phoneNumTreeNode* leftChild = 0;
	phoneNumTreeNode* rightChild = 0;
};
#endif