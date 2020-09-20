#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN (maxa)10000002
#define N (maxN - 2)
#define PR prime.size()

typedef long long maxa;

maxa x;
bool p[maxN];
std::vector <maxa> prime;


void Era() {
	p[0] = p[1] = 1;
	for (maxa i = 2; i <= N; i++) {
		if (p[i]) continue;
		for (maxa j = i * i; j <= N; j += i) p[j] = 1;
		prime.push_back(i);
	}
}


maxa LPD(maxa x) {
	maxa re = 1, LIM = x;
	for (maxa i = 0; i < PR && prime[i] * prime[i] <= LIM && x != 1; i++) 
		while (x % prime[i] == 0) x /= prime[i], re = prime[i];
	return x == 1 ? re : x;
}


void Process() {
	Era();
	while (std::cin >> x && x) {
		if (x < 0) x = -x;
		maxa res = LPD(x);
		if (res == x) std::cout << "-1\n";
		else std::cout << res << '\n';
	}
}


int main() {
	//freopen("11466.inp", "r", stdin);
	//freopen("11466.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Process();
}