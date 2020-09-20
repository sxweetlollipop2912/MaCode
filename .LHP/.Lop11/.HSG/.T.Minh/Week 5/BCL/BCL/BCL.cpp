#include <iostream>
#include <algorithm>
#include <cstdio>

#pragma warning(disable:4996)

#define maxN 2001
#define toChar(x) (char)((x) + 'A')

typedef int maxn, maxa;

maxn n;
bool trace[maxN][maxN];
maxa a[maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		char c; std::cin >> c;
		a[i] = c - 'A';
	}
}


void Trace(const maxn i, const maxn j) {
	if (!trace[i][j]) std::cout << toChar(a[i]);
	else std::cout << toChar(a[j]);

	if (i == j) return;
	if (!trace[i][j]) Trace(i + 1, j);
	else Trace(i, j - 1);
}


void Process() {
	for (maxn i = 0; i < n; i++) trace[i][i] = 0;
	for (maxn i = 1; i < n; i++) trace[i - 1][i] = a[i] < a[i - 1];

	for (maxn len = 3; len <= n; len++) for (maxn i = 0; i <= n - len; i++) {
		maxn j = i + len - 1;
		if (a[i] != a[j]) trace[i][j] = a[j] < a[i];
		else trace[i][j] = trace[i + 1][j - 1];
	}

	Trace(0, n - 1);
}


int main() {
	//freopen("bcl.inp", "r", stdin);
	//freopen("bcl.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}