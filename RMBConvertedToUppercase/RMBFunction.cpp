/* 1551265 ��1 �Ų���*/
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/* ������Ա��������κ��޸�
���������⣬�������κκ�����������㡱-������!!!!!! */
void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)	//�˱��ʲô��˼������˼��
			cout << "��";
		break;
	case 1:
		cout << "Ҽ";
		break;
	case 2:
		cout << "��";
		break;
	case 3:
		cout << "��";
		break;
	case 4:
		cout << "��";
		break;
	case 5:
		cout << "��";
		break;
	case 6:
		cout << "½";
		break;
	case 7:
		cout << "��";
		break;
	case 8:
		cout << "��";
		break;
	case 9:
		cout << "��";
		break;
	default:
		cout << "error";
		break;
	}
}

/* �ɸ�����Ҫ�Զ����������� */


/* ������Ҫ���main���� */
int main() {
	cout << "����һ��������������Ϊ����Ҽ۸�ȡֵ��ΧΪ[0 -100 ��)" << endl;
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
		cout << "ʰ";
	}
	if (b)
	{
		daxie(b, 0);
		cout << "��";
	}
	else if (a && !b)
		cout << "��";
	if (c)
	{
		daxie(c, 0);
		cout << "ǧ";
	}
	else if (!c && d && (a || b))
		daxie(0, 1);
	if (d)
	{
		daxie(d, 0);
		cout << "��";
	}
	else if (!d && (a || b || c) && e)
		daxie(0, 1);
	if (e)
	{
		daxie(e, 0);
		cout << "ʰ";
	}
	else if (!e && f && (a || b || c || d))
		daxie(0, 1);
	if (f)
	{
		daxie(f, 0);
		cout << "��";
	}
	else
	{
		if (!f && (c || d || e))
			cout << "��";
		if (!(c || d || e || f) && (g || h || i || r) && (a || b) || !f && g && (a || b || c || d || e))
			daxie(0, 1);
	}
	if (g)
	{
		daxie(g, 0);
		cout << "ǧ";
	}
	else if (!g && h && (a || b || c || d || e || f) && (c || d || e || f))
		daxie(0, 1);
	if (h)
	{
		daxie(h, 0);
		cout << "��";
	}
	else if (!h && i && (a || b || c || d || e || f || g) && (c || d || e || f) || !h && i && g && (a || b || c || d || e || f || g))
		daxie(0, 1);
	if (i)
	{
		daxie(i, 0);
		cout << "ʰ";
	}
	else if (!i && (a || b || c || d || e || f || g || h) && r && (c || d || e || f) || !i && r && (a || b || c || d || e || f || g || h) && (g || h))
		daxie(0, 1);
	if (r)
	{
		daxie(r, 0);
		cout << "Բ";
	}
	else if (!r && (a || b || c || d || e || f || g || h || i))
		cout << "Բ";
	if (!t && !s) {
		if (!(int)(x*10.01))
		{
			daxie(0, 1);
			cout << "Բ";
		}
		cout << "��";
	}
	else {
		if (s) {
			daxie(s, 0);
			cout << "��";
		}
		else if (!s && t && (a || b || c || d || e || f || g || h || i || r))
			daxie(0, 1);
		if (!t)
			cout << "��";
		else {
			daxie(t, 0);
			cout << "��";
		}
	}
	return 0;
}