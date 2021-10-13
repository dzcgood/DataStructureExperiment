//文件名：main.cpp
//程序功能：实现与用户的交互，根据用户输出调用相应函数
//作者：邓智超
//日期：2020.12.05
//版本：2.0
#include"studentDataBase.h"
#include<iomanip>
using namespace std;

//函数指针数组的内容
//利用函数指针数组，避免使用了switch结构来实现相应函数的调用，提升效率
void func1(void);//第1到11个功能调用的函数
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

//函数指针数组，用于根据用户输入调用对应函数
void(*functionPointer[12])(void) = { func1,func2,func3,func4,func5,func6,func7,func8,func9,func10,func11,func12 };


//此函数用于生成百万数据
//已经生成完毕，暂时不用了
//void emergeData(); 

//声明全局类对象
studentDataBase studata;
nameTreeNode *nameTree=0;//以姓名为关键字的搜索树
numberTreeNode* numberTree = 0;//以学号为关键字的搜索树
phoneNumTreeNode* phoneNumTree = 0;//以电话为关键字的搜索树
student* MIN = 0;//保存年龄最小的学生地址

//返回值：无
//函数功能：显示菜单
void menu()
{
    cout << "\n*****************学生通讯录系统***********************\n";
    cout << "1:新建学生通讯录（以层次遍历的方式进行学生信息的输入）\n";
    cout << "2:向学生通讯录插入学生信息\n";
    cout << "3:在通讯录中查询学生信息（按学号查询）\n";
    cout << "4:在通讯录中查询学生信息（按姓名查询）\n";
    cout << "5:在通讯录中查询学生信息（按电话号码查询）\n";
    cout << "6:在通讯录删除学生信息\n";
    cout << "7:输出年龄最小的学生信息\n";
    cout << "8:在屏幕中输出全部学生信息\n";
    cout << "9:从文件中读取通讯录信息\n";
    cout << "10:向文件写入学生通讯录信息\n";
    cout << "11:读入百万数据\n";
    cout << "12:退出\n";
    cout << "*********************输入对应数字以执行功能************\n";
}

//返回值：无
//函数功能：输出各项属性的名称（学号、姓名、出生日期、性别、电话、地址）
void title()
{
    cout << setw(15) << "学号";
    cout << setw(10) << "姓名";
    cout << setw(12) << "出生日期";
    cout << setw(8) << "性别";
    cout << setw(15) << "电话";
    cout << setw(20) << "地址";
    cout << endl;
}


//主函数
//函数功能：实现用户交互，调用对应函数
int main()
{
    
    int input;
    menu();
    while (true)
    {
        cin >> input;
        if (input >= 1 && input <= 12)
        {
            (*functionPointer[input - 1])();//调用对应函数
            menu();//显示菜单
        }
        else
            cout << "请输入正确的指令！" << endl;
    }
   //以下语句用于生成百万数据，现在已经用不到了
   //emergeData();
    return 0;
}

////////////////////////////////
//以下是func1-func11函数的实现
///////////////////////////////

//返回值：无
//函数功能：调用新建通讯录函数
void func1(void)
{
    cout << "请依次输入每个学生的学号、姓名、出生日期、性别、电话和地址,并以#结束" << endl;
    studata.createTree();
    cout << "新建成功！" << endl;
}


//返回值：无
//函数功能：调用插入学生的函数
void func2(void)
{
    cout << "请依次输入学生的学号、姓名、出生日期、性别、电话和地址" << endl;
    student *p = new student;
    cin >> *p;
    //同时在四棵树中插入（一棵主树和三棵辅助树）
    studata.insert(p, studata.root);
    studata.insertByName(p, nameTree);
    studata.insertByNum(p, numberTree);
    studata.insertByPhoneNum(p, phoneNumTree);
    cout << "插入成功！" << endl;
}

//返回值：无
//函数功能：调用按学号查找学生的函数
void func3(void)
{
    cout << "请输入要查找的学号" << endl;
    char num[15];
    cin >> num;
    student* p = studata.searchNum(numberTree, num);
    if (p)
    {
        title();
        cout << *p << endl;
    }
    else
        cout << "未查到相关信息" << endl;
}

//返回值：无
//函数功能：调用按姓名查找学生的函数
void func4(void)
{
    cout << "请输入要查找的姓名" << endl;
    char name[10];
    cin >> name;
    student* p = studata.searchName(nameTree, name);
    if (p)
    {
        title();
        cout << *p << endl;
    }
    else
        cout << "未查到相关信息" << endl;
}


//返回值：无
//函数功能：调用按电话号码查找学生的函数
void func5(void)
{
    cout << "请输入要查找的电话号码" << endl;
    char phoneNum[15];
    cin >> phoneNum;
    student* p = studata.searchPhoneNum(phoneNumTree, phoneNum);
    if (p)
    {
        title();
        cout << *p << endl;
    }
    else
        cout << "未查到相关信息" << endl;
}


//返回值：无
//函数功能：调用删除学生的函数
void func6(void)
{
    cout << "请输入要删除结点 1(按学号查找) 2(按姓名查找) 3(按号码查找)" << endl;
    int input;
    cin >> input;
    if (input == 1)
    {
        cout << "请输入要删除的学号" << endl;
        char num[15];
        cin >> num;
        studata.delByNum(num);
    }
    else if (input == 2)
    {
        cout << "请输入要删除的姓名" << endl;
        char name[10];
        cin >> name;
        studata.delByName(name);
    }
    else if (input == 3)
    {
        cout << "请输入要删除的电话号码" << endl;
        char phoneNum[15];
        cin >> phoneNum;
        studata.delByPhoneNum(phoneNum);
    }
    else
        cout << "请输入正确的指令！" << endl;
}


////返回值：无
//函数功能：调用输出年龄最低的学生信息的函数
void func7(void)
{
    studata.getYoungest(studata.root);
    if (!MIN)cout << "空通讯录！" << endl;
    else
    {
        title();
        cout << *MIN<<endl;
    }
}


//返回值：无
//函数功能：调用输出所有学生信息的函数
void func8(void)
{
    if (!studata.root)
    {
        cout << "通讯录为空！" << endl;
        return;
    }
    studata.output();
    cout << endl;
}


//返回值：无
//函数功能：调用读取文件函数
void func9(void)
{
    cout << "请输入要读取的文件名" << endl;
    string fileName;
    cin >> fileName;
    studata.readFile(fileName);
    cout << endl;
}

//返回值：无
//函数功能：调用写入文件的函数
void func10(void)
{
    cout << "请输入要写入的文件名" << endl;
    string fileName;
    cin >> fileName;
    studata.writeFile(fileName);
    cout << endl;
}

//返回值：无
//函数功能：调用读取百万数据的函数
void func11(void)
{
    cout << "读取中，请稍后" << endl;
    cout << "预计耗时16分钟……" << endl;
    studata.readFile("randomData.dat");
    cout << "读入完成" << endl;
}

//返回值：无
//函数功能：退出程序
void func12(void)
{
    cout << "祝您生活愉快！再见！" << endl;
    exit(1);
}