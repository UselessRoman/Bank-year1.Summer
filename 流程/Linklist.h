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

	void Printlist();//输出链表所有节点

	int GetListLength();//得到链表长度

	void DeleteNode( int num);//删除某处节点

	void Add(int num, int data);//在某处节点后添加一个节点

	int getFirst();//取得第一个节点的编号并将第一个节点移除

	~Linklist();
};

