// Copyright (c) 2020 ���ǳ�.20192121026.ʦ��һ�� All rights reserved.
//�ļ�����: studentData.cpp
//ģ�鹦��˵��:���ļ���studentData���ʵ���ļ������幦����鿴studentData.h�ļ�ע��
//��ǰ�汾��:version 3.0
//����:���ǳ�
//�޸���:���ǳ�
//�������:2020/10/25
//�汾��ʷ��Ϣ:
//              version 1.0:��ɻ���ϵͳ���ܵĿ��� ʱ�䣺2020/10/23
//              version 2.0:���ϵͳbug���޸�      ʱ�䣺2020/10/24
//              version 3.0:�Ż��û���������       ʱ�䣺2020/10/25
//
#include"studentData.h"
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;


//�����µ��ļ��������û����룬ȷ���ļ���
void studentData::establish()
{
	cout << "�����뽡�������ƣ�" << endl;
	cin >> fileName;
	fileName = fileName + ".dat";
	cout << "�����ɹ�����" << endl << endl;
}


//��ȡ�ļ�����������
//���ļ�Ϊ�գ�����
//ÿ�ζ�������ַ������ֱ�ֵ��������ѧ�ţ��Ա𣬳������ڣ�����״����֮��ͨ��ͷ���뽨��
void studentData::readData()
{
	fstream file;
	string fileName1;
	cout << "������Ҫ��ȡ���ļ���:" << endl;
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
		p->next = first;//ͷ���뷽ʽ�����Ա����ж������Ƿ�Ϊ��
		first = p;
	}
	file.close();
	if (first == 0)
	{
		cout << "ERROR�����ļ�Ϊ�գ���" << endl << endl;
		return;
	}
	else cout << "��ȡ�ɹ�����" << endl << endl;
	list();//���������Ϣ������ʵ���ں���
}


