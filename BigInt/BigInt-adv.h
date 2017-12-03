/* 1551265 计1 张伯阳 */
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>   
#include<string>   
#include <stdlib.h>
#include<fstream>
#include<iomanip>   
#include <stdio.h>
#include <fcntl.h>
#include<vector>
#include<algorithm>   
using namespace std;

#define MAXN 9
#define LEN 1024

class BigInt {
private:
	vector <char> a;//大数储存形式
	int len;//大数长度 
	bool neg;//负数
public:
	BigInt();//构造函数  
	BigInt(const int);//int转大数  
	BigInt(const string b);//string转大数  
	~BigInt();//析构
	BigInt &operator=(const BigInt &);//赋值

	friend istream& operator >> (istream&, BigInt&);//输入
	friend ostream& operator << (ostream&, BigInt&);//输出

	BigInt operator+(const BigInt &) const;//加
	BigInt operator-(const BigInt &) const;//减
	BigInt operator*(const BigInt &) const;//乘
	BigInt operator/(const BigInt &) const;//除
	BigInt operator%(const BigInt &) const;//取模
	BigInt operator ++();//前置自增
	BigInt operator ++(int);//后置自增
	BigInt operator --();//前置自减
	BigInt operator --(int);//后置自减
	BigInt operator +();//正号
	BigInt operator -();//负号
	BigInt operator +=(const BigInt &);//加等
	BigInt operator -=(const BigInt &);//减等
	BigInt operator *=(const BigInt &);//乘等
	BigInt operator /=(const BigInt &);//除等
	BigInt operator %=(const BigInt &);//模等
	bool operator>(const BigInt & T) const;//大于比较  
	bool operator>=(const BigInt & T) const;//大于等于比较  
	bool operator<(const BigInt & T) const;//小于比较  
	bool operator<=(const BigInt & T) const;//小于等于比较  
	bool operator==(const BigInt & T) const;//等于比较  
};
