#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 1000001
#define maxA (maxa)21
#define maxR (maxa)999999999

typedef long maxn;
typedef double maxa;

maxn n, left;
maxa a[maxN], b[maxN], rest, res;
bool mn[maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i];
	}
}


maxa Min() {
	maxn re = 0;
	while (mn[re]) ++re;

	for (maxn i = re; i < n; i++) {
		if (!mn[i] && b[re] > b[i]) re = i;
	}

	mn[re] = 1;
	//std::cout << re << ' ' << b[re] << '\n';
	return b[re];
}


void Process() {
	rest = Min() + Min() + Min(); // 1 2 3
	left = Min();                 // 4
	rest += left;

	res = maxR;
	for (maxn i = 0; i < n; i++) {
		maxa tmp = mn[i] ? a[i] + rest - b[i] : a[i] + rest - left;
		if (res > tmp) res = tmp;
	}

	std::cout << res;
}


int main() {
	//freopen("tiepsuc.inp", "r", stdin);
	//freopen("tiepsuc.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}