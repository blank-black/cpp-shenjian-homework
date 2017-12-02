/*1551265 计1 张伯阳*/
#include<iostream>
using namespace std;
float count(float a, float b, int i);
void print(float a, float b, float c, float d, int i, int j, int k, int flag);
char pr(int i);
int pr1(float a, float b, float c, float d, int i, int j, int k, int flag, int t, float n);
int main(){
	float a, b, c, d, s, m, n;
	int t = 0, flag;
	while (1){
		cout << "请输入4个[1:10]整数a,b,c,d:";
		cin >> a >> b >> c >> d;
		if (!cin || a < 1 || a > 10 || b < 1 || b > 10 || c < 1 || c > 10 || d < 1 || d > 10){
			cin.clear();
			cin.sync();
			cout << "输入错误 请重新输入" << endl;
			cin.ignore(1024, '\n');
			}
		else
			break;
		}//判断合法
	for (int i = 0; i <= 3; i++){
		for (int j = 0; j <= 3; j++) {
			for (int k = 0; k <= 3; k++) {
				flag = 1;
				s = count(a, b, i), m = count(s, c, j), n = count(m, d, k), t = pr1(a, b, c, d, i, j, k, flag, t, n);
				flag = 2;
				s = count(b, c, j), m = count(a, s, i), n = count(m, d, k), t = pr1(a, b, c, d, i, j, k, flag, t, n);
				flag = 3;
				s = count(c, d, k), m = count(b, s, j), n = count(a, m, i), t = pr1(a, b, c, d, i, j, k, flag, t, n);
				flag = 4;
				s = count(b, c, j), m = count(s, d, k), n = count(a, m, i), t = pr1(a, b, c, d, i, j, k, flag, t, n);
				flag = 5;
				s = count(a, b, i), m = count(c, d, k), n = count(s, m, j), t = pr1(a, b, c, d, i, j, k, flag, t, n);
			}//将运算顺序分为5类
		}
		}//遍历三个运算符号的所有可能情况
	if (!t)
		cout << "无解" << endl;
	}//计数器
float count(float a, float b, int i){
	if (!i)
		return a + b;
	if (i == 1)
		return a - b;
	if (i == 2)
		return a * b;
	if (!b)
		return 1000;//除数不为0
	return a / b;
	}//计算
void print(float a, float b, float c, float d, int i, int j, int k, int flag){
	if (flag == 1)
		cout << "((" << a << pr(i) << b << ")" << pr(j) << c << ")" << pr(k) << d << "=24" << endl;
	if (flag == 2)
		cout << "(" << a << pr(i) << "(" << b << pr(j) << c << "))" << pr(k) << d << "=24" << endl;
	if (flag == 3)
		cout << a << pr(i) << "(" << b << pr(j) << "(" << c << pr(k) << d << "))=24" << endl;
	if (flag == 4)
		cout << a << pr(i) << "((" << b << pr(j) << c << ")" << pr(k) << d << ")=24" << endl;
	if (flag == 5)
		cout << "(" << a << pr(i) << b << ")" << pr(j) << "(" << c << pr(k) << d << ")=24" << endl;
	}//输出算式
char pr(int i){
	if (!i)
		return '+';
	else if (i == 1)
		return '-';
	else if (i == 2)
		return '*';
	else
		return '/';
	}//输出符号
int pr1(float a, float b, float c, float d, int i, int j, int k, int flag, int t, float n) {
	if (fabs(n-24)<1e-3){
		print(a, b, c, d, i, j, k, flag);
		t++;
		}
	return t;
	}//判断结果是否为24