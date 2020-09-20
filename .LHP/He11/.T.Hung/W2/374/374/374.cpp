#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning(disable:4996)

typedef long long maxa;

maxa a, p, M;


maxa pow(maxa a, maxa P, maxa MOD) {
	maxa re = 1, x = a;
	for (maxa p = P; p != 0; p >>= 1) {
		if (p & 1) re = (re * x) % MOD;
		x = (x * x) % MOD;
	}
	return (re % MOD);
}


void Process() {
	std::cout << pow(a, p, M) << '\n';
}



int main() {
	freopen("374.inp", "r", stdin);
	freopen("374.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> a >> p >> M) Process();
}