/*1551265 计1 张伯阳*/
#include "90-b2.h"
int main()
{
	int a[XX + 2][YY + 2], choice;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);  //取标准输入设备对应的句柄
	setcolor(hout, 0, 7);
	srand((unsigned)time(NULL));
	while (1)
	{
		memset(a, -1, sizeof(a));
		setconsoleborder(hout, length, hight, hight);
		read1_1(&choice);
		if (!choice)
			break;
		system("cls");
		if (choice == 1)
			choice1(a);
		if (choice == 2)
			choice2(a);
		if (choice == 3)
			choice3(a);
		setcolor(hout, 0, 7);
		if (choice != 1)
			gotoxy(hout, 1, 24);
		cout << "本小题结束，请输入回车键继续..." << endl;
		while (_getch() != '\r');
		setfontsize(hout, L"新宋体", 18);
		system("cls");
	}
}

void read1_1(int *choice)
{
	while (1)
	{
		cout << "----------------------------------" << endl;
		cout << "1.字符界面游戏(带回退功能)\n2.图形界面游戏(带回退功能)\n3.图形界面自动解(显示过程并带延时)\n0.退出\n";
		cout << "----------------------------------" << endl;
		char ch = _getch();
		if (ch >= '0' && ch <= '3')
		{
			*choice = int(ch - '0');
			break;
		}
	}
}

