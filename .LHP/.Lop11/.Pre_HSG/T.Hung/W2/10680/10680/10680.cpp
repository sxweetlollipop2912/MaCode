//AC UVa
#include <iostream>
#include <cstdio>
#include <vector>

#define maxN 1000001
#define maxE 1000002
#define E (maxn)1000000

typedef long long maxn;

maxn n, res;
std::vector <maxn> prime;


void Era() {
	std::vector <bool> p(maxE, 1);
	p[0] = p[1] = 0;

	for (maxn i = 2; i <= 5; i++) 
		for (maxn j = i * i; j <= E; j += i) p[j] = 0;

	prime.push_back(3);
	for (maxn i = 7; i <= E; i++) {
		if (!p[i]) continue;
		for (maxn j = i * i; j <= E; j += i) p[j] = 0;
		prime.push_back(i);
	}
}


void Process() {
	maxn cnt2 = 0, cnt5 = 0;
	res = 1;

	for (maxn i = 2; i <= n; i *= 2) ++cnt2;
	for (maxn i = 5; i <= n; i *= 5) ++cnt5;
	for (maxn i = 1; i <= cnt2 - cnt5; i++) res = (res * 2) % 10;

	for (maxn i = 0; i < prime.size() && prime[i] <= n; i++)
		for (maxn j = prime[i]; j <= n; j *= prime[i])
			res = (res * prime[i]) % 10;

	std::cout << res << '\n';
}




int main() {
	//freopen("10680.inp", "r", stdin);
	//freopen("10680.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Era();

	while (std::cin >> n && n)
		Process();
}