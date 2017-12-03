/*1551265 计1 张伯阳*/
#include "90-b2.h"

int console_file(char file[][20], int line)
{
	setcursor(hout, CURSOR_INVISIBLE);
	int i, j = 0, k;
	const int l = 2 + 4 * 9;
	const int r = 2 + 2 * 9;
	gotoxy(hout, l + 6, 2);
	cout << "数独文本文件";
	gotoxy(hout, l + 4, 3);
	cout << "╔══════════╗";
	for (i = 0; i < 5; i++)
		if (i != line - 1&&line)
		{
			gotoxy(hout, l + 4, 4 + i);
			cout << "║" << setw(20) << setiosflags(ios::left) << file[i] << "║";
		}
		else
			break;
	gotoxy(hout, l + 4, 4 + i);
	cout << "╚══════════╝";
	if (line == 0)
		return -1;
	gotoxy(hout, l + 6, 4);
	setcolor(hout, 7, 0);
	cout << setw(20) << setiosflags(ios::left) << file[0];
	while (1)
	{
		int a, b;
		a = _getch();
		if (a == 13)
			return j;
		else if (a == 224)
			b = _getch();
		while (a != 224 || (b != 72 && b != 75 && b != 77 && b != 80))
		{
			cin.clear();
			cin.sync();
			a = _getch();
			if (a == 13)
				return j;
			else if (a == 224)
				b = _getch();
		}
		if (b == 72)
		{
			if (j > 0)
			{
				if (j > i - 5)
				{
					if (i <= 5)
						gotoxy(hout, l + 6, 4 + j);
					else
						gotoxy(hout, l + 6, 9 + j - i);
					setcolor(hout, 0, 7);
					cout << setw(20) << setiosflags(ios::left) << file[j];
					j--;
					if (i < 5)
						gotoxy(hout, l + 6, 4 + j);
					else
						gotoxy(hout, l + 6, 9 + j - i);
					setcolor(hout, 7, 0);
					cout << setw(20) << setiosflags(ios::left) << file[j];
				}
				else if (j == i - 5)
				{
					j--, i--;
					for (k = j; k < j + 5; k++)
						if (strcmp(file[k], "NULL"))
						{
							gotoxy(hout, l + 6, 4 + k - j);
							setcolor(hout, 0, 7);
							cout << setw(20) << setiosflags(ios::left) << file[k];
						}
						else
							break;
					gotoxy(hout, l + 6, 4);
					setcolor(hout, 7, 0);
					cout << setw(20) << setiosflags(ios::left) << file[j];
				}
			}
		}
		else if (b == 80)
		{
			if (j < line - 2)
			{
				if (j < i - 1)
				{
					if (i <= 5)
						gotoxy(hout, l + 6, 4 + j);
					else
						gotoxy(hout, l + 6, 9 + j - i);
					setcolor(hout, 0, 7);
					cout << setw(20) << setiosflags(ios::left) << file[j];
					j++;
					if (i <= 5)
						gotoxy(hout, l + 6, 4 + j);
					else
						gotoxy(hout, l + 6, 9 + j - i);
					setcolor(hout, 7, 0);
					cout << setw(20) << setiosflags(ios::left) << file[j];
				}
				else if (j == i - 1)
				{
					j++;
					i++;
					for (k = 0; k < 5; k++)
						if (strcmp(file[j - 4 + k], "NULL"))
						{
							gotoxy(hout, l + 6, 4 + k);
							setcolor(hout, 0, 7);
							cout << setw(20) << setiosflags(ios::left) << file[j - 4 + k];
						}
						else
							break;
					gotoxy(hout, l + 6, 8);
					setcolor(hout, 7, 0);
					cout << setw(20) << setiosflags(ios::left) << file[j];
				}
			}
		}
	}
	return 0;
}

void showch_(const HANDLE hout, const char ch, const int bg_color, const int fg_color)
{
	setcolor(hout, bg_color, fg_color);
	cout << ch;
}

