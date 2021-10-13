//�ļ�����studentDataBase.h
//�����ܣ�studentDataBase�������������Ĺ�����ʵ�ֶԶ������ĸ������
//���ߣ����ǳ�
//���ڣ�2020.12.05
//�汾��2.0
#pragma once
#ifndef STUDENTDATABASE_H_
#define STUDENTDATABASE_H_
#include<string>
#include<iostream>
#include"student.h"
using namespace std;


class studentDataBase
{
private:
    void previsit(student* root);//ǰ�����
    void midvisit(student* root);//�������
    void behvisit(student* root);//�������
public:
    student* root;//�����
    studentDataBase();//���캯��
	void createTree();//�½�
    student* searchNum(numberTreeNode*root,char num[]);//��ѧ�Ų���
    student* searchName(nameTreeNode*root,char name[]);//����������
    student* searchPhoneNum(phoneNumTreeNode*root,char phoneNum[]);//���绰��ѯ
    bool delByNum(char num[]);//��ѧ��ɾ��
    bool delByName(char name[]);//������ɾ��
    bool delByPhoneNum(char phoneNum[]);//���绰ɾ��
    bool insertByNum(student* p, numberTreeNode*& root1);//��ѧ��������
    bool insertByName(student* p, nameTreeNode*& root1);//������������
    bool insertByPhoneNum(student* p, phoneNumTreeNode*& root1);//�ڵ绰������
    void insert(student* p, student*& root);//�ڶ���������
    void getYoungest(student*root);//���������Сѧ����Ϣ
    void output();//���ѧ����Ϣ
    void readFile(string fileName);//����
    void writeFile(string fileName);//д��
    void deleteTree(student* root);//�ͷ��Ŀ����Ŀռ�
};
#endif

