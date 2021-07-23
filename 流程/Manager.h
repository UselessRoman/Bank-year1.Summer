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

	void customer();//顾客功能

	void getNum();//取票

	void Bussiness();//办理业务功能

	void showBussiness();//展示业务功能

	void showMenu();//顾客选择菜单

	void showStaffMenu();//员工菜单

	void checkStaff();//检查是否有空柜台

	void login();//员工登录界面

	long gettime();//获取时间

	char* showtime();//展示时间

	void timedif(long dif, long diff);//展示时间差

	void cLogin();

	void sLogin();

	void loadInfo();

	~Manager();
	
	};