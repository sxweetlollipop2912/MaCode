#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 47
#define N 45
#define limK 200000

typedef int maxn;
typedef long long maxa;

maxn n, k;
maxa f[maxN], cnt[maxN][200002];


void Prepare() {
	std::cin >> n >> k;
}


maxa Try(const maxn n, const maxn k) {
	if (k <= limK) {
		if (cnt[n][k]) return cnt[n][k];
		if (n <= 1) return (cnt[n][k] = !n);
		if (k <= f[n - 2]) return (cnt[n][k] = Try(n - 2, k));
		return (cnt[n][k] = Try(n - 2, f[n - 2]) + Try(n - 1, k - f[n - 2]));
	}

	if (n <= 1) return !n;
	if (k <= f[n - 2]) return Try(n - 2, k);
	return Try(n - 2, f[n - 2]) + Try(n - 1, k - f[n - 2]);
}

void Process() {
	std::cout << Try(n, k) << '\n';
}


int main() {
	//freopen("fib2.inp", "r", stdin);
	//freopen("fib2.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	f[0] = f[1] = 1;
	for (maxn i = 2; i <= N; i++) f[i] = f[i - 2] + f[i - 1];

	int t; std::cin >> t;
	while (t--) {
		Prepare();
		Process();
	}
}