#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1000002

typedef long long maxa;

maxa n, k, res;
bool p[maxN];


void Prepare() {
	std::cin >> n >> k;
}


void Era() {
	//p.set();
	res = 0, p[0] = p[1] = 1;

	for (maxa i = 2; i <= n; i++) {
		if (p[i]) continue;
		for (maxa j = i * i; j <= n; j += i) p[j] = 1;
		res += !p[std::max(i - k, (maxa)0)];
	}
}


void Process() {
	Era();
	std::cout << res;
}


int main() {
	//freopen("twins.inp", "r", stdin);
	//freopen("twins.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}