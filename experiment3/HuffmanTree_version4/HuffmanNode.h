#ifndef _HUFFMANNODE_H_
#define _HUFFMANNODE_H_
#pragma once
//��������������
#include<iostream>
#include"myHeap.h"
#include<fstream>
#include<cstdio>

using namespace std;

/////////////////////////////////
//��������HuffmanNode�ṹ��Ķ���
/////////////////////////////////
struct HuffmanNode
{
	char key;//��ĸ
	int times;//���ֵĴ���
	string code;//���ַ���Ӧ�ı���
	HuffmanNode* leftChild, * rightChild;
	HuffmanNode* parent;
	//ȱʡ���캯��
	HuffmanNode() :leftChild(NULL), rightChild(NULL), parent(NULL)
	{
		key = '\0';
		times = 0;
		code = "";
	}
	//�������캯��
	HuffmanNode(char c,int t=0, HuffmanNode* left = NULL, HuffmanNode* right = NULL,HuffmanNode*par=NULL)
	{
		key = c;
		times = t;
		leftChild = left;
		rightChild = right;
		parent = par;
		code = "";
	}
	//����<=����������������Ǹ÷��ų��ֵĴ���times
	bool operator<=(HuffmanNode& R) { return times <= R.times; }
	//����>����������������Ǹ÷��ų��ֵĴ���times
	bool operator>(HuffmanNode& R) { return times > R.times; }
};



//////////////////////////////
//��������HuffmanTree��Ķ���
//////////////////////////////

class HuffmanTree
{
public:
	HuffmanTree();
	//�����������ͷ�HuffmanTree�Ŀռ�
	~HuffmanTree() 
	{
		deleteTree(root);
		delete[]times;
		delete[]codes;
		delete[]keys;
	}
	unsigned short *times;//���飬�洢���ַ����ֵĴ���
	int wpl;//�ܱ��볤��
	short typeNum;//���ֵ��ַ�������
	string* codes;//�ַ������飬���ڴ洢ÿ���ַ��ı���
	char* keys;//�ַ����飬�洢���ֵ��ַ�
	HuffmanNode* root;//�����
	//����֪��������HuffmanTree
	void createTree(char keys[], unsigned short w[], int n);
	//���������ϲ���һ��
	void mergeTree(HuffmanNode* bt1, HuffmanNode* bt2, HuffmanNode*& parent);
	//���ļ����벢�����ñ���д���ļ�
	void encoding(string fileName);
	//��fileName�ļ����벢�����������ļ�
	void decode(string fileName);                                      
	//�����ɵ�HuffmanTreeд�뵽hfmTree.txt�ļ�
	void save(); 
	//�����������Ƿ�Ϊ��
	bool isEmpty() { return root == 0; }
	//ͳ��wpl��wpl�����з�Ҷ�ӽ���Ȩֵ֮��
	void setWpl(HuffmanNode* root);
	//�����Ƕ�HuffmanTree��ÿ��Ҷ�ӽ����б���
	void encode(HuffmanNode* root, string s);
	//��дcodes[]�ַ������������
	void setCodeArray(HuffmanNode* root);
	//�Ӻ�����������ͳ�������и��ַ����ִ�������ʾ
	void countTimes();
	//�������洢��
	void displayHuffman();
private:
	//�Ӻ�����������ӡ���ɵ�HuffmanTree
	void displayHuffman(HuffmanNode* root, int ident, ofstream& out);
	//�Ӻ������������ɾ�������
	void deleteTree(HuffmanNode* root);
};

//////////////////////////////
//��������HuffmanTree���ʵ��
/////////////////////////////

//�������ܣ����������ʽ�ͷŶ������ռ�
//����������HuffmanTree�ĸ����root
//����ֵ��void
void HuffmanTree::deleteTree(HuffmanNode* root)
{
	if (root == 0)return;
	else
	{
		deleteTree(root->leftChild);
		deleteTree(root->rightChild);
		delete root;
	}
}

