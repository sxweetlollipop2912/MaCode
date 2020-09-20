#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 501

typedef int maxn;
typedef std::vector <maxn> num_t;

maxn n, K, a[maxN];
num_t f[maxN];


void Prepare() {
	std::cin >> K >> n;
	for (maxn i = 0; i < K; i++) std::cin >> a[i];
}


void add(num_t& x1, const num_t& x2) {
	for (maxn i = 0; i < x1.size() && i < x2.size(); i++)
		x1[i] += x2[i];
	for (maxn i = x1.size(); i < x2.size(); i++) x1.push_back(x2[i]);

	for (maxn i = 1; i < x1.size(); i++)
		x1[i] += (x1[i - 1] / 10), x1[i - 1] %= 10;
	while (x1.back() >= 10) {
		maxn x = x1.back();
		x1.back() %= 10; x1.push_back(x / 10);
	}
}


void Process() {
	for (maxn i = 1; i <= n; i++) f[i].push_back(0);
	f[0].push_back(1);

	for (maxn i = 1; i <= n; i++) for (maxn j = 0; j < K; j++) {
		if (a[j] > i) continue;
		add(f[i], f[i - a[j]]);
	}
	for (maxn i = f[n].size() - 1; i >= 0; i--) std::cout << f[n][i];
}


int main() {
	//freopen("coc.inp", "r", stdin);
	//freopen("coc.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}