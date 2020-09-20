#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 1000001

typedef long long maxn, maxa;

maxn n;
maxa a[maxN], l, r;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


bool Process() {
	l = 0, r = a[0];

	for (maxn i = 1; i < n; i++) {
		if (a[i] < l) return 0;
		maxa tmp = r;
		r = a[i] - l;
		l = std::max(a[i] - tmp, (maxa)0);
	}

	std::cout << r - l + 1;
	return 1;
}


int main() {
	//freopen("dayso.inp", "r", stdin);
	//freopen("dayso.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << 0;
}