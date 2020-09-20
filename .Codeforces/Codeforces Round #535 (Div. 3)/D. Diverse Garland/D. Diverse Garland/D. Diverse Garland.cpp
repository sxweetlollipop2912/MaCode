#include "pch.h"
#include <iostream>

#define maxN 200001
#define R 0
#define G 1
#define B 2
#define maxM 3

typedef long maxa, maxn;

maxn rep[maxM][maxM] = { {1,2,1},{2,0,0},{1,0,1} };
maxn n;
maxa a[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) {
		char c;
		std::cin >> c;

		if (c == 'B') a[i] = B;
		if (c == 'G') a[i] = G;
		if (c == 'R') a[i] = R;
	}

	a[n] = (a[n - 1] + 1) % 3;
	n++;
}


char ch(maxa a) {
	if (a == B) return 'B';
	if (a == G) return 'G';
	return 'R';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();

	maxn step = 0;
	for (maxn i = 1; i < n - 1; i++) {
		if (a[i] != a[i - 1]) continue;
		a[i] = rep[a[i - 1]][a[i + 1]];
		step++;
		i++;
	}

	std::cout << step << '\n';
	for (maxn i = 0; i < n - 1; i++) std::cout << ch(a[i]);
}