#include "pch.h"
#include <iostream>
#include <fstream>

#pragma warning(disable:4996)
#define maxN 501
#define maxM 100001

typedef long maxn;

maxn n;
bool d[maxN][maxN], done[maxN];
maxn place[maxN], b, f;

void Prepare() {
	freopen("VASES.inp", "r", stdin);
	freopen("VASES.out", "w", stdout);
	long m = 0;
	std::cin >> n >> m;
	maxn u, v;
	for (maxn i = 0; i < m; i++) {
		std::cin >> u >> v;
		d[u - 1][v - 1] = 1;
	}
}


void DFSf(maxn a, maxn x) {
	done[x] = 1;
	for (maxn i = 0; i < n; i++) {
		if (!d[x][i] || done[i]) continue;
		f++;
		DFSf(a, i);
	}
}


void DFSb(maxn a, maxn x) {
	done[x] = 1;
	for (maxn i = 0; i < n; i++) {
		if (!d[i][x] || done[i]) continue;
		b++;
		DFSb(a, i);
	}
}


int main() {
	Prepare();
	
	maxn count = 0;
	for (maxn i = 0; i < n; i++) {
		b = f = 0;
		
		std::fill(done, done + n, 0);
		DFSf(i, i);
		
		std::fill(done, done + n, 0);
		DFSb(i, i);
		
		if (b + f == n - 1) {
			place[b] = i + 1;
			count++;
		}
	}
	
	std::cout << count;

	for (maxn i = 0; i < n; i++) 
		if (place[i] != 0) std::cout << '\n' << place[i] << ' ' << i + 1;
}