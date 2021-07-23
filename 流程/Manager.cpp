#include"Manager.h"

Manager::Manager() {
	waitList = new Linklist();
	staffs = new Staff*;	
	staffs[0] = new Staff("һ�Ź�Ա", "001", "123654");
	staffs[1] = new Staff("���Ź�Ա", "002", "123654");
	staffs[2] = new Staff("���Ź�Ա", "003", "123654");
	loadInfo();
	number = 0;
}
//�˿�ѡ��˵�
void  Manager::showMenu() {
	cout << "1.ȡƱ" << endl;
	cout << "2.ҵ�����" << endl;
	cout << "3.�鿴�Ŷ�" << endl;
	cout << "4.�鿴ʱ��" << endl;
	cout << "5.�˳�" << endl;
}

void  Manager::showBussiness() {
	cout << "1.���" << endl;
	cout << "2.ȡ��" << endl;
	cout << "3.ת��" << endl;
	cout << "4.VIP����" << endl;
	cout << "5.����" << endl;
	cout << "6.����" << endl;
	cout << "7.�˳�" << endl;
}
//ҵ��
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
			cout << "���" << endl;
			b = new saveMoney(100);
			system("pause");
			break;
		case '2':
			cout << "ȡ��" << endl;
			b = new getMoney(100);
			system("pause");
			break;
			break;
		case '3':
			b = new transfer("���", 100);
			cout << "ת��" << endl;
			system("pause");
			break;
		case '4':
			cout << "VIP����" << endl;
			b = new VIPcharge(2);
			system("pause");
			break;
		case '5':
			cout << "����" << endl;
			system("pause");
		case '6':
			cout << "����" << endl;
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
//�˿͹���
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
			cout << "չʾ�Ŷ����" << endl;
			system("pause");
			break;
		case '4':
			cout << "չʾʱ��" << endl;
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
	cout << "1.�鿴�Ŷ�" << endl;
	cout << "2.�鿴���׼�¼" << endl;
	cout << "3.�鿴ҵ��ƽ������ʱ��" << endl;
	cout << "4.�˳�" << endl;
}

void  Manager::login() {
	cout << "�����˺�����...." << endl;
	cout << "�˶��˺�����..." << endl;
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
			cout << "�Ŷ����" << endl;
			system("pause");
			break;
		case '2':
			cout << "���׼�¼" << endl;
			system("pause");
			break;
		case '3':
			cout << "����ʱ��" << endl;
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
	cout << "����ʱ��Ϊ" << hour << " Сʱ" << min << " ����" << sec << " ��" << endl;
}

void Manager::getNum() {
	while (true) {
		cout << "1.��ͨȡƱ" << endl;
		cout << "2.��ԱȡƱ" << endl;
		char ch = '0';
		cin >> ch;
		if (ch == '1') {
			this->waitList->Add(this->waitList->GetListLength(), number);
			cout << number << endl;
			cout << "�ɹ�ȡƱ�����Ϊ" << number << endl;
			number++;
			break;
		}
		else if (ch == '2') {
			cout << "����������" << endl;
			cout << "�������˺�" << endl;
			cout << "����������" << endl;
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
			cout << i << "��λ�ñ�"<<k<<"�Ź˿�ռ��" << endl;
			break;
		}
	}
}

void Manager::cLogin() {
	cout << "�������˺�" << endl;
	string id;
	cin >> id;
}

void Manager::sLogin() {

}

void Manager::loadInfo() {
	ifstream ifs;
	ifs.open("account.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
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

