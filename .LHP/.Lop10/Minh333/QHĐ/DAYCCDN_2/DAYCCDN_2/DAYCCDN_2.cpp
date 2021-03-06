#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


#define maxN 5002
#define maxA 256

typedef int maxn, maxa;

maxa a[maxN], b[maxN];
std::vector <maxn> cb;
maxn m, n, f[maxN][maxN];

void Prepare() {
	//freopen("DAYCCDN.inp", "r", stdin);
	//freopen("DAYCCDN.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin >> m >> n;
	for (maxn i = 0; i < m; i++) std::cin >> a[i];
	for (maxn i = 0; i < n; i++) std::cin >> b[i];
}


void Trace() {

	maxn i = 1, j = 1;

	while (i <= m && j <= n) {

		if (a[i - 1] == b[j - 1]) {
			std::cout << i << " ";
			cb.push_back(j);
			i++; j++;
		}

		else if (f[i][j] == f[i][j + 1]) j++;

		else i++;
	}
}


int main() {
	Prepare();

	for (maxn i = m; i > 0; i--) 
		for (maxn j = n; j > 0; j--) {
			if (a[i - 1] == b[j - 1]) f[i][j] = f[i + 1][j + 1] + 1;
			else f[i][j] = std::max(f[i + 1][j], f[i][j + 1]);
		}

	std::cout << f[1][1] << '\n';

	Trace();

	std::cout << '\n';
	for (maxn i = 0; i < cb.size(); i++) std::cout << cb[i] << ' ';
}
