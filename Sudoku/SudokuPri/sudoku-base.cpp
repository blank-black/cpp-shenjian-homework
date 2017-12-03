/*1551265 计1 张伯阳*/
#include "90-b2.h"
void printarr(int a[][11], bool err[][11], bool err_x[], bool err_y[], bool err_squa[])
{
	int i, j;
	char ch;
	cout << "  | ";
	for (i = 1; i <= XX; i++)
		cout << ' ' << i << ' ';
	cout << endl;
	cout << "--+-";
	for (i = 1; i <= XX; i++)
		cout << "---";
	cout << endl;
	for (i = 1; i <= YY; i++)
	{
		ch = 'a' + i - 1;
		cout << ch << " | ";
		for (j = 1; j <= XX; j++)
		{
			cout << ' ';
			if (a[j][i] % 10 == 0)
				showch_(hout, a[j][i] % 10 + '0', (err_x[i] || err_y[j] || err_squa[(i - 1) / 3 * 3 + (j - 1) / 3]) * 15, 6);
			else
				showch_(hout, a[j][i] % 10 + '0', (err_x[i] || err_y[j] || err_squa[(i - 1) / 3 * 3 + (j - 1) / 3]) * 15, 9 + err[j][i] * 3);
			setcolor(hout, 0, 7);
			cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void choice1(int a[][11])
{
	char file[20];
	do {
		char name[15][20];
		read_name(name, file);
	} while (read_data(a, file));
	cout << "读入的数据为：" << endl;
	int num = 0;
	step *p, *head, *q;
	bool err[11][11], err_x[11] = { 0 }, err_y[11] = { 0 }, err_squa[9] = { 0 }, ok = 0;
	memset(err, 0, sizeof(err));
	if (num = judge_start(a, err, err_x, err_y, err_squa))
		cout << "检查后的数据有" << num << "处冲突，具体是：" << endl;
	if (num)
	{
		printarr(a, err, err_x, err_y, err_squa);
		cout << "原始数据文件有错，请修改正确后继续" << endl;
		return;
	}
	if (judge_finish(a))
	{
		cout << "完整数独" << endl;
		return;
	}
	head = p = q = new step;
	if (head == NULL)
		return;
	while (1)
	{
		printarr(a, err, err_x, err_y, err_squa);
		if (play(&p, head, &q, a, err, err_x, err_y, err_squa, num))
			break;
	}
}
