#include <iostream>
#include <algorithm>
#include <cstdio>
#include <deque>

#define maxN 220002

typedef long maxn;
typedef long long maxa;

maxn n, m;
maxa a[maxN], res[maxN];


void Prepare() {
	std::cin >> n >> m;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i];
}


void Process() {
	maxa sum = 0, p = 0;
	std::deque <maxn> de;

	for (maxn i = 1; i <= n; i++) {
		while (!de.empty() && res[de.back()] > res[i - 1]) de.pop_back();
		de.push_back(i - 1);

		while (de.front() < i - m) de.pop_front();
		
		maxn prev = de.front();
		sum += a[i], res[i] = sum - res[prev];
		//std::cout << i << ' ' << f[i - 1] << ' ' << prev << ' ' << p << ' ' << res[i] << ' ' << sum[i] - res[i] << '\n';
	}

	std::cout << res[n];
}


int main() {
	//freopen("stacker.inp", "r", stdin);
	//freopen("stacker.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}