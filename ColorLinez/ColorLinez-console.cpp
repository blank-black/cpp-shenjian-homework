/* 1551265 ��1 �Ų��� */
#include "ColorLinez.h"
#include "cmd_console_tools.h"
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

void choice45(int a[][11], const int choice, int row, int line)
{
	cout << "��ʼ����:" << endl;
	printarr(a, row, line);
	cout << "���س�����ʾͼ��...";
	while (_getch() != '\r');
	setfontsize(hout, L"������", 24);
	if (choice == 4)
		setconsoleborder(hout, 2 * line + 8, row + 8, row + 8);
	else
		setconsoleborder(hout, 4 * line + 8, 2 * row + 8, 2 * row + 8);
	print45_1(a, choice, row, line);
	if (choice == 4)
		gotoxy(hout, 1, row + 4);
	else
		gotoxy(hout, 1, 2 * row + 4);
	cout << "��С�������������س�������...";
	while (_getch() != '\r');
	setfontsize(hout, L"������", 18);
}
void choice6(int a[][11], int row, int line)
{
	int score0 = 0, x, y, score = 0, choose[2] = { 0 }, choose_[2] = { 0 }, b[3], dead[8] = { 0 }, last[8] = { 0 };
	setconsoleborder(hout, 4 * line + 6, 2 * row + 6, 2 * row + 6);
	setfontsize(hout, L"������", 24);
	print45_1(a, 6, row, line);
	mouse(a, 6, b, dead, last, choose, choose_, x, y, row, line);
	setcolor(hout, 0, 7);
	setcursor(hout, CURSOR_VISIBLE_NORMAL);	//�򿪹��
	gotoxy(hout, 1, 2 * row + 4);
	cout << "��С�������������س�������...";
	while (_getch() != '\r');
	setfontsize(hout, L"������", 18);
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
					showstr(hout, 2 * j + 1, i + 1, str0, 15, 15);
				else
					showstr(hout, 2 * j + 1, i + 1, str0, a[i][j] - 1, 15);
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
							showstr(hout, 2 * j + 1, i + 1, str0, 15, 15);
						else
							showstr(hout, 2 * j + 1, i + 1, str0, a[(i + 1) / 2][(j + 1) / 2] - 1, 15);
						setcolor(hout, 15, 0);
					}
					else
						cout << "��";
				}
				else if (j % 2)
					cout << "��";
				else
					cout << "��";
			}
	setcolor(hout, 0, 7);
}
int mouse(int a[][11], int choice, int b[], int dead[], int last[], int choose[], int choose_[], int &x, int &y, int row, int line)
{
	enable_mouse(hin);
	int X = 0, Y = 0, is_move = 0, action, score[1] = { 0 }, flagf3 = 0, flagf5 = 0;
	setcursor(hout, CURSOR_INVISIBLE);	//�رչ��
	while (1)
	{
		if (choice == 7 || choice == 6)
			action = read_mouse(hin, X, Y);
		else
			action = read_mouse_and_key(hin, X, Y, 1);
		if (action == MOUSE_RIGHT_BUTTON_CLICK)
			return -2;
		if (action == F3)
		{
			flagf3 = !flagf3;
			if (flagf3)
				for (int i = 0; i < 3; i++)
					for (int j = 0; j <= 6; j++)
						showstr(hout, line * 4 + 5 + 2 * j, 5 + i, str0, 0, 0);
			else
				print7_2(a, b, line);
		}
		if (action == F4)
			return -3;
		if (action == F5)
		{
			flagf5 = !flagf5;
			if (flagf5)
				for (int i = 0; i <= 9; i++)
					for (int j = 0; j <= 12; j++)
						showstr(hout, line * 4 + 5 + 2 * j, 9 + i, str0, 0, 0);
			else
				print7_3(a, dead, last, row, line);
		}
		if (X < line * 4 + 1 && Y < 2 * row + 1 && (!(X % 4) || X % 4 == 3) && !(Y % 2))
		{
			x = (X + 1) / 4, y = Y / 2;
			if (action == MOUSE_LEFT_BUTTON_CLICK)
			{
				int b = judge_left(a, choose, choose_, score, x, y, row, line, is_move);
				choose_[0] = choose[0], choose_[1] = choose[1];
				if (!b)
				{
					gotoxy(hout, 0, 2 * row + 3);
					cout << "�޷��ƶ����õ�";
				}
				else if (b == 1)
				{
					choose[0] = x, choose[1] = y;
					return score[0];
				}
				else if (b == -1)
					choose[0] = x, choose[1] = y;
			}
			else if (action == MOUSE_ONLY_MOVED)
			{
				setcolor(hout, 0, 15);
				gotoxy(hout, 0, 2 * row + 3);
				cout << "[��ǰ���]: " << char(y + 'A' - 1) << " ��   Y: " << x << " ��";
			}
		}
	}
}

