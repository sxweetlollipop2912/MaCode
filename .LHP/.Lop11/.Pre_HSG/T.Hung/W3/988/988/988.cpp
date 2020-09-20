// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 101

typedef long long maxn;

maxn n;
maxn f[maxN], res;


void Process() {
	std::fill(f, f + n, 0);
	res = 0, f[0] = 1;

	for (maxn u = 0; u < n; u++) {
		maxn choice;
		std::cin >> choice;

		if (!choice) res += f[u];
		else while (choice--) {
			maxn v;
			std::cin >> v;
			f[v] += f[u];
		}
	}

	std::cout << res << '\n';
}


int main() {
	//freopen("988.inp", "r", stdin);
	//freopen("988.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n) 
		Process();
}