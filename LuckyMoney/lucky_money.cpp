/* 1551265 计1 张伯阳 */
#include<iostream>  
#include<time.h>  
using namespace std;
int main()
{
	double total, m;
	int tt, t, max, p, ram, num, j = 0;
	while (1)
	{
		cout << "输入总金额(0-200),总人数" << endl;
		cin >> total >> p;
		tt = int(total * 100);
		if (p > tt || p == 0 || total < 0 || total>200)
			cout << "输入错误" << endl;
		else
			break;
	}
	srand((unsigned int)time(NULL));
	num = p;
	t = tt;
	int s = t / ((p / 10) + 1);
	if (s < 10)
		s = 10;
	while (p)
	{
		if (p > 10)
		{
			t = s;
			num = 10;
		}
		else
		{
			t = tt;
			num = p;
		}
		p -= num;
		tt -= t;
		max = t - num + 1;
		for (int i = 1; num > i; i++)
		{
			while (1)
			{
				ram = rand() % (max + 1) - rand() % (max);
				if (ram > 0 && ram <= max)
					break;
			}
			m = ram*1.0 / 100;
			cout << "第" << i + j * 10 << "个人抢到金额为:" << m << endl;
			t -= ram;
			max -= ram - 1;
		}
		m = t*1.0 / 100;
		cout << "第" << num + j * 10 << "个人抢到金额为:" << m << endl;
		j++;
	}
	return 0;
}

