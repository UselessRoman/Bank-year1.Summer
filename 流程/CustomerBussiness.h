#include<iostream>
#include"ACCOUNT.h"
using namespace std;

class CustmoerBussiness {


public:
	bool checkAccount(string ID, string password);

	Account getAccount(string ID, string password);

	bool moneycheck(Account Acc, int money);

	void deposit();

	void withdraw();

	void tansfer();

	void openVIP();

	void openAccount();

	void deleteAccount();
};