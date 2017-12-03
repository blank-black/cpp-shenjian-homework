/*1551265 计1 张伯阳*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char result[256];
char chistr[] = "零壹贰叁肆伍陆柒捌玖";

void write(int n)
{
	strncat(result, &chistr[2 * n], 2);
}
int main() {
	cout << "输入一个浮点型数字做为人民币价格，取值范围为[0 -100 亿)" << endl;
	int a, b, c, d, e, f, g, h, i, n, r, s, t;
	double x, y, j, k, m, l, p;
	cin >> x;
	x /= 10;
	n = int(x);
	y = x - n;
	a = n / 100000000, b = n / 10000000 % 10, c = n / 1000000 % 10, d = n / 100000 % 10, e = n / 10000 % 10, f = n / 1000 % 10, g = n / 100 % 10, h = n / 10 % 10, i = n % 10;
	m = y * 10;
	j = (int)(m*1.001);
	p = (m - j) * 100;
	k = (int)(p / 10 * 1.001);
	l = p - k * 10;
	r = int(j*1.001), s = int(k*1.001), t = int(l*1.001);
	if (a)
	{
		write(a);
		strcat(result, "拾");
	}
	if (b)
	{
		write(b);
		strcat(result, "亿");
	}
	else if (a && !b)
		strcat(result, "亿");
	if (c)
	{
		write(c);
		strcat(result, "千");
	}
	else if (!c && d && (a || b))
		write(0);
	if (d)
	{
		write(d);
		strcat(result, "佰");
	}
	else if (!d && (a || b || c) && e)
		write(0);
	if (e)
	{
		write(e);
		strcat(result, "拾");
	}
	else if (!e && f && (a || b || c || d))
		write(0);
	if (f)
	{
		write(f);
		strcat(result, "万");
	}
	else
	{
		if (!f && (c || d || e))
			strcat(result, "万");
		if (!(c || d || e || f) && (g || h || i || r) && (a || b) || !f && g && (a || b || c || d || e))
			write(0);
	}
	if (g)
	{
		write(g);
		strcat(result, "千");
	}
	else if (!g && h && (a || b || c || d || e || f) && (c || d || e || f))
		write(0);
	if (h)
	{
		write(h);
		strcat(result, "佰");
	}
	else if (!h && i && (a || b || c || d || e || f || g) && (c || d || e || f) || !h && i && g && (a || b || c || d || e || f || g))
		write(0);
	if (i)
	{
		write(i);
		strcat(result, "拾");
	}
	else if (!i && (a || b || c || d || e || f || g || h) && r && (c || d || e || f) || !i && r && (a || b || c || d || e || f || g || h) && (g || h))
		write(0);
	if (r)
	{
		write(r);
		strcat(result, "圆");
	}
	else if (!r && (a || b || c || d || e || f || g || h || i))
		strcat(result, "圆");
	if (!t && !s) {
		if (!(int)(x*10.01))
		{
			write(0);
			strcat(result, "圆");
		}
		strcat(result, "整");
	}
	else {
		if (s) {
			write(s);
			strcat(result, "角");
		}
		else if (!s && t && (a || b || c || d || e || f || g || h || i || r))
			write(0);
		if (!t)
			strcat(result, "整");
		else {
			write(t);
			strcat(result, "分");
		}
	}
	cout << result;
	return 0;
}