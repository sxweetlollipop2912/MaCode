#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 200003
#define none -1
#define all -2

typedef long maxn, maxa;
maxn n, id[maxN];
maxa a[maxN], pref[maxN], posf[maxN];


bool cmp(const maxn &x, const maxn &y) {
	return a[x] < a[y];
}

void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) {
		std::cin >> a[i];
		id[i] = i;
	}
	std::sort(id + 1, id + n + 1, cmp);
	id[0] = 0;
	id[n + 1] = n + 1;
}


void PreCal() {
	std::fill(pref, pref + maxN, none);

	pref[1] = a[id[2]] - a[id[1]];
	for (maxn i = 2; i <= n; i++) {
		if (a[id[i]] - a[id[i - 1]] != pref[i - 1]) break;
		pref[i] = pref[i - 1];
	}

	std::fill(posf, posf + maxN, none);

	posf[n] = a[id[n]] - a[id[n - 1]];
	for (maxn i = n - 1; i >= 1; i--) {
		if (a[id[i + 1]] - a[id[i]] != posf[i + 1]) break;
		posf[i] = posf[i + 1];
		//std::cout << i << ' ' << a[id[i]] << ' ' << posf[i] << '\n';
	}

	pref[0] = pref[1] = posf[n] = posf[n + 1] = all;
	a[id[0]] = a[id[2]] - all;
	//std::cout << a[id[0]] << ' ' << a[id[2]] << '\n';
	a[id[n + 1]] = a[id[n - 1]] + all;
}


bool check(const maxa val1, const maxa val2, const maxa val3) {
	//std::cout << val1 << ' ' << val2 << ' ' << val3 << '\n';
	if (val1 == none || val3 == none) return 0;
	if (val1 == all) return val2 == all || val3 == all || val2 == val3;
	if (val2 == all) return val3 == all || val1 == val3;
	if (val3 == all) return val1 == val2;
	return val1 == val2 && val2 == val3;
}


maxn Process() {
	PreCal();
	for (maxn i = 1; i <= n; i++) {
		//std::cout << i << ' ' << pref[i - 1] << ' ' << a[id[i - 1]] << ' ' << a[id[i + 1]] << ' ' << posf[i + 1] << '\n';
		if (check(pref[i - 1], a[id[i + 1]] - a[id[i - 1]], posf[i + 1])) return id[i];
	}
	return -1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	std::cout << Process();
}
