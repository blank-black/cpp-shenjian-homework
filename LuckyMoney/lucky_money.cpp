/* 1551265 ��1 �Ų��� */
#include<iostream>  
#include<time.h>  
using namespace std;
int main()
{
	double total, m;
	int tt, t, max, p, ram, num, j = 0;
	while (1)
	{
		cout << "�����ܽ��(0-200),������" << endl;
		cin >> total >> p;
		tt = int(total * 100);
		if (p > tt || p == 0 || total < 0 || total>200)
			cout << "�������" << endl;
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
			cout << "��" << i + j * 10 << "�����������Ϊ:" << m << endl;
			t -= ram;
			max -= ram - 1;
		}
		m = t*1.0 / 100;
		cout << "��" << num + j * 10 << "�����������Ϊ:" << m << endl;
		j++;
	}
	return 0;
}

