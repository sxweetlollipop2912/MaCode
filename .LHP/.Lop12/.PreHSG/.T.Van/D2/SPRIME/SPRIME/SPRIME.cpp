#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 9

typedef long long maxa;
typedef int maxn;

maxn n;
maxa x1[4] = { 2,3,5,7 }, xx[4] = { 1,3,7,9 };


void Prepare() {
	std::cin >> n;
}


bool isPrime(const maxa x) {
	if ((x != 2 && x % 2 == 0) || (x != 3 && x % 3 == 0)) 
		return 0;
	for (maxa i = 1; (6 * i - 1) * (6 * i - 1) <= x; i++)
		if ((x % (6 * i - 1) == 0) || (x % (6 * i + 1) == 0))
			return 0;
	return 1;
}


void Try(const maxa x, const maxn n1) {
	if (!isPrime(x)) return;
	if (n1 == n) {
		std::cout << x << '\n';
		return;
	}
	for (int i = 0; i < 4; i++)
		Try(x * 10 + xx[i], n1 + 1);
}


void Process() {
	for (int i = 0; i < 4; i++) Try(x1[i], 1);
}


int main() {
	//freopen("sprime.inp", "r", stdin);
	//freopen("sprime.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}