// AC Kattis
#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 200001
#define maxA 200001
#define maxR 40000000001

typedef long maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], res;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
	
	std::sort(a, a + n);
}


void Process() {
	for (maxn i = n - 3; i >= 0; i -= 3) res += a[i];
	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}