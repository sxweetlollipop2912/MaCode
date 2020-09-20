#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1001
#define maxA 1001

typedef int maxn, maxa;

maxn n;
maxa a[maxN], s;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i], s ^= a[i];
}


bool Process() {
	if (!s) return 0;
	for (maxn i = 0; i < n; i++) {
		if ((s ^ a[i]) >= a[i]) continue;
		std::cout << i + 1 << ' ' << a[i] - (s ^ a[i]);
		return 1;
	}
	return 0;
}


int main() {
	//freopen("bocsoi1.inp", "r", stdin);
	//freopen("bocsoi1.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "0 0";
}