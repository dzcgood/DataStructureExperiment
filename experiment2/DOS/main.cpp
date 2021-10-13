//�ļ�����main.cpp
//�����ܣ�ʵ�����û��Ľ����������û����������Ӧ����
//���ߣ����ǳ�
//���ڣ�2020.12.05
//�汾��2.0
#include"studentDataBase.h"
#include<iomanip>
using namespace std;

//����ָ�����������
//���ú���ָ�����飬����ʹ����switch�ṹ��ʵ����Ӧ�����ĵ��ã�����Ч��
void func1(void);//��1��11�����ܵ��õĺ���
void func2(void);
void func3(void);
void func4(void);
void func5(void);
void func6(void);
void func7(void);
void func8(void);
void func9(void);
void func10(void);
void func11(void);
void func12(void);

//����ָ�����飬���ڸ����û�������ö�Ӧ����
void(*functionPointer[12])(void) = { func1,func2,func3,func4,func5,func6,func7,func8,func9,func10,func11,func12 };


//�˺����������ɰ�������
//�Ѿ�������ϣ���ʱ������
//void emergeData(); 

//����ȫ�������
studentDataBase studata;
nameTreeNode *nameTree=0;//������Ϊ�ؼ��ֵ�������
numberTreeNode* numberTree = 0;//��ѧ��Ϊ�ؼ��ֵ�������
phoneNumTreeNode* phoneNumTree = 0;//�Ե绰Ϊ�ؼ��ֵ�������
student* MIN = 0;//����������С��ѧ����ַ

//����ֵ����
//�������ܣ���ʾ�˵�
void menu()
{
    cout << "\n*****************ѧ��ͨѶ¼ϵͳ***********************\n";
    cout << "1:�½�ѧ��ͨѶ¼���Բ�α����ķ�ʽ����ѧ����Ϣ�����룩\n";
    cout << "2:��ѧ��ͨѶ¼����ѧ����Ϣ\n";
    cout << "3:��ͨѶ¼�в�ѯѧ����Ϣ����ѧ�Ų�ѯ��\n";
    cout << "4:��ͨѶ¼�в�ѯѧ����Ϣ����������ѯ��\n";
    cout << "5:��ͨѶ¼�в�ѯѧ����Ϣ�����绰�����ѯ��\n";
    cout << "6:��ͨѶ¼ɾ��ѧ����Ϣ\n";
    cout << "7:���������С��ѧ����Ϣ\n";
    cout << "8:����Ļ�����ȫ��ѧ����Ϣ\n";
    cout << "9:���ļ��ж�ȡͨѶ¼��Ϣ\n";
    cout << "10:���ļ�д��ѧ��ͨѶ¼��Ϣ\n";
    cout << "11:�����������\n";
    cout << "12:�˳�\n";
    cout << "*********************�����Ӧ������ִ�й���************\n";
}

//����ֵ����
//�������ܣ�����������Ե����ƣ�ѧ�š��������������ڡ��Ա𡢵绰����ַ��
void title()
{
    cout << setw(15) << "ѧ��";
    cout << setw(10) << "����";
    cout << setw(12) << "��������";
    cout << setw(8) << "�Ա�";
    cout << setw(15) << "�绰";
    cout << setw(20) << "��ַ";
    cout << endl;
}


//������
//�������ܣ�ʵ���û����������ö�Ӧ����
int main()
{
    
    int input;
    menu();
    while (true)
    {
        cin >> input;
        if (input >= 1 && input <= 12)
        {
            (*functionPointer[input - 1])();//���ö�Ӧ����
            menu();//��ʾ�˵�
        }
        else
            cout << "��������ȷ��ָ�" << endl;
    }
   //��������������ɰ������ݣ������Ѿ��ò�����
   //emergeData();
    return 0;
}

////////////////////////////////
//������func1-func11������ʵ��
///////////////////////////////

//����ֵ����
//�������ܣ������½�ͨѶ¼����
void func1(void)
{
    cout << "����������ÿ��ѧ����ѧ�š��������������ڡ��Ա𡢵绰�͵�ַ,����#����" << endl;
    studata.createTree();
    cout << "�½��ɹ���" << endl;
}


