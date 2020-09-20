// AC SPOJ
#include <iostream>
#include <algorithm>
#include <math.h>

#define maxN 100001
#define maxS 18

typedef long maxn, maxa;

maxn n;
maxa a[maxN][maxS];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i][0];

	for (maxn p = 1; (1 << p) <= n; p++) for (maxn i = 0; i < n - (1 << (p - 1)); i++)
		a[i][p] = std::min(a[i][p - 1], a[i + (1 << (p - 1))][p - 1]);
}


maxn Query(const maxn L, const maxn R) {
	maxn p = log2(R - L + 1);
	return std::min(a[L][p], a[R - (1 << p) + 1][p]);
}


void Process() {
	long q;
	std::cin >> q;

	while (q--) {
		maxn L, R;
		std::cin >> L >> R;
		std::cout << Query(L, R) << '\n';
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}