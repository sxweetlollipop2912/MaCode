#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxS 1000000000000
#define maxQ 101
#define maxC 100
#define bok 0
#define pen 1
#define bag 2

typedef long long maxa, maxn;

maxa S, P, p[3], t[3], c[3];
maxn res;
//maxn x[3];


void Prepare() {
	std::cin >> S;

	std::cin >> p[bok] >> p[pen] >> p[bag];
	std::cin >> t[bok] >> t[pen] >> t[bag];
	std::cin >> c[bok] >> c[pen] >> c[bag];

	P = c[bok]*p[bok] + c[pen]*p[pen] + c[bag]*p[bag];
}


void Process() {
	while (S > 0 && (t[bok] > 0 || t[pen] > 0 || t[bag] > 0)) {
		maxa cost = P;
		cost -= (t[bok] > 0)*std::min(t[bok], p[bok])*c[bok];
		cost -= (t[pen] > 0)*std::min(t[pen], p[pen])*c[pen];
		cost -= (t[bag] > 0)*std::min(t[bag], p[bag])*c[bag];

		S -= cost;
		t[bok] -= p[bok];
		t[pen] -= p[pen];
		t[bag] -= p[bag];

		res += S >= 0;

		//if (S >= 0) x[bok] += p[bok], x[pen] += p[pen], x[bag] += p[bag];
	}

	res += (S > 0)*(S / P);

	//if (S > 0) x[bok] += p[bok]* (S / P), x[pen] += p[pen]* (S / P), x[bag] += p[bag]* (S / P);
	//std::cout << x[bok] << ' ' << x[pen] << ' ' << x[bag] << '\n';

	std::cout << res;
}


int main() {
	//freopen("chuanbi.inp", "r", stdin);
	//freopen("chuanbi.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}