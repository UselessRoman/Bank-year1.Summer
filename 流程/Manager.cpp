#include"Manager.h"

Manager::Manager() {
	waitList = new Linklist();
	staffs = new Staff*;	
	staffs[0] = new Staff("一号柜员", "001", "123654");
	staffs[1] = new Staff("二号柜员", "002", "123654");
	staffs[2] = new Staff("三号柜员", "003", "123654");
	loadInfo();
	number = 0;
}
//顾客选择菜单
void  Manager::showMenu() {
	cout << "1.取票" << endl;
	cout << "2.业务办理" << endl;
	cout << "3.查看排队" << endl;
	cout << "4.查看时间" << endl;
	cout << "5.退出" << endl;
}

void  Manager::showBussiness() {
	cout << "1.存款" << endl;
	cout << "2.取款" << endl;
	cout << "3.转账" << endl;
	cout << "4.VIP办理" << endl;
	cout << "5.开户" << endl;
	cout << "6.销户" << endl;
	cout << "7.退出" << endl;
}
//业务
void Manager::Bussiness() {
	long bt = gettime();
	long et = 0;
	system("cls");
	while (true) {
		bussinessLog* b = NULL;
		char ch = '0';
		showBussiness();
		cin >> ch;
		string time(showtime());
		switch (ch)
		{
		case '1':
			cout << "存款" << endl;
			b = new saveMoney(100);
			system("pause");
			break;
		case '2':
			cout << "取款" << endl;
			b = new getMoney(100);
			system("pause");
			break;
			break;
		case '3':
			b = new transfer("李白", 100);
			cout << "转账" << endl;
			system("pause");
			break;
		case '4':
			cout << "VIP办理" << endl;
			b = new VIPcharge(2);
			system("pause");
			break;
		case '5':
			cout << "开户" << endl;
			system("pause");
		case '6':
			cout << "销户" << endl;
			system("pause");
		case '7':
			et = gettime();
			for (vector<bussinessLog*>::iterator i = buLogs.begin(); i != buLogs.end(); i++) {
				(*i)->toString();
			}
			timedif(bt, et);
			system("pause");
			return;
		default:
			break;
		}
		b->time = time;
		buLogs.push_back(b);
		system("cls");
	}
}
//顾客功能
void Manager::customer() {
	while (true) {
		char ch = '0';
		showMenu();
		cin >> ch;
		switch (ch)
		{
		case '1':
			getNum();
			system("pause");
			break;
		case '2':
			Bussiness();
			break;
		case '3':
			cout << "展示排队请款" << endl;
			system("pause");
			break;
		case '4':
			cout << "展示时间" << endl;
			system("pause");
			break;
		case '5':
			system("cls");
			return;
		default:
			break;
		}
		system("cls");
	}
}

void  Manager::showStaffMenu() {
	cout << "1.查看排队" << endl;
	cout << "2.查看交易记录" << endl;
	cout << "3.查看业务平均办理时间" << endl;
	cout << "4.退出" << endl;
}

void  Manager::login() {
	cout << "输入账号密码...." << endl;
	cout << "核对账号密码..." << endl;
	system("pause");
	system("cls");
	while (true) {
		char ch = '0';
		showStaffMenu();
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			cout << "排队情况" << endl;
			system("pause");
			break;
		case '2':
			cout << "交易记录" << endl;
			system("pause");
			break;
		case '3':
			cout << "交易时间" << endl;
			system("pause");
			break;
		case '4':
			system("cls");
			return;
		default:
			break;
		}
		system("cls");
	}
}

long Manager::gettime() {
	time_t now = time(0);
	long nowtime = long(now);
	return nowtime;
}

char* Manager::showtime() {
	time_t now = time(0);
	char *show = ctime(&now);
	return show;
}

void  Manager::timedif(long dif, long diff) {
	int cost = int(diff - dif);
	int min = 0;
	int sec = 0;
	int hour = 0;
	hour = cost / 3600;
	min = (cost - 3600 * hour) / 60;
	sec = cost - 3600 * hour - 60 * min;
	cout << "办理时间为" << hour << " 小时" << min << " 分钟" << sec << " 秒" << endl;
}

void Manager::getNum() {
	while (true) {
		cout << "1.普通取票" << endl;
		cout << "2.会员取票" << endl;
		char ch = '0';
		cin >> ch;
		if (ch == '1') {
			this->waitList->Add(this->waitList->GetListLength(), number);
			cout << number << endl;
			cout << "成功取票，编号为" << number << endl;
			number++;
			break;
		}
		else if (ch == '2') {
			cout << "请输入姓名" << endl;
			cout << "请输入账号" << endl;
			cout << "请输入密码" << endl;
			break;	
		}
	}
	checkStaff();
}

void Manager::checkStaff() {
	for (int i = 0; i < 3; i++) {
		if (staffs[i]->isEmpty) {
			int k = waitList->getFirst();
			staffs[i]->isEmpty = false;
			cout << i << "号位置被"<<k<<"号顾客占用" << endl;
			break;
		}
	}
}

void Manager::cLogin() {
	cout << "请输入账号" << endl;
	string id;
	cin >> id;
}

void Manager::sLogin() {

}

void Manager::loadInfo() {
	ifstream ifs;
	ifs.open("account.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}	
	else {
		string name("0");
		string id("0");
		string password("0");
		int money=0;
		int vipLevel=1;
		while (ifs >> name && ifs >> id && ifs >> password && ifs >> money && ifs >> vipLevel) {
			Account*ac = new Account(name, id, money, password, vipLevel);
			accounts.push_back(ac);
		}
		for (vector<Account*>::iterator i = accounts.begin(); i != accounts.end(); i++) {
			(*i)->show();
		}
		ifs.close();
	}
}

 Manager::~Manager() {
	 for (int i = 0; i < 3; i++) {
		 delete staffs[i];
	 }
	delete waitList;
}

