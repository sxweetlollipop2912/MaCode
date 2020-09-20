#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>

#define maxN 12
#define maxA 100000000001

typedef int maxn;
typedef long long maxa;
typedef std::string str;

maxa X, A, B, base, res;
bool digit[11];


void Prepare() {
	str s;
	std::cin >> X >> A >> B >> s;
	for (int i = 0; i < s.size(); i++) digit[s[i] - '0'] = 1;
}


bool check(maxa x) {
	while (x != 0) {
		if (!digit[x % 10]) return 0;
		x /= 10;
	}
	return 1;
}


maxa Count(const maxa mn1, const maxa mn2, const maxa mx2, const maxa mod1, const maxa mod2, const maxa step1 = X, const maxa step2 = X) {
	maxa cnt1 = 0, cnt2 = 0;
	for (maxa x = mn1 + ((mod1 - (mn1 % X) + X) % X); x < mn1 * 10; x += step1) cnt1 += check(x);
	for (maxa x = mn2 + ((mod2 - (mn2 % X) + X) % X); x < mx2; x += step2) cnt2 += check(x);
	return cnt1 * cnt2;
}


void Process() {
	base = 10, res = 0;
	maxa mx1 = 1;
	for (maxn len = 2; base * base <= B * 10; len++, base = (len % 2 == 1) ? base * 10 : base) {
		mx1 = (len % 2 == 0) ? mx1 *= 10 : mx1;
		for (maxa mn2 = 0; mn2 < X && mn2 < base; mn2++) {
			maxa mod2 = mn2 % X, mod1 = (X - mod2) % X;
			if (base % X == 0) {
				if (mod1 != 0) continue;
				res += Count(mx1 / 10, 0, base, (mx1 / 10) % X, mod2, 1);
			}
			else {
				mod1 = (((X / (base % X)) % X) * (base % X)) % X == 0 ? ((X / (base % X)) % X) : 0;
				res += Count(mx1 / 10, 0, base, mod1, mod2);
			}
		}
	}
	std::cout << res + 1;
}


int main() {
	Prepare();
	Process();
}