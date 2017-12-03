/* 1551265 计1 张伯阳 */
#include <iostream>
#include <windows.h>
#include <conio.h>
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
void gotoxy(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}
void showch(HANDLE hout, int X, int Y, char A)
{
	gotoxy(hout, X, Y);
	putchar(A);
}
void showin(HANDLE hout, int X, int Y, int A)
{
	gotoxy(hout, X, Y);
	cout << A;
}
int main()
{
	system("mode con cols=106 lines=45");
	system("color 1A");
	void head(int m);
	int zeller(int year, int month, int day), year, month;
	int m[72][8] = { 0 }, n[13];
	SetConsoleTextAttribute(hout, 16 + 8);
	cout << "请输入年份（1900-2100）：";
	cin >> year;
	while (year < 1900 || year > 2100)
	{
		cin.clear();
		cin.sync();
		cout << "输入非法，重新输入" << endl;
		cout << "输入年份1900-2100:";
		cin.ignore(1024, '\n');
		cin >> year;
	}
	cout << year << "年的日历:" << endl << "\t";
	for (month = 1; month < 13; month++)
	{
		if (1 == month || 3 == month || 5 == month || 7 == month || 8 == month || 10 == month || 12 == month)
			n[month] = 31;
		else if (4 == month || 6 == month || 9 == month || 11 == month)
			n[month] = 30;
		if (2 == month) {
			if (year % 4 || !(year % 100) && year % 400)
				n[month] = 28;
			else
				n[month] = 29;
		}
	}
	for (month = 1; month < 13; month++)
	{
		int i = zeller(year, month, 1), a = 1;
		for (int t = (month - 1) * 6; t < month * 6 && a <= n[month]; )
		{
			m[t][i] = a;
			if (i < 7)
			{
				i++;
				a++;
			}
			else if (i == 7)
			{
				i = 1;
				a++;
				t++;
			}
		}
	}
	for (int t = 0; t <= 3; t++)
	{
		head(3 * t + 1);
		for (int j = 0; j < 6; j++)
		{
			for (int p = 0; p < 3; p++)
			{
				for (int i = 1; i < 8; i++)
				{
					if (m[18 * t + j + 6 * p][i] == 0)
						cout << "    ";
					else
					{
						if (zeller(year, (18 * t + j + 6 * p) / 6 + 1, m[18 * t + j + 6 * p][i]) == 6)
							SetConsoleTextAttribute(hout,  16 + 12);
						else if (zeller(year, (18 * t + j + 6 * p) / 6 + 1, m[18 * t + j + 6 * p][i]) % 7 == 0)
							SetConsoleTextAttribute(hout, 16 + 10);
						if (m[18 * t + j + 6 * p][i] < 10)
							cout << m[18 * t + j + 6 * p][i] << "   ";
						else
							cout << m[18 * t + j + 6 * p][i] << "  ";
						SetConsoleTextAttribute(hout, 16 + 15);
					}
				}
				cout << "    ";
			}
			cout << endl << "\t";
		}
	}
	cout << endl;
	SetConsoleTextAttribute(hout, 16 + 11);
	for (int i = 0; i <= 30; i++)
		showch(hout, i % 8, i+3, '*');
	for (int i = 0; i <= 30; i++)
		showch(hout, 105 - i % 8, i+3, '*');
	gotoxy(hout, 0, 35);
	SetConsoleTextAttribute(hout, 16 + 15);
	return 0;
}
int zeller(int year, int month, int day)
{
	int date;
	if (month >= 3)
		date = year % 100 + year % 100 / 4 + year / 400 - 2 * year / 100 + 13 * (month + 1) / 5 + day - 1;
	else
	{
		month += 12;
		year -= 1;
		date = year % 100 + year % 100 / 4 + year / 400 - 2 * (year / 100) + 13 * (month + 1) / 5 + day - 1;
	}
	if (date >= 0)
		date = (date - 1) % 7 + 1;
	else
		date = (date + 6999) % 7 + 1;
	return date;
}
void head(int m)
{
	SetConsoleTextAttribute(hout, 16 + 8);
	for (int month = m; month < m + 3; month++)
	{
		if (month < 10)
		{
			if (month == m)
				cout << "            " << month << "月";
			else
				cout << "                             " << month << "月";
		}
		else
			if (month == m)
				cout << "            " << month << "月";
			else
				cout << "                            " << month << "月";
	}
	cout << endl << "\t";
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			cout << "Mon" << ' ' << "Tue" << ' ' << "Wed" << ' ' << "Thu" << ' ' << "Fri" << ' ' << "Sat" << ' ' << "Sun";
		else
			cout << "     Mon" << ' ' << "Tue" << ' ' << "Wed" << ' ' << "Thu" << ' ' << "Fri" << ' ' << "Sat" << ' ' << "Sun";
	}
	cout << endl << "\t";
}