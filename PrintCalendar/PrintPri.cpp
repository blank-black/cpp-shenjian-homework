/* 1551265 ��1 �Ų��� */
#include <iostream>
using namespace std;
int zeller(int year, int month, int day);
void print(int year, int month, int d);
int main()
{
	int year, month, day = 1, d;

	bool rn = 0;
	cout << "������������:" << endl;
	cin >> year >> month ;
	while (year < 1900 || year > 2100 || month < 1 || month > 12 )
	{

		cout << "�Ƿ�����" << endl;
		cout << "����������������:" << endl;
		cin >> year >> month ;
		while (!cin.good())
		{
			cout << "�Ƿ���������" << endl;
			cin.clear();
			cin.sync();
			cin.ignore(1024, '\n');
			cin >> year >> month ;
		}
	}
	d = zeller(year, month, day);
	print(year, month, d);
	return 0;
}
int zeller(int year, int month, int day)
{
	int w;
	if (month >= 3)
		w = year % 100 + year % 100 / 4 + year / 400 - 2 * year / 100 + 13 * (month + 1) / 5 + day - 1;
	else
	{
		month += 12;
		year -= 1;
		w = year % 100 + year % 100 / 4 + year / 400 - 2 * (year / 100) + 13 * (month + 1) / 5 + day - 1;
	}
	if (w >= 0)
		w %= 7;
	else
		w = 7 - abs(w) % 7;
	return w;
}
void print(int year, int month, int d)
{
	int a = 1, n, i = 1;
	bool flag = 0, rn = 0;
	cout << endl << year << "��" << month << "�µ�����Ϊ��" << endl;
	cout << '\t' << "������" << '\t' << "����һ" << '\t' << "���ڶ�" << '\t' << "������" << '\t' << "������" << '\t' << "������" << '\t' << "������" << '\t' << endl;
	if (year % 400 == 0 || year % 100 && year % 4 == 0)
		rn = 1;
	if (rn)
	{

		if (month == 4 || month == 6 || month == 9 || month == 11)
			n = 30;
		else if (month == 2)
			n = 28;
		else
			n = 31;
	}
	else
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
			n = 30;
		else if (month == 2)
			n = 29;
		else
			n = 31;
	}
	i += d;
	if (!d)
		cout << "\t" << a;
	else if (d == 1)
		cout << "\t\t" << a;
	else if (d == 2)
		cout << "\t\t\t" << a;
	else if (d == 3)
		cout << "\t\t\t\t" << a;
	else if (d == 4)
		cout << "\t\t\t\t\t" << a;
	else if (d == 5)
		cout << "\t\t\t\t\t\t" << a;
	else if (d == 6)
		cout << "\t\t\t\t\t\t\t" << a;
	for (a++; a <= n; a++)
	{
		if (i < 7)
		{
			cout << " ";
			i++;
		}
		else if (i == 7)
		{
			cout << endl;
			i = 1;
		}
		cout << "\t" << a;
	}
	cout << endl;
}

