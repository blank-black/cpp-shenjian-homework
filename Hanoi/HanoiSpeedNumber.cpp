/*1551265 ��1 �Ų���*/
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
#define disY 21
#define DisY 16
int aa[11] = { 0 }, bb[11] = { 0 }, cc[11] = { 0 }, i = 0, ii = 0;
int a_ = 18, b_ = 38, c_ = 58;
int N;
void print();
void swap(char a, char c);
void Hanoi(int n, char a, char b, char c);
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
	int  n, k;
	char A, B, C;
	cout << "������������n��n��[1��10]�ϣ���";
	cin >> n;
	while (!cin || n < 1 || n > 10)
	{
		cin.clear();
		cin.sync();
		cout << "�����������������������n[1-10]:";
		cin.ignore(1024, '\n');
		cin >> n;
	}
	cout << "��������ʼԲ������A-C��:";
	cin >> A;
	while (A != 'A' && A != 'B' && A != 'C')
	{
		cout << "�������������������ʼԲ������A-C��:";
		cin >> A;
	}
	cout << "���������Բ������A-C����";
	cin >> C;
	while (C != 'A' && C != 'B' && C != 'C' && C == A)
	{
		cout << "��������������������Բ������A-C����";
		cin >> C;
	}
	cout << "�������ƶ��ƶ��ٶȣ�0-5��0-���س�������ʾ 1-��ʱ� 5-��ʱ��̣�";
	cin >> N;
	while (!cin || N < 0 || N>5)
	{
		cin.clear();
		cin.sync();
		cout << "������������������ƶ��ƶ��ٶȣ�0-5��0-���س�������ʾ 1-��ʱ� 5-��ʱ��̣�";
		cin.ignore(1024, '\n');
		cin >> N;
	}
	if (A == 'A')
	{
		A = 'A';
		if (C == 'C')
		{
			C = 'C';
			B = 'B';
		}
		else
		{
			C = 'B';
			B = 'C';
		}
		for (i = 0; i < n; i++)
			aa[i] = n - i;
	}
	else if (A == 'B')
	{
		A = 'B';
		if (C == 'C')
		{
			C = 'C';
			B = 'A';
		}
		else
		{
			C = 'A';
			B = 'C';
		}
		for (i = 0; i < n; i++)
			bb[i] = n - i;
	}
	else
	{
		A = 'C';
		if (C == 'B')
		{
			C = 'B';
			B = 'A';
		}
		else
		{
			C = 'A';
			B = 'B';
		}
		for (i = 0; i < n; i++)
			cc[i] = n - i;
	}
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "         ============================================================" << endl;
	cout << "                  A                   B                   C          " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	cout << "                                                                     " << endl;
	for (k = 0, i = 0; i < 10; i++)
	{
		if (aa[k] != 0)
		{
			if (aa[k] == 10)
				showin(hout, a_ - 1, DisY - i, aa[k]);
			else
				showin(hout, a_, DisY - i, aa[k]);
			k++;
		}
		else
			showch(hout, a_, DisY - i, ' ');
	}
	for (k = 0, i = 0; i < 10; i++)
	{
		if (bb[k] != 0)
		{
			if (bb[k] == 10)
				showin(hout, b_ - 1, DisY - i, bb[k]);
			else
				showin(hout, b_, DisY - i, bb[k]);
			k++;
		}
		else
			showch(hout, b_, DisY - i, ' ');
	}
	for (k = 0, i = 0; i < 10; i++)
	{
		if (cc[k] != 0)
		{
			if (cc[k] == 10)
				showin(hout, c_ - 1, DisY - i, cc[k]);
			else
				showin(hout, c_, DisY - i, cc[k]);
			k++;
		}
		else
			showch(hout, c_, DisY - i, ' ');
	}
	gotoxy(hout, c_, disY);
	if (!N)
	{
		k = _getch();
		while (k != 13)
		{
			gotoxy(hout, c_, disY);
			k = _getch();
		}
	}
	else
		Sleep(625 / N / N / N / N);
	Hanoi(n, A, B, C);
	return 0;
}
void Hanoi(int n, char a, char b, char c)
{
	++ii;
	n > 1?Hanoi(n - 1, a, c, b):1;
	swap(a, c);
	gotoxy(hout, 0, disY);
	cout << "�� " << ii << "��\t" << '<' << n << ">��" << a << "--->" << c << "\t";
	print();
	n > 1?Hanoi(n - 1, b, a, c):1;
}
void swap(char a, char c)
{
	int x = 0, y = 0, z = 0;
	while (aa[x])
		x++;
	while (bb[y])
		y++;
	while (cc[z])
		z++;
	if (a == 'A')
	{
		if (c == 'B')
			bb[y] = aa[x - 1];
		else
			cc[z] = aa[x - 1];
		aa[x - 1] = 0;
	}
	else if (a == 'B')
	{
		if (c == 'A')
			aa[x] = bb[y - 1];
		else
			cc[z] = bb[y - 1];
		bb[y - 1] = 0;
	}
	else
	{
		if (c == 'A')
			aa[x] = cc[z - 1];
		else
			bb[y] = cc[z - 1];
		cc[z - 1] = 0;
	}
}
void print()
{
	int k;
	for (k = 0, i = 0; i < 10; i++)
	{
		if (aa[k] != 0)
		{
			if (aa[k] == 10)
				showin(hout, a_ - 1, DisY - i, aa[k]);
			else
				showin(hout, a_, DisY - i, aa[k]);
			k++;
		}
		else
			showch(hout, a_, DisY - i, ' ');
	}
	for (k = 0, i = 0; i < 10; i++)
	{
		if (bb[k] != 0)
		{
			if (bb[k] == 10)
				showin(hout, b_ - 1, DisY - i, bb[k]);
			else
				showin(hout, b_, DisY - i, bb[k]);
			k++;
		}
		else
			showch(hout, b_, DisY - i, ' ');
	}
	for (k = 0, i = 0; i < 10; i++)
	{
		if (cc[k] != 0)
		{
			if (cc[k] == 10)
				showin(hout, c_ - 1, DisY - i, cc[k]);
			else
				showin(hout, c_, DisY - i, cc[k]);
			k++;
		}
		else
			showch(hout, c_, DisY - i, ' ');
	}
	gotoxy(hout, c_, disY);
	if (!N)
	{
		k = _getch();
		while (k != 13)
		{
			gotoxy(hout, c_, disY);
			k = _getch();
		}
	}
	else
		Sleep(625 / N / N / N / N);
}