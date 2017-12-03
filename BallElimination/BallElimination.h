/*1551265 计1 张伯阳*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <conio.h>
#include <Windows.h>
#include<fstream>
#include <profileapi.h>
#include"cmd_console_tools.h"

using namespace std;
#define length  100
#define hight 40
#define pertime 50

struct ball {
	int a[11][11];
	bool del[11][11];
	bool mov[11][11];
};

const char  str_[3] = "◎", str00[3] = "●", str0[3] = "〇", str1[3] = "═", str2[3] = "╔", str3[3] = "╤", str4[3] = "╧", str5[3] = "╝", str6[3] = "╗", str7[3] = "║",
str8[3] = "╟", str9[3] = "╢", str10[3] = "╚", str11[3] = "│", str12[3] = "─";
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);  //取标准输入设备对应的句柄
void read1_1(int *choice);
void read1_2(int *row, int *line);
void showin(HANDLE hout, int X, int Y, int A, const int bg_color, const int fg_color);
void showdb(HANDLE hout, int X, int Y, double A, const int bg_color, const int fg_color);
int judge1(int a[][11], bool del[][11], int row, int line);
int judge2(int a[][11], bool mov[][11], int row, int line);
int judge3(int a[][11], bool mov[][11], int x1, int y1, int x2, int y2);
int judge4(int a[][11], bool del[][11], bool mov[][11], int choice, int row, int line, int score0);
void printarr(int a[][11], bool del[][11], bool mov[][11], int flag, int row, int line);
void random_gene(int a[][11], const int row, const int line);
void choice1(int a[][11], bool del[][11], bool mov[][11], int row, int line);
void choice2(int a[][11], bool del[][11], bool mov[][11], int row, int line);
void choice3(int a[][11], bool del[][11], bool mov[][11], int row, int line);
void drop(int a[][11], bool del[][11], int row, int line);
void gen(int a[][11], int row, int line);
int choice6(int a[][11], bool del[][11], int row, int line);
int choice7(int a[][11], bool del[][11], bool mov[][11], int choice, int row, int line, int score0);
void choice8(int a[][11], bool del[][11], bool mov[][11], int choice, int row, int line);
int mouse(int a[][11], bool del[][11], bool mov[][11], int choice, int row, int line, int score);
void choice45(int a[][11], const int choice, int row, int line);
void print45_1(int a[][11], const int choice, int row, int line);
void print45_2(int a[][11], const int choice, int row, int line);
void print45_3(int a[][11], const int choice, int row, int line);
void tapeenter(int row, int choice);
void swap(int *a, int *b);
int input_dat(int a[][11], bool mov[][11], int *line, int *row,char name[]);
int input_ans(int a[][11], bool mov[][11], int line, int row,char name[]);
void choice9(int a[][11], bool del[][11], bool mov[][11]);