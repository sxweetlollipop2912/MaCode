#include "pch.h"
#include <iostream>
#include <fstream>

//constexpr auto mod = 1000000007;
#define mod 1000000007;

bool snt[1000000];
int n, k;
long long re;

void Prepare() {
	//freopen("BT20.inp", "r", stdin);
	//freopen("BT20.out", "w", stdout);
	std::cin >> n >> k;
}


void Era() {
	snt[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (snt[i] == 1) continue;
		int x = 2;
		while (x*i <= n) {
			snt[x*i] = 1;
			x++;
		}
	}
}


int Legendre(int k, int n) {
	int re = 0, p = k;
	while (n / p > 0) {
		re += n / p;
		p *= k;
	}
	return re;
}


int result(int p, int z) {
	int re = 1;
	for (int i = 0; i < z; i++) 
		re = (re * p) % mod;
	return re % mod;
}


int main() {
	Prepare();
	Era();
	re = 1;
	for (int i = 2; i <= n; i++) {
		if (snt[i] == 1) continue;
		int z = Legendre(i, n) - Legendre(i, k) - Legendre(i, n - k);
		re = (re * result(i, z)) % mod;
	}
	std::cout << re;
}