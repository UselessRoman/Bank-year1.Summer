#include "ACCOUNT.h"

//
Account::Account(string name, string id, int money, string password, int VIPLevel) {
	this->name = name;
	this->money = money;
	this->password = password;
	this->VIPLevel = VIPLevel;
}

//
int Account::getMoney() {
	return this->money;
}

//
string Account::getName() {
	return this->name;
}

//
string Account::getPassword() {
	return this->password;
}

//
string Account::getId() {
	return id;
}

//
int Account::getVIPLevel() {
	return this->VIPLevel;
}

//
void Account::setMoney(int money) {
	this->money = money;
}

//
void Account::setName(string name) {
	this->name = name;
}

//
void Account::setPassword(string password) {
	this->password = password;
}

//
void Account::setVIPLevel(int VIPLevel) {
	this->VIPLevel = VIPLevel;
}

//
void Account::setId(string id) {
	this->id = id;
}

void Account::show() {
	cout << name << " " << id << " " << money << " " << endl;
}