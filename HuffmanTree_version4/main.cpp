#include<iostream>
#include"HuffmanNode.H"
using namespace std;

void menu()
{
	cout << "---------�ı�ѹ�����ѹ---------" << endl;
	cout << "0---ͳ�������ַ������Ƶ��" << endl;
	cout << "1---��ʼ��(Initialization)" << endl;
	cout << "2---����(Encoding)" << endl;
	cout << "3---����(Decoding)" << endl;
	cout << "4---��ӡ�����ļ�(Print)" << endl;
	cout << "5---��ӡ��������(TreePrinting)" << endl;
	cout << "6---�˳�(Exit)" << endl;
}
//����ָ�����������
//���ú���ָ�����飬����ʹ����switch�ṹ��ʵ����Ӧ�����ĵ��ã�����Ч��
void func0(HuffmanTree &myTree);//ͳ��
void func1(HuffmanTree &myTree);//��ʼ��
void func2(HuffmanTree &myTree);//����
void func3(HuffmanTree &myTree);//����
void func4(HuffmanTree &myTree);//��ӡ�����ļ�
void func5(HuffmanTree &myTree);//��ӡ��������
void func6(HuffmanTree& myTree);//�˳�

//����ָ�����飬���ڸ����û�������ö�Ӧ����
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
			(*functionPointer[input])(myTree);//���ö�Ӧ����
			menu();//��ʾ�˵�
		}
		else
			cout << "��������ȷ��ָ�" << endl;
		cin >> input;
	}
	return 0;
}

////////////////////////////////
//��������func0-func6�ĺ���ʵ��
///////////////////////////////

//�������ܣ�ͳ���������ַ����ֵ�����ʹ���
//����������HuffmanTree�����myTree
//����ֵ��void
void func0(HuffmanTree& myTree)
{
	myTree.countTimes();
}

//�������ܣ�ִ�г�ʼ������
//����������HuffmanTree�����myTree
//����ֵ��void
void func1(HuffmanTree &myTree)
{
	unsigned short num,times;
	char c;
	cout << "�������ַ����ĸ���" << endl;
	cin >> num;
	myTree.keys = new char[num+1];
	myTree.times = new unsigned short[num];
	myTree.codes = new string[num];
	
	for (int i = 0; i < num; i++)
	{
		cout << "�������"<<i+1<<"���ַ�" << endl;
		getchar();//ȥ��\n��\t
		myTree.keys[i] = getchar();
		cout << "��������ַ���Ƶ��" << endl;
		getchar();//ȥ��\n��\t
		cin >> myTree.times[i];
	}
	myTree.typeNum = num;//�ַ�������
	myTree.createTree(myTree.keys, myTree.times, num);//������
	myTree.setWpl(myTree.root);//ͳ��wpl
	myTree.encode(myTree.root,"");//��ÿ���ַ�������Ӧ�ı���
	myTree.setCodeArray(myTree.root);
	myTree.save();//����
}


//�������ܣ�ִ�б������
//����������HuffmanTree�����myTree
//����ֵ��void
void func2(HuffmanTree &myTree)
{
	if (myTree.isEmpty())
	{
		ifstream in("hfmTree.txt", ios::binary);
		if (!in)
		{
			cout << "���ȳ�ʼ������������" << endl;
			return;
		}
		//�ȶ���������
		in.read((char*)&myTree.typeNum, sizeof(myTree.typeNum));
		myTree.keys = new char[myTree.typeNum + 1];
		myTree.times = new unsigned short[myTree.typeNum];
		myTree.codes = new string[myTree.typeNum];
		//���Ŷ����ַ���Ƶ��
		for (int i = 0; i < myTree.typeNum; i++)
		{
			in.read((char*)&myTree.keys[i], sizeof(myTree.keys[i]));
			in.read((char*)&myTree.times[i], sizeof(myTree.times[i]));
		}
		myTree.createTree(myTree.keys, myTree.times, myTree.typeNum);//������
		myTree.setWpl(myTree.root);//ͳ��wpl
		myTree.encode(myTree.root, "");//��ÿ���ַ�������Ӧ�ı���
		myTree.setCodeArray(myTree.root);
		myTree.save();//����
	}
	//��������ʼ����
	string fileName;
	cout << "��������Ҫ������ļ���" << endl;
	cin >> fileName;
	myTree.encoding(fileName);

}

