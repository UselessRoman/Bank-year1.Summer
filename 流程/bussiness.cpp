#include"bussiness.h"

VIPcharge::VIPcharge(int type) {
	this->type = type;
}

VIPcharge::VIPcharge() {
}

saveMoney::saveMoney(double money) {
	this->money = money;
}

transfer::transfer(string name, double money) {
	this->name = name;
	this->money = money;
}

getMoney::getMoney(double money) {
	this->money = money;
}