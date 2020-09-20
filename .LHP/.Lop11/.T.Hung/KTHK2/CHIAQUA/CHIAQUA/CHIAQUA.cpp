#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 102
#define maxA 20002

typedef int maxn, maxa;

maxn n, lim_n;
bool f[maxA][maxN];
maxa a[maxN], lim_t, sum, res;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i], sum += a[i];
	lim_t = sum / 2, lim_n = n / 2 + (n & 1);
}


void Process() {
	f[0][0] = 1;
	for (maxn i = 0; i < n; i++) 
		for (maxn j = std::min(i + 1, lim_n); j >= 1; j--) for (maxa t = lim_t; t >= a[i]; t--) {
			f[t][j] |= f[t - a[i]][j - 1];
		}

	if (n == 1) lim_t = sum;
	while (!f[lim_t][lim_n] && !f[lim_t][lim_n - (n & 1)]) --lim_t;
	std::cout << std::min(sum - lim_t, lim_t) << ' ' << std::max(lim_t, sum - lim_t);
}


int main() {
	//freopen("chiaqua.inp", "r", stdin);
	//freopen("chiaqua.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}