#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 300002

typedef long maxn, maxa;

maxn n;
int Q;
maxa a[maxN], sum[maxN], f[maxN];


void Prepare() {
	std::cin >> n >> Q;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i], sum[i] = sum[i - 1] + a[i];
	f[1] = a[1];
	for (maxn i = 2; i <= n; i++) f[i] = a[i] + f[i - 2] - a[i - 1];
}


maxn BS(const maxa x, const maxn L, const maxn R) {
	maxn l = L, r = R;
	while (l != r) {
		maxn m = (l + r + 1) / 2;
		if (sum[m] - sum[L - 1] > x) r = m - 1;
		else l = m;
	}
	return sum[l] - sum[L - 1] <= x ? l : L - 1;
}


void Process() {
	while (Q--) {
		maxa x; maxn L, R; std::cin >> x >> L >> R;
		maxn idx = BS(x, L, R);
		maxa res = (R & 1) == (idx & 1) ? f[R] - f[idx] : f[R] - f[idx - 1] + a[idx]; 
		res = ((R - idx) & 1) ? res - (x - (sum[idx] - sum[L - 1])) : res + (x - (sum[idx] - sum[L - 1]));
		std::cout << res << '\n';
	}
}


int main() {
	//freopen("rating.inp", "r", stdin);
	//freopen("rating.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}