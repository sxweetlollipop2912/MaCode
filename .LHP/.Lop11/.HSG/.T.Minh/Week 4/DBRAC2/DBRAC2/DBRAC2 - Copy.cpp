#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#pragma warning(disable:4996)

#define maxN 71
#define maxK 37
#define dp 0
#define su 1
#define LEN (2 * n)
#define erase(s) s.erase(s.size() - 1)
#define LIM 10000

typedef int maxn;
typedef long long maxa;
typedef std::string str;

maxn n, KK;
maxa f[maxN][maxN][maxK], sum[maxN][maxN][maxK], curK[maxN][maxN], CNT;
str s;


maxa DP(const maxn L, const maxn R, const maxn K, const bool opt) {
	if (L > R) return opt == dp ? K == 0 : K >= 0;

	sum[L][R][0] = f[L][R][0] = 0;
	if (curK[L][R] >= K) return opt == dp ? f[L][R][K] : sum[L][R][K];

	for (maxn k = curK[L][R] + 1; k <= K; k++) {
		f[L][R][k] = DP(L + 1, R - 1, k - 1, dp);
		for (maxn m = L + 1; m < R - 1; m += 2) {
			f[L][R][k] += DP(L + 1, m - 1, k - 1, dp) * DP(m + 1, R, k - 1, su);
			f[L][R][k] += DP(L + 1, m - 1, k - 2, su) * DP(m + 1, R, k, dp);
			f[L][R][k] += DP(L + 1, m - 1, k - 1, dp) * DP(m + 1, R, k, dp);
		}
		sum[L][R][k] = f[L][R][k] + sum[L][R][k - 1];
	}

	curK[L][R] = K;
	return opt == dp ? f[L][R][K] : sum[L][R][K];
}


void Try(str& s, const maxn cnt, const maxn i, const maxn mx) {
	if (CNT == LIM) return;
	if (i == LEN) {
		if (!cnt && mx == KK) std::cout << s << '\n', ++CNT;
		return;
	}
	if ((mx != KK && i + (KK - cnt) - 1 >= LEN - KK) || (cnt > LEN - i)) return;

	s += '(';
	if (cnt != KK) Try(s, cnt + 1, i + 1, std::max(mx, cnt + 1));
	erase(s); s += ')';
	if (cnt != 0)  Try(s, cnt - 1, i + 1, mx);
	erase(s);
}


void Process() {
	std::cout << DP(0, LEN - 1, KK, dp) << '\n';
}


int main() {
	freopen("dbrac2.inp", "r", stdin);
	//freopen("dbrac2.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n >> KK) Process();
	Try(s, 0, 0, 0);
}