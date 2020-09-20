#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 300001

typedef long maxn, maxa;

maxn n, lo, hi;
maxa a[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


class cmp {
public:
	bool operator()(const maxa x, const maxa y) {

	}
};