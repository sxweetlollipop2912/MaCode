#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define maxN 252
#define Cnt first
#define Col second

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxn, int> bl_t;

maxn n, N;
bl_t bl[maxN];
maxa f[maxN][maxN][maxN];


void Prepare() {
	N = 1, bl[N - 1].Cnt = 1;
	std::cin >> bl[N - 1].Col;

	for (maxn i = 1; i < n; i++) {
		int c; std::cin >> c;
		if (c == bl[N - 1].Col) ++bl[N - 1].Cnt;
		else ++N, bl[N - 1].Col = c, bl[N - 1].Cnt = 1;
	}

	for (maxn i = 0; i < N; i++) for (maxn j = 0; j < N; j++) std::fill(f[i][j], f[i][j] + maxN, -1);
}


maxa power(maxa a, maxa x) {
	maxa re = 1;
	//std::cout << a << ' ' << x << ' ';
	for (; x; x >>= 1, a *= a) if (x & 1) re *= a;
	//std::cout << re << '\n';
	return re;
}


maxa DP(const maxn L, const maxn R, const maxn K) {
	if (L > R) return 0;
	if (f[L][R][K] != -1) return f[L][R][K];
	if (L == R) return (f[L][R][K] = power((maxa)bl[L].Cnt + (maxa)K, bl[L].Col));

	f[L][R][K] = DP(L, R - 1, 0) + DP(R, R, K);
	for (maxn m = L; m < R; m++) {
		f[L][R][K] = std::max(f[L][R][K], DP(L, m, 0) + DP(m + 1, R, K));
		if (bl[m].Col == bl[R].Col) f[L][R][K] = std::max(f[L][R][K], DP(L, m, bl[R].Cnt + K) + DP(m + 1, R - 1, 0));
	}
	return f[L][R][K];
}


void Process() {
	std::cout << DP(0, N - 1, 0) << '\n';
}


int main() {
	//freopen("tetris.inp", "r", stdin);
	//freopen("tetris.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n) {
		Prepare();
		Process();
	}
}