/*1551265 计1 张伯阳*/
#include "90-b2.h"
void clr_a(int a[])
{
	for (int i = 0; i <= 9; i++)
		a[i] = 0;
}

int filesearch(char path[], char mode[], char name[][20])
{
	struct _finddata_t filefind;
	char curr[40];
	strcpy(curr, path);
	strcat(curr, "\\");
	strcat(curr, mode);
	int done = 0, handle, i = 0;
	handle = _findfirst(curr, &filefind);
	if (-1 == handle)
		return -1;
	do {
		if (!strcmp(filefind.name, ".."))
			continue;
		strcpy(curr, filefind.name);
		strcpy(name[i], curr);
		if (_A_SUBDIR == filefind.attrib)
			filesearch(curr, mode, name);
		i++;
	} while (!(done = _findnext(handle, &filefind)));
	_findclose(handle);
	return i;
}

int judge_start(int a[][11], bool err[][11], bool err_x[], bool err_y[], bool err_squa[])//初始判断
{
	int flag[11], num = 0;
	//行判断
	for (int i = 1; i <= YY; i++)
	{
		clr_a(flag);
		for (int j = 1; j <= XX; j++)
			if (flag[a[j][i] % 10])
				num++, err_x[i] = 1, err[j][i] = 1;
			else if (a[j][i] % 10)
				flag[a[j][i] % 10]++;
	}
	//列判断
	for (int i = 1; i <= XX; i++)
	{
		clr_a(flag);
		for (int j = 1; j <= YY; j++)
			if (flag[a[i][j] % 10])
				num++, err_y[i] = 1, err[i][j] = 1;
			else if (a[i][j] % 10)
				flag[a[i][j] % 10]++;
	}
	//九宫格判断
	for (int i = 0; i < 9; i++)
	{
		clr_a(flag);
		for (int j = 1; j <= 3; j++)
			for (int k = 1; k <= 3; k++)
				if (flag[a[(i % 3) * 3 + k][(i / 3) * 3 + j] % 10])
					num++, err_squa[i] = 1, err[(i % 3) * 3 + k][(i / 3) * 3 + j] = 1;
				else if (a[(i % 3) * 3 + k][(i / 3) * 3 + j] % 10)
					flag[a[(i % 3) * 3 + k][(i / 3) * 3 + j] % 10]++;
	}
	return num;
}

int judge_in(int a[][11], int x, int y, int num, bool err[][11], bool err_x[], bool err_y[], bool err_squa[])//输入判断
{
	int flag[11] = { 0 };
	err_x[y] = 0, err_y[x] = 0, err_squa[((y - 1) / 3) * 3 + (x - 1) / 3] = 0;
	for (int i = 1; i <= YY; i++)
		err[x][i] = 0, err[i][y] = 0;
	for (int j = 1, i = ((y - 1) / 3) * 3 + (x - 1) / 3; j <= 3; j++)
		for (int k = 1; k <= 3; k++)
			err[(i % 3) * 3 + k][(i / 3) * 3 + j] = 0;
	//行判断
	for (int j = 1; j <= XX; j++)
		if (flag[a[j][y] % 10])
		{
			num++, err_x[y] = 1, err[j][y] = 1;
			for (int k = 1; k <= XX; k++)
				if (a[j][y] % 10 == a[k][y] % 10)
					err[k][y] = 1;
		}
		else if (a[j][y] % 10)
			flag[a[j][y] % 10]++;
	//列判断
	clr_a(flag);
	for (int j = 1; j <= YY; j++)
		if (flag[a[x][j] % 10])
		{
			num++, err_y[x] = 1, err[x][j] = 1;
			for (int k = 1; k <= YY; k++)
				if (a[x][j] % 10 == a[x][k] % 10)
					err[x][k] = 1;
		}
		else if (a[x][j] % 10)
			flag[a[x][j] % 10]++;
	//九宫格判断
	clr_a(flag);
	for (int j = 1, i = ((y - 1) / 3) * 3 + (x - 1) / 3; j <= 3; j++)
		for (int k = 1; k <= 3; k++)
			if (flag[a[(i % 3) * 3 + k][(i / 3) * 3 + j] % 10])
			{
				num++, err_squa[i] = 1, err[(i % 3) * 3 + k][(i / 3) * 3 + j] = 1;
				for (int jj = 1; jj <= 3; jj++)
					for (int kk = 1; kk <= 3; kk++)
						if (a[(i % 3) * 3 + k][(i / 3) * 3 + j] % 10 == a[(i % 3) * 3 + kk][(i / 3) * 3 + jj] % 10)
							err[(i % 3) * 3 + kk][(i / 3) * 3 + jj] = 1;
			}
			else if (a[(i % 3) * 3 + k][(i / 3) * 3 + j] % 10)
				flag[a[(i % 3) * 3 + k][(i / 3) * 3 + j] % 10]++;
	return num;
}

bool judge_finish(int a[][11])
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			if (!(a[j][i] % 10))
				return 0;
	return 1;
}

