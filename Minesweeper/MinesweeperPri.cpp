/*1551265 ¼Æ1 ÕÅ²®Ñô*/
#include<iostream>
#include<time.h>
using namespace std;
int count(int mine[28][12], int a, int b)
{
	if (mine[a][b] == 9)
		return 9;
	int num = 0;
	if (mine[a-1][b] == 9)
		num++;
	if (mine[a+1][b] == 9)
		num++;
	if (mine[a][b+1] == 9)
		num++;
	if (mine[a][b-1] == 9)
		num++;
	if (mine[a+1][b+1] == 9)
		num++;
	if (mine[a+1][b-1] == 9)
		num++;
	if (mine[a-1][b+1] == 9)
		num++;
	if (mine[a-1][b-1] == 9)
		num++;
	return num;
}
int main()
{
	srand((unsigned int)time(NULL));
	int mine[28][12] = { 0 };
	for (int i = 1, a, b; i <= 50; i++)
		while (1)
		{
			a = rand() % 26 + 1, b = rand() % 10 + 1;
			if (mine[a][b] == 9)
				continue;
			mine[a][b] = 9;
			break;
		}
	for (int j = 1; j <= 10; j++)
	{
		for (int i = 1; i <= 26; i++)
			count(mine, i, j) == 9 ? cout << "* " : cout << count(mine, i, j) << " ";
		cout << endl;
	}
	return 0;
}