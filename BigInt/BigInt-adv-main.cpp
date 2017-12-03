/* 1551265 计1 张伯阳 */
#include "90-b5-adv.h"
void fun(BigInt a);
int main()
{
	BigInt a(123456), b(789101112);
	/*fstream in;
	string p_a;
	string p_b;
	in.open("print_a.txt", ios::in);
	if (!in.is_open())
	{
		cout << "文件无法打开" << endl;
		return -1;
	}
	in << p_a;
	in.close();
	in.open("print_b.txt", ios::in);
	if (!in.is_open())
	{
		cout << "文件无法打开" << endl;
		return -1;
	}
	in << p_b;
	in.close();
	cout<<read()
	BigInt a(p_a), b(p_b);
	fstream out;
	out.open("print_a+b.txt", ios::out);*/
	BigInt c[3] = { 131415161718,192021222324,252627282930 }, d[3] = { 313233343536,373839404142,434445464748 };
	/*if (!out.is_open())
	{
		cout << "文件无法打开" << endl;
		return -1;
	}
	out << a + b ;
	out.close();
	out.open("print_a-b.txt", ios::out);
	if (!out.is_open())
	{
		cout << "文件无法打开" << endl;
		return -1;
	}
	out << a - b ;
	out.close();*/
	cout << a+b << endl;
	cout << a-b << endl;
	cout << a*b << endl;
	cout << a / b << endl;
	cout << a%b << endl;
	cout << (a += b) << endl;
	cout << (a = b) << endl;
	cout << ++a << ' ' << b-- << endl;
	cout << -a << ' ' << a << endl;
	cout << (a < b) << endl;
	fun(a + b);
	cout << c[0] + d[1] << endl;
	cout << c[2] - d[1] << endl;
	cout << c[1] * d[2] << endl;
	cout << d[2] / c[0] << endl;
	cout << d[2] % c[0] << endl;
	cout << (d[2] += c[0]) << endl;
	cout << (d[2] = c[0]) << endl;
	fun(c[0] + d[1]);
	return 0;
}
void fun(BigInt a)
{
	cout << a*a << endl;
}