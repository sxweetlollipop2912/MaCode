// UNDONE
#include "pch.h"
#include <iostream>
#include <algorithm>

typedef int maxn;

int a[200001], n, k, id[200001], max;

void Prepare() {
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int c;
		std::cin >> c;
		max = std::max(max, c);
		a[c]++;
		id[i] = i;
	}
}

void Qsort(maxn l, maxn r) {
	if (l + 1 > k) return;
	maxn x = a[id[(l + r) / 2]];
	maxn i = l, j = r;
	while (a[id[i]] > x) i++;
	while (a[id[j]] < x) j--;
	if (i <= j) {
		x = id[i];
		id[i] = id[j];
		id[j] = x;
		i++; j--;
	}
	if (l < j) Qsort(l, j);
	if (i < r) Qsort(i, r);
}


int main() {
	Prepare();
	Qsort(0, max);
	int di = a[id[k - 1]];

}