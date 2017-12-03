/*1551265 计1 张伯阳*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <io.h>
#include "cmd_console_tools.h"
using namespace std;

#define length  100
#define hight 40
#define pertime 5
#define XX 9
#define YY 9

struct step {
	int x, y, data;
	struct step *pre;
};

const char  file_name[15] = "sudoku*.txt";
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);  //取标准输入设备对应的句柄
void read1_1(int *choice);
int read_data(int a[][11], char file[]);
void read_name(char name[][20], char file[]);
bool read_name_(char name[][20], char file[]);int filesearch(char path[], char mode[], char name[][20]);
int read_pre(int a[][11], bool err[][11], bool err_x[], bool err_y[], bool err_squa[]);int console_file(char file[][20], int line);
void choice1(int a[][11]);
void choice2(int a[][11]);
void choice3(int a[][11]);
int judge_start(int a[][11], bool err[][11], bool err_x[], bool err_y[], bool err_squa[]);
int judge_in(int a[][11], int x, int y, int num, bool err[][11], bool err_x[], bool err_y[], bool err_squa[]);
bool judge_finish(int a[][11]);
void showch_(const HANDLE hout, const char ch, const int bg_color = COLOR_BLACK, const int fg_color = COLOR_WHITE);
void printarr(int a[][11], bool err[][11], bool err_x[], bool err_y[], bool err_squa[]);
void print_pre(int a[][11], bool err[][11], bool err_x[], bool err_y[], bool err_squa[]);
int play(step **p, step *head, step **q, int a[][11], bool err[][11], bool err_x[], bool err_y[], bool err_squa[], int num);
void clr_a(int a[]);
int auto_solve(int a[][11], int x, int y,int *n);
