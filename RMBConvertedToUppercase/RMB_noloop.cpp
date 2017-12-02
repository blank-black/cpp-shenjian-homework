/* 1551265 º∆1 ’≈≤Æ—Ù */
#include <iostream>
using namespace std;
int main() {
	cout << " ‰»Î“ª∏ˆ∏°µ„–Õ ˝◊÷◊ˆŒ™»À√Ò±“º€∏Ò£¨»°÷µ∑∂ŒßŒ™[0 -100 “⁄)" << endl;
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
	if (a) {
		if (a == 1)
			cout << "“º ∞";
		else if (a == 2)
			cout << "∑° ∞";
		else if (a == 3)
			cout << "»˛ ∞";
		else if (a == 4)
			cout << "À¡ ∞";
		else if (a == 5)
			cout << "ŒÈ ∞";
		else if (a == 6)
			cout << "¬Ω ∞";
		else if (a == 7)
			cout << "∆‚ ∞";
		else if (a == 8)
			cout << "∞∆ ∞";
		else
			cout << "æ¡ ∞";
		}
	if (b) {
		if (b == 1)
			cout << "“º“⁄";
		else if (b == 2)
			cout << "∑°“⁄";
		else if (b == 3)
			cout << "»˛“⁄";
		else if (b == 4)
			cout << "À¡“⁄";
		else if (b == 5)
			cout << "ŒÈ“⁄";
		else if (b == 6)
			cout << "¬Ω“⁄";
		else if (b == 7)
			cout << "∆‚“⁄";
		else if (b == 8)
			cout << "∞∆“⁄";
		else
			cout << "æ¡“⁄";
		}
	else if (!a && b)
		cout << "“⁄";
	if (c) {
		if (c == 1)
			cout << "“º«™";
		else if (c == 2)
			cout << "∑°«™";
		else if (c == 3)
			cout << "»˛«™";
		else if (c == 4)
			cout << "À¡«™";
		else if (c == 5)
			cout << "ŒÈ«™";
		else if (c == 6)
			cout << "¬Ω«™";
		else if (c == 7)
			cout << "∆‚«™";
		else if (c == 8)
			cout << "∞∆«™";
		else
			cout << "æ¡«™";
		}
	else if (!c && d && (a || b))
		cout << "¡„";
	if (d) {
		if (d == 1)
			cout << "“º∞€";
		else if (d == 2)
			cout << "∑°∞€";
		else if (d == 3)
			cout << "»˛∞€";
		else if (d == 4)
			cout << "À¡∞€";
		else if (d == 5)
			cout << "ŒÈ∞€";
		else if (d == 6)
			cout << "¬Ω∞€";
		else if (d == 7)
			cout << "∆‚∞€";
		else if (d == 8)
			cout << "∞∆∞€";
		else
			cout << "æ¡∞€";
		}
	else if (!d && (a || b || c) && e)
		cout << "¡„";
	if (e) {
		if (e == 1)
			cout << "“º ∞";
		else if (e == 2)
			cout << "∑° ∞";
		else if (e == 3)
			cout << "»˛ ∞";
		else if (e == 4)
			cout << "À¡ ∞";
		else if (e == 5)
			cout << "ŒÈ ∞";
		else if (e == 6)
			cout << "¬Ω ∞";
		else if (e == 7)
			cout << "∆‚ ∞";
		else if (e == 8)
			cout << "∞∆ ∞";
		else
			cout << "æ¡ ∞";
		}
	else if (!e && f && (a || b || c || d))
		cout << "¡„";
	if (f) {
		if (f == 1)
			cout << "“ºÕÚ";
		else if (f == 2)
			cout << "∑°ÕÚ";
		else if (f == 3)
			cout << "»˛ÕÚ";
		else if (f == 4)
			cout << "À¡ÕÚ";
		else if (f == 5)
			cout << "ŒÈÕÚ";
		else if (f == 6)
			cout << "¬ΩÕÚ";
		else if (f == 7)
			cout << "∆‚ÕÚ";
		else if (f == 8)
			cout << "∞∆ÕÚ";
		else
			cout << "æ¡ÕÚ";
		}
	else {
		if (!f && (c || d || e))
			cout << "ÕÚ";
		if (!(c || d || e || f) && (g || h || i || r) && (a || b) || !f && g && (a || b || c || d || e))
			cout << "¡„";
		}
	if (g) {
		if (g == 1)
			cout << "“º«™";
		else if (g == 2)
			cout << "∑°«™";
		else if (g == 3)
			cout << "»˛«™";
		else if (g == 4)
			cout << "À¡«™";
		else if (g == 5)
			cout << "ŒÈ«™";
		else if (g == 6)
			cout << "¬Ω«™";
		else if (g == 7)
			cout << "∆‚«™";
		else if (g == 8)
			cout << "∞∆«™";
		else
			cout << "æ¡«™";
		}
	else if (!g && h && (a || b || c || d || e || f) && (c || d || e || f))
		cout << "¡„";
	if (h) {
		if (h == 1)
			cout << "“º∞€";
		else if (h == 2)
			cout << "∑°∞€";
		else if (h == 3)
			cout << "»˛∞€";
		else if (h == 4)
			cout << "À¡∞€";
		else if (h == 5)
			cout << "ŒÈ∞€";
		else if (h == 6)
			cout << "¬Ω∞€";
		else if (h == 7)
			cout << "∆‚∞€";
		else if (h == 8)
			cout << "∞∆∞€";
		else
			cout << "æ¡∞€";
		}
	else if (!h && i && (a || b || c || d || e || f || g) && (c || d || e || f) || !h && i && g && (a || b || c || d || e || f || g))
		cout << "¡„";
	if (i) {
		if (i == 1)
			cout << "“º ∞";
		else if (i == 2)
			cout << "∑° ∞";
		else if (i == 3)
			cout << "»˛ ∞";
		else if (i == 4)
			cout << "À¡ ∞";
		else if (i == 5)
			cout << "ŒÈ ∞";
		else if (i == 6)
			cout << "¬Ω ∞";
		else if (i == 7)
			cout << "∆‚ ∞";
		else if (i == 8)
			cout << "∞∆ ∞";
		else
			cout << "æ¡ ∞";
		}
	else if (!i && (a || b || c || d || e || f || g || h) && r && (c || d || e || f) || !i && r && (a || b || c || d || e || f || g || h) && (g || h))
		cout << "¡„";
	if (r) {
		if (r == 1)
			cout << "“º‘≤";
		else if (r == 2)
			cout << "∑°‘≤";
		else if (r == 3)
			cout << "»˛‘≤";
		else if (r == 4)
			cout << "À¡‘≤";
		else if (r == 5)
			cout << "ŒÈ‘≤";
		else if (r == 6)
			cout << "¬Ω‘≤";
		else if (r == 7)
			cout << "∆‚‘≤";
		else if (r == 8)
			cout << "∞∆‘≤";
		else
			cout << "æ¡‘≤";
		}
	else if (!r && (a || b || c || d || e || f || g || h || i))
		cout << "‘≤";
	if (!t && !s) {
		if (!(int)(x*10.01))
			cout << "¡„‘≤";
		cout << "’˚";
		}
	else {
		if (s) {
			if (s == 1)
				cout << "“ºΩ«";
			else if (s == 2)
				cout << "∑°Ω«";
			else if (s == 3)
				cout << "»˛Ω«";
			else if (s == 4)
				cout << "À¡Ω«";
			else if (s == 5)
				cout << "ŒÈΩ«";
			else if (s == 6)
				cout << "¬ΩΩ«";
			else if (s == 7)
				cout << "∆‚Ω«";
			else if (s == 8)
				cout << "∞∆Ω«";
			else
				cout << "æ¡Ω«";
			}
		else if (!s && t && (a || b || c || d || e || f || g || h || i || r))
			cout << "¡„";
		if (!t)
			cout << "’˚";
		else {
			if (t == 1)
				cout << "“º∑÷";
			else if (t == 2)
				cout << "∑°∑÷";
			else if (t == 3)
				cout << "»˛∑÷";
			else if (t == 4)
				cout << "À¡∑÷";
			else if (t == 5)
				cout << "ŒÈ∑÷";
			else if (t == 6)
				cout << "¬Ω∑÷";
			else if (t == 7)
				cout << "∆‚∑÷";
			else if (t == 8)
				cout << "∞∆∑÷";
			else
				cout << "æ¡∑÷";
			}
		}
	return 0;
	}
