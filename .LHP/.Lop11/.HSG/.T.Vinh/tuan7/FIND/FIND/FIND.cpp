#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>

#define maxE 10000003
#define E 10000001

typedef long long maxa;

maxa a, b;
bool p[maxE];
std::vector <maxa> prime;


void Prepare() {
	std::cin >> a >> b;
}


void Era() {
	p[0] = p[1] = 1;

	for (maxa i = 2; i <= E; i++) {
		if (p[i]) continue;
		for (maxa j = i * i; j <= E; j += i) p[j] = 1;
		prime.push_back(i);
	}
}


bool isPrime(const maxa x) {
	//std::cout << x << ' ';
	maxa lim = sqrt(x);
	for (maxa i = 0; i < prime.size() && prime[i] <= lim; i++) 
		if (x % prime[i] == 0) return 0;
	//std::cout << 1 << '\n';
	return 1;
}


bool Process() {
	Era();

	if (abs(a - b) == 2) return 1;
	if ((a == 2 || isPrime(a - 2) || isPrime(a + 2)) && (b == 2 || isPrime(b - 2) || isPrime(b + 2))) return 1;

	std::cout << "NO";
	return 0;
}


int main() {
	//freopen("find.inp", "r", stdin);
	//freopen("find.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (Process()) std::cout << "YES";
}