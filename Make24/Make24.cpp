/*1551265 ��1 �Ų���*/
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
		cout << "������4��[1:10]����a,b,c,d:";
		cin >> a >> b >> c >> d;
		if (!cin || a < 1 || a > 10 || b < 1 || b > 10 || c < 1 || c > 10 || d < 1 || d > 10){
			cin.clear();
			cin.sync();
			cout << "������� ����������" << endl;
			cin.ignore(1024, '\n');
			}
		else
			break;
		}//�жϺϷ�
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
			}//������˳���Ϊ5��
		}
		}//��������������ŵ����п������
	if (!t)
		cout << "�޽�" << endl;
	}//������
float count(float a, float b, int i){
	if (!i)
		return a + b;
	if (i == 1)
		return a - b;
	if (i == 2)
		return a * b;
	if (!b)
		return 1000;//������Ϊ0
	return a / b;
	}//����
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
	}//�����ʽ
char pr(int i){
	if (!i)
		return '+';
	else if (i == 1)
		return '-';
	else if (i == 2)
		return '*';
	else
		return '/';
	}//�������
int pr1(float a, float b, float c, float d, int i, int j, int k, int flag, int t, float n) {
	if (fabs(n-24)<1e-3){
		print(a, b, c, d, i, j, k, flag);
		t++;
		}
	return t;
	}//�жϽ���Ƿ�Ϊ24