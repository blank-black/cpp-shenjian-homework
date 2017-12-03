/*1551265 计1 张伯阳*/
#include"BallElimination.h"
#include"cmd_console_tools.h"

void choice45(int a[][11], const int choice, int row, int line)
{
	bool del[11][11], mov[11][11];
	memset(del, 0, sizeof(del));
	memset(mov, 0, sizeof(mov));
	if (choice == 4 || choice == 5)
	{
		cout << "初始数组:" << endl;
		printarr(a, del, mov, 0, row, line);
		cout << "按回车键显示图形...";
		while (_getch() != '\r');
	}
	if (choice == 4 || choice == 5)
		setfontsize(hout, L"新宋体", 24);
	if (choice == 4)
		setconsoleborder(hout, 2 * line + 8, row + 8, row + 8);
	else if (choice == 5)
		setconsoleborder(hout, 4 * line + 8, 2 * row + 8, 2 * row + 8);
	print45_1(a, choice, row, line);
	if (choice == 4)
		gotoxy(hout, 1, row + 4);
	else
		gotoxy(hout, 1, 2 * row + 4);
}

void print45_1(int a[][11], const int choice, int row, int line)
{
	showstr(hout, 1, 1, str2, 15, 0);
	if (choice == 4)
	{
		for (int i = 1; i <= line; i++)
		{
			showstr(hout, i * 2 + 1, 1, str1, 15, 0);
			showstr(hout, i * 2 + 1, row + 2, str1, 15, 0);
		}
		showstr(hout, line * 2 + 3, row + 2, str5, 15, 0);
		showstr(hout, line * 2 + 3, 1, str6, 15, 0);
	}
	else
	{
		for (int i = 1; i <= 2 * line - 1; i++)
		{

			if (i % 2)
			{
				showstr(hout, i * 2 + 1, 1, str1, 15, 0);
				showstr(hout, i * 2 + 1, 2 * row + 1, str1, 15, 0);
			}
			else
			{
				showstr(hout, i * 2 + 1, 1, str3, 15, 0);
				showstr(hout, i * 2 + 1, 2 * row + 1, str4, 15, 0);
			}
		}
		showstr(hout, line * 4 + 1, 2 * row + 1, str5, 15, 0);
		showstr(hout, line * 4 + 1, 1, str6, 15, 0);
	}
	print45_2(a, choice, row, line);
	print45_3(a, choice, row, line);
}

void print45_2(int a[][11], const int choice, int row, int line)
{
	if (choice == 4)
	{
		for (int i = 1; i <= row; i++)
		{
			showstr(hout, 1, i + 1, str7, 15, 0);
			showstr(hout, line * 2 + 3, i + 1, str7, 15, 0);
		}
		showstr(hout, 1, row + 2, str10, 15, 0);
	}
	else
	{
		for (int i = 1; i <= 2 * row - 1; i++)
		{
			if (i % 2)
			{
				showstr(hout, 1, i + 1, str7, 15, 0);
				showstr(hout, line * 4 + 1, i + 1, str7, 15, 0);
			}
			else
			{
				showstr(hout, 1, i + 1, str8, 15, 0);
				showstr(hout, line * 4 + 1, i + 1, str9, 15, 0);
			}
		}
		showstr(hout, 1, 2 * row + 1, str10, 15, 0);
	}
}

void print45_3(int a[][11], const int choice, int row, int line)
{
	if (choice == 4)
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= line; j++)
				if (!a[i][j])
					showstr(hout, 2 * i + 1, j + 1, str0, 15, 15);
				else
					showstr(hout, 2 * i + 1, j + 1, str0, a[i][j] / 7 + a[i][j] - 1, 15);
	else
		for (int i = 1; i < 2 * row; i++)
			for (int j = 1; j < 2 * line; j++)
			{
				gotoxy(hout, 2 * j + 1, i + 1);
				if (i % 2)
				{
					if (j % 2)
					{
						if (!a[(i + 1) / 2][(j + 1) / 2])
							showstr(hout, 2 * i + 1, j + 1, str0, 15, 15);
						else
							showstr(hout, 2 * i + 1, j + 1, str0, a[(i + 1) / 2][(j + 1) / 2] / 7 + a[(i + 1) / 2][(j + 1) / 2] - 1, 15);
						setcolor(hout, 15, 0);
					}
					else
						cout << "│";
				}
				else if (j % 2)
					cout << "─";
				else
					cout << "┼";
			}
	setcolor(hout, 0, 7);
}

