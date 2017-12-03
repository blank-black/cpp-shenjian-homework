/* 1551265 计1 张伯阳 */
#include "ColorLinez.h"
#include "cmd_console_tools.h"
int main()
{
	int a[11][11], choice, row, line;
	setcolor(hout, 0, 7);
	srand((unsigned)time(NULL));
	while (1)
	{
		setconsoleborder(hout, length, hight, hight);
		read1_1(&choice);
		if (!choice)
			break;
		if (choice != 9)
		{
			read1_2(&row, &line);
			clr(a, row, line);
			random_gene(a, row, line, initial);
		}
		if (choice == 1)
			choice1(a, row, line);
		if (choice == 2)
			choice2(a, choice, row, line);
		if (choice == 3 || choice == 7 || choice == 8)
			choice37(a, choice, row, line);
		if (choice == 4 || choice == 5)
			choice45(a, choice, row, line);
		if (choice == 6)
			choice6(a, row, line);
		if (choice == 9)
			mouse_test();
		system("cls");
	}
}

void read1_1(int *choice)
{
	while (1)
	{
		cout << "----------------------------------" << endl;
		cout << "1.内部数组，随机生成初始5个球\n2.内部数组，随机生成60%的球，寻找移动路径\n3.内部数组，完整版\n4.画出n*n的框架（无分隔线），随机显示5个球\n5.画出n*n的框架（有分隔线），随机显示5个球\n6.9 * 9的框架，50个球，完成一次移动\n7.cmd图形界面完整版\n8.鼠标键盘同时读入(要多按几次)\n9.鼠标双击加左右键演示\n0.退出\n" << endl;
		cout << "----------------------------------" << endl;
		cin >> *choice;
		if (!cin || *choice < 0 || *choice>9)
		{
			cin.clear();
			cin.sync();
			cin.ignore(1024, '\n');
		}
		else
			break;
	}
}

void read1_2(int *row, int *line)
{
	while (1)
	{
		cout << "请输入行数(7-9)：";
		cin >> *row;
		if (!cin || *row>9 || *row<7)
		{
			cin.clear();
			cin.sync();
			cin.ignore(1024, '\n');
		}
		else
			break;
	}
	while (1)
	{
		cout << "请输入列数(7-9)：";
		cin >> *line;
		if (!cin || *line>9 || *line<7)
		{
			cin.clear();
			cin.sync();
			cin.ignore(1024, '\n');
		}
		else
			break;
	}
}
