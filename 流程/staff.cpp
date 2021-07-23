#include "STAFF.h"

//staff的构造函数，输入name，ID，password创建一个staff类
Staff::Staff(string name, string ID, string password) {
	this->name = name;
	this->ID = ID;
	this->password = password;
	this->isEmpty = true;
}

//返回staff的name
string Staff::getName() {
	return this->name;
}

//返回staff的ID
string Staff::getId() {
	return this->ID;
}

//返回staff的password
string Staff::getPassword() {
	return this->password;
}

//
void Staff::setName(string name) {
	this->name = name;
}

//
void Staff::setID(string ID) {
	this->ID = ID;
}

//
void Staff::setPassword(string password) {
	this->password = password;
}