//�������ܣ�ִ���������
//����������HuffmanTree�����myTree
//����ֵ��void
void func3(HuffmanTree &myTree)
{
	if (myTree.isEmpty())
	{
		ifstream in("hfmTree.txt", ios::binary);
		if (!in)
		{
			cout << "���ȳ�ʼ������������" << endl;
			return;
		}
		//�ȶ���������
		in.read((char*)&myTree.typeNum, sizeof(myTree.typeNum));
		//��ʼ������������
		myTree.keys = new char[myTree.typeNum + 1];
		myTree.times = new unsigned short[myTree.typeNum];
		myTree.codes = new string[myTree.typeNum];
		//�ȶ����ַ���Ƶ��
		for (int i = 0; i < myTree.typeNum; i++)
		{
			in.read((char*)&myTree.keys[i], sizeof(myTree.keys[i]));
			in.read((char*)&myTree.times[i], sizeof(myTree.times[i]));
		}
		myTree.createTree(myTree.keys, myTree.times, myTree.typeNum);//������
		myTree.setWpl(myTree.root);//ͳ��wpl
		myTree.encode(myTree.root, "");//��ÿ���ַ�������Ӧ�ı���
		myTree.setCodeArray(myTree.root);//�Ա�������codes[]���и�ֵ���Ա��������
		myTree.save();//����
	}
	//��������ʼ����
	cout << "������Ҫ������ļ�����" << endl;
	string fileName;
	cin >> fileName;
	myTree.decode(fileName);
}


//�������ܣ�������洢�����������
//����������HuffmanTree�����myTree
//����ֵ��void
void func4(HuffmanTree &myTree)
{
	//Ϊʡȥ������ʱ�䣬���ǽ�wplֱ��д���ļ������ȡʱ�ɲ�����Huffman�����������������
	string fileName;
	cout << "������Ҫ��ʾ����������ļ���" << endl;
	cin >> fileName;
	ifstream in(fileName, ios::binary);
	ofstream out("CodePrin.txt", ios::out);
	if (!in||!out)
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	int wpl;
	in.read((char*)&wpl, sizeof(int));
	unsigned char c;
	int temp=0;//������
	//�������ʮ������ת����01�����ƴ���
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
			if (temp % 50 == 0)//��֤ÿ��50��
			{
				cout << endl;
				out << endl;
			}
		}
	}
	//�����һλʮ�������Ƿ�ת��8λ�����ƴ���Ĵ���
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
			if (temp % 50 == 0)//��֤ÿ��50��
			{
				cout << endl;
				out << endl;
			}
		}
	}
	cout << endl;
}

//�������ܣ���ӡ���洢huffman��
//����������HuffmanTree�����myTree
//����ֵ��void
void func5(HuffmanTree &myTree)
{
	if (myTree.isEmpty())
	{
		ifstream in("hfmTree.txt", ios::binary);
		if (!in)
		{
			cout << "���ȳ�ʼ������������" << endl;
			return;
		}
		//�ȶ���������
		in.read((char*)&myTree.typeNum, sizeof(myTree.typeNum));
		myTree.keys = new char[myTree.typeNum + 1];
		myTree.times = new unsigned short[myTree.typeNum];
		myTree.codes = new string[myTree.typeNum];
		//���Ŷ����ַ���Ƶ��
		for (int i = 0; i < myTree.typeNum; i++)
		{
			in.read((char*)&myTree.keys[i], sizeof(myTree.keys[i]));
			in.read((char*)&myTree.times[i], sizeof(myTree.times[i]));
		}
		myTree.createTree(myTree.keys, myTree.times, myTree.typeNum);//������
		myTree.setWpl(myTree.root);//ͳ��wpl
		myTree.encode(myTree.root, "");//��ÿ���ַ�������Ӧ�ı���
		myTree.setCodeArray(myTree.root);
		myTree.save();//����
		myTree.displayHuffman();
	}
	else
		myTree.displayHuffman();
	cout << "���������Ѿ�д���ļ�TreePrin.txt����Ҷ�ӽ��Ĺؼ���Ĭ����ʾ\\0" << endl << endl;
}

//�������ܣ��˳�����
//����������HuffmanTree�����myTree
//����ֵ��void
void func6(HuffmanTree &myTree)
{
	cout << "ף��������죬�ټ���" << endl;
	exit(0);
}