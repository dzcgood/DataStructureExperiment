// Copyright (c) 2020 ���ǳ�.20192121026.ʦ��һ�� All rights reserved.
// Copyright (c) 2020 ���ǳ�.20192121026.ʦ��һ�� All rights reserved.
// Copyright (c) 2020 ���ǳ�.20192121026.ʦ��һ�� All rights reserved.

//���ļ���student��Ķ����ļ�
#pragma once
#ifndef _student_h_
#define _student_h_
#include<string>
using namespace std;
//
//������student��Ķ��壬����Ҫ�����Ǵ洢ÿһ��ѧ���ĸ�������
//
class student
{
private:
	string name;//����
	string number;//ѧ��
	string dateOfBirth;//��������
	string gender;//�Ա�
	string healthCondition;//����״��
public:
	student* next;//ָ����һ�ڵ�
	student();//���캯������ʼ����Ϣ
	string getName();//��������
	string getDateOfBirth();//���س�������
	string getGender();//�����Ա�
	string getHealthCondition();//���ؽ���״��
	string getNumber();//����ѧ��
	bool addStudent(string n, string num, string g,string dOB, string hC);//��ӣ���ĳ��������Ը�ֵ
	//                                                                      �βηֱ����������ѧ�ţ��Ա𣬳������ڣ�����״��
	friend ostream& operator <<(ostream& out, student& student1);//����<<
	void exchange(student& w2);//����������������ݣ�����ѡ�������ʱ����ڽ�������
};
#endif