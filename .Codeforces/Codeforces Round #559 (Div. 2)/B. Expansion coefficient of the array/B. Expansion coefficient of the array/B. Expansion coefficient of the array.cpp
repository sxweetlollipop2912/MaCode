#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 300001
#define maxA 1000000000

typedef long maxn, maxa;

maxn n;
maxa a[maxN], K;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
	maxn l = 0, r = n - 1;
	maxa mini = K = maxA;

	while (l <= r) {
		mini = std::min(mini, std::min(a[l], a[r]));
		K = std::min(K, mini / r);
		l++; r--;
	}

	std::cout << K;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare(); 
	Process();
}