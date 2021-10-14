//�ļ�����studentDataBase.cpp
//�����ܣ�studentDataBase���ʵ��
//���ߣ����ǳ�
//���ڣ�2020.12.05
//�汾��2.0
#include"studentDataBase.h"
#include<queue>
#include<iostream>
#include<fstream>
extern void title();//������⺯��
extern studentDataBase studata;//�������� �����
extern nameTreeNode* nameTree;//�����������
extern numberTreeNode* numberTree;//ѧ���������
extern phoneNumTreeNode* phoneNumTree;//�绰�������
extern student* MIN;//�洢������С��ѧ������ַ

//����ֵ����
//�������ܣ��ͷ��������Ŀռ�
//�����������������ĸ���ַ
void deleteNameTree(nameTreeNode* root)
{
	if (root == 0)return;
	else
	{
		deleteNameTree(root->leftChild);
		deleteNameTree(root->rightChild);
		delete root;
	}
}

//����ֵ����
//�������ܣ��ͷ�ѧ�����Ŀռ�
//����������ѧ�����ĸ���ַ
void deleteNumberTree(numberTreeNode* root)
{
	if (root == 0)return;
	else
	{
		deleteNumberTree(root->leftChild);
		deleteNumberTree(root->rightChild);
		delete root;
	}
}

//����ֵ����
//�������ܣ��ͷŵ绰���Ŀռ�
//�����������绰���ĸ���ַ
void deletePhoneNumTree(phoneNumTreeNode* root)
{
	if (root == 0)return;
	else
	{
		deletePhoneNumTree(root->leftChild);
		deletePhoneNumTree(root->rightChild);
		delete root;
	}
}

//����ֵ����
//�������ܣ��ͷŶ������Ŀռ�
//�����������������ĸ���ַ
void studentDataBase::deleteTree(student* root)
{
	if (root == 0)return;
	else
	{
		deleteTree(root->leftChild);
		deleteTree(root->rightChild);
		delete root;
	}
}

//����ֵ����
//�������ܣ��ͷ������Ŀ����Ŀռ�
//          һ�����������ø�����
void deleteTrees()
{
	studata.deleteTree(studata.root);
	deleteNameTree(nameTree);
	deleteNumberTree(numberTree);
	deletePhoneNumTree(phoneNumTree);
}

//����ֵ����
//�������ܣ����캯������root��ʼ��Ϊ0
studentDataBase::studentDataBase()
{
	root = 0;
}


//����ֵ����
//�������ܣ��½�ͨѶ¼��Ϣ
void studentDataBase::createTree()
{
	queue<student*>stu;
	root = new student;
	cin >> *root;
	MIN = root;
	stu.push(root);//��������
	while (!stu.empty())
	{
		student* temp = stu.front();//����Ԫ�س���
		stu.pop();
		student* p = new student;//������
		cin >> *p;
		if (p->number[0]=='#')break;
		insertByName(p, nameTree);//�����ø�������Ҳ����
		insertByNum(p, numberTree);
		insertByPhoneNum(p, phoneNumTree);
		temp->leftChild= p;
		stu.push(p);
		p = new student;//������
		cin >> *p;
		if (p->number[0] == '#')break;
		insertByName(p, nameTree);//�����ø�������Ҳ����
		insertByNum(p, numberTree);
		insertByPhoneNum(p, phoneNumTree);
		temp->rightChild = p;
		stu.push(p);
	}
}

//����ֵ��ָ��Ŀ�����ָ��
//�������ܣ���ѧ�Ų�ѯ��Ϣ
//����������ǰ��ΪnumberTree�ĸ��ڵ㣬����Ϊ����ѯ��ѧ��
student* studentDataBase::searchNum(numberTreeNode*root,char num[])
{
	if (root == 0)return 0;
	else if (strcmp(root->number, num) > 0)return searchNum(root->leftChild, num);
	else if (strcmp(root->number, num) < 0)return searchNum(root->rightChild, num);
	else return root->pointer;
}

//����ֵ��ָ��Ŀ�����ָ��
//�������ܣ���������ѯ��Ϣ
//����������ǰ��ΪnameTree�ĸ��ڵ㣬����Ϊ����ѯ������
student* studentDataBase::searchName(nameTreeNode*root,char name[])
{
	if (root == 0)return 0;
	else if (strcmp(root->name, name) > 0)return searchName(root->leftChild, name);
	else if (strcmp(root->name, name) < 0)return searchName(root->rightChild, name);
	else return root->pointer;
}

