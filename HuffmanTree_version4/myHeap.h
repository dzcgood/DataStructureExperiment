//文件名：myHeap.h
//功能：  最小堆的定义
//作者：  邓智超
//修改时间：2020.12.25
#ifndef _MYHEAP_H_
#define _MYHEAP_H_
#pragma once
#include<iostream>
using namespace std;
//声明最小堆的最大结点树，此处设置为130
const int DefaultSize =130;

//////////////////////////////
//接下来是最小堆myHeap类的定义
//////////////////////////////

template<class T>
class MyHeap
{
	//heap数组
	T* heap;
	//当前元素数量
	int currentSize;
	//最大元素数量
	int maxHeapSize;
public:
	//缺省构造函数
	MyHeap(int sz = DefaultSize);
	//由数组生成最小堆
	MyHeap(T arr[], int n);
	//析构函数
	~MyHeap() { delete[]heap; }
	//最小堆插入算法
	bool Insert(T& x);
	//最小堆删除算法
	bool Remove(T& x);
	//判断堆是否为空
	bool IsEmpty()const
	{
		return currentSize == 0;
	}
	//判断堆是否已满
	bool IsFull()const
	{
		return currentSize == maxHeapSize;
	}
	//清空堆
	void MakeEmpty()
	{
		currentSize = 0;
	}
private:
	//最小堆向下调整算法
	void siftDown(int start, int m);
	//最小堆向上调整算法
	void siftUp(int start);
};

///////////////////////////////
//接下来是最小堆myHeap类的实现
//////////////////////////////
//构造函数，根据给定大小maxSize，建立堆对象
//函数功能：创建堆数组，执行初始化操作
//函数参数：数组大小sz
//返回值：无
template<class T>
MyHeap<T>::MyHeap(int sz)
{
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new T[maxHeapSize];//创建堆数组
	currentSize = 0;
}

//函数功能：构造函数，由已有数组建立堆对象
//函数参数：包含字符出现次数的数组arr，数组长度n
//返回值：无
template <class T>
MyHeap<T>::MyHeap(T arr[], int n)
{
	maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
	heap = new T[maxHeapSize];
	//对数组赋值
	for (int i = 0; i < n; i++)
	{
		heap[i] = arr[i];
	}
	//对数组进行调整，使之成为最小堆
	currentSize = n;
	int currentPos = (currentSize - 2) / 2;//最后非叶子结点
	while (currentPos >= 0)
	{	
		//从currentPos调整到currentSize
		siftDown(currentPos, currentSize - 1); 
		currentPos--;						  
	}
}

//函数功能：最小堆插入算法，将元素x插入最小堆
//函数参数：要插入堆的元素x
//返回值：逻辑值true或false
template <class T>
bool MyHeap<T>::Insert(T& x)
{
	//若堆已满
	if (currentSize == maxHeapSize)
	{ 
		cout << "堆已满！" << endl;
		return false;
	}
	//未满
	heap[currentSize] = x;
	siftUp(currentSize);   //向上调整
	currentSize++;		   //当前元素数加1
	return true;
}

//函数功能：最小堆删除算法，删除堆顶元素
//函数参数：将堆顶元素赋值给x
//返回值：逻辑值true或false
template <class T>
bool MyHeap<T>::Remove(T& x)
{
	//若堆为空
	if (!currentSize)
	{ 
		cout << "堆为空" << endl;
		return false;
	}
	//堆不空
	x = heap[0];					 // 返回最小元素
	heap[0] = heap[currentSize - 1]; //最后元素填补到根结点
	currentSize--;                   //当前元素数减1
	siftDown(0, currentSize - 1); //自上向下调整为堆
	return true;
}

//函数功能：最小堆向下调整算法
//函数参数：起点位置start，终点位置m
//返回值：无
template<class T>
void MyHeap<T>::siftDown(int start, int m)
{
	int i = start, j = 2 * i + 1;
	T temp = heap[i];
	while (j <= m)
	{
		//两子女选小的
		if (j<m && heap[j]>heap[j + 1])
			j++;
		if (temp <= heap[j])break;
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;//往下走
		}
	}
	heap[i] = temp;
} 

//函数功能：最小堆向上调整算法
//函数参数：起点位置start
//返回值：无
template<class T>
void MyHeap<T>::siftUp(int start)
{
	//从start开始向上调整到0
	int j = start, i = (j - 1) / 2;//i是j的双亲
	T temp = heap[j];
	while (j > 0)
	{
		if (heap[i] <= temp)break;
		else
		{
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;//往上走
		}
	}
	heap[j] = temp;
}
#endif

