#include "pch.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

#define maxN 100001
#define maxK 100001
#define maxM 10000001
#define maxA 1000001

typedef long long maxn, maxa, maxm;
typedef double maxr;

maxn n, q, dec;
maxm k, m, inc[maxN];
maxa a[maxN];
maxn begin;
maxa t;


void Prepare() {
	std::cin >> n >> k >> m;
	q = n;

	for (maxn j = m, i = n - 1; j > 0 && i >= 0; j -= k, i--) {
		dec = i;
		inc[i] = std::min(j, k);
	}

	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i];
		t += a[i] + inc[i];
	}

	std::sort(a, a + n);
	begin = 0;
}


bool check() {
	if (q == 1) return 0;
	return t * (q - 1) < (t - a[begin] - std::max(inc[begin], (maxm)1)) * q;
}


void Process() {
	while (m--) {
		if (!check()) return;

		t = t - a[begin] - std::max(inc[begin], (maxm)1);
		q -= 1;
		begin++;

		if (inc[begin - 1]) continue;

		if (!inc[dec]) dec++;
		inc[dec]--;
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
	maxr res = t / (maxr)q;

	std::cout << std::fixed;
	std::cout << std::setprecision(7) << res;
}