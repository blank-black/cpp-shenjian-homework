/*1551265 ��1 �Ų���*/
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
			cout << "��С�������������س�������..." << endl;
			while (_getch() != '\r');
		}
		setfontsize(hout, L"������", 18);
		system("cls");
	}
}

void read1_1(int *choice)
{
	while (1)
	{
		cout << "----------------------------------" << endl;
		cout << "1.�ڲ����飬���ɳ�ʼ״̬��Ѱ���Ƿ��г�ʼ��������\n2.�ڲ����飬������ʼ����������0�����䲢��0���\n3.�ڲ����飬������ʼ������������������ʾ\n4.n*n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬\n5.n*n�Ŀ��(�зָ���)����ʾ��ʼ״̬\n6.n*n�Ŀ��(�зָ���)����ʾ��ʼ״̬����ʼ��������\n7.n*n�Ŀ��(�зָ���)��������ʼ�����������ʾ������ʾ\n8.cmdͼ�ν���������\n9.���ļ��ж�ȡ��������֤����������ʾ���㷨����ȷ��\n0.�˳�\n";
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
		cout << "����������(5-9)��";
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
		cout << "����������(5-9)��";
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
