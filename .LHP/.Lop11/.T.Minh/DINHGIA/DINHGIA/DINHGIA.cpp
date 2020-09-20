#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 100002
//#define maxA (maxa)1000001

typedef long maxn;
typedef long long maxa;

maxn n, m;
maxa a[maxN], res, res_cnt;


void Prepare() {
	std::cin >> n >> m;
	for (maxn i = 0; i < m; i++) std::cin >> a[i];
	std::sort(a, a + m);
}


void Process() {
	res = 0, res_cnt = 0;
	for (maxn i = 0; i < m; i++) {
		maxa cnt = (maxa)std::min(n, m - i);
		if (a[i] * cnt < res * res_cnt) continue;
		res = a[i], res_cnt = cnt;
	}
	std::cout << res << ' ' << res * res_cnt;
}


int main() {
	//freopen("dinhgia.inp", "r", stdin);
	//freopen("dinhgia.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}