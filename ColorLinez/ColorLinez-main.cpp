/* 1551265 ��1 �Ų��� */
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
		cout << "1.�ڲ����飬������ɳ�ʼ5����\n2.�ڲ����飬�������60%����Ѱ���ƶ�·��\n3.�ڲ����飬������\n4.����n*n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����\n5.����n*n�Ŀ�ܣ��зָ��ߣ��������ʾ5����\n6.9 * 9�Ŀ�ܣ�50�������һ���ƶ�\n7.cmdͼ�ν���������\n8.������ͬʱ����(Ҫ�ఴ����)\n9.���˫�������Ҽ���ʾ\n0.�˳�\n" << endl;
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
		cout << "����������(7-9)��";
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
		cout << "����������(7-9)��";
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
