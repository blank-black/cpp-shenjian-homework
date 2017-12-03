/* 1551265 计1 张伯阳 */
#include "90-b5-adv.h"
BigInt::BigInt()
{
	len = 1;
	a.push_back(0);
	neg = 0;
}
BigInt::BigInt(const int b)//int转大数  
{
	int c, d = b;
	len = 0;
	neg = b < 0;
	if (neg)
		d = -d;
	a.insert(a.end(), LEN, 0);
	while (d > MAXN)
	{
		c = d % (MAXN + 1);
		d = d / (MAXN + 1);
		a[len++] = c;
	}
	a[len++] = d;
}
BigInt::BigInt(const string b)//string转大数  
{
	if (b[0] == '-')
		neg = 1;
	else
		neg = 0;
	int length = b.length();
	a.insert(a.end(), length, 0);
	for (int i = 0; i < length; i++)
		a[i] = b[i]-'0';
	len = length;
}
BigInt::~BigInt()
{
	vector<char>(a).swap(a);
}
BigInt & BigInt::operator=(const BigInt & n)//赋值
{
	(*this).a = n.a;
	(*this).len = n.len;
	(*this).neg = n.neg;
	return *this;
}
istream& operator >> (istream & in, BigInt & b)//输入
{
	string str;
	in >> str;
	int len = str.length();
	b.a.insert(b.a.end(), len, 0);
	if (str[0] == '-')
	{
		b.neg = 1;
		for (int i = 0; i < len - 1; i++)
			b.a[i] = str[len - i - 1] - '0';
		b.len = len - 1;
	}
	else
	{
		b.neg = 0;
		for (int i = 0; i < len; i++)
			b.a[i] = str[len - i - 1] - '0';
		b.len = len;
	}
	return in;
}
ostream& operator<<(ostream& out, BigInt& b)//输出
{
	if (b.neg)
		cout << "-";
	for (int i = b.len - 1; i >= 0; i--)
		cout << int(b.a[i]);
	return out;
}

BigInt BigInt::operator+(const BigInt & T) const//加
{
	BigInt t(*this),TT(T);
	int big,flag=0;   
	if (t.neg^T.neg && t.neg)
	{
		t.neg = 0;
		return TT - t;
	}
	else if (t.neg^T.neg)
	{
		TT.neg = 0;
		return t - TT;
	}
	big = TT.len > len ? TT.len : len;
	if (big > t.len)
	{
		t.a.insert(t.a.end(), big - t.len + 1, 0);
		TT.a.push_back(0);
	}
	else
	{
		TT.a.insert(TT.a.end(), big - TT.len + 1, 0);
		t.a.push_back(0);
	}
	for (int i = 0; i < big; i++)
	{
		t.a[i] += TT.a[i];
		if (t.a[i] > MAXN)
		{
			t.a[i + 1]++;
			t.a[i] -= MAXN + 1;
		}
	}
	if (t.a[big] != 0)
		t.len = big + 1;
	else
		t.len = big;
	t.neg = neg&&T.neg;
	if (t.len == 1&&t.a[0]==0)
		t.neg = 0;
	return t;
}
BigInt BigInt::operator-(const BigInt & T) const//减
{
	int i, j, big;
	bool flag = !((*this) >= T);
	BigInt t1= (*this), t2 = T;
	if (t1.neg^t2.neg && t1.neg)
	{
		t2.neg = 1;
		return t1 + t2;
	}
	else if (t1.neg^t2.neg)
	{
		t2.neg = 0;
		return t1 + t2;
	}
	t1.neg = t2.neg = 0;
	if (!(t1 >= t2))
	{
		BigInt t3;
		t3 = t1;
		t1 = t2;
		t2 = t3;
	}
	t2.a.insert(t2.a.end(), len - t2.len + 1, 0);
	t1.a.push_back(0);
	big = t1.len;
	for (i = 0; i < big; i++)
	{
		if (t1.a[i] < t2.a[i])
		{
			j = i + 1;
			while (t1.a[j] == 0)
				j++;
			t1.a[j--]--;
			while (j > i)
				t1.a[j--] += MAXN;
			t1.a[i] += MAXN + 1 - t2.a[i];
		}
		else
			t1.a[i] -= t2.a[i];
	}
	t1.len = big;
	while (!t1.a[t1.len - 1] && t1.len > 1)
	{
		t1.len--;
		big--;
	}
	t1.neg = flag;
	if (t1.len == 1 && t1.a[0] == 0)
		t1.neg = 0;
	return t1;
}

