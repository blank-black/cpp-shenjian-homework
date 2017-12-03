/* 1551265 计1 张伯阳 */
#include <iostream>
using namespace std;
int main()
{
	system("mode con cols=100 lines=40");
	void head(int m);
	int zeller(int year, int month, int day), year, month;
	int m[72][7] = { 0 }, n[13];
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
	cout << year << "年的日历:" << endl;
	for (month = 1; month < 13; month++)
	{
		if (1 == month || 3 == month || 5 == month || 7 == month || 8 == month || 10 == month || 12 == month)
			n[month] = 31;
		else if (4 == month || 6 == month || 9 == month || 11 == month)
			n[month] = 30;
		if (year % 4 || !(year % 100) && year % 400)
		{
			if (month == 2)
				n[month] = 28;
		}
		else
			if (month == 2)
				n[month] = 29;
	}
	for (month = 1; month < 13; month++)
	{
		int i = zeller(year, month, 1), a = 1;
		for (int t = (month - 1) * 6; t < month * 6;t++)
		{
			while (a <= n[month])
			{
				m[t][i] = a;
				if (i < 6)
				{
					i++;
					a++;
				}
				else if (i == 6)
				{
					i = 0;
					a++;
					break;
				}
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
				for (int i = 0; i < 7; i++)
				{
					if (m[18 * t + j + 6 * p][i] == 0)
						cout << "    ";
					else
					{
						if (m[18 * t + j + 6 * p][i] < 10)
							cout << m[18 * t + j + 6 * p][i] << "   ";
						else
							cout << m[18 * t + j + 6 * p][i] << "  ";
					}
				}
				cout << "    ";
			}
			cout << endl;
		}
	}
	cout << endl;
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
		date %= 7;
	else
		date = 7 - abs(date) % 7;
	return date;
}
void head(int m)
{
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
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			cout << "Sun" << ' ' << "Mon" << ' ' << "Tue" << ' ' << "Wed" << ' ' << "Thu" << ' ' << "Fri" << ' ' << "Sat";
		else
			cout << "     Sun" << ' ' << "Mon" << ' ' << "Tue" << ' ' << "Wed" << ' ' << "Thu" << ' ' << "Fri" << ' ' << "Sat";
	}
	cout << endl;
}