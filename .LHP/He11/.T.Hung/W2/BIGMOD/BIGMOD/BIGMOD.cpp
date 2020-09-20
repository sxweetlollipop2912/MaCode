#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 200001

typedef long maxn;
typedef long long maxm;
typedef std::string str;

maxm M, res;
str a;


void Prepare() {
	std::cin >> M >> a;
}


void Process() {
	maxm pow = 1;
	res = 0;
	for (maxn i = a.size() - 1; i >= 0; i--) {
		res = (res + (a[i] - (maxm)'0') * pow) % M;
		pow = (pow * 10) % M;
	}
	std::cout << res << '\n';
}


int main() {
	freopen("bigmod.inp", "r", stdin);
	freopen("bigmod.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Prepare();
		Process();
	}
}