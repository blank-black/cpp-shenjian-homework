/* 1551265 ��1 �Ų��� */
#include <iostream>
using namespace std;
int zeller(int year, int month, int day);
int main()
{
	int year, month, day, d;
	bool rn = 0;
	cout << "��������������:";
	cin >> year >> month >> day;
	if (year % 400 == 0 || year % 100 && year % 4 == 0)
		rn = 1;
	while ((year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || (month == 2 && day > 28 + rn))
	{

		cout << "�Ƿ�����" << endl;
		cout << "������������������:";
		cin >> year >> month >> day;
		if (!cin)
		{
			cin.clear();
			cin.sync();
			cout << "������� ����������" << endl;
			cin.ignore(1024, '\n');
			cin >> year >> month >> day;
		}
	}
	d = zeller(year, month, day);
	cout << "����������";
	switch (d)
	{
	case 0:
		cout << "��" << endl; 
		break;
	case 1:
		cout << "һ" << endl; 
		break;
	case 2:
		cout << "��" << endl; 
		break;
	case 3:
		cout << "��" << endl; 
		break;
	case 4:
		cout << "��" << endl; 
		break;
	case 5:
		cout << "��" << endl; 
		break;
	case 6:
		cout << "��" << endl; 
		break;
	}
	return 0;
}
int zeller(int year, int month, int day)
{
	int d;
	if (month < 3)
	{
		month += 12;
		year--;
	}
	d = year % 100 + year % 100 / 4 + year / 400 - 2 * (year / 100) + 13 * (month + 1) / 5 + day - 1;
	d+=7000;//ʹdΪ���� ���Ҳ�Ӱ�����%7��� ʡȥ�ж�
	d %= 7;
	return d;
}