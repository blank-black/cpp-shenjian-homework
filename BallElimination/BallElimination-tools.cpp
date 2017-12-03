/*1551265 计1 张伯阳*/
#include"BallElimination.h"
#include"cmd_console_tools.h"

int judge1(int a[][11], bool del[][11], int row, int line)
{
	for (int i = 0; i <= line + 1; i++)
		for (int j = 0; j <= row + 1; j++)
			del[j][i] = 0;
	for (int i = 0; i <= line + 1; i++)
		del[0][i] = 1, del[row + 1][i] = 1;
	for (int i = 0; i <= row + 1; i++)
		del[i][0] = 1, del[i][line + 1] = 1;
	int ir = 0, il = 0, i1 = 0, i2 = 0, score0 = 0;
	for (int r2 = 1; r2 <= row; r2++)
		for (int l2 = 1; l2 <= line; l2++)
		{
			ir = 0, il = 0;
			int score = 0;
			for (int j = 1; a[r2 + j][l2] == a[r2][l2]; j++, ir++);
			for (int j = 1; a[r2 - j][l2] == a[r2][l2]; j++, ir++);
			for (int j = 1; a[r2][l2 + j] == a[r2][l2]; j++, il++);
			for (int j = 1; a[r2][l2 - j] == a[r2][l2]; j++, il++);
			if (ir >= 2)
			{
				for (int j = 1; a[r2 + j][l2] == a[r2][l2]; j++)
					del[r2 + j][l2] = 1;
				for (int j = 1; a[r2 - j][l2] == a[r2][l2]; j++)
					del[r2 - j][l2] = 1;
				score += ir;
			}
			if (il >= 2)
			{
				for (int j = 1; a[r2][l2 + j] == a[r2][l2]; j++)
					del[r2][l2 + j] = 1;
				for (int j = 1; a[r2][l2 - j] == a[r2][l2]; j++)
					del[r2][l2 - j] = 1;
				score += il;
			}
			if (score)
				del[r2][l2] = 1;
			score0 += score;
		}
	return score0;
}//judge del

int judge2(int a[][11], bool mov[][11], int row, int line)
{
	for (int i = 0; i <= line + 1; i++)
		for (int j = 0; j <= row + 1; j++)
			mov[j][i] = 0;
	int ir[5] = { 0 }, il[5] = { 0 }, iu[5] = { 0 }, id[5] = { 0 }, flag = 0;
	for (int r2 = 1; r2 <= row; r2++)
		for (int l2 = 1; l2 <= line; l2++)
		{
			for (int i = 0; i < 5; i++)
				ir[i] = 0, il[i] = 0, iu[i] = 0, id[i] = 0;
			int score = 0;
			for (int j = 1; a[r2 + 1][l2] && a[r2 + 1][l2] != a[r2][l2] && a[r2 + 1 + j][l2] == a[r2][l2]; j++, ir[1]++);
			for (int j = 1; a[r2 + 1][l2] && a[r2 + 1][l2] != a[r2][l2] && a[r2 + 1][l2 + j] == a[r2][l2]; j++, ir[3]++);
			for (int j = 1; a[r2 + 1][l2] && a[r2 + 1][l2] != a[r2][l2] && a[r2 + 1][l2 - j] == a[r2][l2]; j++, ir[4]++);
			for (int j = 1; a[r2 - 1][l2] && a[r2 - 1][l2] != a[r2][l2] && a[r2 - 1 - j][l2] == a[r2][l2]; j++, il[2]++);
			for (int j = 1; a[r2 - 1][l2] && a[r2 - 1][l2] != a[r2][l2] && a[r2 - 1][l2 - j] == a[r2][l2]; j++, il[3]++);
			for (int j = 1; a[r2 - 1][l2] && a[r2 - 1][l2] != a[r2][l2] && a[r2 - 1][l2 + j] == a[r2][l2]; j++, il[4]++);
			for (int j = 1; a[r2][l2 + 1] && a[r2][l2 + 1] != a[r2][l2] && a[r2 + j][l2 + 1] == a[r2][l2]; j++, id[1]++);
			for (int j = 1; a[r2][l2 + 1] && a[r2][l2 + 1] != a[r2][l2] && a[r2 - j][l2 + 1] == a[r2][l2]; j++, id[2]++);
			for (int j = 1; a[r2][l2 + 1] && a[r2][l2 + 1] != a[r2][l2] && a[r2][l2 + 1 + j] == a[r2][l2]; j++, id[3]++);
			for (int j = 1; a[r2][l2 - 1] && a[r2][l2 - 1] != a[r2][l2] && a[r2 + j][l2 - 1] == a[r2][l2]; j++, iu[1]++);
			for (int j = 1; a[r2][l2 - 1] && a[r2][l2 - 1] != a[r2][l2] && a[r2 - j][l2 - 1] == a[r2][l2]; j++, iu[2]++);
			for (int j = 1; a[r2][l2 - 1] && a[r2][l2 - 1] != a[r2][l2] && a[r2][l2 - 1 - j] == a[r2][l2]; j++, iu[4]++);
			if (ir[1] >= 2 || ir[3] >= 2 || ir[4] >= 2)
			{
				mov[r2][l2] = 1;
				mov[r2 + 1][l2] = 1;
				flag = 1;
			}
			if (il[2] >= 2 || il[3] >= 2 || il[4] >= 2)
			{
				mov[r2][l2] = 1;
				mov[r2 - 1][l2] = 1;
				flag = 1;
			}
			if (iu[1] >= 2 || iu[2] >= 2 || iu[4] >= 2)
			{
				mov[r2][l2] = 1;
				mov[r2][l2 - 1] = 1;
				flag = 1;
			}
			if (id[1] >= 2 || id[2] >= 2 || id[3] >= 2)
			{
				mov[r2][l2] = 1;
				mov[r2][l2 + 1] = 1;
				flag = 1;
			}
		}
	return flag;
}//judge mov

