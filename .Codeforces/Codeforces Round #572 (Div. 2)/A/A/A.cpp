#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 100002
#define maxP 17

typedef long long maxn;
typedef long long maxa;

maxn n, p2[maxP] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536 }, f[maxN][maxP];
maxa a[maxN], sum[2][maxN];
bool pp = 1;


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum[pp][i] = a[i];
	}
}


void Init() {
	for (maxn p = 1; p < maxP; p++) {
		if (n < p2[p]) return;
		pp = !pp;
		for (maxn i = p2[p]; i <= n; i++) {
			sum[pp][i] = sum[!pp][i] + sum[!pp][i - p2[p - 1]];
			f[i][p] = f[i - p2[p]][p] + (sum[pp][i] >= 10);
			sum[pp][i] %= 10;
		}
	}
}


maxn Process(const maxn L, const maxn R) {
	maxn re = 0, len = R - L + 1;
	for (maxn p = 1; p < maxP; p++) {
		if (len < p2[p]) break;
		re += f[R][p] - f[L - 1][p];
		//std::cout << p2[p] << ' ' << f[R][p] << ' ' << f[L - 1][p] << '\n';
	}
	return re;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Init();
	
	long q;
	std::cin >> q;

	while (q--) {
		maxn l, r;
		std::cin >> l >> r;
		std::cout << Process(l, r) << '\n';
	}
}