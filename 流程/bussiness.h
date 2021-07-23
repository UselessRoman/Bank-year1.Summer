#pragma once
#include<string>
#include<iostream>
using namespace std;

class bussinessLog {
public:
	string stName;//ְԱ����
	string acName;//�˿�����
	string time;//����ʱ��
	virtual void toString() = 0;
};
//VIP��ֵ
class VIPcharge : public bussinessLog{
	int type;
public:
	VIPcharge(int type);
	VIPcharge();
	void toString() {
		string s = stName + "_" + acName + "_" + "��ֵ��";
		switch (this->type)
		{
		case 1:
			s.append("��ͭVIP");
			break;
		case 2:
			s.append("����VIP");
			break;
		case 3:
			s.append("�ƽ�VIP");
			break;
		default:
			break;
		}
		cout << s << " ʱ��:" << time << endl;
	}
};
//��Ǯ
class saveMoney : public bussinessLog {
	double money;
public:
	saveMoney(double money);
	void toString() {
		cout << acName << "����" << money << "Ԫ" <<" ʱ��:"<< time << endl;
	}
};
//ȡǮ
class getMoney : public bussinessLog {
	double money;
public:
	getMoney(double money);
	void toString() {
		cout << acName << "ȡ��" << money << "Ԫ" << " ʱ��:" << time << endl;
	}
};
//ת��
class transfer : public bussinessLog {
	string name;
	double money;
public:
	transfer(string name, double money);
	void toString() {
		cout << acName << "��" << name << "ת��" << money << "Ԫ" << " ʱ��:" << time << endl;
	}
};