BigInt BigInt::operator*(const BigInt & T) const//乘
{
	BigInt ret;
	ret.a.insert(ret.a.end(), len + T.len, 0);
	int i, j, up, temp, temp1;
	for (i = 0; i < len; i++)
	{
		up = 0;
		for (j = 0; j < T.len; j++)
		{
			temp = a[i] * T.a[j] + ret.a[i + j] + up;
			if (temp > MAXN)
			{
				temp1 = temp % (MAXN + 1);
				up = temp / (MAXN + 1);
				ret.a[i + j] = temp1;
			}
			else
			{
				up = 0;
				ret.a[i + j] = temp;
			}
		}
		if (up != 0)
			ret.a[i + j] = up;
	}
	ret.len = i + j;
	while (ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	ret.neg = neg^T.neg;
	if (ret.len == 1 && ret.a[0] == 0)
		ret.neg = 0;
	return ret;
}
BigInt BigInt::operator/(const BigInt & T) const//除
{
	BigInt t = (*this), ret = 0, TT = T;
	int big;
	bool flag= neg^T.neg;
	t.neg = 0, TT.neg = 0;
	big = TT.len > len ? TT.len : len;
	if (big > TT.len)
		TT.a.insert(TT.a.end(), big - TT.len, 0);
	else if (big > t.len)
		t.a.insert(t.a.end(), big - t.len, 0);
	ret.a.insert(ret.a.end(), big, 0);
	if (t == 0)
		return 0;
	if (TT == 0)
	{
		cout << "error!" << endl;
		return 0;
	}
	while (t > TT || t == TT)
	{
		t = t - TT;
		ret = ret + 1;
	}
	ret.neg = flag;
	if (ret.len == 1 && ret.a[0] == 0)
		ret.neg = 0;
	return ret;
}
BigInt BigInt::operator++()//前置自增
{
	(*this) = (*this) + 1;
	return (*this);
}

BigInt BigInt::operator++(int)//后置自增
{
	(*this) = (*this) + 1;
	return (*this) - 1;
}

BigInt BigInt::operator--()//前置自减
{
	(*this) = (*this) - 1;
	return (*this);
}

BigInt BigInt::operator--(int)//后置自减
{
	(*this) = (*this) - 1;
	return (*this) + 1;
}

BigInt BigInt::operator+()//正号
{
	return (*this);
}

BigInt BigInt::operator-()//负号
{
	BigInt c = (*this);
	c.neg = !c.neg;
	return c;
}

BigInt BigInt::operator +=(const BigInt & b)//加等
{
	(*this) = (*this) + b;
	return (*this);
}
BigInt BigInt::operator -=(const BigInt & b)//减等
{
	(*this) = (*this) - b;
	return (*this);
}
BigInt BigInt::operator *=(const BigInt & b)//乘等
{
	(*this) = (*this) * b;
	return (*this);
}
BigInt BigInt::operator /=(const BigInt & b)//除等
{
	(*this) = (*this) / b;
	return (*this);
}
BigInt BigInt::operator %=(const BigInt & b)//模等
{
	(*this) = (*this) % b;
	return (*this);
}

BigInt BigInt::operator %(const BigInt & b) const//取模
{
	BigInt c = (*this) - (((*this) / b)*b);
	if (c < 0)
		c += b;
	return c;
}
bool BigInt::operator>(const BigInt & T) const//大于比较  
{
	int ln;
	if (neg && !T.neg)
		return false;
	if (!neg&&T.neg)
		return true;
	if (len > T.len&&!neg)
		return true;
	if (len > T.len&& neg)
		return false;
	if (len == T.len && !neg)
	{
		ln = len - 1;
		while (ln >= 0&& a[ln] == T.a[ln] )
			ln--;
		if (ln >= 0 && a[ln] > T.a[ln])
			return true;
		else
			return false;
	}
	else if (len == T.len&&neg)
	{
		ln = len - 1;
		while (ln >= 0&&a[ln] == T.a[ln]  )
			ln--;
		if (ln >= 0 && a[ln] < T.a[ln])
			return true;
		else
			return false;
	}
	else if (!neg)
		return false;
	else
		return true;
}
bool BigInt::operator<(const BigInt & T) const//小于比较  
{
	int ln;
	if (neg && !T.neg)
		return true;
	if (!neg&&T.neg)
		return false;
	if (len > T.len && !neg)
		return false;
	if (len > T.len&& neg)
		return true;
	if (len == T.len && !neg)
	{
		ln = len - 1;
		while (ln >= 0&&a[ln] == T.a[ln]  )
			ln--;
		if (ln >= 0 && a[ln] < T.a[ln])
			return true;
		else
			return false;
	}
	else if (len == T.len&&neg)
	{
		ln = len - 1;
		while (ln >= 0&&a[ln] == T.a[ln]  )
			ln--;
		if (ln >= 0 && a[ln] > T.a[ln])
			return true;
		else
			return false;
	}
	else if (!neg)
		return true;
	else
		return false;
}
bool BigInt::operator==(const BigInt & T) const//等于比较  
{
	int ln;
	if (len != T.len)
		return false;
	if (neg != T.neg)
		return false;
	else 
	{
		ln = len - 1;
		while (ln > 0 && a[ln] == T.a[ln])
			ln--;
		if (!ln && a[ln] == T.a[ln])
			return true;
		else
			return false;
	}
}
bool BigInt::operator<=(const BigInt & T) const//小于等于比较  
{
	if ((*this) < T || (*this) == T)
		return true;
	else
		return false;
}
bool BigInt::operator>=(const BigInt & T) const//大于等于比较  
{
	if ((*this) > T || (*this) == T)
		return true;
	else
		return false;
}
