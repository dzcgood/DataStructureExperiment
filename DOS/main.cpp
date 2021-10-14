// Copyright (c) 2020 ���ǳ�.20192121026.ʦ��һ�� All rights reserved.
//�ļ�����: main.cpp
//ģ�鹦��˵��:���ļ�����������ʵ���ļ�����Ҫ��������Ϊ�˵�������ʹ���ߵ�ָ�����������صĺ�����
//��ǰ�汾��:version 3.0
//����:���ǳ�
//�޸���:���ǳ�
//�������:2020/10/25
//�汾��ʷ��Ϣ:
//              version 1.0:��ɻ���ϵͳ���ܵĿ��� ʱ�䣺2020/10/23
//              version 2.0:���ϵͳbug���޸�      ʱ�䣺2020/10/24
//              version 3.0:�Ż��û���������       ʱ�䣺2020/10/25


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
	cout << "                                            ��ӭ���롰ѧ����������ϵͳ��" << endl << endl;
	//������ָ���11ʱ����Ĭ�ϲ��˳�ϵͳ
	while (input != 11)
	{
		cout << "------------------------------------------------------------------------------" << endl;
		cout << "  1���½�ѧ�������� 2�������Ϣ 3��������Ϣ 4��ɾ����Ϣ 5���޸Ľ���״̬" << endl << endl;
		cout << "  6������ 7����ѯ 8�����������Ϣ 9:��ȡ�ļ� 10��д���ļ� 11���˳�ϵͳ" << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			WD.establish();//���ļ�
			break;
		case 2:
			WD.add();//���
			break;
		case 3:
			WD.insert();//����
			break;
		case 4:
			WD.del();//ɾ��
			break;
		case 5:
			WD.change();//�޸�
			break;
		case 6:
			WD.rank();//����
			break;
		case 7:
			//��ѯ
			cout << "������Ҫ���ҵ�ѧ�ţ�" << endl;
			cin >> num;
			if (WD.searchNum(num, 0) != 0)
			{
				cout << endl << endl;
				title();
				cout << *WD.searchNum(num, 0) << endl;
			}
			else cout << "δ�鵽�����Ϣ����";
			cout << endl << endl;
			break;
		case 8:
			WD.list();//���������Ϣ
			break;
		case 9:
			WD.readData();//��ȡ�ʼ�
			break;
		case 10:
			WD.writeData();//д���ļ�
			break;
		case 11:
		{
			cout << "ף��������죬�ټ���!" << endl;//�˳�ϵͳ
			break;
		}
		default:
			cout << "This is impossible! Please input correct orders!!!" << endl << endl;
		}
	}
	return 0;
}