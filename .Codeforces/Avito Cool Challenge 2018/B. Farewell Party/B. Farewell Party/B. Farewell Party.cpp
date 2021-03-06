// AC
#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 100000

typedef int maxn;

maxn n, a[maxN], id[maxN];


bool cmp(maxn x, maxn y) {
	return a[x] < a[y];
}


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i];
		id[i] = i;
	}
	std::sort(id, id + n, cmp);
}


bool Process() {

	maxn re[maxN];
	maxn hat = 0, cnt = 0, prev = a[0];

	for (maxn i = 0; i < n; i++) {
		
		if (cnt > 0) {
			if (a[id[i]] != prev) return 0;

			cnt--;
			re[id[i]] = hat;
		}

		else {
			if (a[id[i]] < i) return 0;
			cnt = n - a[id[i]];
			hat++;
			prev = a[id[i]];
			i--;
		}
	}

	std::cout << "Possible\n";
	for (maxn i = 0; i < n; i++) std::cout << re[i] << ' ';
	return 1;
}


int main() {
	Prepare();
	if (!Process()) std::cout << "Impossible";
}