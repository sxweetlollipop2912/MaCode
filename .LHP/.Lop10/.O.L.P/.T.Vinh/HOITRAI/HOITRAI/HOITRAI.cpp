#include "pch.h"
#include <iostream>
#include <cstdio>

#define maxN 301
#define maxM 22001
#define maxW 99999999999999999

typedef int maxn;
typedef long long maxm;

maxn n;
maxm m, k, re[maxN][maxN];
maxm d[maxN][maxN];


void Prepare() {
	std::cin >> n >> m >> k;

	for (maxn i = 0; i < n; i++) {
		std::fill(d[i], d[i] + n, maxW);
		d[i][i] = 0;
	}

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;

		u--; v--;
		d[u][v] = d[v][u] = re[u][v] = re[v][u] = 1;
	}

}


void Floyd() {
	for(maxn k = 0; k < n; k++) 
		for(maxn i = 0; i < n; i++)
			for (maxn j = 0; j < n; j++) {

				maxm x = d[i][k] + d[j][k];
				maxm way = d[i][k] * d[j][k];

				if (d[i][j] > x) {
					d[i][j] = x;
					re[i][j] = way;
				}
				else if (d[i][j] == x) re[i][j] += way;
			}
}


int main() {
	Prepare();
	Floyd();
	
	for (maxm i = 0; i < k; i++) {
		maxn u, v;
		std::cin >> u >> v;
		u--; v--;

		std::cout << re[u][v] << '\n';
	}
}