#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

#define maxA 50002
#define maxE 50023
#define E 50021
//#define P 5135
#define isPrime(x) (!p[x])

typedef long long maxa;

maxa n, MOD, f[maxA];


//************** Era ************************
bool p[maxE];
std::vector <maxa> prime;

void Era() {
	p[0] = p[1] = 1;

	for (maxa i = 2; i <= E; i++) {
		if (p[i]) continue;
		for (maxa j = i * i; j <= E; j += i) p[j] = 1;
		prime.push_back(i);
	}
}
//************** END_OF_Era *****************


void Prepare() {
	Era();
	std::cin >> n;
	MOD = *std::upper_bound(prime.begin(), prime.end(), n);
}


void Process() {
	f[0] = 1;
	for (maxa i = 0; i < prime.size() && prime[i] <= n; i++) for (maxa j = prime[i]; j <= n; j++) f[j] = (f[j] + f[j - prime[i]]) % MOD;
	std::cout << (f[n] + MOD - isPrime(n)) % MOD;
}


int main() {
	//freopen("prime.inp", "r", stdin);
	//freopen("prime.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}