//����ֵ��ָ��Ŀ�����ָ��
//�������ܣ����绰�����ѯ��Ϣ
//����������ǰ��ΪphoneNumTree�ĸ��ڵ㣬����Ϊ����ѯ�ĵ绰����
student* studentDataBase::searchPhoneNum(phoneNumTreeNode*root,char phoneNum[])
{
	if (root == 0)return 0;
	else if (strcmp(root->phoneNumber, phoneNum) > 0)return searchPhoneNum(root->leftChild, phoneNum);
	else if (strcmp(root->phoneNumber, phoneNum) < 0)return searchPhoneNum(root->rightChild, phoneNum);
	else return root->pointer;
}

//����ֵ����
//�������ܣ��Բ��������ķ�ʽ����Ŀ������뵽����������
//����������ǰ��ΪĿ�����ַ������Ϊ�������ĸ���ַ
void studentDataBase::insert(student* p, student* &root)
{
	if (root == 0)
		root = p;
	else
	{
		queue<student*>stu;
		stu.push(root);
		student* temp;
		while (!stu.empty())
		{
			temp = stu.front();
			stu.pop();
			if (temp->leftChild != 0)
				stu.push(temp->leftChild);
			else//˵�����ڴ˽�������������
			{
				temp->leftChild = p;
				break;
			}
			if (temp->rightChild != 0)
				stu.push(temp->rightChild);
			else//˵�����ڴ˽�������������
			{
				temp->rightChild = p;
				break;
			}
		}
	}
}

//����ֵ����
//�������ܣ���ѧ��Ϊ�ؼ��֣���Ŀ������뵽ѧ������
//����������ǰ��ΪĿ�����ַ������Ϊѧ�����ĸ���ַ
bool studentDataBase::insertByNum(student*p, numberTreeNode*& root1)
{
	if (root1 == 0)
	{
		root1 = new numberTreeNode;
		strcpy_s(root1->number, p->number);
		root1->pointer = p;//ʹ�ø�������pointer��Աָ��Ŀ����
		return true;
	}
	else if (strcmp(p->number, root1->number) < 0) return insertByNum(p, root1->leftChild);
	else if (strcmp(p->number, root1->number) > 0) return insertByNum(p, root1->rightChild);
	else return false;
}

//����ֵ����
//�������ܣ�������Ϊ�ؼ��֣���Ŀ������뵽��������
//����������ǰ��ΪĿ�����ַ������Ϊ�������ĸ���ַ
bool studentDataBase::insertByName(student* p, nameTreeNode*& root1)
{
	if (root1 == 0)
	{
		root1 = new nameTreeNode;
		strcpy_s(root1->name, p->name);
		root1->pointer = p;//ʹ�ø�������pointer��Աָ��Ŀ����
		return true;
	}
	else if (strcmp(p->name, root1->name) < 0)return insertByName(p, root1->leftChild);
	else if (strcmp(p->name, root1->name) > 0)return insertByName(p, root1->rightChild);
	else return false;
}

//����ֵ����
//�������ܣ��Ե绰Ϊ�ؼ��֣���Ŀ������뵽�绰����
//����������ǰ��ΪĿ�����ַ������Ϊ�绰���ĸ���ַ
bool studentDataBase::insertByPhoneNum(student* p, phoneNumTreeNode*& root1)
{
	if (root1 == 0)
	{
		root1 = new phoneNumTreeNode;
		strcpy_s(root1->phoneNumber, p->phoneNumber);
		root1->pointer = p;//ʹ�ø�������pointer��Աָ��Ŀ����
		return true;
	}
	else if (strcmp(p->phoneNumber, root1->phoneNumber) < 0)return insertByPhoneNum(p, root1->leftChild);
	else if ((p->phoneNumber, root1->phoneNumber) > 0)return insertByPhoneNum(p, root1->rightChild);
	else return false;
}

//����ֵ���߼�ֵ0��1
//�������ܣ�����ѧ�ţ���Ŀ�����isDeleted������Ϊ1
//������������ɾ����ѧ��
bool studentDataBase::delByNum(char num[])//ɾ��(��������ѧ��ɾ��)
{
	student* p = searchNum(numberTree, num);//��ʱp��Ŀ����
	if (p)
	{
		p->isDeleted = 1;
		cout << "ɾ���ɹ���" << endl;
		return 1;
	}
	else
		cout << "�������Ϣ��" << endl;
	return 0;
}

