/* 1551265 计1 张伯阳 */
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
#define disY1 21
#define DisY1 26
#define disY2 31
#define DisY2 34
#define a_  18
#define b_  38
#define c_  58

int aa[11], bb[11], cc[11] , i , ii ;

void read(int *n, char *A, char *B, char *C); 
void word(int *n, char *A, char *B, char *C);
void Hanoi(int choice, int n, char a, char b, char c, int N);
void print(int choice, int n, char a, char b, char c, int N);
void print1(int choice, int n, char a, char b, char c);
void print3(int choice, int n, char a, char b, char c);
void print4(int choice, int n, char a, char b, char c, int N);
void print5();
void print6(int n);
void print7(int choice, char a, char c); 
void print9(int n, char a, char b, char c);
void up(int choice, int ax, int I, int color, int fg_color, int LENGTH, char a, char ch);
void trans(int choice, int I, int color, int fg_color, int LENGTH, char a, char c, char ch);
void down(int choice, int x, int y, int z, int I, int color, int fg_color, int LENGTH, char c, char ch);
void swap(char a, char c);
int judge(char a, char c);
void showin(HANDLE hout, int X, int Y, int A)
{
	gotoxy(hout, X, Y);
	cout << A;
}

int main()
{
	system("mode con cols=100 lines=50");
	while (1)
	{
		cout << "----------------------------------" << endl;
		cout << "1.基本解\n2.基本解(步数记录)\n3.内部数组显示(横向)\n4.内部数组显示(纵向+横向)\n5.图形解-预备-画三个圆柱\n6.图形解-预备-在起始柱上画n个盘子\n7.图形解-预备-第一次移动\n8.图形解-自动移动版本\n9.图形解-游戏版\n0.退出" << endl;
		cout << "----------------------------------" << endl;
		int choice, n, N = 1;
		for (int j = 0; j <= 10; j++)
			aa[j] = 0, bb[j] = 0, cc[j] = 0;
		i = 0, ii = 0;
		char A, B, C;
		while (1)
		{
			cout << "[请选择0-9]";
			cin >> choice;
			if (!cin || choice < 0 || choice>9)
			{
				cin.clear();
				cin.sync();
				cin.ignore(1024, '\n');
			}
			else
				break;
		}
		if (!choice)
			return 0;
		else if (choice != 5)
			read(&n, &A, &B, &C);
		if (choice == 4 || choice == 8)
		{
			cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短)";
			cin >> N;
		}
		system("cls");
		if (choice == 9||choice==6||choice==7)
			print(choice, n, A, B, C, N);
		else if (choice == 5)
			print5();
		else
			Hanoi(choice, n, A, B, C, N);
		showch(hout, 10, DisY2+3, ' ', COLOR_BLACK, COLOR_WHITE, 1);
		cout << "输入回车返回";
		while (_getch() != '\r');
		system("cls");
	}
}

void read(int *n, char *A, char *B, char *C)
{
	cout << "请输入盘子数n（n在[1，10]上）：";
	cin >> *n;
	while (!cin || *n < 1 || *n>10)
	{
		cin.clear();
		cin.sync();
		cout << "输入错误，请重新输入盘子数n（n在[1，10]上）：";
		cin.ignore(1024, '\n');
		cin >> *n;
	}
	cout << "请输入起始圆柱名（A-C）：";
	cin >> *A;
	while (*A != 'A' && *A != 'B' && *A != 'C'&&*A != 'a' && *A != 'b' && *A != 'c')
	{
		cout << "输入错误，请重新输入起始圆柱名（A-C）：";
		cin >> *A;
	}
	cout << "请输入结束圆柱名（A-C）：";
	cin >> *C;
	while (*C != 'A' && *C != 'B' && *C != 'C'&&*C != 'a' && *C != 'b' && *C != 'c' && *C == *A)
	{
		cout << "输入错误，请重新输入结束圆柱名（A-C）：";
		cin >> C;
	}
	word(n, A, B, C);
}

