/* 1551265 计1 张伯阳 */
#include "ColorLinez.h"
#include "cmd_console_tools.h"

void clr(int a[][11], const int row, const int line)
{
	for (int i = 1; i < 11; i++)
		for (int j = 1; j < 11; j++)
			a[i][j] = -1;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= line; j++)
			a[i][j] = 0;
}
void random_gene(int a[][11], const int row, const int line, const int num)
{
	srand((unsigned)time(NULL));
	for (int i = 0, b, c; i < num; i++)
		while (1)
			if (!a[b = (rand()*rand()) % row + 1][c = rand() % line + 1])//确认为空位
			{
				a[b][c] = (rand() / 2) % 7 + 1;//避免取得rand相同
				break;
			}
}
int move(int a[][11], int path[][11], int arr[][11], int r1, int l1, int r2, int l2)
{
	path[r1][l1] = 1;
	arr[r1][l1] = 1;
	int b;
	if (b = dfs(a, path, arr, r1, l1, r2, l2, 'l'))
		return b;
	if (b = dfs(a, path, arr, r1, l1, r2, l2, 'r'))
		return b;
	if (b = dfs(a, path, arr, r1, l1, r2, l2, 'd'))
		return b;
	return dfs(a, path, arr, r1, l1, r2, l2, 'u');
}

int dfs(int a[][11], int path[][11], int arr[][11], int r1, int l1, int r2, int l2, const char c)
{
	int t;
	if (r1 == r2&&l1 == l2)
	{
		arr[r1][l1] = 1;
		return OK;
	}
	if (c != 'r' && !a[r1 - 1][l1] && !path[r1 - 1][l1])/*若左侧可以走并且没走过*/
	{
		path[r1][l1] = 1;
		if (t = dfs(a, path, arr, r1 - 1, l1, r2, l2, 'l'))
		{
			arr[r1][l1] = t + 1;
			return t + 1;
		}
	}
	if (c != 'l' && !a[r1 + 1][l1] && !path[r1 + 1][l1])/*若右侧可以走并且没走过*/
	{
		path[r1][l1] = 1;
		if (t = dfs(a, path, arr, r1 + 1, l1, r2, l2, 'r'))
		{
			arr[r1][l1] = t + 1;
			return t + 1;
		}
	}
	if (c != 'u' && !a[r1][l1 + 1] && !path[r1][l1 + 1])/*若下侧可以走并且没走过*/
	{
		path[r1][l1] = 1;
		if (t = dfs(a, path, arr, r1, l1 + 1, r2, l2, 'd'))
		{
			arr[r1][l1] = t + 1;
			return t + 1;
		}
	}
	if (c != 'd' && !a[r1][l1 - 1] && !path[r1][l1 - 1])/*若上侧可以走并且没走过*/
	{
		path[r1][l1] = 1;
		if (t = dfs(a, path, arr, r1, l1 - 1, r2, l2, 'u'))
		{
			arr[r1][l1] = t + 1;
			return t + 1;
		}
	}
	return ERROR;
}
int judge1(int a[][11], int row, int line, int r2, int l2)
{
	int ir = 0, il = 0, i1 = 0, i2 = 0, flag = 0, score = 0;
	for (int j = 1; a[r2 + j][l2] == a[r2][l2]; j++, ir++);
	for (int j = 1; a[r2 - j][l2] == a[r2][l2]; j++, ir++);
	for (int j = 1; a[r2][l2 + j] == a[r2][l2]; j++, il++);
	for (int j = 1; a[r2][l2 - j] == a[r2][l2]; j++, il++);
	for (int j = 1; a[r2 - j][l2 - j] == a[r2][l2]; j++, i1++);
	for (int j = 1; a[r2 + j][l2 + j] == a[r2][l2]; j++, i1++);
	for (int j = 1; a[r2 + j][l2 - j] == a[r2][l2]; j++, i2++);
	for (int j = 1; a[r2 - j][l2 + j] == a[r2][l2]; j++, i2++);
	if (ir >= 4)
	{
		for (int j = 1; a[r2 + j][l2] == a[r2][l2]; j++)
			a[r2 + j][l2] = 0;
		for (int j = 1; a[r2 - j][l2] == a[r2][l2]; j++)
			a[r2 - j][l2] = 0;
		flag = 1;
		score += ir*(ir - 1);
	}
	if (il >= 4)
	{
		for (int j = 1; a[r2][l2 + j] == a[r2][l2]; j++)
			a[r2][l2 + j] = 0;
		for (int j = 1; a[r2][l2 - j] == a[r2][l2]; j++)
			a[r2][l2 - j] = 0;
		flag = 1;
		score += il*(il - 1);
	}
	if (i1 >= 4)
	{
		for (int j = 1; a[r2 + j][l2 + j] == a[r2][l2]; j++)
			a[r2 + j][l2 + j] = 0;
		for (int j = 1; a[r2 - j][l2 - j] == a[r2][l2]; j++)
			a[r2 - j][l2 - j] = 0;
		flag = 1;
		score += i1*(i1 - 1);
	}
	if (i2 >= 4)
	{
		for (int j = 1; a[r2 - j][l2 + j] == a[r2][l2]; j++)
			a[r2 - j][l2 + j] = 0;
		for (int j = 1; a[r2 + j][l2 - j] == a[r2][l2]; j++)
			a[r2 + j][l2 - j] = 0;
		flag = 1;
		score += i2*(i2 - 1);
	}

	if (flag)
		a[r2][l2] = 0;
	return score;
}

