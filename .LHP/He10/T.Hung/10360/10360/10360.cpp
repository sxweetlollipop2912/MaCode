// AC UVa
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxC 1026
#define mnC (maxc)0
#define mxC (maxc)1024
#define maxN 20001
#define maxR 5100001
#define maxD 51

typedef int maxn, maxc;
typedef long long maxr;

maxn n;
maxc d, resx, resy;
maxr kill[maxC][maxC];


void Prepare() {
	std::cin >> d >> n;

	for (maxc i = mnC; i <= mxC; i++) 
		std::fill(kill[i], kill[i] + maxC, 0);
}


void Fill(const maxc x, const maxc y, const maxr r) {
	for (maxc i = std::max(x - d, mnC); i <= std::min(x + d, mxC); i++) 
		for (maxc j = std::max(y - d, mnC); j <= std::min(y + d, mxC); j++) 
			kill[i][j] += r;
}


void Process() {
	while (n--) {
		maxc x, y;
		maxr r;
		std::cin >> x >> y >> r;
		Fill(x, y, r);
	}

	resx = resy = 0;
	for (maxc i = mnC; i <= mxC; i++) 
		for (maxn j = mnC; j <= mxC; j++) 
			if (kill[i][j] > kill[resx][resy]) resx = i, resy = j;

	std::cout << resx << ' ' << resy << ' ' << kill[resx][resy] << '\n';
}


int main() {
	//freopen("10360.inp", "r", stdin);
	//freopen("10360.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	while (q--) {
		Prepare();
		Process();
	}
}