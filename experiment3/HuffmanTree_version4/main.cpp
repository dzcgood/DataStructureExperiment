#include<iostream>
#include"HuffmanNode.H"
using namespace std;

void menu()
{
	cout << "---------文本压缩与解压---------" << endl;
	cout << "0---统计文章字符种类和频度" << endl;
	cout << "1---初始化(Initialization)" << endl;
	cout << "2---编码(Encoding)" << endl;
	cout << "3---译码(Decoding)" << endl;
	cout << "4---打印代码文件(Print)" << endl;
	cout << "5---打印哈夫曼树(TreePrinting)" << endl;
	cout << "6---退出(Exit)" << endl;
}
//函数指针数组的内容
//利用函数指针数组，避免使用了switch结构来实现相应函数的调用，提升效率
void func0(HuffmanTree &myTree);//统计
void func1(HuffmanTree &myTree);//初始化
void func2(HuffmanTree &myTree);//编码
void func3(HuffmanTree &myTree);//译码
void func4(HuffmanTree &myTree);//打印代码文件
void func5(HuffmanTree &myTree);//打印哈夫曼树
void func6(HuffmanTree& myTree);//退出

//函数指针数组，用于根据用户输入调用对应函数
void(*functionPointer[7])(HuffmanTree &myTree) = { func0,func1,func2,func3,func4,func5,func6 };

int main()
{
	int input;
	menu();
	cin >> input;
	HuffmanTree myTree;
	while (true)
	{
		if (input >= 0 && input <= 6)
		{
			(*functionPointer[input])(myTree);//调用对应函数
			menu();//显示菜单
		}
		else
			cout << "请输入正确的指令！" << endl;
		cin >> input;
	}
	return 0;
}

////////////////////////////////
//接下来是func0-func6的函数实现
///////////////////////////////

//函数功能：统计文章中字符出现的种类和次数
//函数参数：HuffmanTree类对象myTree
//返回值：void
void func0(HuffmanTree& myTree)
{
	myTree.countTimes();
}

//函数功能：执行初始化操作
//函数参数：HuffmanTree类对象myTree
//返回值：void
void func1(HuffmanTree &myTree)
{
	unsigned short num,times;
	char c;
	cout << "请输入字符集的个数" << endl;
	cin >> num;
	myTree.keys = new char[num+1];
	myTree.times = new unsigned short[num];
	myTree.codes = new string[num];
	
	for (int i = 0; i < num; i++)
	{
		cout << "请输入第"<<i+1<<"个字符" << endl;
		getchar();//去掉\n和\t
		myTree.keys[i] = getchar();
		cout << "请输入该字符的频度" << endl;
		getchar();//去掉\n和\t
		cin >> myTree.times[i];
	}
	myTree.typeNum = num;//字符种类数
	myTree.createTree(myTree.keys, myTree.times, num);//建立树
	myTree.setWpl(myTree.root);//统计wpl
	myTree.encode(myTree.root,"");//对每个字符进行相应的编码
	myTree.setCodeArray(myTree.root);
	myTree.save();//保存
}


//函数功能：执行编码操作
//函数参数：HuffmanTree类对象myTree
//返回值：void
void func2(HuffmanTree &myTree)
{
	if (myTree.isEmpty())
	{
		ifstream in("hfmTree.txt", ios::binary);
		if (!in)
		{
			cout << "请先初始化哈夫曼树！" << endl;
			return;
		}
		//先读入种类数
		in.read((char*)&myTree.typeNum, sizeof(myTree.typeNum));
		myTree.keys = new char[myTree.typeNum + 1];
		myTree.times = new unsigned short[myTree.typeNum];
		myTree.codes = new string[myTree.typeNum];
		//接着读入字符和频度
		for (int i = 0; i < myTree.typeNum; i++)
		{
			in.read((char*)&myTree.keys[i], sizeof(myTree.keys[i]));
			in.read((char*)&myTree.times[i], sizeof(myTree.times[i]));
		}
		myTree.createTree(myTree.keys, myTree.times, myTree.typeNum);//建立树
		myTree.setWpl(myTree.root);//统计wpl
		myTree.encode(myTree.root, "");//对每个字符进行相应的编码
		myTree.setCodeArray(myTree.root);
		myTree.save();//保存
	}
	//接下来开始编码
	string fileName;
	cout << "请输入你要编码的文件名" << endl;
	cin >> fileName;
	myTree.encoding(fileName);

}

