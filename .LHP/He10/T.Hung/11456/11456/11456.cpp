// AC UVa
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

#define maxN 2001

typedef int maxn;
typedef long maxa;	

maxn n, res;
maxa a[maxN];
std::vector <maxa> Lmx, Lmn;


void Prepare() {
	std::cin >> n;
	for (maxn i = n - 1; i >= 0; i--) std::cin >> a[i];

	Lmn.clear();
	Lmx.clear();
}


void Process() {
	res = 0;
	for (maxn i = 0; i < n; i++) {
		maxn LmxU = std::upper_bound(Lmx.begin(), Lmx.end(), a[i]) - Lmx.begin();
		maxn LmnU = std::upper_bound(Lmn.begin(), Lmn.end(), a[i], std::greater <maxa>()) - Lmn.begin();

		if (LmxU == Lmx.size()) Lmx.push_back(a[i]);
		else Lmx[LmxU] = a[i];

		if (LmnU == Lmn.size()) Lmn.push_back(a[i]);
		else Lmn[LmnU] = a[i];

		res = std::max(res, LmxU + LmnU + 1);
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	while (q--) {
		Prepare();
		Process();
		std::cout << res << '\n';
	}
}