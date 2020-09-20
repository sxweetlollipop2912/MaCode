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
#define p(i) ((i) & 1)

typedef int maxn;
typedef long maxa;
typedef long double maxw;

maxn n, C, D, a[maxN];
maxa val[maxV], sum;
maxw W[maxA], f[2][maxA], res;
std::vector <maxa> v;


void Prepare() {
	std::cin >> C >> D >> n;
	
	std::fill(W + 1, W + maxA, maxW);
	for (maxn i = 0; i < D; i++) {
		std::cin >> val[i];
		std::cin >> W[val[i]];
		v.push_back(val[i]);
	}
	for (maxn i = 1; i <= n; i++) std::cin >> a[i], --a[i], sum += val[a[i]];

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
			f[p(i)][j + val[a[i]]] = std::max(f[p(i)][j + val[a[i]]], f[!p(i)][j] + W[val[a[i]]]);
			if (f[p(i)][j + val[a[i]]] < 0) f[p(i)][j + val[a[i]]] = minW;
		}
	}
	
	res = maxW;
	for (maxa i = C; i <= sum; i++)
		if (W[i - C] < maxW && f[p(n)][i] >= 0) res = std::min(res, W[i - C] - f[p(n)][i]);// std::cout << i << ' ' << W[i - C] << ' ' << f[p(n)][i] << ' ' << res << '\n';
	if (res == maxW) return 0;

	for (maxn i = 1; i <= n; i++) res += W[val[a[i]]];

	std::cout << std::fixed; std::cout << std::setprecision(2);
	std::cout << res;
	return 1;
}


int main() {
	//freopen("weight.inp", "r", stdin);
	//freopen("weight.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "too poor";
}