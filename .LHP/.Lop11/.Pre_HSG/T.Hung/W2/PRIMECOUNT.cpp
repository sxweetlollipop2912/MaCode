#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define SQRT (maxa)31700

typedef long maxa;

std::vector<maxa> prime;
maxa L, R;


void Era() {
	std::vector<bool> p(SQRT + 1, 0);
	for (maxa i = 2; i <= SQRT; i++) {
		if (p[i]) continue;
		for (maxa j = i * i; j <= SQRT; j += i) p[j] = 1;
		prime.push_back(i);
	}
}


maxa Era_range(const maxa L, const maxa R) {
	std::vector<bool> p(R - L + 2, 0);

	for (int i = 0; i < prime.size() && prime[i] * prime[i] <= R; i++) {
		for (int j = prime[i] >= L ? prime[i] * 2 : prime[i] * (L / prime[i] + (bool)(L % prime[i])); j <= R; j += prime[i]) p[j - L] = 1;
	}

	maxa re = 0;
	for (maxa i = L; i <= R; i++) re += !p[i - L];
	return re;
}


int main() {
	freopen("PRIMECOUNT.inp", "r", stdin);
	freopen("PRIMECOUNT.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Era();

	int q;
	std::cin >> q;

	while (q--) {
		std::cin >> L >> R;
		std::cout << Era_range(std::max(L, (maxa)2), R) << '\n';
	}
}