// Copyright (c) 2020 ���ǳ�.20192121026.ʦ��һ�� All rights reserved.
//�ļ�����: student.cpp
//ģ�鹦��˵��:���ļ���student���ʵ���ļ������幦����鿴student.h�ļ�ע��
//��ǰ�汾��:version 3.0
//����:���ǳ�
//�޸���:���ǳ�
//�������:2020/10/25
//�汾��ʷ��Ϣ:
//              version 1.0:��ɻ���ϵͳ���ܵĿ��� ʱ�䣺2020/10/23
//              version 2.0:���ϵͳbug���޸�      ʱ�䣺2020/10/24
//              version 3.0:�Ż��û���������       ʱ�䣺2020/10/25
//
#include"student.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//���캯�������������Գ�ʼ��Ϊ""
student::student()
{
	name = "";
	number = "";
	gender = "";
	dateOfBirth = "";
	healthCondition = "";
}


//��������
string student::getName()
{
	return name;
}


//���س�������
string student::getDateOfBirth()
{
	return dateOfBirth;
}


//�����Ա�
string student::getGender()
{
	return gender;
}


//���ؽ���״��
string student::getHealthCondition()
{
	return healthCondition;
}


//����ѧ��
string student::getNumber()
{
	return number;
}


////"���"��Ա��������ĸ������Ը�ֵΪ��������������
bool student::addStudent(string n, string num, string g, string dOB, string hC)
{
	name=n;
	number = num;
	dateOfBirth = dOB;
	gender = g;
	healthCondition = hC;
	return 1;
}


//��student������<<��������������
ostream& operator <<(ostream& out, student& student1)//����<<
{
	cout << setw(8) << student1.name;
	cout << setw(13) << student1.number;
	cout << setw(6) << student1.gender;
	cout << setw(16) << student1.dateOfBirth;
	cout << setw(10) << student1.healthCondition;
	return out;
}

//�����������������
void student::exchange(student& w2)
{
	string temp1;
	temp1 = this->name;//��������
	this->name = w2.name;
	w2.name = temp1;
	temp1 = this->number;//����ѧ��
	this->number = w2.number;
	w2.number = temp1;
	temp1 = this->gender;//�����Ա�
	this->gender = w2.gender;
	w2.gender = temp1;
	temp1 = this->dateOfBirth;//������������
	this->dateOfBirth = w2.dateOfBirth;
	w2.dateOfBirth = temp1;
	temp1 = this->healthCondition;//��������״��
	this->healthCondition = w2.healthCondition;
	w2.healthCondition = temp1;
}