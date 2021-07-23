#pragma once
#include<string>
#include<iostream>
using namespace std;

class bussinessLog {
public:
	string stName;//职员姓名
	string acName;//顾客姓名
	string time;//交易时间
	virtual void toString() = 0;
};
//VIP充值
class VIPcharge : public bussinessLog{
	int type;
public:
	VIPcharge(int type);
	VIPcharge();
	void toString() {
		string s = stName + "_" + acName + "_" + "充值了";
		switch (this->type)
		{
		case 1:
			s.append("青铜VIP");
			break;
		case 2:
			s.append("白银VIP");
			break;
		case 3:
			s.append("黄金VIP");
			break;
		default:
			break;
		}
		cout << s << " 时间:" << time << endl;
	}
};
//存钱
class saveMoney : public bussinessLog {
	double money;
public:
	saveMoney(double money);
	void toString() {
		cout << acName << "存了" << money << "元" <<" 时间:"<< time << endl;
	}
};
//取钱
class getMoney : public bussinessLog {
	double money;
public:
	getMoney(double money);
	void toString() {
		cout << acName << "取了" << money << "元" << " 时间:" << time << endl;
	}
};
//转账
class transfer : public bussinessLog {
	string name;
	double money;
public:
	transfer(string name, double money);
	void toString() {
		cout << acName << "向" << name << "转了" << money << "元" << " 时间:" << time << endl;
	}
};
