#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 100001
#define maxA 200001

typedef int maxn, maxa;

struct seg {
	maxa l;
	maxa r;
	maxn id;
};

seg a[maxN];
maxn n;
bool re[maxN];


bool cmp(seg x, seg y) {
	return x.l < y.l;
}


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i].l >> a[i].r;
		a[i].id = i;
	}

	std::sort(a, a + n, cmp);

	std::fill(re, re + n, 0);
}


bool Set() {
	maxa maxr = 0;

	for (maxn i = 0; i < n - 1; i++) {
		re[a[i].id] = 1;
		maxr = std::max(maxr, a[i].r);
		if (maxr < a[i + 1].l) return 1;
	}

	return 0;
}


void Process() {
	Prepare();

	if (!Set()) {
		std::cout << -1 << '\n';
		return;
	}

	for (maxn i = 0; i < n; i++) std::cout << re[i] + 1 << ' ';
	std::cout << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int t;
	std::cin >> t;

	while (t--) Process();
}