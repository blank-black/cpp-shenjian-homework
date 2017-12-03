/* 1551265 计1 张伯阳*/
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/* 不允许对本函数做任何修改
除本函数外，不允许任何函数中输出“零”-“玖”!!!!!! */
void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}

/* 可根据需要自定义其它函数 */


/* 根据需要完成main函数 */
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
		daxie(a, 0);
		cout << "拾";
	}
	if (b)
	{
		daxie(b, 0);
		cout << "亿";
	}
	else if (a && !b)
		cout << "亿";
	if (c)
	{
		daxie(c, 0);
		cout << "千";
	}
	else if (!c && d && (a || b))
		daxie(0, 1);
	if (d)
	{
		daxie(d, 0);
		cout << "佰";
	}
	else if (!d && (a || b || c) && e)
		daxie(0, 1);
	if (e)
	{
		daxie(e, 0);
		cout << "拾";
	}
	else if (!e && f && (a || b || c || d))
		daxie(0, 1);
	if (f)
	{
		daxie(f, 0);
		cout << "万";
	}
	else
	{
		if (!f && (c || d || e))
			cout << "万";
		if (!(c || d || e || f) && (g || h || i || r) && (a || b) || !f && g && (a || b || c || d || e))
			daxie(0, 1);
	}
	if (g)
	{
		daxie(g, 0);
		cout << "千";
	}
	else if (!g && h && (a || b || c || d || e || f) && (c || d || e || f))
		daxie(0, 1);
	if (h)
	{
		daxie(h, 0);
		cout << "佰";
	}
	else if (!h && i && (a || b || c || d || e || f || g) && (c || d || e || f) || !h && i && g && (a || b || c || d || e || f || g))
		daxie(0, 1);
	if (i)
	{
		daxie(i, 0);
		cout << "拾";
	}
	else if (!i && (a || b || c || d || e || f || g || h) && r && (c || d || e || f) || !i && r && (a || b || c || d || e || f || g || h) && (g || h))
		daxie(0, 1);
	if (r)
	{
		daxie(r, 0);
		cout << "圆";
	}
	else if (!r && (a || b || c || d || e || f || g || h || i))
		cout << "圆";
	if (!t && !s) {
		if (!(int)(x*10.01))
		{
			daxie(0, 1);
			cout << "圆";
		}
		cout << "整";
	}
	else {
		if (s) {
			daxie(s, 0);
			cout << "角";
		}
		else if (!s && t && (a || b || c || d || e || f || g || h || i || r))
			daxie(0, 1);
		if (!t)
			cout << "整";
		else {
			daxie(t, 0);
			cout << "分";
		}
	}
	return 0;
}