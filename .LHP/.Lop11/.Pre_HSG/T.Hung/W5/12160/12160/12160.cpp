// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

#define maxA 100000
#define maxN 11
#define MOD 10000

typedef int maxn;
typedef long maxa;

maxn n;
maxa L, U, b[maxN], cnt[maxA];


void Prepare() {
	for (maxn i = 0; i < n; i++) std::cin >> b[i];
	std::fill(cnt, cnt + maxA, maxA);
}


void Process() {
	bool exist[maxA] = {};
	std::queue <maxa> q;
	q.push(L); cnt[L] = 0; exist[L] = 1;

	while (!q.empty()) {
		L = q.front(); q.pop(); exist[L] = 0;
		for (maxn i = 0; i < n; i++) {
			maxa val = (b[i] + L) % MOD;
			if (cnt[L] + 1 >= cnt[val]) continue;

			if (!exist[val]) q.push(val); 
			exist[val] = 1, cnt[val] = cnt[L] + 1;
		}
	}

	if (cnt[U] == maxA) std::cout << "Permanently Locked \n";
	else std::cout << cnt[U] << '\n';
}


int main() {
	freopen("12160.inp", "r", stdin);
	freopen("12160.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int cntq = 0;
	while (std::cin >> L >> U >> n && n) {
		++cntq, std::cout << "Case " << cntq << ": ";
		Prepare();
		Process();
	}
}