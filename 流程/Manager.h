#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
#include<ctime>
#include"Linklist.h"
#include"bussiness.h"
#include"STAFF.h"
#include"ACCOUNT.h"
using namespace std;

class Manager {
	int number;
	Staff**staffs;
public:
	vector<bussinessLog*> buLogs;
	vector<Account*> accounts;
	Linklist*waitList;
public:
	Manager();

	void customer();//�˿͹���

	void getNum();//ȡƱ

	void Bussiness();//����ҵ����

	void showBussiness();//չʾҵ����

	void showMenu();//�˿�ѡ��˵�

	void showStaffMenu();//Ա���˵�

	void checkStaff();//����Ƿ��пչ�̨

	void login();//Ա����¼����

	long gettime();//��ȡʱ��

	char* showtime();//չʾʱ��

	void timedif(long dif, long diff);//չʾʱ���

	void cLogin();

	void sLogin();

	void loadInfo();

	~Manager();
	
	};