//�������ܣ����캯������ʼ����������
//������������
//����ֵ����
HuffmanTree::HuffmanTree()
{
	codes = 0;
	times = 0;
	root = 0;
	typeNum = 0;
	keys = 0;
	wpl = 0;
}


//�������ܣ������������飬����HuffmanTree���������ṹ���������ڴ洢�ַ��ͳ��ִ�������Ϣ
//�����������洢���ַ�����Ƶ�ʵ�����w���洢�ַ����������keys���Լ��ַ���������n
//����ֵ��void
void HuffmanTree::createTree(char keys[], unsigned short w[], int n)
{
	MyHeap<HuffmanNode>heap1;
	HuffmanNode* parent = 0, * first, * second, * work, temp;
	for (int i = 0; i < n; i++)//���������С��
	{
		work = new HuffmanNode();
		work->leftChild = NULL;//һ���ǵó�ʼ������
		work->rightChild = NULL;
		work->parent = work;
		work->key = keys[i];
		work->times = w[i];
		heap1.Insert(*work);
	}
	//ִ��n-1�β������Խ�����������
	for (int i = 1; i <= n - 1; i++)
	{
		heap1.Remove(temp);
		first = temp.parent;
		heap1.Remove(temp);
		second = temp.parent;
		mergeTree(first, second, parent);//�ϲ�
		heap1.Insert(*parent);//�½ڵ�������
	}
	root = parent;
}

//�������ܣ����������ϳ�һ����
//�����������������ĸ����bt1,bt2,�Լ������ĸ����parent
//����ֵ��void
void HuffmanTree::mergeTree(HuffmanNode* bt1, HuffmanNode* bt2, HuffmanNode*& parent)
{
	parent = new HuffmanNode;
	parent->leftChild = bt1;
	parent->rightChild = bt2;
	parent->parent = parent;
	parent->times = bt1->times + bt2->times;
	parent->key = '\0';//����Ҷ�ӽ���ֵ���ó�'\0'
	bt1->parent = bt2->parent = parent;
}

//�������ܣ�ǰ������ݹ����wpl
//���������������root
//����ֵ��void
void HuffmanTree::setWpl(HuffmanNode*root)
{
	if (!root)return;
	else
	{
		if (root->leftChild != 0 || root->rightChild != 0)//�ж��Ƿ�ΪҶ�ӽ��
			wpl += root->times;//wplֵ�����з�Ҷ�ӽ��Ȩֵ֮��
		setWpl(root->leftChild);
		setWpl(root->rightChild);
	}
}

//�������ܣ���HuffmanTree��Ҷ�ӽ����б��룬�涨�����߼�'0'�������߼ӡ�1��
//����������HuffmanTree�ĸ����root���Լ���ǰ�ı���s
//����ֵ��void
void HuffmanTree::encode(HuffmanNode* root, string s)
{
	if (root == NULL)
		return;
	//�ȷ���������
	//s��Ҫ����'0'
	s = s + '0';
	if (root->leftChild != NULL)
	{
		root->leftChild->code = s;
	}
	encode(root->leftChild, s);//����������
	//������֮ǰ���Ȱ����һ�����뻻��1
	s[s.size() - 1] = '1';
	if (root->rightChild != NULL)
		root->rightChild->code = s;
	encode(root->rightChild, s);//����������
}

//�������ܣ����ݹ�������Ҷ�ӽ��ı��룬����codes[]�ַ������������
//���������������root
//����ֵ��void
void HuffmanTree::setCodeArray(HuffmanNode* root)
{
	if (root == 0)return;
	if (root->leftChild == 0 && root->rightChild == 0)
	{
		for (int i = 0; i < typeNum; i++)//�ҵ���Ӧ�ı��
			if (keys[i] == root->key)codes[i] = root->code;
	}
	setCodeArray(root->leftChild);
	setCodeArray(root->rightChild);
}

