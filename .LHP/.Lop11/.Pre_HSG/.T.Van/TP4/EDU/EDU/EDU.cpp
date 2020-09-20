#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 100

typedef int maxn;
typedef long long maxa;

maxn n, T, p;
maxa f[maxN], sum[maxN];


void Prepare() {
	std::cin >> n >> T >> p;
}


void Process() {
	std::fill(f, f + maxN, 1);

	for (maxn b = 2; b <= n; b++) {
		sum[(b - 1) * p - 1] = 0;
		for (maxn t = (b - 1) * p; t <= T; t++)
			sum[t] = sum[t - 1] + f[t];
		for (maxn t = b * p; t <= T; t++)
			f[t] = sum[t - p];
	}

	std::cout << f[T];
}


int main() {
	//freopen("edu.inp", "r", stdin);
	//freopen("edu.out", "w", stdout);

	Prepare();
	Process();
}