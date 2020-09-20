#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 51
//#define maxA 1001

typedef int maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], mn, mx;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
	mn = mx = 0;
	for (maxn i = n - 1; i >= 0; i--) {
		mn = std::max((maxa)0, (mn + a[i]) * 2 - 1);
		mx = (mx + a[i]) * 2 + 1;
	}
	std::cout << mn << '\n' << mx;
}


int main() {
	//freopen("caygiong.inp", "r", stdin);
	//freopen("caygiong.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}