//�������ܣ������ɵ�HuffmanTree����hfmTree.txt�ļ�
//          ʵ���ϴ洢����ÿ���ַ��Լ��ַ����ֵĴ���
//������������
//����ֵ��void
void HuffmanTree::save()
{
	ofstream out("hfmTree.txt", ios::binary);
	if (!out)
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	//��д��������
	out.write((char*)&typeNum, sizeof(short));
	//д����ַ���Ƶ��
	for (int i = 0; i < typeNum; i++)
	{
		out.write((char*)&keys[i], sizeof(keys[i]));
		out.write((char*)&times[i], sizeof(times[i]));
	}
	out.close();
}


//�������ܣ����ļ����벢��������д�뵽CodeFile.txt�ļ�
//������������
//����ֵ��void
void HuffmanTree::encoding(string fileName)
{
	//�����ַ�������ʱ�洢�����Ʊ���
	char* binaryCode = new char[wpl];
	//��ʼԪ������Ϊ\0
	memset(binaryCode, '\0', sizeof(binaryCode));
	ofstream out("CodeFile.txt", ios::binary);
	ifstream in(fileName, ios::in);
	if (!in || !out)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return;
	}
	char c;//���ļ����������ַ�
	//�ַ������±���
	int flag = 0;
	while (in.peek() != EOF)
	{
		c = in.get();
		//�ҵ�c�ַ���Ӧcodes������ĸ��±�
		for(int u=0;u<typeNum;u++)
		{
			if (keys[u] == c)//�ҵ�
			{
				for (int i = 0; i < codes[u].length(); i++)//��c�ı���д��binaryCode��
				{
					binaryCode[flag] = codes[u][i];
					flag++;
				}
				break;
			}
		}
	}
	out.write((char*)&flag, sizeof(flag));
	//��������ʼת����ʮ���Ʋ�д���ļ�
	//�˴���flag�Ƕ����ƴ����ܳ���
	short num = 0;
	int i = 0;
	for (i = 0; i < flag-flag%8; i++)
	{
		if(binaryCode[i]=='1')
			num += pow(2, 7 - i % 8);
		if ((i + 1) % 8 == 0)
		{
			unsigned char c = num;//��Ϊnum�����ֵ��255����unsigned char���ɴ洢�����Խ�Լ�洢�ռ䣬����ѹ����
			out.write((char*)&c,sizeof(c));
			num = 0;
		}
	}
	int temp = 128;
	for (i = flag-flag%8; i < flag ; i++)
	{
		num += (binaryCode[i]-'0')*temp;
		temp = temp / 2;
	}
	unsigned char numToWrite = num;
	out.write((char*)&numToWrite, sizeof(numToWrite));
	out.close();
	in.close();
	cout << "�����Ѿ�д���ļ�CodeFile.txt��" << endl;
}

