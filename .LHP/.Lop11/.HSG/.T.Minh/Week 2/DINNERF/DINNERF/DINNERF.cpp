#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 101

typedef int maxn;

maxn N, n, cnt[maxN], pos[maxN], K, f[maxN][maxN][maxN], mid[maxN][maxN][maxN], res;
std::string s;


void Prepare() {
	std::cin >> N >> K >> s;

	maxn count = 1; pos[n] = 0;
	for (maxn i = 1; i < N; i++) {
		if (s[i] == s[i - 1]) ++count;
		else cnt[n] = count, ++n, count = 1, pos[n] = i;
	}
	cnt[n] = count, ++n, pos[n] = N;
}


maxn DP(const maxn l, const maxn r, const maxn k) {
	if (l > r) return 0;
	if (f[l][r][k]) return f[l][r][k];

	if (l == r) f[l][r][k] = cnt[r] + k >= K ? 1 : maxN;
	else f[l][r][k] = DP(l, r - 1, 0) + DP(r, r, k);
	mid[l][r][k] = r;

	for (maxn m = r - 2; m >= l; m -= 2) {
		if (DP(l, m, cnt[r] + k) + DP(m + 1, r - 1, 0) > f[l][r][k]) continue;
		f[l][r][k] = f[l][m][cnt[r] + k] + f[m + 1][r - 1][0];
		mid[l][r][k] = m;
	}

	return f[l][r][k];
}


void Output(const maxn l, const maxn r, const maxn k) {
	if (l > r) return;
	maxn r1 = r, K = 0;
	while (mid[l][r1][k] != r1) {
		Output(mid[l][r1][k] + 1, r1 - 1, 0);
		K += cnt[r], r1 = mid[l][r1][k];
	}
	Output(l, r1 - 1, K);
	for (maxn i = pos[l]; i < pos[r + 1]; i++) s[i] = '-';
	std::cout << s << '\n';
}


bool Process() {
	res = DP(0, n - 1, 0);
	if (res >= maxN) return 0;

	std::cout << res << '\n';

	std::cout << s << '\n';
	Output(0, n - 1, 0);
	return 1;
}


int main() {
	//freopen("dinnerf.inp", "r", stdin);
	//freopen("dinnerf.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << -1;
}