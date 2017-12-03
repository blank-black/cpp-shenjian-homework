/* 1551265 ��1 �Ų��� */
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
	vector <char> a;//����������ʽ
	int len;//�������� 
	bool neg;//����
public:
	BigInt();//���캯��  
	BigInt(const int);//intת����  
	BigInt(const string b);//stringת����  
	~BigInt();//����
	BigInt &operator=(const BigInt &);//��ֵ

	friend istream& operator >> (istream&, BigInt&);//����
	friend ostream& operator << (ostream&, BigInt&);//���

	BigInt operator+(const BigInt &) const;//��
	BigInt operator-(const BigInt &) const;//��
	BigInt operator*(const BigInt &) const;//��
	BigInt operator/(const BigInt &) const;//��
	BigInt operator%(const BigInt &) const;//ȡģ
	BigInt operator ++();//ǰ������
	BigInt operator ++(int);//��������
	BigInt operator --();//ǰ���Լ�
	BigInt operator --(int);//�����Լ�
	BigInt operator +();//����
	BigInt operator -();//����
	BigInt operator +=(const BigInt &);//�ӵ�
	BigInt operator -=(const BigInt &);//����
	BigInt operator *=(const BigInt &);//�˵�
	BigInt operator /=(const BigInt &);//����
	BigInt operator %=(const BigInt &);//ģ��
	bool operator>(const BigInt & T) const;//���ڱȽ�  
	bool operator>=(const BigInt & T) const;//���ڵ��ڱȽ�  
	bool operator<(const BigInt & T) const;//С�ڱȽ�  
	bool operator<=(const BigInt & T) const;//С�ڵ��ڱȽ�  
	bool operator==(const BigInt & T) const;//���ڱȽ�  
};