void word(int *n, char *A, char *B, char *C)
{
	if (*A == 'A' || *A == 'a')
	{
		*A = 'A';
		if (*C == 'C' || *C == 'c')
		{
			*C = 'C';
			*B = 'B';
		}
		else
		{
			*C = 'B';
			*B = 'C';
		}
		for (i = 0; i < *n; i++)
			aa[i] = *n - i;
	}
	else if (*A == 'B' || *A == 'b')
	{
		*A = 'B';
		if (*C == 'C' || *C == 'c')
		{
			*C = 'C';
			*B = 'A';
		}
		else
		{
			*C = 'A';
			*B = 'C';
		}
		for (i = 0; i < *n; i++)
			bb[i] = *n - i;
	}
	else
	{
		*A = 'C';
		if (*C == 'B' || *C == 'b')
		{
			*C = 'B';
			*B = 'A';
		}
		else
		{
			*C = 'A';
			*B = 'B';
		}
		for (i = 0; i < *n; i++)
			cc[i] = *n - i;
	}
}

void Hanoi(int choice, int n, char a, char b, char c, int N)
{
	n > 1 ? Hanoi(choice, n - 1, a, c, b, N) : 1;
	++ii;
	swap(a, c);
	choice == 4 ? gotoxy(hout, 0, 51) : 1;
	print(choice, n, a, b, c, N);
	n > 1 ? Hanoi(choice, n - 1, b, a, c, N) : 1;
}

void print(int choice, int n, char a, char b, char c, int N)
{
	if (choice < 3)
		print1(choice, n, a, b, c);
	else if (choice == 3)
		print3(choice, n, a, b, c);
	else if (choice == 4)
		print4(choice, n, a, b, c, N);
	else if (choice > 4)
	{

		if (ii <= 1)
		{
			print5();
			print6(n);
		}
		else if (choice==7||choice==8)
			print7(choice, a, c);
		if (choice==8)
			print4(choice, n, a, b, c, N);
		if (choice == 9)
		{
			print4(choice, n, a, b, c, 1);
			print9(n, a, b, c);
		}
	}
}

void print1(int choice, int n, char a, char b, char c)
{
	if (choice == 1)
		cout << n << "# " << a << "--->" << c << "\n";
	else
		cout << "第 " << ii << "\t步" << '(' << n << ")：" << a << "--->" << c << "\n";
}

