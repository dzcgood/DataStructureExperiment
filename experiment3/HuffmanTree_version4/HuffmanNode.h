#ifndef _HUFFMANNODE_H_
#define _HUFFMANNODE_H_
#pragma once
//定义哈夫曼树结点
#include<iostream>
#include"myHeap.h"
#include<fstream>
#include<cstdio>

using namespace std;

/////////////////////////////////
//接下来是HuffmanNode结构体的定义
/////////////////////////////////
struct HuffmanNode
{
	char key;//字母
	int times;//出现的次数
	string code;//该字符对应的编码
	HuffmanNode* leftChild, * rightChild;
	HuffmanNode* parent;
	//缺省构造函数
	HuffmanNode() :leftChild(NULL), rightChild(NULL), parent(NULL)
	{
		key = '\0';
		times = 0;
		code = "";
	}
	//参数构造函数
	HuffmanNode(char c,int t=0, HuffmanNode* left = NULL, HuffmanNode* right = NULL,HuffmanNode*par=NULL)
	{
		key = c;
		times = t;
		leftChild = left;
		rightChild = right;
		parent = par;
		code = "";
	}
	//重载<=运算符，排序依据是该符号出现的次数times
	bool operator<=(HuffmanNode& R) { return times <= R.times; }
	//重载>运算符，排序依据是该符号出现的次数times
	bool operator>(HuffmanNode& R) { return times > R.times; }
};



//////////////////////////////
//接下来是HuffmanTree类的定义
//////////////////////////////

class HuffmanTree
{
public:
	HuffmanTree();
	//析构函数，释放HuffmanTree的空间
	~HuffmanTree() 
	{
		deleteTree(root);
		delete[]times;
		delete[]codes;
		delete[]keys;
	}
	unsigned short *times;//数组，存储各字符出现的次数
	int wpl;//总编码长度
	short typeNum;//出现的字符种类数
	string* codes;//字符串数组，用于存储每个字符的编码
	char* keys;//字符数组，存储出现的字符
	HuffmanNode* root;//根结点
	//由已知数组生成HuffmanTree
	void createTree(char keys[], unsigned short w[], int n);
	//将两棵树合并成一棵
	void mergeTree(HuffmanNode* bt1, HuffmanNode* bt2, HuffmanNode*& parent);
	//将文件编码并将所得编码写入文件
	void encoding(string fileName);
	//将fileName文件译码并将保存译码文件
	void decode(string fileName);                                      
	//将生成的HuffmanTree写入到hfmTree.txt文件
	void save(); 
	//检测哈夫曼树是否为空
	bool isEmpty() { return root == 0; }
	//统计wpl，wpl是所有非叶子结点的权值之和
	void setWpl(HuffmanNode* root);
	//功能是对HuffmanTree的每个叶子结点进行编码
	void encode(HuffmanNode* root, string s);
	//编写codes[]字符串数组的内容
	void setCodeArray(HuffmanNode* root);
	//子函数，功能是统计文章中各字符出现次数并显示
	void countTimes();
	//画出并存储树
	void displayHuffman();
private:
	//子函数，辅助打印生成的HuffmanTree
	void displayHuffman(HuffmanNode* root, int ident, ofstream& out);
	//子函数，后序遍历删除树结点
	void deleteTree(HuffmanNode* root);
};

//////////////////////////////
//接下来是HuffmanTree类的实现
/////////////////////////////

//函数功能：后序遍历方式释放二叉树空间
//函数参数：HuffmanTree的根结点root
//返回值：void
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

//函数功能：构造函数，初始化各类数据
//函数参数：无
//返回值：无
HuffmanTree::HuffmanTree()
{
	codes = 0;
	times = 0;
	root = 0;
	typeNum = 0;
	keys = 0;
	wpl = 0;
}