int choice6(int a[][11], bool del[][11], int row, int line)
{
	int num;
	setconsoleborder(hout, 4 * line + 8, 2 * row + 8, 2 * row + 8);
	setfontsize(hout, L"新宋体", 24);
	choice45(a, 6, row, line);
	if (num = judge1(a, del, row, line))
		for (int r2 = 1; r2 <= row; r2++)
			for (int l2 = 1; l2 <= line; l2++)
				if (del[r2][l2])
					showstr(hout, 4 * r2 - 1, 2 * l2, str00, a[r2][l2] / 7 + a[r2][l2] - 1, 0);//?
	gotoxy(hout, 1, 2 * row + 4);
	return num;
}

int choice7(int a[][11], bool del[][11], bool mov[][11], int choice, int row, int line, int score0)
{
	int score = 0, over = 1;
	setconsoleborder(hout, 4 * line + 8, 2 * row + 8, 2 * row + 8);
	setfontsize(hout, L"新宋体", 24);
	while (score = choice6(a, del, row, line))//hint del
	{
		tapeenter(row, choice);
		for (int r2 = 1; r2 <= row; r2++)
			for (int l2 = 1; l2 <= line; l2++)
				if (del[r2][l2])
				{
					showstr(hout, 4 * r2 - 1, 2 * l2, str0, a[r2][l2] / 7 + a[r2][l2] - 1, 0);
					Sleep(pertime * 2);
					showstr(hout, 4 * r2 - 1, 2 * l2, str0, 15, 15);
					Sleep(pertime * 2);
				}//delete
		for (int r2 = row; r2 >= 1; r2--)
			for (int l2 = line; l2 >= 1; l2--)
			{
				if (del[r2][l2])
				{
					int i = 1;
					if (l2 == 1)
						continue;
					while (del[r2][l2 - i] && a[r2][l2 - i])
						i++;
					if (!a[r2][l2 - i])
						continue;
					for (int j = i; j >= 1; j--)
					{
						showstr(hout, (r2 - 1) * 4 + 3, 2 * (l2 - j), str0, 15, 15);
						showstr(hout, (r2 - 1) * 4 + 3, 2 * (l2 - j) + 1, str0, a[r2][l2 - j] / 7 + a[r2][l2 - j] - 1, 15);
						Sleep(pertime);
						showstr(hout, (r2 - 1) * 4 + 3, 2 * (l2 - j) + 1, str12, 15, 0);
						showstr(hout, (r2 - 1) * 4 + 3, 2 * (l2 - j) + 2, str0, a[r2][l2 - j] / 7 + a[r2][l2 - j] - 1, 15);
						Sleep(pertime);
						swap(a[r2][l2 - j + 1], a[r2][l2 - j]);
					}//drop down
					bool t = del[r2][l2 - i];
					del[r2][l2 - i] = del[r2][l2];
					del[r2][l2] = t;//swap del
				}
			}
		for (int r2 = row; r2 >= 1; r2--)
			for (int l2 = line; l2 >= 1; l2--)
				if (del[r2][l2])
					a[r2][l2] = 0;//
		tapeenter(row, choice);
		gen(a, row, line);
		for (int r2 = row; r2 >= 1; r2--)
			for (int l2 = line; l2 >= 1; l2--)
				if (del[r2][l2])
				{
					showstr(hout, 4 * r2 - 1, 2 * l2, str0, a[r2][l2] / 7 + a[r2][l2] - 1, 0);
					Sleep(pertime * 2);
				}//generate
		for (int i = 0; i <= line + 1; i++)
			for (int j = 0; j <= row + 1; j++)
				del[j][i] = 0;
		tapeenter(row, choice);
		score0 += score;
	}
	if (choice != 10)
		judge2(a, mov, row, line);
	for (int r2 = row; r2 >= 1; r2--)
		for (int l2 = line; l2 >= 1; l2--)
			if (mov[r2][l2])
			{
				showstr(hout, 4 * r2 - 1, 2 * l2, str_, a[r2][l2] / 7 + a[r2][l2] - 1, 0);
				Sleep(pertime);
				over = 0;//judge game over
			}//hint mov
	if (over)
		return -1;
	gotoxy(hout, 1, 2 * row + 4);
	return score0;
}

