/*1551265 计1 张伯阳*/
#include"BallElimination.h"
#include"cmd_console_tools.h"

int main()
{
	int choice, row, line;
	ball b;
	setcolor(hout, 0, 7);
	srand((unsigned)time(NULL));
	while (1)
	{
		memset(b.del, 0, sizeof(b.del));
		memset(b.mov, 0, sizeof(b.mov));
		memset(b.a, 0, sizeof(b.a));
		setconsoleborder(hout, length, hight, hight);
		read1_1(&choice);
		if (!choice)
			break;
		if (choice != 9)
		{
			read1_2(&row, &line);
			random_gene(b.a, row, line);
		}
		system("cls");
		if (choice == 1)
			choice1(b.a, b.del, b.mov, row, line);
		if (choice == 2)
			choice2(b.a, b.del, b.mov, row, line);
		if (choice == 3)
			choice3(b.a, b.del, b.mov, row, line);
		if (choice == 4 || choice == 5)
			choice45(b.a, choice, row, line);
		if (choice == 6)
			choice6(b.a, b.del, row, line);
		if (choice == 7)
			choice7(b.a, b.del, b.mov, choice, row, line, 0);
		if (choice == 8)
			choice8(b.a, b.del, b.mov, choice, row, line);
		if (choice == 9)
			choice9(b.a, b.del,b.mov);
		setcolor(hout, 0, 7);
		if (choice != 8)
		{
			cout << "本小题结束，请输入回车键继续..." << endl;
			while (_getch() != '\r');
		}
		setfontsize(hout, L"新宋体", 18);
		system("cls");
	}
}

void read1_1(int *choice)
{
	while (1)
	{
		cout << "----------------------------------" << endl;
		cout << "1.内部数组，生成初始状态，寻找是否有初始可消除项\n2.内部数组，消除初始可消除项后非0项下落并用0填充\n3.内部数组，消除初始可消除项后查找消除提示\n4.n*n的框架(无分隔线)，显示初始状态\n5.n*n的框架(有分隔线)，显示初始状态\n6.n*n的框架(有分隔线)，显示初始状态及初始可消除项\n7.n*n的框架(有分隔线)，消除初始可消除项后显示消除提示\n8.cmd图形界面完整版\n9.从文件中读取数据以验证查找消除提示的算法的正确性\n0.退出\n";
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
		cout << "请输入行数(5-9)：";
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
		cout << "请输入列数(5-9)：";
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
