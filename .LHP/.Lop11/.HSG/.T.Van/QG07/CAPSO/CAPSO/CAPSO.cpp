#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 300002

typedef long maxn, maxa;

maxn n, l[maxN], r[maxN], cur[maxN], res, res_cnt;
maxa a[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i];
}


void Process() {
	for (maxn i = n; i >= 1; i--) {
		r[i] = i; while (r[i] != n && a[r[i] + 1] % a[i] == 0) r[i] = r[r[i] + 1];
	}
	for (maxn i = 1; i <= n; i++) {
		l[i] = i; while (l[i] != 1 && a[l[i] - 1] % a[i] == 0) l[i] = l[l[i] - 1];
	}

	res = -1; std::fill(cur, cur + n + 1, -1);

	for (maxn i = 1; i <= n; i++) {
		if (r[i] - l[i] > res) res = r[i] - l[i], res_cnt = 1, cur[l[i]] = res;
		else if (r[i] - l[i] == res && cur[l[i]] != res) ++res_cnt, cur[l[i]] = res;
	}

	std::cout << res_cnt << ' ' << res << '\n';
	for (maxn i = 1; i <= n; i++) if (cur[i] == res) std::cout << i << ' ';
}


int main() {
	//freopen("capso.inp", "r", stdin);
	//freopen("capso.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}