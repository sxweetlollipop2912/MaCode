#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iomanip>

#define maxN 300002
#define maxA 1000001
#define eps (maxa)(1e-9)

typedef long maxn;
typedef double maxa;

maxn n, K;
maxa a[maxN], sum[maxN], l, r;


void Prepare() {
	std::cin >> n >> K;
	l = maxA, r = 0;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i], l = std::min(a[i], l), r = std::max(a[i], r);
}


bool Check(const maxa x) {
	sum[0] = 0;
	for (maxn i = 1; i < K; i++) sum[i] = sum[i - 1] + a[i] - x;
	maxa mn = sum[0];
	for (maxn i = K; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i] - x, mn = std::min(mn, sum[i - K]);
		if (sum[i] - mn > eps) return 1;
	}
	return 0;
}


void Process() {
	for(int i = 0; i < 200 && l + eps < r; i++) {
		maxa m = (l + r) / 2.0;
		if (!Check(m)) r = m;
		else l = m;
	}

	std::cout << std::fixed;
	std::cout << std::setprecision(6);
	std::cout << l;
}


int main() {
	//freopen("rate.inp", "r", stdin);
	//freopen("rate.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}