int judge2(int a[][11], int row, int line, int r2, int l2)
{
	int num = 0, score = 0;
	score = judge1(a, row, line, r2, l2);
	if (!score)
	{
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= line; j++)
				if (!a[i][j])
					num++;
		if (num <= 3)
		{
			for (int i = 1; i <= row; i++)
				for (int j = 1; j <= line; j++)
					if (!a[i][j])
						a[i][j] = 1;
			score = -1;
		}
	}
	return score;
}
void clrpa(int path[][11], int arr[][11])
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			path[i][j] = 0, arr[i][j] = 0;
}
void choice37(int a[][11], const int choice, int row, int line)
{
	int score0 = 0, b[3], c, d, x, y, score = 0, score_ = 0, dead[8] = { 0 }, last[8] = { 0 }, choose[2] = { 0 }, choose_[2] = { 0 };
	random(b);
	system("cls");
	choice == 7 || choice == 8 ? setconsoleborder(hout, 4 * row + 35, 2 * line + 6, 2 * line + 6), setfontsize(hout, L"新宋体", 24) : 1;
	while (1)
	{
		if (choice == 3)
		{
			printarr(a, row, line);
			score = read2(a, b, choice, row, line);
		}
		else
		{
			print45_1(a, choice, row, line);
			print7(a, b, dead, last, score0, row, line);
			if (choose[0] && !score)
				showstr(hout, (choose[0] - 1) * 4 + 3, 2 * choose[1], str_, a[choose[1]][choose[0]] - 1, 15);
			else if (score)
				choose[0] = 0, choose[1] = 0;
			score = 0;
			cout << (score = mouse(a, choice, b, dead, last, choose, choose_, x, y, row, line));
			setcolor(hout, 0, 7);
		}
		if (score == -1 || score == -2)
			break;
		if (score == -3)
		{
			clr(a, row, line);
			random_gene(a, row, line, initial);
			choice37(a, choice, row, line);
		}
		if (!score)
		{
			for (int i = 0; i < 3; i++)
				while (1)
					if (!a[c = (rand()*rand()) % row + 1][d = rand() % line + 1])
					{
						a[c][d] = b[i];
						break;
					}
			random(b);
		}
		score0 += score;
		if (choice == 3)
			cout << "本次得分:" << score << "\t总得分:" << score0 << endl;
	}
	if (choice == 7)
	{
		print45_1(a, choice, row, line);
		print7(a, b, dead, last, score0, row, line);
	}
	setcursor(hout, CURSOR_VISIBLE_NORMAL);	//打开光标
	setcolor(hout, 0, 7);
	gotoxy(hout, 1, 2 * row + 4);
	if (score == -1)
		cout << "游戏结束 最终得分:" << score0 << endl;
	cout << "本小题结束，请输入回车键继续...";
	while (_getch() != '\r');
	setfontsize(hout, L"新宋体", 18);
}
void random(int b[])
{
	for (int i = 0; i < 3; i++)
		b[i] = rand() % 7 + 1;
}
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
