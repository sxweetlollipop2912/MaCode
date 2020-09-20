#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 2001

typedef int maxn;
typedef long long maxa;

maxn m, n;
maxa R, a[maxN][maxN], t[maxN][maxN], t1[maxN][maxN], t2[maxN][maxN];


void Prepare() {
	std::cin >> m >> n >> R;
	for (maxn j = 0; j < n; j++) std::cin >> a[0][j];
}


void Process() {
	for (maxn j = 0; j < n; j++) t[0][j] = t1[0][j] = t2[0][j] = a[0][j] % R;

	for (maxn i = 1; i < m; i++) for (maxn j = 0; j < n; j++) {
		t1[i][j] = (j != 0? t1[i - 1][j - 1] : 0) % R;
		t2[i][j] = (j != n - 1? t2[i - 1][j + 1] : 0) % R;
		t[i][j] = ((t1[i][j] + t2[i][j]) % R + t[i - 1][j]) % R;
		t1[i][j] += t[i][j];
		t2[i][j] += t[i][j];
		t[i][j] += t[i][j];
	}

	for (maxn j = 0; j < n; j++) std::cout << t[m - 1][j] / 2 << ' ';
}


int main() {
	//freopen("table.inp", "r", stdin);
	//freopen("table.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}