//函数功能：执行译码操作
//函数参数：HuffmanTree类对象myTree
//返回值：void
void func3(HuffmanTree &myTree)
{
	if (myTree.isEmpty())
	{
		ifstream in("hfmTree.txt", ios::binary);
		if (!in)
		{
			cout << "请先初始化哈夫曼树！" << endl;
			return;
		}
		//先读入种类数
		in.read((char*)&myTree.typeNum, sizeof(myTree.typeNum));
		//开始建立哈夫曼树
		myTree.keys = new char[myTree.typeNum + 1];
		myTree.times = new unsigned short[myTree.typeNum];
		myTree.codes = new string[myTree.typeNum];
		//先读入字符和频度
		for (int i = 0; i < myTree.typeNum; i++)
		{
			in.read((char*)&myTree.keys[i], sizeof(myTree.keys[i]));
			in.read((char*)&myTree.times[i], sizeof(myTree.times[i]));
		}
		myTree.createTree(myTree.keys, myTree.times, myTree.typeNum);//建立树
		myTree.setWpl(myTree.root);//统计wpl
		myTree.encode(myTree.root, "");//对每个字符进行相应的编码
		myTree.setCodeArray(myTree.root);//对编码数组codes[]进行赋值，以便后续操作
		myTree.save();//保存
	}
	//接下来开始解码
	cout << "请输入要解码的文件名称" << endl;
	string fileName;
	cin >> fileName;
	myTree.decode(fileName);
}


//函数功能：输出并存储二进制码操作
//函数参数：HuffmanTree类对象myTree
//返回值：void
void func4(HuffmanTree &myTree)
{
	//为省去建树的时间，考虑将wpl直接写入文件，则读取时可不依赖Huffman树即可输出二进制码
	string fileName;
	cout << "请输入要显示二进制码的文件名" << endl;
	cin >> fileName;
	ifstream in(fileName, ios::binary);
	ofstream out("CodePrin.txt", ios::out);
	if (!in||!out)
	{
		cout << "文件打开失败" << endl;
		return;
	}
	int wpl;
	in.read((char*)&wpl, sizeof(int));
	unsigned char c;
	int temp=0;//计数器
	//将读入的十进制数转换成01二进制代码
	for (int i = 0; i < wpl / 8; i++)
	{
		in.read((char*)&c, sizeof(c));
		int num = c;
		for (int i = 8; i > 0; i--)
		{
			if (c & (1 << i))
			{
				cout << "1";
				out << '1';
			}
			else
			{
				cout << "0";
				out << '0';
			}
			temp++;
			if (temp % 50 == 0)//保证每行50个
			{
				cout << endl;
				out << endl;
			}
		}
	}
	//对最后一位十进制数是否转成8位二进制代码的处理
	if (wpl % 8 != 0)
	{
		in.read((char*)&c, sizeof(c));
		int num = c;
		for (int i = wpl%8; i > 0; i--)
		{
			if (c & (1 << i))
			{
				cout << "1";
				out << '1';
			}
			else
			{
				cout << "0";
				out << '0';
			}
			temp++;
			if (temp % 50 == 0)//保证每行50个
			{
				cout << endl;
				out << endl;
			}
		}
	}
	cout << endl;
}

//函数功能：打印并存储huffman树
//函数参数：HuffmanTree类对象myTree
//返回值：void
void func5(HuffmanTree &myTree)
{
	if (myTree.isEmpty())
	{
		ifstream in("hfmTree.txt", ios::binary);
		if (!in)
		{
			cout << "请先初始化哈夫曼树！" << endl;
			return;
		}
		//先读入种类数
		in.read((char*)&myTree.typeNum, sizeof(myTree.typeNum));
		myTree.keys = new char[myTree.typeNum + 1];
		myTree.times = new unsigned short[myTree.typeNum];
		myTree.codes = new string[myTree.typeNum];
		//接着读入字符和频度
		for (int i = 0; i < myTree.typeNum; i++)
		{
			in.read((char*)&myTree.keys[i], sizeof(myTree.keys[i]));
			in.read((char*)&myTree.times[i], sizeof(myTree.times[i]));
		}
		myTree.createTree(myTree.keys, myTree.times, myTree.typeNum);//建立树
		myTree.setWpl(myTree.root);//统计wpl
		myTree.encode(myTree.root, "");//对每个字符进行相应的编码
		myTree.setCodeArray(myTree.root);
		myTree.save();//保存
		myTree.displayHuffman();
	}
	else
		myTree.displayHuffman();
	cout << "哈夫曼树已经写入文件TreePrin.txt，非叶子结点的关键字默认显示\\0" << endl << endl;
}

//函数功能：退出程序
//函数参数：HuffmanTree类对象myTree
//返回值：void
void func6(HuffmanTree &myTree)
{
	cout << "祝您生活愉快，再见！" << endl;
	exit(0);
}