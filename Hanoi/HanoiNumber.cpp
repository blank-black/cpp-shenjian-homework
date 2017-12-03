/* 1551265 计1 张伯阳 */
#include <iostream>
using namespace std;
void hanoi(int n, char a, char b, char c);
void swap(char a, char c);
void print();
int aa[11] = { 0 }, bb[11] = { 0 }, cc[11] = { 0 }, i = 0;
int main()
{
	int  n;
	char A, B, C;
	cout << "请输入盘子数n（n在[1，10]上）：";
	cin >> n;
	while (!cin || n < 1 || n>10)
	{
		cin.clear();
		cin.sync();
		cout << "输入错误，请重新输入盘子数n（n在[1，10]上）：";
		cin.ignore(1024, '\n');
		cin >> n;
	}
	cout << "请输入起始圆柱名（A-C）：";
	cin >> A;
	while ( A != 'A' && A != 'B' && A != 'C'&&A != 'a' && A != 'b' && A != 'c') 
	{
		cout << "输入错误，请重新输入起始圆柱名（A-C）：";
		cin >> A;
	}
	cout << "请输入结束圆柱名（A-C）：";
	cin >> C;
	while ( C != 'A' && C != 'B' && C != 'C'&&C != 'a' && C != 'b' && C != 'c' && C == A) 
	{
		cout << "输入错误，请重新输入结束圆柱名（A-C）：";
		cin >> C;
	}
	if (A == 'A' || A == 'a') 
	{
		A = 'A';
		if (C == 'C' || C == 'c') 
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
	else if (A == 'B' || A == 'b') 
	{
		A = 'B';
		if (C == 'C' || C == 'c') 
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
		if (C == 'B' || C == 'b') 
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
	cout << "初始：\t\t\t\tA：";
	for (i = 0; i < 10; i++) 
	{
		if (aa[i] != 0)
			cout << aa[i] << ' ';
		else
			cout << "  ";
	}
	cout << "B：";
	for (i = 0; i < 10; i++) 
	{
		if (bb[i] != 0)
			cout << bb[i] << ' ';
		else
			cout << "  ";
	}
	cout << "C：";
	for (i = 0; i < 10; i++) 
	{
		if (cc[i] != 0)
			cout << cc[i] << ' ';
		else
			cout << "  ";
	}
	cout << endl;
	i = 0;
	hanoi(n, A, B, C);
	return 0;
}
void hanoi(int n, char a, char b, char c)
{
	if (n > 1) 
	{
		hanoi(n - 1, a, c, b);
		++i;
		swap(a, c);
		cout << "第 " << i << "步\t" << '<' << n << ">：" << a << "--->" << c << "\t";
		print();
		hanoi(n - 1, b, a, c);
	}
	else 
	{
		++i;
		swap(a, c);
		cout << "第 " << i << "步\t" << '<' << n << ">：" << a << "--->" << c << "\t";
		print();
	}
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
	int m;
	cout << "A：";
	for (m = 0; m < 10; m++) 
	{
		if (aa[m] != 0)
			cout << aa[m] << ' ';
		else
			cout << "  ";
	}
	cout << "B：";
	for (m = 0; m < 10; m++) 
	{
		if (bb[m] != 0)
			cout << bb[m] << ' ';
		else
			cout << "  ";
	}
	cout << "C：";
	for (m = 0; m < 10; m++) 
	{
		if (cc[m] != 0)
			cout << cc[m] << ' ';
		else
			cout << "  ";
	}
	cout << endl;
}