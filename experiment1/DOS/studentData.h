// Copyright (c) 2020 ���ǳ�.20192121026.ʦ��һ�� All rights reserved.
// Copyright (c) 2020 ���ǳ�.20192121026.ʦ��һ�� All rights reserved.
// Copyright (c) 2020 ���ǳ�.20192121026.ʦ��һ�� All rights reserved.

//���ļ���ѧ��������Ķ����ļ�
#pragma once
#ifndef _studentData_h_
#define _studentData_h_
#include"student.h"
//
//��������studentData��Ķ��壬��������ͨ��������ʽ�齨�ļ�����
//�������ݽ�����ӡ�ɾ�������롢���ҡ���ȡ��д��ȵȲ���
//
class studentData
{
private:
	student* first;
public:
	string fileName;//�ļ���
	void establish();//�½�������
	void readData();// ��ȡ�ļ�����������
	void writeData();//д���ļ�����������
	student* add();//�����Ϣ
	bool del();//ɾ����Ϣ
	student* change();//�޸���Ϣ
	student* searchNum(string n,int flag);//��ѧ�Ų�����Ϣ��flagΪ0ʱ����Ŀ��ڵ��ַ��flagΪ1ʱ������ǰһ������ַ
	student* searchName(string n);
	bool list();//���������Ϣ
	bool rank();//����
	~studentData();//����������д���ļ����������ݣ��ͷ�����ռ�
	bool insert();//����
};
#endif