int judge3(int a[][11], bool mov[][11], int x1, int y1, int x2, int y2)
{
	return (x1 == x2&&y1 == y2 + 1 || x1 == x2&&y1 == y2 - 1 || x1 == x2 + 1 && y1 == y2 || x1 == x2 - 1 && y1 == y2) && mov[x1][y1] && mov[x2][y2];
}//judge switch

int judge4(int a[][11], bool del[][11], bool mov[][11], int choice, int row, int line, int score0)
{
	if (choice7(a, del, mov, choice, row, line, 0) == -1)//not add score in the beginning
	{
		gotoxy(hout, 0, 2 * row + 4);
		cout << "游戏结束 最终得分:" << score0 << endl;
		return 1;
	}
	return 0;
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void tapeenter(int row, int choice)
{
	if (choice == 7)
	{
		gotoxy(hout, 1, 2 * row + 4);
		setcolor(hout, 0, 7);
		cout << "输入回车键继续";
		while (_getch() != '\r');
		gotoxy(hout, 1, 2 * row + 4);
		cout << endl;
	}
}

void showin(HANDLE hout, int X, int Y, int A, const int bg_color, const int fg_color)
{
	gotoxy(hout, X, Y);
	setcolor(hout, bg_color, fg_color);
	cout << A;
}

void showdb(HANDLE hout, int X, int Y, double A, const int bg_color, const int fg_color)
{
	gotoxy(hout, X, Y);
	setcolor(hout, bg_color, fg_color);
	printf("%.2f", A);
}

int input_dat(int a[][11], bool mov[][11], int *line, int *row,char name[])
{
	ifstream fin;
	fin.open(name, ios::in);
	if (!fin.is_open())
	{
		cout << "无法打开" << endl;
		return -1;
	}
	char l[4], r[4], str[4];
	fin >> l >> r;
	*line = l[0] - '0';
	*row = r[0] - '0';
	for (int i = 1; i <= *row; i++)
		for (int j = 1; j <= *line; j++)
		{
			fin >> str;
			a[j][i] = str[0] - '0';
		}
	fin.close();
	return 0;
}

int input_ans(int a[][11], bool mov[][11],int line, int row,char name[])
{
	ifstream fin;
	fin.open(name, ios::in);
	if (!fin.is_open())
	{
		cout << "无法打开" << endl;
		return -1;
	}
	char str[4];
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= line; j++)
		{
			fin >> str;
			if (!str[1])
				a[j][i] = str[0] - '0';
			else
				a[j][i] = (str[0] - '0') * 10 + str[1] - '0';
		}
	fin.close();
	return 0;
}
