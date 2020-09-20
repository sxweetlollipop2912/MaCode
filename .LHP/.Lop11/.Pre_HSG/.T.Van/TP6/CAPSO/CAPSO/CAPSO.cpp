#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>

#define maxN 300001
//#define maxA 1000001
#define maxL 20
#define do_gcd 0
#define do_min 1
#define getVal(b, x, y) ((b) == do_gcd ? GCD(x, y) : std::min(x, y))

typedef long maxn, maxa;

maxn n;
maxa a[maxN], gcd[maxN][maxL], mn[maxN][maxL];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


maxa GCD(maxa x, maxa y) {
	while (x != 0) {
		maxa tmp = x;
		x = y % x, y = tmp;
	}
	return y;
}


void Build_Table(maxa table[maxN][maxL], const bool opt) {
	for (maxn i = 0; i < n; i++) table[i][0] = a[i];

	for (maxn lg = 1; (1 << lg) <= n; lg++) {
		for (maxn i = 0; i <= n - (1 << lg); i++) {
			table[i][lg] = getVal(opt, table[i][lg - 1], table[i + (1 << (lg - 1))][lg - 1]);
		}
	}
}


maxn get_gcd(const maxn l, const maxn r) {
	maxn lg = log2(r - l + 1);
	return GCD(gcd[l][lg], gcd[r - (1 << lg) + 1][lg]);
}

maxn get_min(const maxn l, const maxn r) {
	maxn lg = log2(r - l + 1);
	return std::min(mn[l][lg], mn[r - (1 << lg) + 1][lg]);
}


maxn Check(const maxn len) {
	maxn cnt = 0;
	for (maxn i = 0; i <= n - len; i++) cnt += (get_gcd(i, i + len - 1) == get_min(i, i + len - 1));
	return cnt;
}


void Process() {
	Build_Table(gcd, do_gcd);
	Build_Table(mn, do_min);

	maxn l = 1, r = n;
	while (l != r) {
		maxn m = (l + r + 1) / 2;
		if (Check(m)) l = m;
		else r = m - 1;
	}
	std::cout << Check(l) << ' ' << (l - 1) << '\n';
	for (maxn i = 0; i <= n - l; i++) if (get_gcd(i, i + l - 1) == get_min(i, i + l - 1)) std::cout << i + 1 << ' ';
}


int main() {
	//freopen("capso.inp", "r", stdin);
	//freopen("capso.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}