#pragma once
#include <string>
#include<iostream>
using namespace std;
class Account {//–’√˚_’À∫≈_√‹¬Î_«Æ_VIPµ»º∂
	string name;
	string id;
	int money;
	string password;
	int VIPLevel;
public:
	Account(string name, string id, int money, string password, int VIPLevel);

	string getName();
	int getMoney();
	string getPassword();
	int getVIPLevel();
	string getId();

	void setName(string name);
	void setMoney(int money);
	void setPassword(string password);
	void setVIPLevel(int VIPLevel);
	void setId(string id);
	void show();
};