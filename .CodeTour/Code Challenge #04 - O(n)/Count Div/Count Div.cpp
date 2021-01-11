#include <iostream>
#include <algorithm>
#include <vector>

#define maxE 100002
#define E 100000
#define MOD 1000000007

typedef long long maxa;

bool p[maxE];
std::vector <maxa> prime;
maxa X, Y, res;


void Era() {
	p[0] = p[1] = 1;

	for (maxa i = 2; i <= E; i++) {
		if (p[i]) continue;
		for (maxa j = i * i; j <= E; j += i) p[j] = 1;
		prime.push_back(i);
	}
}


void Prepare() {
	std::cin >> X >> Y;
}


maxa Legendre(maxa k, maxa n) {
	maxa re = 0, p = k;
	while (n / p != 0) {
		re += n / p;
		p *= k;
	}
	return re;
}


void Process() {
	res = 1;
	for (maxa i = 0; i < prime.size() && prime[i] <= Y; i++) {
		res = (res * (Legendre(prime[i], Y) - Legendre(prime[i], X - 1) + 1) % MOD) % MOD;
		//std::cout << prime[i] << ' ' << Legendre(prime[i], Y) << ' ' << Legendre(prime[i], X - 1) << ' ' << res << '\n';
	}
	std::cout << res << '\n';
}


int main() {
	Era();
	int t; std::cin >> t;
	while (t--) {
		Prepare();
		Process();
	}
}