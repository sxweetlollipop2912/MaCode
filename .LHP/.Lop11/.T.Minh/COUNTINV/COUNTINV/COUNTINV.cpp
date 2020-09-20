#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 65002

typedef long maxn;
typedef long long maxa;

maxn n, a[maxN], bit[maxN];
maxa res;


void Prepare() {
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Update(const maxn x, maxn idx, maxn bit[], maxn n) {
	for (; idx <= n; idx += (idx & (-idx))) bit[idx] += x;
}
maxa Sum(maxn idx, maxn bit[]) {
	maxa re = 0;
	for (; idx > 0; idx -= (idx & (-idx))) re += bit[idx];
	return re;
}


void Process() {
	std::fill(bit, bit + maxN, 0);
	res = 0;
	for (maxn i = n - 1; i >= 0; i--) {
		Update(1, a[i], bit, n);
		res += Sum(a[i] - 1, bit);
	}
	std::cout << res << '\n';
}


int main() {
	freopen("countinv.inp", "r", stdin);
	freopen("countinv.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n) {
		Prepare();
		Process();
	}
}