int judge_left(int a[][11], int choose[], int choose_[], int score[], int x, int y, int row, int line, int &is_move)
{
	if (choose[0])
		if (a[y][x])
		{
			choose[0] = x, choose[1] = y;
			showstr(hout, (choose[0] - 1) * 4 + 3, 2 * choose[1], str_, a[y][x] - 1, 15);
			if (!is_move)
				showstr(hout, (choose_[0] - 1) * 4 + 3, 2 * choose_[1], str0, a[choose_[1]][choose_[0]] - 1, 15);
			return -1;
		}
		else
			return judge_move(a, choose, score, x, y, row, line, is_move);
	else if (a[y][x])
	{
		choose[0] = x, choose[1] = y;
		showstr(hout, (choose[0] - 1) * 4 + 3, 2 * choose[1], str_, a[y][x] - 1, 15);
		return -1;
	}
	return -2;
}

int judge_move(int a[][11], int choose[], int score[], int x, int y, int row, int line, int &is_move)
{
	int path[11][11], arr[11][11], n;
	clrpa(path, arr);
	n = move(a, path, arr, choose[1], choose[0], y, x);
	if (arr[choose[1]][choose[0]] = n)
	{
		is_move = 1;
		movepic(a, arr, n, choose, x, y, row, line);
		if (0)
		{
			gotoxy(hout, 0, 13);
			cout << "��ķֲ�" << endl;
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= line; j++)
					cout << a[i][j] << ' ';
				cout << endl;
			}
			while (_getch() != '\r');
		}
		score[0] = judge2(a, row, line, y, x);
	}
	else
	{
		is_move = 0;
		return ERROR;
	}
	return OK;
}

