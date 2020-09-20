#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 1000002

typedef long maxn, maxr;

maxn n, k, tmp;
maxr res;
bool done[maxN];


void Prepare() {
	std::cin >> n >> k;
}


maxn rightNum(const maxn &v) {
	return v <= n - k ? k + v : v - (n - k);
}


void Move(maxn x) {
	tmp = x, ++res;
	do {
		x = rightNum(x);
		done[x] = 1;
		++res;
	} while (x != tmp);
}


void Process() {
	for (maxn i = 1; i <= n; i++) 
		if (!done[i]) Move(i);

	std::cout << res;
}


int main() {
	freopen("sanbay.inp", "r", stdin);
	freopen("sanbay.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}