// AC UVa
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>

#define maxN 200002
#define maxA 1001
#define maxR 200000001

typedef long long maxn, maxa;

maxn n, cntq;
maxa a[maxN], bit[maxN];


void Update(maxn id, const maxn x) {
	while (id <= n) {
		bit[id] += x;
		id += (id & (-id));
	}
}


maxn Sum(maxn id) {
	maxn re = 0;
	while (id > 0) {
		re += bit[id];
		id -= (id & (-id));
	}
	return re;
}


void Prepare() {
	std::fill(bit, bit + n + 1, 0);

	for (maxn i = 1; i <= n; i++) {
		std::cin >> a[i];
		Update(i, a[i]);
	}
}


void Process() {
	std::cout << "Case " << cntq << ":\n";

	std::string s;
	while (std::cin >> s && s != "END") {
		if (s[0] == 'M') {
			maxn l, r;
			std::cin >> l >> r;
			std::cout << Sum(r) - Sum(l - 1) << '\n';
		}
		else {
			maxn id; maxa x;
			std::cin >> id >> x;
			Update(id, x - a[id]);
			a[id] = x;
		}
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) {
		cntq++;
		Prepare();
		Process();
	}
}