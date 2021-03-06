//AC
#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 5001
#define maxA 5001

typedef int maxn, maxa;

maxa re[maxN], cnt[maxN], cur[maxA];
maxn n;
maxa k, m;


bool Prepare() {
	std::cin >> n >> k;

	for (maxn i = 0; i < n; i++) {
		maxa a;
		std::cin >> a;

		re[i] = ++cur[a];
		if (re[i] > k) return 0;

		cnt[re[i]]++;
		m = std::max(m, re[i]);
	}

	return 1;
}


int main() {
	if (!Prepare()) {
		std::cout << "NO";
		return 0;
	}

	for (maxn i = 0; i < n && m < k; i++) {
		if (cnt[re[i]] == 1) continue;

		cnt[re[i]]--;
		re[i] = ++m;
		cnt[re[i]]++;
	}

	std::cout << "YES\n";
	for (maxn i = 0; i < n; i++) std::cout << re[i] << ' ';
}