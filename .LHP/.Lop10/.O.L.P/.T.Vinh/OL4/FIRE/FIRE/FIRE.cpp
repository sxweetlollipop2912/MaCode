#include "pch.h"
#include <cstdio>
#include <iostream>
#include <algorithm>

#define maxW 200001
#define maxH 500001

typedef long maxn, maxh;

maxn cnt[maxH], W;
maxh H;


void Prepare() {
	std::cin >> W >> H;

	for (maxn i = 0; i < W; i++) {
		maxh a;
		std::cin >> a;

		if (i % 2 == 0) {
			cnt[0]++;
			cnt[a]--;
		}
		else 
			cnt[H - a]++;
	}
}


void Process() {
	maxn res = cnt[0];
	maxh ways = 1;

	for (maxh i = 1; i < H; i++) {
		cnt[i] += cnt[i - 1];

		if (res > cnt[i]) {
			res = cnt[i];
			ways = 1;
		}
		else if (res == cnt[i]) ways++;
	}

	std::cout << res << ' ' << ways;
}


int main() {
	Prepare();
	Process();
}