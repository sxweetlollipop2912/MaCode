#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 41
#define maxA 1000000000000000001

typedef int maxn;
typedef long long maxa, maxr;

maxn n, na, nb;
maxa T, a[maxN];
std::vector <maxa> nat;
maxr res;


void Prepare() {
	std::cin >> n >> T;
	na = n / 2; nb = n - na;

	for (maxn i = 0; i < n; i++)
		std::cin >> a[i];
}


void Na() {
	for (maxr i = 0; i < (1 << na); i++) {
		maxa t = 0; maxn id = 0;
		while (id < na) t += a[id] * (bool)(i & (1 << id)), ++id;
		nat.push_back(t);
	}
	std::sort(nat.begin(), nat.end());
}


maxr fit(const maxa x) {
	return std::upper_bound(nat.begin(), nat.end(), x) - nat.begin();
}


void Nb() {
	for (maxr i = 0; i < (1 << nb); i++) {
		maxa t = 0; maxn id = 0;
		while (id < nb) t += a[id + na] * (bool)(i & (1 << id)), ++id;
		res += fit(T - t);
	}
}


void Process() {
	Na();
	Nb();
	std::cout << res;
}


int main() {
	//freopen("khuyenmai.inp", "r", stdin);
	//freopen("khuyenmai.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}