//����ֵ����
//�������ܣ����ò���ѧ���ĺ���
void func2(void)
{
    cout << "����������ѧ����ѧ�š��������������ڡ��Ա𡢵绰�͵�ַ" << endl;
    student *p = new student;
    cin >> *p;
    //ͬʱ���Ŀ����в��루һ�����������ø�������
    studata.insert(p, studata.root);
    studata.insertByName(p, nameTree);
    studata.insertByNum(p, numberTree);
    studata.insertByPhoneNum(p, phoneNumTree);
    cout << "����ɹ���" << endl;
}

//����ֵ����
//�������ܣ����ð�ѧ�Ų���ѧ���ĺ���
void func3(void)
{
    cout << "������Ҫ���ҵ�ѧ��" << endl;
    char num[15];
    cin >> num;
    student* p = studata.searchNum(numberTree, num);
    if (p)
    {
        title();
        cout << *p << endl;
    }
    else
        cout << "δ�鵽�����Ϣ" << endl;
}

//����ֵ����
//�������ܣ����ð���������ѧ���ĺ���
void func4(void)
{
    cout << "������Ҫ���ҵ�����" << endl;
    char name[10];
    cin >> name;
    student* p = studata.searchName(nameTree, name);
    if (p)
    {
        title();
        cout << *p << endl;
    }
    else
        cout << "δ�鵽�����Ϣ" << endl;
}


//����ֵ����
//�������ܣ����ð��绰�������ѧ���ĺ���
void func5(void)
{
    cout << "������Ҫ���ҵĵ绰����" << endl;
    char phoneNum[15];
    cin >> phoneNum;
    student* p = studata.searchPhoneNum(phoneNumTree, phoneNum);
    if (p)
    {
        title();
        cout << *p << endl;
    }
    else
        cout << "δ�鵽�����Ϣ" << endl;
}


//����ֵ����
//�������ܣ�����ɾ��ѧ���ĺ���
void func6(void)
{
    cout << "������Ҫɾ����� 1(��ѧ�Ų���) 2(����������) 3(���������)" << endl;
    int input;
    cin >> input;
    if (input == 1)
    {
        cout << "������Ҫɾ����ѧ��" << endl;
        char num[15];
        cin >> num;
        studata.delByNum(num);
    }
    else if (input == 2)
    {
        cout << "������Ҫɾ��������" << endl;
        char name[10];
        cin >> name;
        studata.delByName(name);
    }
    else if (input == 3)
    {
        cout << "������Ҫɾ���ĵ绰����" << endl;
        char phoneNum[15];
        cin >> phoneNum;
        studata.delByPhoneNum(phoneNum);
    }
    else
        cout << "��������ȷ��ָ�" << endl;
}


////����ֵ����
//�������ܣ��������������͵�ѧ����Ϣ�ĺ���
void func7(void)
{
    studata.getYoungest(studata.root);
    if (!MIN)cout << "��ͨѶ¼��" << endl;
    else
    {
        title();
        cout << *MIN<<endl;
    }
}


//����ֵ����
//�������ܣ������������ѧ����Ϣ�ĺ���
void func8(void)
{
    if (!studata.root)
    {
        cout << "ͨѶ¼Ϊ�գ�" << endl;
        return;
    }
    studata.output();
    cout << endl;
}


//����ֵ����
//�������ܣ����ö�ȡ�ļ�����
void func9(void)
{
    cout << "������Ҫ��ȡ���ļ���" << endl;
    string fileName;
    cin >> fileName;
    studata.readFile(fileName);
    cout << endl;
}

//����ֵ����
//�������ܣ�����д���ļ��ĺ���
void func10(void)
{
    cout << "������Ҫд����ļ���" << endl;
    string fileName;
    cin >> fileName;
    studata.writeFile(fileName);
    cout << endl;
}

//����ֵ����
//�������ܣ����ö�ȡ�������ݵĺ���
void func11(void)
{
    cout << "��ȡ�У����Ժ�" << endl;
    cout << "Ԥ�ƺ�ʱ16���ӡ���" << endl;
    studata.readFile("randomData.dat");
    cout << "�������" << endl;
}

//����ֵ����
//�������ܣ��˳�����
void func12(void)
{
    cout << "ף��������죡�ټ���" << endl;
    exit(1);
}