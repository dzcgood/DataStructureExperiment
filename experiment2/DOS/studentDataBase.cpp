//文件名：studentDataBase.cpp
//程序功能：studentDataBase类的实现
//作者：邓智超
//日期：2020.12.05
//版本：2.0
#include"studentDataBase.h"
#include<queue>
#include<iostream>
#include<fstream>
extern void title();//输出标题函数
extern studentDataBase studata;//二叉树类 类对象
extern nameTreeNode* nameTree;//姓名树根结点
extern numberTreeNode* numberTree;//学号树根结点
extern phoneNumTreeNode* phoneNumTree;//电话树根结点
extern student* MIN;//存储年龄最小的学生结点地址

//返回值：无
//函数功能：释放姓名树的空间
//函数参数：姓名树的根地址
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

//返回值：无
//函数功能：释放学号树的空间
//函数参数：学号树的根地址
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

//返回值：无
//函数功能：释放电话树的空间
//函数参数：电话树的根地址
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

//返回值：无
//函数功能：释放二叉树的空间
//函数参数：二叉树的根地址
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

//返回值：无
//函数功能：释放上述四棵树的空间
//          一棵主树和三棵辅助树
void deleteTrees()
{
	studata.deleteTree(studata.root);
	deleteNameTree(nameTree);
	deleteNumberTree(numberTree);
	deletePhoneNumTree(phoneNumTree);
}

//返回值：无
//函数功能：构造函数，将root初始化为0
studentDataBase::studentDataBase()
{
	root = 0;
}


//返回值：无
//函数功能：新建通讯录信息
void studentDataBase::createTree()
{
	queue<student*>stu;
	root = new student;
	cin >> *root;
	MIN = root;
	stu.push(root);//根结点入队
	while (!stu.empty())
	{
		student* temp = stu.front();//队首元素出队
		stu.pop();
		student* p = new student;//左子树
		cin >> *p;
		if (p->number[0]=='#')break;
		insertByName(p, nameTree);//在三棵辅助树中也插入
		insertByNum(p, numberTree);
		insertByPhoneNum(p, phoneNumTree);
		temp->leftChild= p;
		stu.push(p);
		p = new student;//右子树
		cin >> *p;
		if (p->number[0] == '#')break;
		insertByName(p, nameTree);//在三棵辅助树中也插入
		insertByNum(p, numberTree);
		insertByPhoneNum(p, phoneNumTree);
		temp->rightChild = p;
		stu.push(p);
	}
}

//返回值：指向目标结点的指针
//函数功能：按学号查询信息
//函数参数：前者为numberTree的根节点，后者为待查询的学号
student* studentDataBase::searchNum(numberTreeNode*root,char num[])
{
	if (root == 0)return 0;
	else if (strcmp(root->number, num) > 0)return searchNum(root->leftChild, num);
	else if (strcmp(root->number, num) < 0)return searchNum(root->rightChild, num);
	else return root->pointer;
}

//返回值：指向目标结点的指针
//函数功能：按姓名查询信息
//函数参数：前者为nameTree的根节点，后者为待查询的姓名
student* studentDataBase::searchName(nameTreeNode*root,char name[])
{
	if (root == 0)return 0;
	else if (strcmp(root->name, name) > 0)return searchName(root->leftChild, name);
	else if (strcmp(root->name, name) < 0)return searchName(root->rightChild, name);
	else return root->pointer;
}

//返回值：指向目标结点的指针
//函数功能：按电话号码查询信息
//函数参数：前者为phoneNumTree的根节点，后者为待查询的电话号码
student* studentDataBase::searchPhoneNum(phoneNumTreeNode*root,char phoneNum[])
{
	if (root == 0)return 0;
	else if (strcmp(root->phoneNumber, phoneNum) > 0)return searchPhoneNum(root->leftChild, phoneNum);
	else if (strcmp(root->phoneNumber, phoneNum) < 0)return searchPhoneNum(root->rightChild, phoneNum);
	else return root->pointer;
}

//返回值：无
//函数功能：以层次序遍历的方式，将目标结点插入到二叉树当中
//函数参数：前者为目标结点地址，后者为二叉树的根地址
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
			else//说明将在此结点的左子树插入
			{
				temp->leftChild = p;
				break;
			}
			if (temp->rightChild != 0)
				stu.push(temp->rightChild);
			else//说明将在此结点的右子树插入
			{
				temp->rightChild = p;
				break;
			}
		}
	}
}

//返回值：无
//函数功能：以学号为关键字，将目标结点插入到学号树中
//函数参数：前者为目标结点地址，后者为学号树的根地址
bool studentDataBase::insertByNum(student*p, numberTreeNode*& root1)
{
	if (root1 == 0)
	{
		root1 = new numberTreeNode;
		strcpy_s(root1->number, p->number);
		root1->pointer = p;//使得辅助结点的pointer成员指向目标结点
		return true;
	}
	else if (strcmp(p->number, root1->number) < 0) return insertByNum(p, root1->leftChild);
	else if (strcmp(p->number, root1->number) > 0) return insertByNum(p, root1->rightChild);
	else return false;
}

