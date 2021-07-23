#include<iostream>
#include"Linklist.h"
using namespace std;

Linklist::Linklist() {
	head = NULL;
	tr = 12;
}

void Linklist::Printlist()
{
	node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

int Linklist::GetListLength()
{
	node* temp = head;
	int length = 0;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}
	return length;
}

void Linklist::DeleteNode( int num)
{
	node* r = head;
	node* temp = r->next;
	int length = 1;
	while (length < num && r != NULL)
	{
		temp = temp->next;
		length++;
		r = r->next;
	}
	if (r != NULL)
	{
		r->next = temp->next;
		delete(temp);
		temp = NULL;
	}
	else
	{
		cout << "节点不存在！";
	}
}

int Linklist::getFirst() {
	if (head == NULL) {
		return -1;
	}
	node*temp = head;
	head = head->next;
	int k = temp->data;
	delete temp;
	return k;
}

void Linklist::Add( int num, int data)
{
	if (num<0 || num>GetListLength())
	{
		cout << "插入位置不符合规范";
	}
	else
	{
		if (num == 0) {
			if (head != NULL) {
				node*temp = head;
				head = new node;
				head->data = data;
				head->next = temp;
			}
			else {
				head = new node;
				head->data = data;
			}
		}
		else {
			node* n = new node;
			n->data = data;
			node* r = head;
			for (int i = 0; i < num-1; i++) {
				r = r->next;
			}
			if (r->next != NULL) {
				node*nextNode = r->next;
				r->next = n;
				n->next = nextNode;
			}
			else {
				r->next = n;
			}
		}	
	}

}

Linklist::~Linklist() 
{
	//delete head;
}