#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 101

typedef int maxn;

maxn N, n, cnt[maxN], K, f[maxN][maxN][maxN];


void Prepare() {
	std::string s;
	std::cin >> N >> K >> s;

	maxn count = 1;
	for (maxn i = 1; i < N; i++) {
		if (s[i] == s[i - 1]) ++count;
		else cnt[n] = count, ++n, count = 1;
	}
	cnt[n] = count, ++n;
}


maxn DP(const maxn l, const maxn r, const maxn k) {
	if (l > r) return 0;
	if (f[l][r][k]) return f[l][r][k];
	if (l == r) return (f[l][r][k] = cnt[r] + k >= K ? 1 : maxN);

	f[l][r][k] = DP(l, r - 1, 0) + DP(r, r, k);

	for (maxn m = r - 2; m >= l; m -= 2) f[l][r][k] = std::min(f[l][r][k], DP(l, m, cnt[r] + k) + DP(m + 1, r - 1, 0));
	return f[l][r][k];
}

bool Process() {
	res = DP(0, n - 1, 0);
	if (res >= maxN) return 0;

	std::cout << res << '\n';
	return 1;
}


int main() {
	//freopen("dinner.inp", "r", stdin);
	//freopen("dinner.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << -1;
}