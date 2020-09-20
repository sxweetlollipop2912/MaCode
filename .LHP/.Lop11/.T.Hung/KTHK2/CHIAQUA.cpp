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
	for (maxn i = 0; i < n; i++) {
		f[a[i]][1] = 1;
		for (maxn j = 2; j <= i + 1 && j <= lim_n; j++) {
			for (maxa t = a[i]; t <= lim_t; t++) {
				f[t][j] |= f[t - a[i]][j - 1];
				//if (f[t][j]) std::cout << a[i] << ' ' << j << ' ' << t << ' ' << f[t][j] << '\n';
			}
		}
	}
	if (n == 1) lim_t = a[0];
	while (!f[lim_t][lim_n] && !f[lim_t][lim_n - (n & 1)]) --lim_t;
	std::cout << std::min(sum - lim_t, lim_t) << ' ' << std::max(lim_t, sum - lim_t);
}


int main() {
	freopen("chiaqua.inp", "r", stdin);
	freopen("chiaqua.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}