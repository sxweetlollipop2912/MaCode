#include <iostream>
#include <algorithm>
#include <math.h>

#define maxN 100001
#define MOD 998244353

typedef long maxn;
typedef long long maxa;

maxn n;
maxa num[maxN], a[maxN][12], b[maxN][12], sa[12], sb[12], cnta[12], cntb[12], res, len[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> num[i];
}


void Seta(const maxn id) {
	maxa n1 = num[id], n2 = 0, p = 1, l = 0;
	a[id][++l] = num[id] * 10;

	while (n1 / 10 != 0) {
		n2 += (n1 % 10) * pow(10, p);
		n1 /= 10;
		a[id][++l] = n1 * pow(10, p + 2) + n2;
		//std::cout << a[id][l] << ' ';
		p += 2;
	}

	len[id] = l;
	a[id][len[id] + 1] = a[id][len[id]];
}


void Setb(const maxn id) {
	maxa n1 = num[id], n2 = 0, p = 0, l = 0;
	//b[id][++l] = (num[id] / 10) * 100 + n2;

	while (n1 / 10 != 0) {
		n2 += (n1 % 10) * pow(10, p);
		n1 /= 10;
		b[id][++l] = n1 * pow(10, p + 2) + n2;
		//std::cout << n2 << ' ' << b[id][l] << ' ';
		p += 2;
	}
	if (!l) b[id][0] = num[id];
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		Seta(i); Setb(i);
		for (int l = 0; l < 11; l++) {
			sa[l] = sa[l] + a[i][l], sb[l] = sb[l] + b[i][l];
			cnta[l] += (bool)a[i][l], cntb[l] += (bool)b[i][l];
			std::cout << l << ' ' << a[i][l] << ' ' << b[i][l] << ' ' << sa[l] << ' ' << sb[l] << '\n';
		}
	}

	for (maxn i = 0; i < n; i++) {
		for (int l = 0; l < len[i]; l++) {
			std::cout << "b " << num[i] << ' ' << l << ' ' << sa[l + 1] << ' ' << b[i][l] << ' ' << cnta[l + 1] << '\n';
			//res += sb[l] - b[i][l] + (a[i][l] * (n - 1)) + (a[i][l + 1] * (n - 1));
			if (b[i][l]) res += sa[l + 1] + (b[i][l] * cnta[l + 1]);
		}
		for (int l = 1; l <= len[i] + 1; l++) {
			std::cout << "a " << num[i] << ' ' << l << ' ' << sb[l - 1] << ' ' << a[i][l] << ' ' << cntb[l - 1] << '\n';
			if (a[i][l]) res += sb[l - 1] + (a[i][l] * cntb[l - 1]);
			//res += sa[l] - a[i][l] + sa[l + 1] - a[i][l + 1] + (b[i][l] * (n - 1));
		}
		//if (len[i] < 10) res += sb[len[i]] - b[i][len[i]] + (a[i][len[i]] * (n - 1)) + (a[i][len[i] + 1] * (n - 1));
	}
}


int main() {
	Prepare();
	Process();
	std::cout << (res / 2) % MOD;
}