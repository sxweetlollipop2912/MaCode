#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxA 1000001
#define maxN 21

typedef long maxa;

maxa n, res;


void Prepare() {
	std::cin >> n;
}


void Try(const maxa a, const maxa cnt) {
	if ((a << 1) <= n) Try(a << 1, cnt);
	if ((a << 1) + 1 <= n) Try((a << 1) + 1, cnt + 1);
	res += cnt;
}


void Process() {
	Try(1, 1);
	std::cout << res;
}


int main() {
	//freopen("digit.inp", "r", stdin);
	//freopen("digit.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}