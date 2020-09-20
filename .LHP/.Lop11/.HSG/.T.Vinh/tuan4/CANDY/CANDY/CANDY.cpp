#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 300001

typedef int maxn;
typedef long long maxa;

maxn n;
maxa b, a[maxN], r;


void Prepare() {
	std::cin >> b >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i], r = std::max(r, a[i]);
}


bool Check(const maxa mx) {
	maxn cnt = 0;
	for (maxn i = 0; i < n; i++) cnt += (a[i] / mx) + (a[i] % mx != 0);
	return cnt <= b;
}


void Process() {
	maxa l = 1;
	while (l != r) {
		maxa m = (l + r) / 2;
		if (Check(m)) r = m;
		else l = m + 1;
	}
	std::cout << l;
}


int main() {
	freopen("candy.inp", "r", stdin);
	freopen("candy.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}