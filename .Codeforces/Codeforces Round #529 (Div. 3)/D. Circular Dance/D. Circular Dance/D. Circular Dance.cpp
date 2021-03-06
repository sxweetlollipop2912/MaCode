// AC
#include "pch.h"
#include <iostream>

#define maxN 200002

typedef long maxn;

maxn a[maxN][2], n;
bool done[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i][0] >> a[i][1];
}


maxn pick(maxn z) {
	maxn x = a[z][0], y = a[z][1];

	if (done[x] ^ done[y]) {
		if (done[x]) return y;
		return x;
	}

	if (done[x] & done[y]) return -1;

	if (a[x][0] == y || a[x][1] == y) return x;
	return y;
}


int main() {
	Prepare();
	
	maxn x = 1;
	while (x != -1) {
		done[x] = 1;
		std::cout << x << ' ';
		x = pick(x);
	}
}