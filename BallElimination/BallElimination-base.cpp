/*1551265 计1 张伯阳*/
#include"BallElimination.h"
#include"cmd_console_tools.h"

void printarr(int a[][11], bool del[][11], bool mov[][11], int flag, int row, int line)
{
	cout << "   ";
	for (int i = 1; i <= line; i++)
		cout << "  " << i;
	cout << endl << "--+";
	for (int i = 1; i <= line; i++)
		cout << "---";
	for (int l = 1; l <= line; l++)
	{
		cout << endl << char('A' + l - 1) << " |";
		for (int r = 1; r <= row; r++)
		{
			setcolor(hout, 0, 7);
			cout << "  ";
			if (flag && (del[r][l] || mov[r][l]))
				setcolor(hout, 6, 0);
			cout << a[r][l];
		}
		setcolor(hout, 0, 7);
	}
	cout << endl << endl;
}

void random_gene(int a[][11], const int row, const int line)
{
	srand((unsigned)time(NULL));
	for (int i = 1; i <= line; i++)
		for (int j = 1; j <= row; j++)
			a[j][i] = rand() % 9 + 1;
}

void choice1(int a[][11], bool del[][11], bool mov[][11], int row, int line)
{
	printarr(a, del, mov, 0, row, line);
	if (judge1(a, del, row, line))
	{
		cout << endl << "输入回车继续" << endl;
		while (_getch() != '\r');
		printarr(a, del, mov, 1, row, line);
	}
}

void choice2(int a[][11], bool del[][11], bool mov[][11], int row, int line)
{
	printarr(a, del, mov, 0, row, line);
	while (judge1(a, del, row, line))
	{
		cout << endl << "输入回车继续" << endl;
		while (_getch() != '\r');
		printarr(a, del, mov, 1, row, line);
		cout << endl << "输入回车继续" << endl;
		while (_getch() != '\r');
		drop(a, del, row, line);
		printarr(a, del, mov, 1, row, line);
		cout << endl << "输入回车继续" << endl;
		while (_getch() != '\r');
		gen(a, row, line);
		printarr(a, del, mov, 1, row, line);
	}
}

void choice3(int a[][11], bool del[][11], bool mov[][11], int row, int line)
{
	choice2(a, del, mov, row, line);
	if (judge2(a, mov, row, line))
	{
		cout << endl << "输入回车继续" << endl;
		while (_getch() != '\r');
		printarr(a, del, mov, 1, row, line);
	}
}

void drop(int a[][11], bool del[][11], int row, int line)
{
	for (int i = row; i >= 1; i--)
		for (int j = line; j >= 1; j--)
			for (int k = 0; del[i][j] && k <= 9; k++)
			{
				for (int jj = j; jj >= 1; jj--)
				{
					a[i][jj] = a[i][jj - 1];
					del[i][jj] = del[i][jj - 1];
				}
			}
}

void gen(int a[][11], int row, int line)
{
	for (int i = row; i >= 1; i--)
		for (int j = line; j >= 1; j--)
			if (!a[i][j])
				a[i][j] = rand() % 9 + 1;
}