void print_pre(int a[][11], bool err[][11], bool err_x[], bool err_y[], bool err_squa[])
{
	int i, j, l = 2 + 4 * 9, r = 2 + 2 * 9;
	gotoxy(hout, 4, 3);
	setcolor(hout, 15, 0);
	for (i = 1; i < r; i++)
	{
		for (j = 0; j < l; j += 2)
		{
			gotoxy(hout, j + 4, i + 2);
			if (i == 1 && j == 0)
				cout << "╔";
			else if (i == 1 && j == l - 2)
				cout << "╗";
			else if (i == r - 1 && j == 0)
				cout << "╚";
			else if (i == r - 1 && j == l - 2)
				cout << "╝";
			else if (j == 0 || j == l - 2)
			{
				if (i % 2 == 1 && j == 0)
				{
					if (i % 6 == 1)
						cout << "╠";
					else
						cout << "╟";
				}
				else if (i % 2 == 1 && j == l - 2)
				{
					if (i % 6 == 1)
						cout << "╣";
					else
						cout << "╢";
				}
				else
					cout << "║";
			}
			else if (i == 1 || i == r - 1)
			{
				if (j % 4 == 0 && i == 1)
				{
					if (j % 12 == 0)
						cout << "╦";
					else
						cout << "╤";
				}
				else if (j % 4 == 0 && i == r - 1)
				{
					if (j % 12 == 0)
						cout << "╩";
					else
						cout << "╧";
				}
				else
					cout << "═";
			}
			else if (j % 4 == 0 || i % 2 == 1)
			{
				if (j % 4 == 0 && i % 2 == 1)
				{
					if (j % 12 == 0 && i % 6 == 1)
						cout << "╬";
					else if (j % 12 == 0 && i % 6 != 1)
						cout << "╫";
					else if (j % 12 && i % 6 == 1)
						cout << "╪";
					else
						cout << "┼";
				}
				else if (j % 4 == 0 && i % 2 != 1)
				{
					if (j % 12 == 0)
						cout << "║";
					else
						cout << "│";
				}
				else
				{
					if (i % 6 == 1)
						cout << "═";
					else
						cout << "─";
				}
			}
			else
				cout << "  ";
		}
	}
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
			if (!(a[j][i] % 10) && (err_x[i] || err_y[j] || err_squa[((i - 1) / 3) * 3 + (j - 1) / 3]))
				showch(hout, 4 * j + 2, 2 * i + 2, a[j][i] % 10 + '0', 14, 1);
			else if (!(a[j][i] % 10))
				showch(hout, 4 * j + 2, 2 * i + 2, a[j][i] % 10 + '0', 15, 1);
			else if (a[j][i]<10 && (err_x[i] || err_y[j] || err_squa[((i - 1) / 3) * 3 + (j - 1) / 3]))
				showch(hout, 4 * j + 2, 2 * i + 2, a[j][i] % 10 + '0', 14, 8);
			else if (a[j][i]<10)
				showch(hout, 4 * j + 2, 2 * i + 2, a[j][i] % 10 + '0', 15, 8);
			else if (!err[j][i] && (err_x[i] || err_y[j] || err_squa[((i - 1) / 3) * 3 + (j - 1) / 3]))
				showch(hout, 4 * j + 2, 2 * i + 2, a[j][i] % 10 + '0', 14, 2);
			else if (err[j][i])
				showch(hout, 4 * j + 2, 2 * i + 2, a[j][i] % 10 + '0', 14, 12);
			else
				showch(hout, 4 * j + 2, 2 * i + 2, a[j][i] % 10 + '0', 15, 2);
	setcolor(hout, 0, 7);
	for (int i = 1; i <= 9; i++)
	{
		gotoxy(hout, 2 + 4 * i, 2);
		cout << char('a' + i - 1);
		gotoxy(hout, 2, 2 + 2 * i);
		cout << i;
	}
}

void choice2(int a[][11])
{
	bool err[11][11], err_x[11] = { 0 }, err_y[11] = { 0 }, err_squa[9] = { 0 }, ok = 0;
	memset(err, 0, sizeof(err));
	step *p, *head, *q;
	if (read_pre(a, err, err_x, err_y, err_squa))
		return;
	head = p = q = new step;
	if (head == NULL)
		return;
	int num = 0;
	while (1)
	{
		print_pre(a, err, err_x, err_y, err_squa);
		gotoxy(hout, 0, 2 * 9 + 5);
		setcolor(hout, 0, 7);
		cout << "                                                                             " << endl << "                             ";
		gotoxy(hout, 0, 2 * 9 + 5);
		setcolor(hout, 0, 7);
		if (play(&p, head, &q, a, err, err_x, err_y, err_squa, num))
			break;
		Sleep(pertime * 300);
	}
}

void choice3(int a[][11])
{
	bool err[11][11], err_x[11] = { 0 }, err_y[11] = { 0 }, err_squa[11] = { 0 };
	memset(err, 0, sizeof(err));
	step *p, *head;
	if (read_pre(a, err, err_x, err_y, err_squa))
		return;
	head = p = new step;
	if (head == NULL)
		return;
	int num = 0, n = 0;
	print_pre(a, err, err_x, err_y, err_squa);
	while (_getch() != '\r');
	if (judge_finish(a))
	{
		cout << "完整数独" << endl;
		return;
	}
	int temp_x = 0, temp_y = 0;
	for (int j = 1; j <= 9; j++)
	{
		for (int k = 1; k <= 9; k++)
			if (!(a[k][j] % 10))
			{
				temp_x = k, temp_y = j;
				break;
			}
		if (temp_x)
			break;
	}
	setcursor(hout, CURSOR_INVISIBLE);
	if (!auto_solve(a, temp_x, temp_y, &n))
	{
		setcolor(hout, 0, 7);
		gotoxy(hout, 15, 23);
		cout << "无解" << endl;
	}
	else
	{
		print_pre(a, err, err_x, err_y, err_squa);
		gotoxy(hout, 15, 23);
		cout << "数独完成" << endl;
	}
	setcursor(hout, CURSOR_VISIBLE_NORMAL);
}
