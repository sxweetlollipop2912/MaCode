#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 100002
#define maxA 1000000001

typedef long maxn;
typedef long long maxa;

maxn n, id[maxN];
maxa a[maxN], K;


bool cmp(const maxn &x, const maxn &y) {
	return a[x] < a[y];
}

void Prepare() {
	std::cin >> n >> K >> a[0];
	a[0] -= K;
	id[0] = 0;

	for (maxn i = 1; i < n; i++) {
		std::cin >> a[i];

		a[i] = a[i] - K + a[i - 1];
		id[i] = i;
	}

	std::sort(id, id + n, cmp);

	a[n] = a[n - 1] + 1;
	id[n] = n;
}


void Process() {
	maxn len_r = 0, pos_r = -1, l = id[0], r = id[0];

	for (maxn i = 0; i < n; i++) {
		l = std::min(l, id[i]);
		r = std::max(r, id[i]);

		if (a[id[i]] != a[id[i + 1]]) {
			if (r - l > len_r) {
				len_r = r - l;
				pos_r = l + 1;
			}
			l = id[i + 1];
			r = id[i + 1];
		}
	}

	if (pos_r != -1) std::cout << pos_r + 1 << ' ';
	std::cout << len_r;
}


int main() {
	Prepare();
	Process();
}