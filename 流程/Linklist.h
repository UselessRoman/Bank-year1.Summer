#pragma once
#include<iostream>
struct node
{
	int data;
	node* next ;
};


class Linklist
{
public:
	node* head;
	int tr;

	Linklist();

	void Printlist();//����������нڵ�

	int GetListLength();//�õ�������

	void DeleteNode( int num);//ɾ��ĳ���ڵ�

	void Add(int num, int data);//��ĳ���ڵ�����һ���ڵ�

	int getFirst();//ȡ�õ�һ���ڵ�ı�Ų�����һ���ڵ��Ƴ�

	~Linklist();
};

