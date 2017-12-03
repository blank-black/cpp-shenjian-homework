/* 1551265 计1 张伯阳 */
#pragma once
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
#include "cmd_console_tools.h"
#include <profileapi.h>
#define PRINT_X_0 3
#define PRINT_Y_0 3
#define OK 1
#define ERROR 0
#define initial 5
#define proportion 0.6
#define pertime 20
#define length  100
#define hight 40
#define F3 61
#define F4 62
#define F5 63
#define times 300
const char  str_[3] = "◎", str0[3] = "〇", str1[3] = "═", str2[3] = "╔", str3[3] = "╤", str4[3] = "╧", str5[3] = "╝", str6[3] = "╗", str7[3] = "║",
str8[3] = "╟", str9[3] = "╢", str10[3] = "╚", str11[3] = "│", str12[3] = "─";
using namespace std;
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);  //取标准输入设备对应的句柄
void read1_1(int *choice);
void read1_2(int *row, int *line);
void clr(int a[][11], const int row, const int line);
void random_gene(int a[][11], const int row, const int line, const int num);
void printarr(int a[][11], int row, int line);
void choice1(int a[][11], int row, int line);
void choice2(int a[][11], const int choice, const int row, const int line);
int move(int a[][11], int path[][11], int arr[][11], int r1, int l1, int r2, int l2);
void choice45(int a[][11], const int choice, int row, int line);
int read2(int a[][11], int b[], const int choice, const int row, const int line);
int dfs(int a[][11], int path[][11], int arr[][11], int r1, int l1, int r2, int l2, const char c);
bool fun(int a[][11], int path[][11], int arr[][11], int row, int line, int *r1, int *l1, int *r2, int *l2);
void choice37(int a[][11], const int choice, int row, int line);
void random(int b[]);
void print2(int a[][11], int arr[][11], int row, int line);
int judge1(int a[][11], int row, int line, int r2, int l2);
void print45_1(int a[][11], const int choice, int row, int line);
void print45_2(int a[][11], const int choice, int row, int line);
void print45_3(int a[][11], const int choice, int row, int line);
void print7(int a[][11], int b[], int dead[], int last[], int score, int row, int line);
void print7_1(int a[][11], int score, int line);
void print7_2(int a[][11], int b[], int line);
void print7_3(int a[][11], int dead[], int last[], int row, int line);
int judge2(int a[][11], int row, int line, int r2, int l2);
void clrpa(int path[][11], int arr[][11]);
int mouse(int a[][11], int choice, int b[], int dead[], int last[], int choose[], int choose_[], int &x, int &y, int row, int line);
int judge_left(int a[][11], int choose[], int choose_[], int score[], int x, int y, int row, int line, int &is_move);
int judge_move(int a[][11], int choose[], int score[], int x, int y, int row, int line, int &is_move);
void movepic(int a[][11], int arr[][11], int n, int choose[], int x2, int y2, int row, int line);
void swap(int *a, int *b);
void choice6(int a[][11], int row, int line);
void mouse_test();
int read_mouse_and_key(const HANDLE hin, int &X, int &Y, const int enable_read_mouse_moved);
