#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 16
#define N 15
#define X f[N]

typedef int maxn;
typedef long long maxa;

maxa f[maxN] = { 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000 , 0}, a[maxN], t;


void Prepare() {
	std::cin >> X >> t;
}


maxa Count(maxa x, maxn n, maxa f[]) {
	maxa re = 0;
	for (maxn i = n; i >= 0; i--) 
		if (f[i]) re += x / f[i], x %= f[i];
	return re;
}


void Process() {
	for (maxn i = 0; i <= N; i++) a[i] = f[i];
	std::sort(a, a + N + 1);

	std::cout << std::min(Count(t, N, a), std::min(Count(t, N, f), Count(t, N - 1, f))) << '\n';
}


int main() {
	//freopen("oddcoin.inp", "r", stdin);
	//freopen("oddcoin.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Prepare();
		Process();
	}
}