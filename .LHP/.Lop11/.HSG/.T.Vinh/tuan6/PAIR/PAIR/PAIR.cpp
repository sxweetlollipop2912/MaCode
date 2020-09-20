#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100001
#define maxA 1000000001

typedef long maxn, maxa;

maxn n[2];
maxa a[2][maxN];
bool S;


void Prepare() {
	std::cin >> n[0] >> n[1];
	for (maxn i = 0; i < n[0]; i++) std::cin >> a[0][i];
	for (maxn i = 0; i < n[1]; i++) std::cin >> a[1][i];
	std::sort(a[0], a[0] + n[0]);
	std::sort(a[1], a[1] + n[1]);

	S = n[0] > n[1];
}


bool Check(const maxa x) {
	maxn i = 0, is = 0;
	for (i = 0, is = 0; i < n[!S] && is < n[S]; i++, is++) {
		while (i != n[!S] && a[S][is] - a[!S][i] > x) ++i;
		if (i == n[!S] || abs(a[S][is] - a[!S][i]) > x) return 0;
	}
	return is == n[S];
}


void Process() {
	maxn l = 0, r = maxA;
	while (l != r) {
		maxn m = (l + r) / 2;
		if (Check(m)) r = m;
		else l = m + 1;
	}
	std::cout << l;
}


int main() {
	//freopen("pair.inp", "r", stdin);
	//freopen("pair.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}