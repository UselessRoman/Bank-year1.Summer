#include "STAFF.h"

//staff�Ĺ��캯��������name��ID��password����һ��staff��
Staff::Staff(string name, string ID, string password) {
	this->name = name;
	this->ID = ID;
	this->password = password;
	this->isEmpty = true;
}

//����staff��name
string Staff::getName() {
	return this->name;
}

//����staff��ID
string Staff::getId() {
	return this->ID;
}

//����staff��password
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