// AC UVa
#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 100001
#define maxA 10000001

typedef long maxn, maxa;

maxn n;
maxa a[maxN], res;
int cntq;


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i];
	a[0] = 0;
}


void Process() {
	res = 0;
	maxa mx = 0;

	for (maxn i = n - 1; i >= 0; i--) {
		maxa dist = a[i + 1] - a[i];
		if (res > dist) continue;
		if (res == dist) ++res;
		else res = dist;
		mx = std::max(mx, dist);
	}

	std::cout << "Case " << cntq << ": " << res << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	cntq = 0;
	while (q--) {
		++cntq;
		Prepare();
		Process();
	}
}