//函数功能：根据已有数组，建立HuffmanTree，并建立结构体数组用于存储字符和出现次数的信息
//函数参数：存储各字符出现频率的数组w，存储字符种类的数组keys，以及字符种类总数n
//返回值：void
void HuffmanTree::createTree(char keys[], unsigned short w[], int n)
{
	MyHeap<HuffmanNode>heap1;
	HuffmanNode* parent = 0, * first, * second, * work, temp;
	for (int i = 0; i < n; i++)//逐个插入最小堆
	{
		work = new HuffmanNode();
		work->leftChild = NULL;//一定记得初始化！！
		work->rightChild = NULL;
		work->parent = work;
		work->key = keys[i];
		work->times = w[i];
		heap1.Insert(*work);
	}
	//执行n-1次操作，以建立哈夫曼树
	for (int i = 1; i <= n - 1; i++)
	{
		heap1.Remove(temp);
		first = temp.parent;
		heap1.Remove(temp);
		second = temp.parent;
		mergeTree(first, second, parent);//合并
		heap1.Insert(*parent);//新节点插入堆中
	}
	root = parent;
}

//函数功能：将两棵树合成一棵树
//函数参数：两棵树的根结点bt1,bt2,以及新树的根结点parent
//返回值：void
void HuffmanTree::mergeTree(HuffmanNode* bt1, HuffmanNode* bt2, HuffmanNode*& parent)
{
	parent = new HuffmanNode;
	parent->leftChild = bt1;
	parent->rightChild = bt2;
	parent->parent = parent;
	parent->times = bt1->times + bt2->times;
	parent->key = '\0';//不是叶子结点的值设置成'\0'
	bt1->parent = bt2->parent = parent;
}

//函数功能：前序遍历递归计算wpl
//函数参数：根结点root
//返回值：void
void HuffmanTree::setWpl(HuffmanNode*root)
{
	if (!root)return;
	else
	{
		if (root->leftChild != 0 || root->rightChild != 0)//判断是否为叶子结点
			wpl += root->times;//wpl值是所有非叶子结点权值之和
		setWpl(root->leftChild);
		setWpl(root->rightChild);
	}
}

//函数功能：对HuffmanTree的叶子结点进行编码，规定往左走加'0'，往右走加‘1’
//函数参数：HuffmanTree的根结点root，以及当前的编码s
//返回值：void
void HuffmanTree::encode(HuffmanNode* root, string s)
{
	if (root == NULL)
		return;
	//先访问左子树
	//s需要加上'0'
	s = s + '0';
	if (root->leftChild != NULL)
	{
		root->leftChild->code = s;
	}
	encode(root->leftChild, s);//遍历左子树
	//往右走之前，先把最后一个编码换成1
	s[s.size() - 1] = '1';
	if (root->rightChild != NULL)
		root->rightChild->code = s;
	encode(root->rightChild, s);//遍历右子树
}

//函数功能：根据哈夫曼树叶子结点的编码，设置codes[]字符串数组的内容
//函数参数：根结点root
//返回值：void
void HuffmanTree::setCodeArray(HuffmanNode* root)
{
	if (root == 0)return;
	if (root->leftChild == 0 && root->rightChild == 0)
	{
		for (int i = 0; i < typeNum; i++)//找到对应的编号
			if (keys[i] == root->key)codes[i] = root->code;
	}
	setCodeArray(root->leftChild);
	setCodeArray(root->rightChild);
}

//函数功能：将生成的HuffmanTree存入hfmTree.txt文件
//          实际上存储的是每个字符以及字符出现的次数
//函数参数：无
//返回值：void
void HuffmanTree::save()
{
	ofstream out("hfmTree.txt", ios::binary);
	if (!out)
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	//先写入种类数
	out.write((char*)&typeNum, sizeof(short));
	//写入各字符和频度
	for (int i = 0; i < typeNum; i++)
	{
		out.write((char*)&keys[i], sizeof(keys[i]));
		out.write((char*)&times[i], sizeof(times[i]));
	}
	out.close();
}


