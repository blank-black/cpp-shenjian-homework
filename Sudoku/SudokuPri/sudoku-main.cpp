/*1551265 ��1 �Ų���*/
#include "90-b2.h"
int main()
{
	int a[XX + 2][YY + 2], choice;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);  //ȡ��׼�����豸��Ӧ�ľ��
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
		cout << "��С�������������س�������..." << endl;
		while (_getch() != '\r');
		setfontsize(hout, L"������", 18);
		system("cls");
	}
}

void read1_1(int *choice)
{
	while (1)
	{
		cout << "----------------------------------" << endl;
		cout << "1.�ַ�������Ϸ(�����˹���)\n2.ͼ�ν�����Ϸ(�����˹���)\n3.ͼ�ν����Զ���(��ʾ���̲�����ʱ)\n0.�˳�\n";
		cout << "----------------------------------" << endl;
		char ch = _getch();
		if (ch >= '0' && ch <= '3')
		{
			*choice = int(ch - '0');
			break;
		}
	}
}