int play(step **p, step *head, step **q, int a[][11], bool err[][11], bool err_x[], bool err_y[], bool err_squa[], int num)
{
	cout << "请按行/列/值的方式输入(例如:5c6=第5行第c列为6)，输入bk表示回退一次：";//y-x-值
	char str[10];
	bool ok = 0;
	cin >> str;
	if (!strcmp(str, "bk"))
	{
		if (*p == head)//步数为0不能撤回
		{
			cout << "操作步骤已为空" << endl;
			return 0;
		}
		else
		{
			*q = *p;
			*p = (*p)->pre;
			delete[] * q;
			a[(*p)->x][(*p)->y] = (*p)->data + 10;
			num = judge_in(a, (*p)->x, (*p)->y, num, err, err_x, err_y, err_squa);
		}

	}
	else
	{
		if (str[0] > '9' || str[0]<'1' || str[1]>'i' || str[1]<'a' || str[2]>'9' || str[2] < '0')
		{
			cout << "输入错误" << endl;
			return 0;
		}
		else
		{
			if (a[str[1] - 'a' + 1][str[0] - '0'] >= 10)
			{
				(*p)->x = str[1] - 'a' + 1, (*p)->y = str[0] - '0', (*p)->data = a[str[1] - 'a' + 1][str[0] - '0'] % 10;
				(*q) = (*p);
				(*p) = new step;//申请(*p)储存历史操作,(*p)百位表示x,十位y值,个位为之前值
				if ((*p) == NULL)
					return -1;
				(*p)->pre = *q;
				a[str[1] - 'a' + 1][str[0] - '0'] = str[2] - '0' + 10;//之后修改的值+10和原有值进行区分
				num = judge_in(a, str[1] - 'a' + 1, str[0] - '0', num, err, err_x, err_y, err_squa);
				if (!num)//判断完成
				{
					if (judge_finish(a))
					{
						cout << "数独已完成" << endl;
						return 1;
					}
				}
				else
					cout << "检测出数据有" << num << "处冲突" << endl;
			}
			else
				cout << "输入非法" << endl;
		}
	}
	return 0;
}

int auto_solve(int a[][11], int x, int y, int *n)
{
	if (x > 9 || x < 1 || y > 9 || y < 1)
		return 0;
	for (int i = 1; i <= 9; i++)
	{
		bool err[11][11], err_x[11] = { 0 }, err_y[11] = { 0 }, err_squa[11] = { 0 };
		memset(err, 0, sizeof(err));
		a[x][y] = i + 10;
		if (!judge_in(a, x, y, 0, err, err_x, err_y, err_squa))
		{
			(*n)++;
			showch(hout, 4 * x + 2, 2 * y + 2, a[x][y] % 10 + '0', 15, 4);
			gotoxy(hout, 1, 23);
			setcolor(hout, 0, 7);
			cout << "搜索" << *n << "次";
			Sleep(pertime);
			int temp_x = 0, temp_y = 0;
			if (judge_finish(a))
				return 1;
			for (int j = y; j <= 9; j++)
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
			if (auto_solve(a, temp_x, temp_y, n))
				return 1;
		}
		if (i == 9)
		{
			a[x][y] = 10;
			showch(hout, 4 * x + 2, 2 * y + 2, a[x][y] % 10 + '0', 15, 2);
			Sleep(pertime);
		}
	}
	return 0;
}

int read_pre(int a[][11], bool err[][11], bool err_x[], bool err_y[], bool err_squa[])
{
	char name[20][20], file[20];
	int num = 0;
	bool ok = 0;
	if (read_name_(name, file))
	{
		gotoxy(hout, 2, 2 * 9 + 5);
		cout << "未读取到sudoku为前缀的文件" << endl;
		return -1;
	}
	read_data(a, file);
	setcolor(hout, 0, 15);
	print_pre(a, err, err_x, err_y, err_squa);
	gotoxy(hout, 0, 2 * 9 + 5);
	setcolor(hout, 0, 7);
	if (num = judge_start(a, err, err_x, err_y, err_squa))
		cout << "检查后的数据有" << num << "处冲突 " << endl;
	if (num)
	{
		cout << "原始文件有错，修改正确后继续" << endl;
		return -1;
	}
	for (int i = 1, ok = 1; i <= XX; i++)
		for (int j = 1; j <= YY; j++)
			if (!a[i][j])
				ok = 0;
	if (ok)
	{
		cout << "完整数独" << endl;
		return 1;
	}
	return 0;
}

int read_data(int a[][11], char file[])
{
	fstream data;
	data.open(file, ios::in);
	if (!data.is_open())
	{
		cout << "文件无法打开" << endl;
		return -1;
	}
	for (int j = 1, temp; j <= YY; j++)
		for (int i = 1; i <= XX; i++)
		{
			data >> temp;
			if (temp > 9 || temp < 0)
			{
				cout << "数据非法" << endl;
				return -2;
			}
			a[i][j] = !temp * 10 + temp;
		}
	return 0;
}

void read_name(char name[][20], char file[])
{
	char file_[20];
	cout << "当前目录下符合sudoku*.txt的匹配文件有：" << endl;
	int num = filesearch(".", "sudoku*.txt", name);
	for (int i = 1; i < num; i++)
		cout << name[i] << "\t";
	cout << endl << "请输入数独题目文件名(回车表示默认sudoku.txt)：";
	char str = _getch();
	cout << str;
	if (str == '\r')
		strcpy(file, "sudoku.txt");
	else
	{
		cin >> file_;
		file[0] = str, file[1] = '\0';
		strcat(file, file_);
	}
}

bool read_name_(char name[][20], char file[])
{
	int num = filesearch(".", "sudoku*.txt", name), n = console_file(name, num + 1);
	if (n == -1)
		return 1;
	strcpy(file, name[n]);
	setcursor(hout, CURSOR_VISIBLE_NORMAL);
	return 0;
}
