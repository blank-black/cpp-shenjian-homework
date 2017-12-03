/* 1551265 计1 张伯阳 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
using namespace std;
struct info {
	char name[16];
	unsigned short lifeValue;
	unsigned short strengthValue;
	unsigned short constitution;
	unsigned short dexterity;
	unsigned int money;
	unsigned int fame;
	unsigned int charm;
	int pre_1, pre_2;
	char moveSpeed;
	char attackSpeed;
	char attackRange;
	char pre_3;
	unsigned short attack;
	unsigned short defence;
	char agility;
	char intelligence;
	char experience;
	char level;
	unsigned short magicalValue;
	char magicalValue_consumption;
	char magicDamage;
	char hitRate;
	char magicDefence;
	char critRate;
	char endurance;
};
void gotoxy(HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

void print_player(info player, const char list[][30])
{
	int i;
	cout << "当前属性：" << endl;
	for (i = 0; i < 24; i++) 
	{
		cout << list[i] << "：";
		switch (i) 
		{
		case 0:
			cout << player.name; 
			break;
		case 1:
			cout << (unsigned)player.lifeValue;
			break;
		case 2:
			cout << (unsigned)player.strengthValue;
			break;
		case 3:
			cout << (unsigned)player.constitution;
			break;
		case 4:
			cout << (unsigned)player.dexterity; 
			break;
		case 5:
			cout << (unsigned)player.money; 
			break;
		case 6:
			cout << (unsigned)player.fame; 
			break;
		case 7:
			cout << (unsigned)player.charm; 
			break;
		case 8:
			cout << (unsigned)player.moveSpeed;
			break;
		case 9:
			cout << (unsigned)player.attackSpeed;
			break;
		case 10:
			cout << (unsigned)player.attackRange;
			break;
		case 11:
			cout << (unsigned)player.attack;
			break;
		case 12:
			cout << (unsigned)player.defence; 
			break;
		case 13:
			cout << (unsigned)player.agility; 
			break;
		case 14:
			cout << (unsigned)player.intelligence;
			break;
		case 15:
			cout << (unsigned)player.experience;
			break;
		case 16:
			cout << (unsigned)player.level; 
			break;
		case 17:
			cout << (unsigned)player.magicalValue;
			break;
		case 18:
			cout << (unsigned)player.magicalValue_consumption;
			break;
		case 19:
			cout << (unsigned)player.magicDamage;
			break;
		case 20:
			cout << (unsigned)player.hitRate; 
			break;
		case 21:
			cout << (unsigned)player.magicDefence;
			break;
		case 22:
			cout << (unsigned)player.critRate; 
			break;
		case 23:
			cout << (unsigned)player.endurance;
			break;
		}
		cout << endl;
	}
}
void modify(HANDLE hout, const int max[], int i, info *player)
{
	int x = 0, y = 0;
	if (i != 0) 
	{
		int modify;
		cin >> modify;
		while ( modify<0 || modify>max[i]) 
		{
			cout << "输入有误" << endl;
			cin.clear();
			cin.sync();
			cin.ignore(1024, '\n');
			cout << "请输入修改后的值:";
			cin >> modify;
		}
		switch (i) 
		{
		case 1:
			player->lifeValue = modify; 
			break;
		case 2:
			player->strengthValue = modify; 
			break;
		case 3:
			player->constitution = modify; 
			break;
		case 4:
			player->dexterity = modify; 
			break;
		case 5:
			player->money = modify; 
			break;
		case 6:
			player->fame = modify;
			break;
		case 7:
			player->charm = modify; 
			break;
		case 8:
			player->moveSpeed = modify;
			break;
		case 9:
			player->attackSpeed = modify;
			break;
		case 10:
			player->attackRange = modify;
			break;
		case 11:
			player->attack = modify;
			break;
		case 12:
			player->defence = modify; 
			break;
		case 13:
			player->agility = modify; 
			break;
		case 14: 
			player->intelligence = modify;
			break;
		case 15:
			player->experience = modify;
			break;
		case 16: 
			player->level = modify;
			break;
		case 17:
			player->magicalValue = modify;
			break;
		case 18:
			player->magicalValue_consumption = modify;
			break;
		case 19:
			player->magicDamage = modify; 
			break;
		case 20:
			player->hitRate = modify; 
			break;
		case 21:
			player->magicDefence = modify; 
			break;
		case 22:
			player->critRate = modify; 
			break;
		case 23:
			player->endurance = modify; 
			break;
		}
	}
	else 
	{
		char modify[16];
		cin.getline(modify, 16);
		strcpy(player->name, modify);
	}
	cout << "修改成功" << endl;
}
int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	system("mode constitution cols=100 lines=30");
	const char list[][30] = { "0.玩家昵称","1.生命值","2.力量值","3.体质值","4.灵巧值","5.金钱值","6.名声值","7.魅力值","8.移动速度值","9.攻击速度值","10.攻击范围值","11.攻击力值","12.防御力值","13.敏捷度值","14.智力值","15.经验值","16.等级值","17.魔法值","18.消耗魔法值","19.魔法伤害力值","20.命中率值","30.魔法防御力值","31.暴击率值","32.耐力值" };
	const int max[] = { 16,10000,10000,8192,1024,100000000,1000000,1000000,100,100,100,2000,2000,100,100,100,100,10000,100,100,100,100,100,100 };
	info player;
	ifstream in;
	in.open("game.dat", ios::in | ios::binary);
	if (!in.is_open())
	{
		cout << "文件不存在" << endl;
		return 0;
	}
	in.read((char*)&player, sizeof(info));
	in.close();
	while (1) 
	{
		system("cls");
		print_player(player, list);
		int i;
		cout << "请输入要修改项前的序号:";
		cin >> i;
		gotoxy(hout, 0, 27);
		cout << "请输入修改后的值:";
		modify(hout, max, i, &player);
		cout << "按1继续修改,任意键保存并退出" << endl;
		int aa = _getch();
		if (aa != '1')
			break;
	}
	ofstream out;
	out.open("game.dat", ios::out | ios::binary);
	if (!out.is_open())
	{
		cout << "文件不存在" << endl;
		return 0;
	}
	out.write((char*)&player, sizeof(info));
	out.close();
}