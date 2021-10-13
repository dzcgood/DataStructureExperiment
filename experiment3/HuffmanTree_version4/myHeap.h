//�ļ�����myHeap.h
//���ܣ�  ��С�ѵĶ���
//���ߣ�  ���ǳ�
//�޸�ʱ�䣺2020.12.25
#ifndef _MYHEAP_H_
#define _MYHEAP_H_
#pragma once
#include<iostream>
using namespace std;
//������С�ѵ�����������˴�����Ϊ130
const int DefaultSize =130;

//////////////////////////////
//����������С��myHeap��Ķ���
//////////////////////////////

template<class T>
class MyHeap
{
	//heap����
	T* heap;
	//��ǰԪ������
	int currentSize;
	//���Ԫ������
	int maxHeapSize;
public:
	//ȱʡ���캯��
	MyHeap(int sz = DefaultSize);
	//������������С��
	MyHeap(T arr[], int n);
	//��������
	~MyHeap() { delete[]heap; }
	//��С�Ѳ����㷨
	bool Insert(T& x);
	//��С��ɾ���㷨
	bool Remove(T& x);
	//�ж϶��Ƿ�Ϊ��
	bool IsEmpty()const
	{
		return currentSize == 0;
	}
	//�ж϶��Ƿ�����
	bool IsFull()const
	{
		return currentSize == maxHeapSize;
	}
	//��ն�
	void MakeEmpty()
	{
		currentSize = 0;
	}
private:
	//��С�����µ����㷨
	void siftDown(int start, int m);
	//��С�����ϵ����㷨
	void siftUp(int start);
};

///////////////////////////////
//����������С��myHeap���ʵ��
//////////////////////////////
//���캯�������ݸ�����СmaxSize�������Ѷ���
//�������ܣ����������飬ִ�г�ʼ������
//���������������Сsz
//����ֵ����
template<class T>
MyHeap<T>::MyHeap(int sz)
{
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new T[maxHeapSize];//����������
	currentSize = 0;
}

//�������ܣ����캯�������������齨���Ѷ���
//���������������ַ����ִ���������arr�����鳤��n
//����ֵ����
template <class T>
MyHeap<T>::MyHeap(T arr[], int n)
{
	maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
	heap = new T[maxHeapSize];
	//�����鸳ֵ
	for (int i = 0; i < n; i++)
	{
		heap[i] = arr[i];
	}
	//��������е�����ʹ֮��Ϊ��С��
	currentSize = n;
	int currentPos = (currentSize - 2) / 2;//����Ҷ�ӽ��
	while (currentPos >= 0)
	{	
		//��currentPos������currentSize
		siftDown(currentPos, currentSize - 1); 
		currentPos--;						  
	}
}

//�������ܣ���С�Ѳ����㷨����Ԫ��x������С��
//����������Ҫ����ѵ�Ԫ��x
//����ֵ���߼�ֵtrue��false
template <class T>
bool MyHeap<T>::Insert(T& x)
{
	//��������
	if (currentSize == maxHeapSize)
	{ 
		cout << "��������" << endl;
		return false;
	}
	//δ��
	heap[currentSize] = x;
	siftUp(currentSize);   //���ϵ���
	currentSize++;		   //��ǰԪ������1
	return true;
}

//�������ܣ���С��ɾ���㷨��ɾ���Ѷ�Ԫ��
//�������������Ѷ�Ԫ�ظ�ֵ��x
//����ֵ���߼�ֵtrue��false
template <class T>
bool MyHeap<T>::Remove(T& x)
{
	//����Ϊ��
	if (!currentSize)
	{ 
		cout << "��Ϊ��" << endl;
		return false;
	}
	//�Ѳ���
	x = heap[0];					 // ������СԪ��
	heap[0] = heap[currentSize - 1]; //���Ԫ����������
	currentSize--;                   //��ǰԪ������1
	siftDown(0, currentSize - 1); //�������µ���Ϊ��
	return true;
}

//�������ܣ���С�����µ����㷨
//�������������λ��start���յ�λ��m
//����ֵ����
template<class T>
void MyHeap<T>::siftDown(int start, int m)
{
	int i = start, j = 2 * i + 1;
	T temp = heap[i];
	while (j <= m)
	{
		//����ŮѡС��
		if (j<m && heap[j]>heap[j + 1])
			j++;
		if (temp <= heap[j])break;
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;//������
		}
	}
	heap[i] = temp;
} 

//�������ܣ���С�����ϵ����㷨
//�������������λ��start
//����ֵ����
template<class T>
void MyHeap<T>::siftUp(int start)
{
	//��start��ʼ���ϵ�����0
	int j = start, i = (j - 1) / 2;//i��j��˫��
	T temp = heap[j];
	while (j > 0)
	{
		if (heap[i] <= temp)break;
		else
		{
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;//������
		}
	}
	heap[j] = temp;
}
#endif

