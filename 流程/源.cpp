#include<iostream>
#include<Windows.h>
#include"STAFF.h"
#include"Linklist.h"
#include"Manager.h"

using namespace std;

int main() {
	Manager mg;
	while (true) {
		char ch = '0';
		cout << "1.�˿�" << endl;
		cout << "2.ְԱ" << endl;
		cout << "3.�˳�" << endl;
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			mg.customer();
			break;
		case '2':
			mg.login();
			break;
		case'3':
			mg.waitList->Printlist();
			exit(0);
		default:
			break;
		}
	}
	return 0;
}