void print3(int choice, int n, char a, char b, char c)
{
	if (choice == 8)
		gotoxy(hout, 10, DisY2+1);
	cout << "第 " << ii << "\t步" << '(' << n << ")：" << a << "--->" << c << "\t";
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

void print4(int choice, int n, char a, char b, char c, int N)
{
	int k, DisY, disY;
	if (choice == 4)
		DisY = DisY1, disY = disY1;
	else
		DisY = DisY2, disY = disY2;
	showch(hout, 0, DisY, ' ', COLOR_BLACK, COLOR_WHITE, 1);
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
		Sleep(625 / N ^ 5);
	gotoxy(hout, 0, DisY + 2);
	print3(choice, n, a, b, c);
}

void print5()
{
	showch(hout, a_ - 11, 15, ' ',14, 15,  23);
	Sleep(100);
	showch(hout, b_ - 11, 15, ' ',14, 15,  23);
	Sleep(100);
	showch(hout, c_ - 11, 15, ' ',14, 15,  23);
	Sleep(100);
	int y;
	for (y = 14; y > 2; y--)
	{
		showch(hout, a_, y, ' ',14, 15,  1);
		showch(hout, b_, y, ' ',14, 15,  1);
		showch(hout, c_, y, ' ',14, 15,  1);
		Sleep(100);
	}
}

void print6(int n)
{
	int color, k, j;
	for (color = 10, k = 0, j = 0; j < 10; j++) {
		if (aa[k] != 0) {
			showch(hout, a_ - aa[k], 14 - j,' ', color, 15,  2 * aa[k] + 1);
			k++;
			color--;
			Sleep(100);
		}
	}
	for (color = 10, k = 0, j = 0; j < 10; j++) {
		if (bb[k] != 0) {
			showch(hout, b_ - bb[k], 14 - j,' ', color, 15,  2 * bb[k] + 1);
			k++;
			color--;
			Sleep(100);
		}
	}
	for (color = 10, k = 0, j = 0; j < 10; j++) {
		if (cc[k] != 0) {
			showch(hout, c_ - cc[k], 14 - j,' ', color, 15,  2 * cc[k] + 1);
			k++;
			color--;
			Sleep(100);
		}
	}
}

void print7(int choice, char a, char c)
{
	int color = 0, x = 0, y = 0, z = 0, I = 0;
	while (aa[x])
		x++;
	while (bb[y])
		y++;
	while (cc[z])
		z++;
	const int LENGTH = 1;
	const int fg_color = 15;
	const char ch = ' ';
	int ax;
	if (a == 'A'||a=='a')
		ax = x;
	else if (a == 'B'||a=='b')
		ax = y;
	else if (a == 'C'||a=='c')
		ax = z;
	up(choice, ax, I, color, fg_color, LENGTH, a, ch);
	trans(choice, I, color, fg_color, LENGTH, a, c, ch);
	down(choice, x, y, z, I, color, fg_color, LENGTH, a, ch);
	if (choice == 7)
		exit(0);
}

void print9(int n, char a, char b, char c)
{
	char cha[2];
	int j;
	while (1)
	{
		gotoxy(hout, 10, 95);
		cout << "请输入移动的柱号(命令形式：AC = A顶端的盘子移动到C) ：";
		cin >> cha;
		if (judge(a, c) == 1)
		{
			swap(cha[0], cha[1]);
			ii++;
			print4(9, n, a, b, c, 1);
			print7(9, a, c);
			for (j = 0; j < n; j++)
				if (!cc[j])
					break;
			if (j == n)
			{
				cout << "游戏结束!";
				break;
			}
		}
		else if (!judge(a, c))
			cout << "大盘压小盘,非法移动!";
		else
			cout << "源柱为空!";
	}
}

void up(int choice, int ax, int I, int color, int fg_color, int LENGTH, char a, char ch)
{
	for (int k = 14; k > ax + 1; k--) {
		if (a == 'A'||a=='a')
			showch(hout, a_ - I, k - ax - 1, ch,color, fg_color,  LENGTH);
		else if (a == 'B'||a=='b')
			showch(hout, b_ - I, k - ax - 1, ch,color, fg_color,  LENGTH);
		else if (a == 'C'||a=='c')
			showch(hout, c_ - I, k - ax - 1, ch,color, fg_color,  LENGTH);
		choice != 9 ? Sleep(20) : 1;
		if (k > ax && (a == 'A'||a=='a')) {
			showch(hout, a_ - I, k - ax - 1, ch,0, 7,  LENGTH);
			if (k > ax + 3)
				showch(hout, a_, k - ax - 1, ch,14, 15,  1);
		}
		else if (k > ax && (a == 'B'||a=='b')) {
			showch(hout, b_ - I, k - ax - 1, ch,0, 7,  LENGTH);
			if (k > ax + 3)
				showch(hout, b_, k - ax - 1, ch,14, 15,  1);
		}
		else if (k > ax && (a == 'C'||a=='c')) {
			showch(hout, c_ - I, k - ax - 1, ch,0, 7,  LENGTH);
			if (k > ax + 3)
				showch(hout, c_, k - ax - 1, ch,14, 15,  1);
		}
	}
}//上移

void trans(int choice, int I, int color, int fg_color, int LENGTH, char a, char c, char ch)
{
	if (a == 'A'||a=='a') {
		if (c == 'B'||c=='b')
			for (int k = a_ - I; k < b_ - I + 1; k++) {
				showch(hout, k, 1, ch,color, fg_color,  LENGTH);
				choice != 9 ? Sleep(50) : 1;
				if (k < b_ - I)
					showch(hout, k, 1, ch,0, 7,  LENGTH);
			}
		else
			for (int k = a_ - I; k < c_ - I + 1; k++) {
				showch(hout, k, 1, ch, color, fg_color, LENGTH);
				choice != 9 ? Sleep(50) : 1;
				if (k < c_ - I)
					showch(hout, k, 1, ch,0, 7,  LENGTH);
			}
	}
	else if (a == 'B'||a=='b') {
		if (c == 'C'||c=='c')
			for (int k = b_ - I; k < c_ - I + 1; k++) {
				showch(hout, k, 1, ch, color, fg_color, LENGTH);
				choice != 9 ? Sleep(50) : 1;
				if (k < c_ - I)
					showch(hout, k, 1, ch,0, 7,  LENGTH);
			}
		else {
			for (int k = b_ - I; k > a_ - I + 1; k--) {
				showch(hout, k, 1, ch,color, fg_color,  LENGTH);
				choice != 9 ? Sleep(50) : 1;
				if (k > a_ - I)
					showch(hout, k, 1,ch, 0, 7,  LENGTH);
			}
		}
	}
	else {
		if (c == 'A'||c=='a')
			for (int k = c_ - I; k > a_ - I + 1; k--) {
				showch(hout, k, 1, ch,color, fg_color,  LENGTH);
				choice != 9 ? Sleep(50) : 1;
				if (k > a_ - I)
					showch(hout, k, 1, ch,0, 7,  LENGTH);
			}
		else {
			for (int k = c_ - I; k > b_ - I + 1; k--) {
				showch(hout, k, 1, ch,color, fg_color,  LENGTH);
				choice != 9 ? Sleep(50) : 1;
				if (k > b_ - I)
					showch(hout, k, 1, ch,0, 7,  LENGTH);
			}
		}
	}//平移
}

void down(int choice, int x, int y, int z, int I, int color, int fg_color, int LENGTH, char c, char ch)
{
	int cx;
	if (c == 'A'||c=='a')
		cx = x;
	else if (c == 'B'||c=='b')
		cx = y;
	else if (c == 'C'||c=='c')
		cx = z;
	for (int k = 1; k < 15 - cx; k++) {
		if (c == 'A'||c == 'a')
			showch(hout, a_ - I, k,ch, color, fg_color,  LENGTH);
		else if (c == 'B' || c == 'b')
			showch(hout, b_ - I, k, ch,color, fg_color,  LENGTH);
		else if (c == 'C'|| c == 'c')
			showch(hout, c_ - I, k, ch,color, fg_color,  LENGTH);
		choice != 9 ? Sleep(20) : 1;
		if (k < 14 - cx && (c == 'A'|| c == 'a')) {
			showch(hout, a_ - I, k, ch,0, 7,  LENGTH);
			if (k > 2)
				showch(hout, a_, k, ch,14, 15,  1);
		}
		else if (k < 14 - cx && (c == 'B' || c == 'b')) {
			showch(hout, b_ - I, k, ch,0, 7,  LENGTH);
			if (k > 2)
				showch(hout, b_, k,  ch,14, 15, 1);
		}
		else if (k < 14 - cx &&( c == 'C' || c == 'c')) {
			showch(hout, c_ - I, k, ch,0, 7,  LENGTH);
			if (k > 2)
				showch(hout, c_, k, ch,14, 15,  1);
			Sleep(100);
		}
	}
	gotoxy(hout, 0, 20);
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
	if (a == 'A'||a=='a')
	{
		if (c == 'B'||c=='b')
			bb[y] = aa[x - 1];
		else
			cc[z] = aa[x - 1];
		aa[x - 1] = 0;
	}
	else if (a == 'B' || a == 'b')
	{
		if (c == 'A'||c=='a')
			aa[x] = bb[y - 1];
		else
			cc[z] = bb[y - 1];
		bb[y - 1] = 0;
	}
	else
	{
		if (c == 'A'||c=='a')
			aa[x] = cc[z - 1];
		else
			bb[y] = cc[z - 1];
		cc[z - 1] = 0;
	}
}

int judge(char a, char c)
{
	int x = 0, y = 0, z = 0;
	while (aa[x])
		x++;
	while (bb[y])
		y++;
	while (cc[z])
		z++;
	if (a == 'A' || a == 'a')
	{
		if (!x)
			return -1;
		else if (c == 'B' || c == 'b')
			return bb[y - 1] < aa[x - 1] ? 1 : 0;
		else
			return cc[z - 1] < aa[x - 1] ? 1 : 0;
	}
	else if (a == 'B' || a == 'b')
	{
		if (!y)
			return -1;
		else if (c == 'A' || c == 'a')
			return aa[x - 1] < bb[y - 1] ? 1 : 0;
		else
			return bb[y - 1] < cc[z - 1] ? 1 : 0;
	}
	else
	{
		if (!z)
			return -1;
		else if (c == 'A'||c=='a')
			return aa[x - 1] < cc[z - 1] ? 1 : 0;
		else
			return bb[y - 1] < cc[z - 1] ? 1 : 0;
	}
}