void movepic(int a[][11], int arr[][11], int n, int choose[], int x2, int y2, int row, int line)
{
	for (int x = 0, y = 0, x_ = choose[0], y_ = choose[1], i = n; i >= 1; i--)
	{
		for (int j = 1; j <= row; j++)
			for (int k = 1; k <= line; k++)
				if (arr[j][k] == i)
					y = j, x = k;
		if (!x)
			break;
		else if (x == x_ + 1)
		{
			showstr(hout, (x_ - 1) * 4 + 3, 2 * y, str0, 15, 15);
			showstr(hout, (x_ - 1) * 4 + 5, 2 * y, str_, a[y][x_] - 1, 15);
			Sleep(pertime);
			showstr(hout, (x_ - 1) * 4 + 5, 2 * y, str11, 15, 0);
			showstr(hout, (x_ - 1) * 4 + 7, 2 * y, str_, a[y][x_] - 1, 15);
			Sleep(pertime);
			swap(a[y] + x_ + 1, a[y] + x_);
		}
		else if (x == x_ - 1)
		{
			showstr(hout, (x_ - 1) * 4 + 3, 2 * y, str0, 15, 15);
			showstr(hout, (x_ - 1) * 4 + 1, 2 * y, str_, a[y][x_] - 1, 15);
			Sleep(pertime);
			showstr(hout, (x_ - 1) * 4 + 1, 2 * y, str11, 15, 0);
			showstr(hout, (x_ - 1) * 4 - 1, 2 * y, str_, a[y][x_] - 1, 15);
			Sleep(pertime);
			swap(a[y] + x_ - 1, a[y] + x_);
		}
		else if (y == y_ + 1)
		{
			showstr(hout, (x - 1) * 4 + 3, 2 * y_, str0, 15, 15);
			showstr(hout, (x - 1) * 4 + 3, 2 * y_ + 1, str_, a[y_][x] - 1, 15);
			Sleep(pertime);
			showstr(hout, (x - 1) * 4 + 3, 2 * y_ + 1, str12, 15, 0);
			showstr(hout, (x - 1) * 4 + 3, 2 * y_ + 2, str_, a[y_][x] - 1, 15);
			Sleep(pertime);
			swap(&a[y_ + 1][x], a[y_] + x);
		}
		else if (y == y_ - 1)
		{
			showstr(hout, (x - 1) * 4 + 3, 2 * y_, str0, 15, 15);
			showstr(hout, (x - 1) * 4 + 3, 2 * y_ - 1, str_, a[y_][x] - 1, 15);
			Sleep(pertime);
			showstr(hout, (x - 1) * 4 + 3, 2 * y_ - 1, str12, 15, 0);
			showstr(hout, (x - 1) * 4 + 3, 2 * y_ - 2, str_, a[y_][x] - 1, 15);
			Sleep(pertime);
			swap(a[y_ - 1] + x, a[y_] + x);
		}
		x_ = x, y_ = y;
	}
	choose[0] = x2, choose[1] = y2;
}
void print7(int a[][11], int b[], int dead[], int last[], int score, int row, int line)
{
	print7_1(a, score, line);
	print7_2(a, b, line);
	print7_3(a, dead, last, row, line);
}
/*��ӡ�÷���*/
void print7_1(int a[][11], int score, int line)
{
	char ch[7] = "�÷�:";
	showstr(hout, line * 4 + 5, 1, str2, 15, 0);
	showstr(hout, line * 4 + 5 + 12, 1, str6, 15, 0);
	showstr(hout, line * 4 + 5, 3, str10, 15, 0);
	showstr(hout, line * 4 + 5 + 12, 3, str5, 15, 0);
	showstr(hout, line * 4 + 5 + 12, 2, str7, 15, 0);
	showstr(hout, line * 4 + 5, 2, str7, 15, 0);
	for (int i = 0; i < 5; i++)
	{
		showstr(hout, line * 4 + 7 + 2 * i, 1, str1, 15, 0);
		showstr(hout, line * 4 + 7 + 2 * i, 3, str1, 15, 0);
	}
	for (int i = 0; i < 5; i++)
		showstr(hout, line * 4 + 12 + i, 2, " ", 15, 15);
	showstr(hout, line * 4 + 7, 2, ch, 15, 0);
	showin(hout, line * 4 + 12, 2, score, 15, 0);
}
/*��ӡ����Ԥ����*/
void print7_2(int a[][11], int b[], int line)
{
	showstr(hout, line * 4 + 5, 5, str2, 15, 0);
	showstr(hout, line * 4 + 5 + 12, 5, str6, 15, 0);
	showstr(hout, line * 4 + 5, 7, str10, 15, 0);
	showstr(hout, line * 4 + 5 + 12, 7, str5, 15, 0);
	showstr(hout, line * 4 + 5 + 12, 6, str7, 15, 0);
	showstr(hout, line * 4 + 5, 6, str7, 15, 0);
	showstr(hout, line * 4 + 5 + 4, 6, str11, 15, 0);
	showstr(hout, line * 4 + 5 + 8, 6, str11, 15, 0);
	for (int i = 0; i < 5; i++)
	{
		if (i % 2)
		{
			showstr(hout, line * 4 + 7 + 2 * i, 5, str3, 15, 0);
			showstr(hout, line * 4 + 7 + 2 * i, 7, str4, 15, 0);
		}
		else
		{
			showstr(hout, line * 4 + 7 + 2 * i, 5, str1, 15, 0);
			showstr(hout, line * 4 + 7 + 2 * i, 7, str1, 15, 0);
		}

	}
	for (int i = 0; i < 3; i++)
		showstr(hout, line * 4 + 7 + 4 * i, 6, str0, b[i] - 1, 15);
}
/*��ӡ��������ֲ���*/
void print7_3(int a[][11], int dead[], int last[], int row, int line)
{
	char ch1[2] = ":", ch2[3] = "/(", ch3[7] = ") del-";
	int col[8] = { 0 };
	double cent[8] = { 0 };
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= line; j++)
			col[a[i][j]]++;
	for (int i = 0; i < 8; i++)
		cent[i] = col[i] * 1.0 / row / line;
	if (last[0] - col[0] < 0)
		if (col[0] != row*line - 5)
			for (int i = 1; i < 8; i++)
				dead[i] += (last[i] - col[i]);
	for (int i = 0; i < 8; i++)
		last[i] = col[i];
	showstr(hout, line * 4 + 5, 9, str2, 15, 0);
	showstr(hout, line * 4 + 5 + 24, 9, str6, 15, 0);
	showstr(hout, line * 4 + 5, 18, str10, 15, 0);
	showstr(hout, line * 4 + 5 + 24, 18, str5, 15, 0);
	for (int i = 1; i < 12; i++)
	{
		showstr(hout, line * 4 + 5 + 2 * i, 9, str1, 15, 0);
		showstr(hout, line * 4 + 5 + 2 * i, 18, str1, 15, 0);
	}
	for (int i = 1; i < 9; i++)
	{
		showstr(hout, line * 4 + 5 + 24, 9 + i, str7, 15, 0);
		showstr(hout, line * 4 + 5, 9 + i, str7, 15, 0);
	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 5; j++)
			showstr(hout, line * 4 + 23 + j, 10 + i, "��", 15, 15);
	for (int i = 0; i < 8; i++)
	{
		if (!i)
			showstr(hout, line * 4 + 7, 10 + i, str0, 15, 15);
		else
			showstr(hout, line * 4 + 7, 10 + i, str0, i - 1, 15);
		showstr(hout, line * 4 + 9, 10 + i, ch1, 15, 0);
		if (col[i] < 10)
		{
			showin(hout, line * 4 + 10, 10 + i, 0, 15, 0);
			showin(hout, line * 4 + 11, 10 + i, col[i], 15, 0);
		}
		else
			showin(hout, line * 4 + 10, 10 + i, col[i], 15, 0);
		showstr(hout, line * 4 + 12, 10 + i, ch2, 15, 0);
		showdb(hout, line * 4 + 14, 10 + i, cent[i], 15, 0);
		showstr(hout, line * 4 + 18, 10 + i, ch3, 15, 0);
		showin(hout, line * 4 + 24, 10 + i, dead[i], 15, 0);
	}
}
void mouse_test()
{
	system("cls");
	int X = 0, Y = 0, flagrl = 0;
	int action;
	int loop = 1;

	enable_mouse(hin);

	/* ��ӡ��ʼ���λ��[0,0] */
	setcursor(hout, CURSOR_INVISIBLE);	//�رչ��
	cout << "�ɲ��������/˫��,�Ҽ���/˫��,���Ҽ�ͬʱ�������֣������Ҽ�˫������������" << endl;
	cout << "[��ǰ���λ��] X:0  Y:0"; //��ӡ��ʼ���λ��

	while (loop) {
		/* ����꣬����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
		action = read_mouse(hin, X, Y);

		/* ת����1�н��д�ӡ */
		gotoxy(hout, 0, 1);
		cout << "[��ǰ���λ��] X:" << setw(2) << X << " Y:" << setw(2) << Y << " ����:";
		if (action != MOUSE_LEFT_BUTTON_CLICK && action != MOUSE_RIGHT_BUTTON_CLICK /*&& action != MOUSE_LEFTRIGHT_BUTTON_CLICK*/)
			flagrl = 0;
		if (!flagrl)
			switch (action) {
			case MOUSE_LEFT_BUTTON_CLICK:			//�������
				cout << "�������      " << endl;
				Sleep(times);
				showch(hout, X, Y, '1');			//�����ָ��λ����ʾ1
				break;
			case MOUSE_LEFT_BUTTON_DOUBLE_CLICK:	//˫�����
				cout << "˫�����      " << endl;
				showch(hout, X, Y, '2');			//�����ָ��λ����ʾ2
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:			//�����Ҽ�
				cout << "�����Ҽ�      " << endl;
				Sleep(times);
				showch(hout, X, Y, '3');			//�����ָ��λ����ʾ3
				break;
			case MOUSE_RIGHT_BUTTON_DOUBLE_CLICK:	//˫���Ҽ�
				cout << "˫���Ҽ�      " << endl;
				showch(hout, X, Y, '4');			//�����ָ��λ����ʾ4
				loop = 0;
				break;
			case MOUSE_LEFTRIGHT_BUTTON_CLICK:		//ͬʱ�������Ҽ�
				cout << "ͬʱ�������Ҽ�" << endl;
				showch(hout, X, Y, '5');	//�����ָ��λ����ʾ5
				flagrl = 1;
				break;
			case MOUSE_ONLY_MOVED:
				cout << "�ƶ�          " << endl;
				//showch(hout, X, Y, '*');����ӡ�κ�����
				break;
			case MOUSE_NO_ACTION:
			default:
				cout << "��������" << endl;
				showch(hout, X, Y, '0');			//�����ָ��λ����ʾ0
				break;
			} //end of switch
	} //end of while(1)

	setcursor(hout, CURSOR_VISIBLE_NORMAL);	//�򿪹��
	gotoxy(hout, 1, 30);
	cout << "��С�������������س�������...";
	while (_getch() != '\r');
}
int read_mouse_and_key(const HANDLE hin, int &X, int &Y, const int enable_read_mouse_moved)
{
	INPUT_RECORD    mouseRec;
	DWORD           res;
	COORD           crPos;

	while (1) {
		/* ��hin�ж�����״̬��������ꡢ���̵ȣ� */
		ReadConsoleInput(hin, &mouseRec, 1, &res);
		if (mouseRec.EventType != MOUSE_EVENT)
		{
			int a = _getch();
			if (!a)
			{
				a = _getch();
				if (a == F3)
					return F3;
				if (a == F4)
					return F4;
				if (a == F5)
					return F5;
			}
			else
				continue;
		}
		ReadConsoleInput(hin, &mouseRec, 1, &res);
		/* �ӷ����ж����ָ�뵱ǰ������ */
		crPos = mouseRec.Event.MouseEvent.dwMousePosition;
		X = crPos.X;
		Y = crPos.Y;

		if (enable_read_mouse_moved && mouseRec.Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
			return MOUSE_ONLY_MOVED;

		if (mouseRec.Event.MouseEvent.dwButtonState == (FROM_LEFT_1ST_BUTTON_PRESSED | RIGHTMOST_BUTTON_PRESSED)) { //ͬʱ�������Ҽ�
			return MOUSE_LEFTRIGHT_BUTTON_CLICK;
		}
		else if (mouseRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) { //�������
			if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
				return MOUSE_LEFT_BUTTON_DOUBLE_CLICK;
			else
				return MOUSE_LEFT_BUTTON_CLICK;
		}
		else if (mouseRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) { //�����Ҽ�
			if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
				return MOUSE_RIGHT_BUTTON_DOUBLE_CLICK;
			else
				return MOUSE_RIGHT_BUTTON_CLICK;
		}
		else //�����������������������Ҫ���֣����ж� FROM_LEFT_2ND_BUTTON_PRESSED��
			;
	} //end of while(1)
	return -1;
}