//�������ܣ�������õ��ļ����벢��������д�뵽CodeFile.txt�ļ�
//������������
//����ֵ��void
void HuffmanTree::decode(string fileName)
{
	ifstream in(fileName, ios::binary);
	if (!in)
	{
		cout << "���ȳ�ʼ����������!" << endl;
		return;
	}
	char* binaryCode = new char[wpl];
	memset(binaryCode, '\0', sizeof(binaryCode));
	short num;//�洢��������ʮ������
	unsigned char c;
	int flag = 0;//�ַ������±�
	int WPL;
	in.read((char*)&WPL, sizeof(WPL));
	//����ȡ������ʮ������ת�ɶ����Ʋ�����binaryCode����
	for (int i = 1; i <= WPL / 8; i++)
	{
		in.read((char*)&c, sizeof(c));
		num = c;
		int temp = 128;
		for (int i = 0; i < 8; i++, flag++)
		{
			if (num >= temp)
			{
				num = num - temp;
				binaryCode[flag] = '1';
			}
			else
				binaryCode[flag] = '0';
			temp = temp / 2;
		}
	}
	//�����һ��ʮ�������Ƿ�����Ϊ8Ϊ�����������ж�
	if (WPL % 8 != 0)
	{
		in.read((char*)&c, sizeof(c));
		num = c;
		int temp = 128;
		for (int i = 0; i < WPL % 8; i++, flag++)
		{
			if (num >= temp)
			{
				num = num - temp;
				binaryCode[flag] = '1';
			}
			else
				binaryCode[flag] = '0';
			temp = temp / 2;
		}
	}
	//���������ļ�д��������
	HuffmanNode* current = root;
	ofstream out("TextFile.txt", ios::out);
	if (!out)
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	for (int i = 0; i < WPL; i++)
	{
		char c = binaryCode[i];
		if (c == '0')
		{
			current = current->leftChild;
		}
		else if (c == '1')
		{
			current = current->rightChild;
		}
		if (current->leftChild == NULL && current->rightChild == NULL)
		{
			c = current->key;
			out.write((char*)&c, sizeof(char));
			current = root;//��λ����������ʼ������
		}
	}
	in.close();
	out.close();
	cout << "�����ļ��Ѿ�����TextFile�ļ��У�";
	cout << endl << endl;
}

//�������ܣ��������ɵ�huffman����д���ļ�
//������������
//����ֵ��void
void HuffmanTree::displayHuffman()
{
	ofstream out("TreePrin.txt", ios::out);
	if (!out)
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	displayHuffman(root, 0, out);
	out.close();
}

//�������ܣ��Ӻ�����ӡ���ɵ�HuffmanTree
//���������������root�������±�ident
int vec_left[100] = { 0 };
void HuffmanTree::displayHuffman(HuffmanNode* root, int ident,ofstream&out)
{
	if (ident > 0)
	{
		for (int i = 0; i < ident - 1; ++i)
		{
			cout<<(vec_left[i] ? "��   " : "    ");//�������Ļ
			out << (vec_left[i] ? "��   " : "    ");//������ļ�
		}
		cout<<(vec_left[ident - 1] ? "������ " : "������ ");
		out << (vec_left[ident - 1] ? "������ " : "������ ");
	}
	if (!root)
	{
		cout<<"(null)"<<endl;
		out << "(null)"<<endl;
		return;
	}
	if (root->key == '\0')//��Ҷ�ӽ��Ĺؼ���Ĭ�����\0
	{
		cout << "\\0" << endl;
		out << "\\0" << endl;
	}
	else
	{
		cout << root->key << endl;
		out << root->key << endl;
	}
	if (!root->leftChild && !root->rightChild)
	{
		return;
	}
	vec_left[ident] = 1;
	displayHuffman(root->leftChild, ident + 1,out);//����������
	vec_left[ident] = 0;
	displayHuffman(root->rightChild, ident + 1,out);//����������
}

////�������ܣ�ͳ�������е��ַ����ֵ���������Ƶ��
//������������
//����ֵ����
void HuffmanTree::countTimes()
{
	int counts[128];
	memset(counts, 0, sizeof(counts));
	cout << "������Ҫͳ�Ƶ���������" << endl;
	string fileName;
	cin >> fileName;
	ifstream in(fileName, ios::in);
	if (!in)
	{
		cout << "�ļ���ʧ�ܣ�";
		return;
	}
	char c;
	while (in.peek() != EOF)
	{
		c=in.get(); //����һ���ַ�
		counts[c - '\0']++;
	}
	int num = 0;//ͳ�Ƴ��ֵ��ַ�����
	for (int i = 31; i <128; i++)
	{
		if (counts[i] != 0)
		{
			c = i - 0;
			cout << c << " " << counts[i] << " " << endl;
			num++;
		}
	}
	cout << "�ַ��������Ϊ" << num << endl;
	cout << "(Ĭ�ϲ�ͳ�Ʒ�Ӣ���ַ��ͳ��ո���Ĳ��ɼ��ַ�)" << endl;
	in.close();
}
#endif