void choice8(int a[][11], bool del[][11], bool mov[][11], int choice, int row, int line)
{
	int score0 = 0;
	if (!judge4(a, del, mov, choice, row, line, score0))
		while (1)
		{
			gotoxy(hout, 0, 2 * row + 4);
			setcolor(hout, 0, 7);
			cout << "Score:" << score0 << endl;
			int score = mouse(a, del, mov, choice, row, line, 0);
			if (score == -1 || score == -2)
				break;
			else
				score0 += score;
			if (judge4(a, del, mov, choice, row, line, score0))
				break;
		}
	setcursor(hout, CURSOR_VISIBLE_NORMAL);	//open the cursor
	setcolor(hout, 0, 7);
	gotoxy(hout, 1, 2 * row + 4);
	cout << "游戏结束 最终得分:" << score0 << endl << "输入回车键继续";
	while (_getch() != '\r');
}

int mouse(int a[][11], bool del[][11], bool mov[][11], int choice, int row, int line, int score)
{
	enable_mouse(hin);
	int X = 0, Y = 0, action, x = 0, y = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	setcursor(hout, CURSOR_INVISIBLE);	//close the cursor
	while (1)
	{
		action = read_mouse(hin, X, Y);
		if (action == MOUSE_RIGHT_BUTTON_CLICK)
			return -2;
		if (X < line * 4 + 1 && Y < 2 * row + 1 && (!(X % 4) || X % 4 == 3) && !(Y % 2))
		{
			x = (X + 1) / 4, y = Y / 2;
			if (action == MOUSE_LEFT_BUTTON_CLICK)
			{
				if (!x1)
					x1 = x, y1 = y;
				else if (!x2)
				{
					x2 = x, y2 = y;
					int b = judge3(a, mov, x1, y1, x2, y2);
					if (!b)
					{
						gotoxy(hout, 0, 2 * row + 5);
						cout << "Can't switch\n";
					}
					else
					{
						swap(&a[x1][y1], &a[x2][y2]);
						int score = choice7(a, del, mov, choice, row, line, 0);
						if (!score)
						{
							gotoxy(hout, 0, 2 * row + 5);
							setcolor(hout, 0, 7);
							cout << "Can't switch\n";
							swap(&a[x1][y1], &a[x2][y2]);
							return 0;
						}
						else
						{
							Sleep(pertime * 4);
							showstr(hout, 4 * x1 + 1, 2 * y1 + 1, str0, a[x1][y1] / 7 + a[x1][y1] - 1, 0);
							showstr(hout, 4 * x2 + 1, 2 * y2 + 1, str0, a[x2][y2] / 7 + a[x2][y2] - 1, 0);
							return score / 2;
						}
					}
					x1 = 0, x2 = 0, y1 = 0, y2 = 0;
				}
			}
			else if (action == MOUSE_ONLY_MOVED)
			{
				setcolor(hout, 0, 15);
				gotoxy(hout, 0, 2 * row + 3);
				cout << "[当前光标]: " << char(y + 'A' - 1) << " 行   Y: " << x << " 列";
			}
		}
	}
}

void choice9(int a[][11], bool del[][11],bool mov[][11])
{
	int line, row;
	char name[30] = "test\\",num[8], name_[5] = ".dat";
	cout << "输入学号:" << endl;
	cin >> num;
	strcat(name, num);
	strcat(name, name_);
	input_dat(a, mov, &line, &row, name);
	choice7(a, del, mov, 9, row, line, 0);
	tapeenter(row, 7);
	input_ans(a, mov, line, row, name);
	for (int r = row; r >= 1; r--)
		for (int l = line; l >= 1; l--)
			if (a[r][l] > 10)
				mov[r][l] = 1, a[r][l] -= 90;
			else
				mov[r][l] = 0;
	choice7(a, del, mov, 10, row, line, 0);
}