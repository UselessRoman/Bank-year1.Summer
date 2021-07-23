#pragma once
#include <string>
using namespace std;
class Staff {
	string name;
	string ID;
	string password;
public:
	bool isEmpty;
	Staff(string name, string Id, string password);

	string getName();
	string getId();
	string getPassword();

	void setName(string name);
	void setID(string ID);
	void setPassword(string password);
};