//����ֵ���߼�ֵ0��1
//�������ܣ�������������Ŀ�����isDeleted������Ϊ1
//������������ɾ��������
bool studentDataBase::delByName(char name[])//ɾ��(������������ɾ��)
{
	student* p = searchName(nameTree, name);//��ʱp��Ŀ����
	if (p)
	{
		p->isDeleted = 1;
		cout << "ɾ���ɹ���" << endl;
		return 1;
	}
	else
		cout << "�������Ϣ��" << endl;
	return 0;
}

//����ֵ���߼�ֵ0��1
//�������ܣ����յ绰���룬��Ŀ�����isDeleted������Ϊ1
//������������ɾ���ĵ绰����
bool studentDataBase::delByPhoneNum(char phoneNum[])//ɾ��(���������绰����ɾ��)
{
	student* p = searchPhoneNum(phoneNumTree, phoneNum);//��ʱp��Ŀ����
	if (p)
	{
		p->isDeleted = 1;
		cout << "ɾ���ɹ���" << endl;
		return 1;
	}
	else
		cout << "�������Ϣ��" << endl;
	return 0;
}

//����ֵ����
//�������ܣ����������С��ѧ������Ϣ
//�����������������ĸ���ַ
void studentDataBase::getYoungest(student*root)
{
	//����ǰ������ķ�ʽ
	if (root == 0)return;
	else
	{
		//���ý��ѧ������С��MIN��㣬���Ҹý��û�б�ɾ������MIN�ɸ�ֵ
		if (root->isDeleted==0&&strcmp(root->birthday,MIN->birthday) > 0)
			MIN = root;
		getYoungest(root->leftChild);
		getYoungest(root->rightChild);
	}
}

//����ֵ����
//�������ܣ�ǰ�������Ϣ
void studentDataBase::previsit(student* root)
{
	if (root == 0)return;
	else
	{
		if(!root->isDeleted)
			cout << *root << endl;
		previsit(root->leftChild);
		previsit(root->rightChild);
	}
}

//����ֵ����
//�������ܣ����������Ϣ
void studentDataBase::midvisit(student* root)
{
	if (root == 0)return;
	else
	{
		midvisit(root->leftChild);
		if (!root->isDeleted)
			cout << *root << endl;
		midvisit(root->rightChild);
	}
}

//����ֵ����
//�������ܣ����������Ϣ
void studentDataBase::behvisit(student* root)
{
	if (root == 0)return;
	else
	{
		behvisit(root->leftChild);
		behvisit(root->rightChild);
		if (!root->isDeleted)
			cout << *root << endl;
	}
}

//����ֵ����
//�������ܣ�����ָ��˳���������ѧ������Ϣ
void studentDataBase::output()
{
	cout << "��ϣ������ʲô˳�������1(ǰ��) 2(����) 3(����)" << endl;
	int input;
	cin >> input;
	if (input == 1)
	{
		title();//�������
		previsit(root);
	}
	else if (input == 2)
	{
		title();
		midvisit(root);
	}
	else if (input == 3)
	{
		title();
		behvisit(root);
	}
	else
		cout << "��������ȷ��ָ�" << endl;
}


//����ֵ����
//�������ܣ���Ŀ���ļ���ȡ��Ϣ��ϵͳ��
//��������������ȡ�ļ���
void studentDataBase::readFile(string fileName)
{
	deleteTrees();
	ifstream infile(fileName, ios::binary);
	if (!infile)
	{
		cout << "open error!" << endl;
		return;
	}
	student* p;
	while (infile.peek() != EOF)
	{
		p = new student;
		infile.read((char*)&*p, sizeof(student));
		p->leftChild = 0;  //ע��һ��Ҫ��ʼ��Ϊ0����Ȼ����ָ
		p->rightChild = 0; 
		insert(p,root);//���ý����������
		insertByName(p, nameTree);//ͬʱ�������ø�����
		insertByNum(p, numberTree);
		insertByPhoneNum(p, phoneNumTree);
	}
	MIN = root;//��MIN��ʼ��Ϊroot
	infile.close();
}

//����ֵ����
//�������ܣ���ϵͳ����Ϣ��д�뵽Ŀ���ļ���
//������������д���ļ���
void studentDataBase::writeFile(string fileName)
{
	ofstream outfile(fileName, ios::binary);
	if (!outfile)
	{
		cout << "open error!" << endl;
		exit(1);
	}
	//���ղ��������ķ�ʽд���ļ�
	queue<student*>stu;
	student* p = root;
	stu.push(p);
	while (!stu.empty())
	{
		p = stu.front();
		stu.pop();
		if (p->leftChild)stu.push(p->leftChild);
		if (p->rightChild)stu.push(p->rightChild);
		outfile.write((char*)&(*p), sizeof(*p));
	}
	outfile.close();
}