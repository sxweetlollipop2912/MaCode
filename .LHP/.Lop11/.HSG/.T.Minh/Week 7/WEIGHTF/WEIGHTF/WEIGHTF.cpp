#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iomanip>

#define maxN (maxn)102
#define maxV (maxa)2001
#define maxA (maxa)200002
#define maxW (maxw)2000002
#define minW (maxw)(-2000002)
#define p(i) (i)

typedef int maxn;
typedef long maxa;
typedef long double maxw;

maxn n, C, D, a[maxN];
maxa val[maxV], sum, res;
maxw W[maxA], f[maxN][maxA], sumW;
std::vector <maxa> v;


void Prepare() {
	std::cin >> C >> D >> n;

	std::fill(W + 1, W + maxA, maxW);
	for (maxn i = 0; i < D; i++) {
		std::cin >> val[i];
		std::cin >> W[val[i]];
		v.push_back(val[i]);
	}
	for (maxn i = 1; i <= n; i++) std::cin >> a[i], --a[i], sum += val[a[i]], sumW += W[val[a[i]]];

	std::sort(v.begin(), v.end());
}


bool Process() {
	for (maxa i = 1; i <= sum; i++) {
		maxn idx = std::upper_bound(v.begin(), v.end(), i) - v.begin();
		if (idx) W[i] = W[v[idx - 1]] + W[i - v[idx - 1]];
	}

	std::fill(f[p(0)], f[p(0)] + maxA, minW);
	f[p(0)][0] = 0, sum = 0;

	for (maxn i = 1; i <= n; i++) {
		std::fill(f[p(i)] + 1, f[p(i)] + maxA, minW);
		f[p(i)][0] = 0, sum += val[a[i]];
		for (maxa j = 0; j <= sum - val[a[i]]; j++) {
			f[p(i)][j + val[a[i]]] = std::max(f[p(i)][j + val[a[i]]], f[p(i - 1)][j] + W[val[a[i]]]);
			if (f[p(i)][j + val[a[i]]] < 0) f[p(i)][j + val[a[i]]] = minW;
		}
	}

	res = 0;
	for (maxa i = C; i <= sum; i++)
		if (W[i - C] < maxW && f[p(n)][i] >= 0 && (!res || W[i - C] - f[p(n)][i] < W[res - C] - f[p(n)][res])) res = i;// std::cout << i << ' ' << W[i - C] << ' ' << f[p(n)][i] << ' ' << res << '\n';
	if (!res) return 0;

	std::cout << std::fixed; std::cout << std::setprecision(2);
	std::cout << sumW - f[p(n)][res] + W[res - C] << '\n';

	for (maxn i = n; i > 0 && res; i--) {
		if (f[i][res] == f[i - 1][res]) continue;
		std::cout << a[i] + 1 << '\n', res -= val[a[i]];
	}

	return 1;
}


int main() {
	//freopen("weightf.inp", "r", stdin);
	//freopen("weightf.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "too poor";
}