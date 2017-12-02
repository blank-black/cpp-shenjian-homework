/* 1551265 计1 张伯阳 */
#include <iostream>
using namespace std;
int zeller(int year, int month, int day);
int main()
{
	int year, month, day, d;
	bool rn = 0;
	cout << "依次输入年月日:";
	cin >> year >> month >> day;
	if (year % 400 == 0 || year % 100 && year % 4 == 0)
		rn = 1;
	while ((year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || (month == 2 && day > 28 + rn))
	{

		cout << "非法输入" << endl;
		cout << "依次重新输入年月日:";
		cin >> year >> month >> day;
		if (!cin)
		{
			cin.clear();
			cin.sync();
			cout << "输入错误 请重新输入" << endl;
			cin.ignore(1024, '\n');
			cin >> year >> month >> day;
		}
	}
	d = zeller(year, month, day);
	cout << "该天是星期";
	switch (d)
	{
	case 0:
		cout << "日" << endl; 
		break;
	case 1:
		cout << "一" << endl; 
		break;
	case 2:
		cout << "二" << endl; 
		break;
	case 3:
		cout << "三" << endl; 
		break;
	case 4:
		cout << "四" << endl; 
		break;
	case 5:
		cout << "五" << endl; 
		break;
	case 6:
		cout << "六" << endl; 
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
	d+=7000;//使d为正数 并且不影响最后%7结果 省去判断
	d %= 7;
	return d;
}