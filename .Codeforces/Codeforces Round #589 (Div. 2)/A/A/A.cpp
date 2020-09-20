#include <iostream>
#include <algorithm>

#define maxN 1002
#define none 0
#define f 1
#define nf 2
#define MOD 1000000007

typedef long long maxn;

maxn R, C, r[maxN], c[maxN], res;
int map[maxN][maxN];


void Prepare() {
	std::cin >> R >> C;
	for (maxn i = 0; i < R; i++) std::cin >> r[i];
	for (maxn i = 0; i < C; i++) std::cin >> c[i];
}


void Process() {
	res = 0;

	for (maxn i = 0; i < R; i++) {
		for (maxn j = 0; j < r[i]; j++) {
			if (map[i][j] == nf) return;
			map[i][j] = f;
		}
		if (map[i][r[i]] == f) return;
		map[i][r[i]] = nf;
	}

	for (maxn j = 0; j < C; j++) {
		for (maxn i = 0; i < c[j]; i++) {
			if (map[i][j] == nf) return;
			map[i][j] = f;
		}
		if (map[c[j]][j] == f) return;
		map[c[j]][j] = nf;
	}
	res = 1;
	for (maxn i = 0; i < R; i++) {
		for (maxn j = 0; j < C; j++) if (map[i][j] == none) res = (res * 2) % MOD;
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
	std::cout << res;
}