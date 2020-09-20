// AC UVa
#include <iostream>
#include <cstdio>
#include <vector>

#define val first
#define sum second
#define SQRT (maxa)31623

typedef long long maxa;
typedef std::pair<maxa, int> info;

std::vector<info> prime;


int Sum(maxa a) {
	int re = 0;
	while (a != 0) re += a % 10, a /= 10; 
	return re;
}


void Era() {
	std::vector <bool> p(SQRT + 1, 1);
	p[0] = p[1] = 0;

	for (maxa i = 2; i <= SQRT; i++) {
		if (!p[i]) continue;
		for (maxa j = i * i; j <= SQRT; j += i) p[j] = 0;
		prime.push_back(info(i, Sum(i)));
	}
}


bool Check(maxa a) {
	maxa s = Sum(a), limit = a / 2;
	bool flag = 0;

	for (maxa i = 0; i < prime.size() && prime[i].val <= limit; i++) {
		while (a % prime[i].val == 0)
			s -= prime[i].sum, a /= prime[i].val, flag = 1;
	}

	if (!flag) return 0;
	if (a != 1) while (a != 0) s -= a % 10, a /= 10;
	return s == 0;
}


int main() {
	freopen("10042.inp", "r", stdin);
	freopen("10042.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Era();

	int q;
	std::cin >> q;

	while (q--) {
		maxa a;
		std::cin >> a;
		while (!Check(++a));
		std::cout << a << '\n';
	}
}