//д���ļ�
//��fileNameΪ�գ��������û�����Ҫ�洢���ļ���
//������Ϊ�գ�����
//��������ѧ�ţ��Ա𣬳������ڣ�����״��д���ļ�
void studentData::writeData()
{
	if (fileName == "")
	{
		cout << "������Ҫ������ļ�����" << endl;
		cin >> fileName;
		fileName = fileName + ".dat";
	}
	student* current = first;
	if (first == 0)
	{
		cout << "ERROR������Ϊ�գ��޷�д�룬���������ݣ���" << endl;
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
	cout << "д�����ݳɹ���!" << endl << endl;
}


////����б�ʱ��Ϊ����
void title()
{
	cout << setw(8) << "����";
	cout << setw(13) << "ѧ��";
	cout << setw(6) << "�Ա�";
	cout << setw(16) << "��������";
	cout << setw(10) << "����״��";
	cout << endl;
}


//���������Ϣ
//������Ϊ�գ�����
//�˴��Ѿ���student��������<<��������ֱ����<<���������Ϣ����
bool studentData::list()
{
	cout << endl << endl;
	if (first == 0)cout << "ERROR����Ϣ��Ϊ�գ��������Ϣ��" << endl;

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


//����ѧ�Ų��ҽ��λ�ã�����ֵ�ǵ�ַ
//��flag==0������Ŀ��ڵ��ַ
//��flag==1������Ŀ��ڵ�ǰһ���ڵ�ĵ�ַ�����ڲ����ɾ��
student* studentData::searchNum(string n, int flag)
{
	student* current = first;
	student* prenode = 0;
	while (current != 0 && current->getNumber() != n)
	{
		prenode = current;
		current = current->next;
	}
	if (current == 0)//û�в鵽��Ϣ
	{
		return 0;
	}
	else if (flag == 0 || current == first)return current;//����Ŀ��ڵ��ַ
	else return prenode;//����Ŀ��ڵ��ַ��ǰһ����ַ
}


//�����������ң�ֱ�ӷ���Ŀ��ڵ��ַ
//ʵ��˼·��ѧ�Ų�������
student* studentData::searchName(string n)
{

	student* current = first;
	student* prenode = 0;
	while (current != 0 && current->getName() != n)
	{
		prenode = current;
		current = current->next;
	}
	if (current == 0)//δ�鵽��Ϣ
	{
		return 0;
	}
	return current;//����Ŀ��ڵ��ַ
}


//�����û������λ�ã���currentָ�������Ӧ���ƶ���ʹ��ָ��ָ��Ҫ����λ�õ�ǰһ��ָ��
//���û�������λ�õ�ǰһ��λ��û�нڵ㣬��������ѣ���Ĭ�ϲ��뵽���һ��λ�ã�
//������Ϣʱ��Ҫ����Ϣ�Ƿ��ظ������ж�
bool studentData::insert()
{
	int address;
	cout << "�����ڵڼ���λ�ò�����Ϣ��" << endl;
	cin >> address;
	student* current=first;
	//��ָ������ƶ�
	for (int i = 1; i <= address-2; i++)
	{
		current = current->next;//��ָ���ƶ�������λ��
		if (current->next == 0&&i!=address-2)
		{
			cout << "WARNING������Ϣ��ĵ�" << address - 1 << "��λ��û����Ϣ���ʲ����ڵ�" 
				 << address << "��λ�ò�����Ϣ��Ĭ�������λ�ò��룡" << endl;
			break;
		}

	}
	//������Ϣ
	string name, number, gender, dateOfBirth, healthCondition;
	cout << "��ֱ�����ѧ����������ѧ�ţ��Ա𣬳������ڣ�����״��" << endl;
	cin >> name >> number >> gender >> dateOfBirth >> healthCondition;
	//�ж������Ƿ��ظ�
	if (searchName(name) != 0)
	{
		cout << "ERROR������Ϊ" << name << "��ѧ���Ѿ����ڣ�" << endl << endl << endl;
		return 0;
	}
	//�ж�ѧ���Ƿ��ظ�
	else if (searchNum(number, 0) != 0)
	{
		cout << "ERROR��" << number << "��ѧ���Ѿ����ڣ�" << endl << endl << endl;
		return 0;
	}
	student* p = new student;
	p->addStudent(name, number, gender, dateOfBirth, healthCondition);//��ֵ
	//����λ���ǵ�һ���ڵ�
	if (address == 1)
	{
		p->next = first;
		first = p;
	}
	//�������
	else
	{
		p->next = current->next;
		current->next = p;
	}
	cout << "��ӳɹ�����" << endl << endl;
	return 1;
}


//����ͷ���뷽ʽ
//����ǰ���ж�������ѧ���Ƿ��ظ�
student* studentData::add()//�����Ϣ
{
	string name, number,gender, dateOfBirth, healthCondition;
	cout << "��ֱ�����ѧ����������ѧ�ţ��Ա𣬳������ڣ�����״��" << endl;
	cin >> name >> number >> gender >> dateOfBirth >> healthCondition;
	//�ж������Ƿ��ظ�
	if (searchName(name) != 0)
	{
		cout << "ERROR������Ϊ" << name << "��ѧ���Ѿ����ڣ�" << endl << endl << endl;
		return first;
	}
	//�ж�ѧ���Ƿ��ظ�
	else if (searchNum(number,0) != 0)
	{
		cout << "ERROR��ѧ��Ϊ" << number << "��ѧ���Ѿ����ڣ�" << endl << endl << endl;
		return first;
	}
	student* p = new student;
	p->addStudent(name, number, gender, dateOfBirth, healthCondition);//��������Ϣ
	//����ڵ�
	p->next = first;
	first = p;
	cout << "��ӳɹ�����" << endl << endl;
	return first;
}


//����searchNum�������ص�ǰһ�ڵ��ַ��ʵ��ɾ������
bool studentData::del()//ɾ����Ϣ
{
	cout << "������Ҫɾ���ߵ�ѧ�ţ�" << endl;
	string number1;
	cin >> number1;
	student* p = searchNum(number1, 1);//����ǰһ����ַ
	if (p == 0)
	{
		cout << "ERROR���������Ϣ��" << endl << endl;
		return 0;
	}
	else
	{
		//Ҫɾ���Ľڵ��Ǳ�ͷ
		if (p == first)
		{
			first = p->next;
			delete p;
		}
		//�������
		else
		{
			p->next = (p->next)->next;
			delete p->next;
		}
	}
	cout << "ɾ���ɹ�����" << endl << endl;
	return 1;
}


//�޸���Ϣ
student* studentData::change()
{
	cout << "������Ҫ�޸��ߵ�ѧ�ţ�" << endl;
	string number1;
	cin >> number1;
	student* p = searchNum(number1,0);//����Ŀ�����ַ
	if (p == 0)
	{
		cout << "ERROR���������Ϣ��" << endl << endl;
		return first;
	}
	else
	{
		string condition;
		cout << "�������޸ĺ��ѧ������״����" << endl;
		cin >> condition;
		cout << "��Ϣ�޸ĳɹ���" << endl << endl;
		p->addStudent(p->getName(), p->getNumber(), p->getGender(), p->getDateOfBirth(), condition);//ˢ����Ϣ
		return first;
	}
}


//����ѧ�Ŵ�С��������
//��ѡ������ķ���
//�Ѿ�������exchange�������������ڽ��������ڵ������
bool studentData::rank()//����
{
	if (first == 0)
	{
		cout << "ERROR����Ϣ��Ϊ�գ��޷��������������ݣ�" << endl;
		return 0;
	}
	student* p=0;
	student* q=0;
	//ѡ������
	for(p=first;p!=0;p=p->next)
		for (q = p->next; q != 0; q = q->next)
			if (q->getNumber() < p->getNumber())
				p->exchange(*q);//��������
	cout << "�Ѿ�����ѧ�Ŵ�С����ɹ�����" << endl << endl;
	list();//�����Ϣ
	return 1;
}



//�ͷ�����ռ�
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
