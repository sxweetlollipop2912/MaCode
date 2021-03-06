// W >= 0
#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

#define maxN 50
#define maxW 50000
typedef int maxn;
typedef int maxa;

maxa a[maxN];
maxn n;
long long W, re, S;

void Prepare() {
	std::cin >> n >> W;
	for (int i = 0; i < n; i++) std::cin >> a[i];
	std::sort(a, a + n);
}

void Try(maxn i) {
	
	re = std::max(re, S);

	while (i < n && S + a[i] <= W) {
		S += a[i];
		Try(i + 1);
		S -= a[i];
		i++;
	}
}

int main() {
	Prepare();
	re = 0;
	Try(0);
	std::cout << re;
}