//返回值：无
//函数功能：以姓名为关键字，将目标结点插入到姓名树中
//函数参数：前者为目标结点地址，后者为姓名树的根地址
bool studentDataBase::insertByName(student* p, nameTreeNode*& root1)
{
	if (root1 == 0)
	{
		root1 = new nameTreeNode;
		strcpy_s(root1->name, p->name);
		root1->pointer = p;//使得辅助结点的pointer成员指向目标结点
		return true;
	}
	else if (strcmp(p->name, root1->name) < 0)return insertByName(p, root1->leftChild);
	else if (strcmp(p->name, root1->name) > 0)return insertByName(p, root1->rightChild);
	else return false;
}

//返回值：无
//函数功能：以电话为关键字，将目标结点插入到电话树中
//函数参数：前者为目标结点地址，后者为电话树的根地址
bool studentDataBase::insertByPhoneNum(student* p, phoneNumTreeNode*& root1)
{
	if (root1 == 0)
	{
		root1 = new phoneNumTreeNode;
		strcpy_s(root1->phoneNumber, p->phoneNumber);
		root1->pointer = p;//使得辅助结点的pointer成员指向目标结点
		return true;
	}
	else if (strcmp(p->phoneNumber, root1->phoneNumber) < 0)return insertByPhoneNum(p, root1->leftChild);
	else if ((p->phoneNumber, root1->phoneNumber) > 0)return insertByPhoneNum(p, root1->rightChild);
	else return false;
}

//返回值：逻辑值0或1
//函数功能：按照学号，将目标结点的isDeleted属性置为1
//函数参数：待删除的学号
bool studentDataBase::delByNum(char num[])//删除(搜索树按学号删除)
{
	student* p = searchNum(numberTree, num);//此时p是目标结点
	if (p)
	{
		p->isDeleted = 1;
		cout << "删除成功！" << endl;
		return 1;
	}
	else
		cout << "无相关信息！" << endl;
	return 0;
}

//返回值：逻辑值0或1
//函数功能：按照姓名，将目标结点的isDeleted属性置为1
//函数参数：待删除的姓名
bool studentDataBase::delByName(char name[])//删除(搜索树按姓名删除)
{
	student* p = searchName(nameTree, name);//此时p是目标结点
	if (p)
	{
		p->isDeleted = 1;
		cout << "删除成功！" << endl;
		return 1;
	}
	else
		cout << "无相关信息！" << endl;
	return 0;
}

//返回值：逻辑值0或1
//函数功能：按照电话号码，将目标结点的isDeleted属性置为1
//函数参数：待删除的电话号码
bool studentDataBase::delByPhoneNum(char phoneNum[])//删除(搜索树按电话号码删除)
{
	student* p = searchPhoneNum(phoneNumTree, phoneNum);//此时p是目标结点
	if (p)
	{
		p->isDeleted = 1;
		cout << "删除成功！" << endl;
		return 1;
	}
	else
		cout << "无相关信息！" << endl;
	return 0;
}

//返回值：无
//函数功能：输出年龄最小的学生的信息
//函数参数：二叉树的根地址
void studentDataBase::getYoungest(student*root)
{
	//按照前序遍历的方式
	if (root == 0)return;
	else
	{
		//若该结点学生年龄小于MIN结点，并且该结点没有被删除，则MIN可赋值
		if (root->isDeleted==0&&strcmp(root->birthday,MIN->birthday) > 0)
			MIN = root;
		getYoungest(root->leftChild);
		getYoungest(root->rightChild);
	}
}

//返回值：无
//函数功能：前序输出信息
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

//返回值：无
//函数功能：中序输出信息
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

//返回值：无
//函数功能：后序输出信息
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

//返回值：无
//函数功能：按照指定顺序，输出所有学生的信息
void studentDataBase::output()
{
	cout << "你希望按照什么顺序输出？1(前序) 2(中序) 3(后序)" << endl;
	int input;
	cin >> input;
	if (input == 1)
	{
		title();//输出标题
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
		cout << "请输入正确的指令！" << endl;
}


//返回值：无
//函数功能：从目标文件读取信息到系统中
//函数参数：待读取文件名
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
		p->leftChild = 0;  //注意一定要初始化为0，不然会乱指
		p->rightChild = 0; 
		insert(p,root);//将该结点插入二叉树
		insertByName(p, nameTree);//同时插入三棵辅助树
		insertByNum(p, numberTree);
		insertByPhoneNum(p, phoneNumTree);
	}
	MIN = root;//将MIN初始化为root
	infile.close();
}

//返回值：无
//函数功能：将系统中信息到写入到目标文件中
//函数参数：待写入文件名
void studentDataBase::writeFile(string fileName)
{
	ofstream outfile(fileName, ios::binary);
	if (!outfile)
	{
		cout << "open error!" << endl;
		exit(1);
	}
	//按照层次序遍历的方式写入文件
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