//函数功能：将文件编码并将编码结果写入到CodeFile.txt文件
//函数参数：无
//返回值：void
void HuffmanTree::encoding(string fileName)
{
	//建立字符数组临时存储二进制编码
	char* binaryCode = new char[wpl];
	//初始元素设置为\0
	memset(binaryCode, '\0', sizeof(binaryCode));
	ofstream out("CodeFile.txt", ios::binary);
	ifstream in(fileName, ios::in);
	if (!in || !out)
	{
		cout << "打开文件失败！" << endl;
		return;
	}
	char c;//从文件读出来的字符
	//字符数组下标标记
	int flag = 0;
	while (in.peek() != EOF)
	{
		c = in.get();
		//找到c字符对应codes数组的哪个下标
		for(int u=0;u<typeNum;u++)
		{
			if (keys[u] == c)//找到
			{
				for (int i = 0; i < codes[u].length(); i++)//将c的编码写到binaryCode中
				{
					binaryCode[flag] = codes[u][i];
					flag++;
				}
				break;
			}
		}
	}
	out.write((char*)&flag, sizeof(flag));
	//接下来开始转化成十进制并写入文件
	//此处的flag是二进制串的总长度
	short num = 0;
	int i = 0;
	for (i = 0; i < flag-flag%8; i++)
	{
		if(binaryCode[i]=='1')
			num += pow(2, 7 - i % 8);
		if ((i + 1) % 8 == 0)
		{
			unsigned char c = num;//因为num的最大值是255，用unsigned char即可存储，可以节约存储空间，提升压缩率
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
	cout << "编码已经写入文件CodeFile.txt！" << endl;
}

//函数功能：将编码好的文件译码并将译码结果写入到CodeFile.txt文件
//函数参数：无
//返回值：void
void HuffmanTree::decode(string fileName)
{
	ifstream in(fileName, ios::binary);
	if (!in)
	{
		cout << "请先初始化哈夫曼树!" << endl;
		return;
	}
	char* binaryCode = new char[wpl];
	memset(binaryCode, '\0', sizeof(binaryCode));
	short num;//存储读进来的十进制数
	unsigned char c;
	int flag = 0;//字符数组下标
	int WPL;
	in.read((char*)&WPL, sizeof(WPL));
	//将读取进来的十进制数转成二进制并存入binaryCode数组
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
	//对最后一个十进制数是否译码为8为二进制数的判断
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
	//接下来对文件写入译码结果
	HuffmanNode* current = root;
	ofstream out("TextFile.txt", ios::out);
	if (!out)
	{
		cout << "文件打开失败！" << endl;
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
			current = root;//复位，从树根开始往下走
		}
	}
	in.close();
	out.close();
	cout << "译码文件已经存入TextFile文件中！";
	cout << endl << endl;
}

//函数功能：绘制生成的huffman树并写入文件
//函数参数：无
//返回值：void
void HuffmanTree::displayHuffman()
{
	ofstream out("TreePrin.txt", ios::out);
	if (!out)
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	displayHuffman(root, 0, out);
	out.close();
}

//函数功能：子函数打印生成的HuffmanTree
//函数参数：根结点root，数组下标ident
int vec_left[100] = { 0 };
void HuffmanTree::displayHuffman(HuffmanNode* root, int ident,ofstream&out)
{
	if (ident > 0)
	{
		for (int i = 0; i < ident - 1; ++i)
		{
			cout<<(vec_left[i] ? "│   " : "    ");//输出到屏幕
			out << (vec_left[i] ? "│   " : "    ");//输出到文件
		}
		cout<<(vec_left[ident - 1] ? "├── " : "└── ");
		out << (vec_left[ident - 1] ? "├── " : "└── ");
	}
	if (!root)
	{
		cout<<"(null)"<<endl;
		out << "(null)"<<endl;
		return;
	}
	if (root->key == '\0')//非叶子结点的关键字默认输出\0
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
	displayHuffman(root->leftChild, ident + 1,out);//遍历左子树
	vec_left[ident] = 0;
	displayHuffman(root->rightChild, ident + 1,out);//遍历右子树
}

////函数功能：统计文章中的字符出现的种类数和频率
//函数参数：无
//返回值：无
void HuffmanTree::countTimes()
{
	int counts[128];
	memset(counts, 0, sizeof(counts));
	cout << "请输入要统计的文章名称" << endl;
	string fileName;
	cin >> fileName;
	ifstream in(fileName, ios::in);
	if (!in)
	{
		cout << "文件打开失败！";
		return;
	}
	char c;
	while (in.peek() != EOF)
	{
		c=in.get(); //读入一个字符
		counts[c - '\0']++;
	}
	int num = 0;//统计出现的字符种类
	for (int i = 31; i <128; i++)
	{
		if (counts[i] != 0)
		{
			c = i - 0;
			cout << c << " " << counts[i] << " " << endl;
			num++;
		}
	}
	cout << "字符集格个数为" << num << endl;
	cout << "(默认不统计非英文字符和除空格外的不可见字符)" << endl;
	in.close();
}
#endif
