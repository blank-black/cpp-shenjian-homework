/* 1551265 计1 张伯阳 */
#include "ColorLinez.h"
#include "cmd_console_tools.h"
void printarr(int a[][11], int row, int line)
{
	cout << "   ";
	for (int i = 1; i <= line; i++)
		cout << "  " << i;
	cout << endl << "--+";
	for (int i = 1; i <= line; i++)
		cout << "---";
	for (int r = 1; r <= row; r++)
	{
		cout << endl << char('A' + r - 1) << " |";
		for (int l = 1; l <= line; l++)
		{
			setcolor(hout, 0, 7);
			cout << "  ";
			if (a[r][l])
				setcolor(hout, 6, a[r][l] / 7 + a[r][l] - 1);
			cout << a[r][l];
		}
		setcolor(hout, 0, 7);
	}
	cout << endl;
}

void choice1(int a[][11], int row, int line)
{
	printarr(a, row, line);
	cout << "本小题结束，请输入回车键继续..." << endl;
	while (_getch() != '\r');
}

void choice2(int a[][11], const int choice, const int row, const int line)
{
	int b[3];
	random(b);
	random_gene(a, row, line, int(proportion*row*line - 5));
	printarr(a, row, line);
	read2(a, b, choice, row, line);
}
int read2(int a[][11], int b[], const int choice, const int row, const int line)
{
	srand((unsigned)time(NULL));
	int r1, r2, l1, l2, path[11][11], arr[11][11], score = 0, num = 0;
	cout << "下3个彩球的颜色分别是：" << b[0] << " " << b[1] << " " << b[2] << endl << "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：";
	if (fun(a, path, arr, row, line, &r1, &l1, &r2, &l2))
	{
		if (choice == 2)
			print2(a, arr, row, line);
		else
		{
			a[r2][l2] = a[r1][l1];
			a[r1][l1] = 0;
			score = judge2(a, row, line, r2, l2);
		}
	}
	if (choice == 2)
	{
		cout << endl << "本小题结束，请输入回车键继续...";
		while (_getch() != '\r');
		return OK;
	}
	return score;
}
void print2(int a[][11], int arr[][11], int row, int line)
{
	int x, y;
	system("cls");
	for (int i = 1; i < row; i++)
	{
		cout << endl;
		for (int j = 1; j <= line; j++)
		{
			getxy(hout, x, y);
			if (!arr[i][j])
			{
				cout << arr[i][j] << " ";
				gotoxy(hout, x, y + 12);
				cout << a[i][j] << " ";
				gotoxy(hout, x + 2, y);
			}
			else
			{
				cout << "* ";
				gotoxy(hout, x, y + 12);
				setcolor(hout, 6, a[i][j]);
				cout << a[i][j];
				setcolor(hout, 0, 7);
				cout << " ";
				gotoxy(hout, x + 2, y);
			}
		}
	}
}

bool fun(int a[][11], int path[][11], int arr[][11], int row, int line, int *r1, int *l1, int *r2, int *l2)
{
	char c[10];
	while (1)
	{
		cin >> c;
		if (c[0]<'a' || c[0]>'a' + row - 1 || c[1]<'1' || c[1]>line + '0')
			cout << "输入错误，请重新输入.";
		else if (!a[*r1 = int(c[0] - 'a' + 1)][*l1 = int(c[1] - '0')])
			cout << "起始位置为空，请重新输入.";
		else
			break;
	}
	cout << "输入为" << char(c[0] + 'A' - 'a') << "行" << c[1] << "列" << endl << "请以字母+数字形式[例：c2]输入要移动球的目的坐标：";
	while (1)
	{
		cin >> c;
		if (c[0]<'a' || c[0]>'a' + row - 1 || c[1]<'1' || c[1]>line + '0')
			cout << "输入错误，请重新输入.";
		else if (a[*r2 = int(c[0] - 'a' + 1)][*l2 = int(c[1] - '0')])
			cout << "目标位置非空，请重新输入.";
		else
			break;
	}
	clrpa(path, arr);
	if (move(a, path, arr, *r1, *l1, *r2, *l2))
		return OK;
	cout << "无法找到移动路径";
	return ERROR;
}
