#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

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
maxa f[maxN][maxK], sum[maxN][maxK], curK[maxN], CNT;
str s;


maxa DP(const maxn L, const maxn R, const maxn K, const bool opt) {
	if (L > R) return opt == dp ? K == 0 : K >= 0;

	maxn len = R - L + 1;
	sum[len][0] = f[len][0] = 0;
	if (curK[len] >= K) return opt == dp ? f[len][K] : sum[len][K];

	for (maxn k = curK[len] + 1; k <= K; k++) {
		f[len][k] = DP(L + 1, R - 1, k - 1, dp);
		for (maxn m = L + 1; m < R - 1; m += 2) {
			f[len][k] += DP(L + 1, m - 1, k - 1, dp) * DP(m + 1, R, k - 1, su);
			f[len][k] += DP(L + 1, m - 1, k - 2, su) * DP(m + 1, R, k, dp);
			f[len][k] += DP(L + 1, m - 1, k - 1, dp) * DP(m + 1, R, k, dp);
		}
		sum[len][k] = f[len][k] + sum[len][k - 1];
	}

	curK[len] = K;
	return opt == dp ? f[len][K] : sum[len][K];
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
	freopen("dbrac2.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n >> KK) Process();
	Try(s, 0, 0, 0);
}