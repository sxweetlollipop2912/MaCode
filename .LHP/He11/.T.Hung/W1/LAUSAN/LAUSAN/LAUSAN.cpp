#include <iostream>
#include <cstdio>
#include <algorithm>

typedef long maxa;

int main() {
	freopen("lausan.inp", "r", stdin);
	freopen("lausan.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long t; std::cin >> t;
	while (t--) {
		maxa m, n; std::cin >> m >> n;
		if (n > m) std::swap(m, n);
		--n;

		maxa res = 4 * ((n + 1) / 2) - 1;
		if (n % 2 == 0) {
			if (m == n) --res;
		}
		else {
			if (m == n) res -= 3;
			else res -= 2;
		}
		++res;
		res = std::max(res, (maxa)0);

		std::cout << res << '\n';
	}
}