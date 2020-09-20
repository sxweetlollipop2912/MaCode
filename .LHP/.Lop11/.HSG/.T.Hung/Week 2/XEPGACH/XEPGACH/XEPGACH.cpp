#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 300001
#define maxR 99999999999999999
#define above 1
#define below -1
#define equal 0

typedef long maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], b[maxN], res;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
	for (maxn i = 0; i < n; i++) std::cin >> b[i];
	res = maxR;
}


int Check(const maxa mid) {
	maxn cnta = 0, cntb = 0; maxa cost = 0;

	for (maxn i = 0; i < n; i++) {
		maxa target = mid + abs(n / 2 - i);
		if (std::min(a[i], b[i]) > target) ++cnta;
		if (std::max(a[i], b[i]) < target) ++cntb;
		cost += abs(a[i] - target) + abs(b[i] - target);
	}

	res = std::min(res, cost);
	//std::cout << res << ' ' << cost << ' ' << mid << ' ' << cnta << ' ' << cntb << '\n';
	return cnta > cntb ? above : cnta < cntb ? below : equal;
}


void Process() {
	maxa l = std::min(*std::min_element(a, a + n), *std::min_element(b, b + n)), r = std::max(*std::max_element(a, a + n), *std::max_element(b, b + n));
	while (l != r) {
		maxa m = (l + r) / 2;
		if (Check(m) == above) l = m + 1;
		else r = m;
	}
	std::cout << res;
}


int main() {
	//freopen("xepgach.inp", "r", stdin);
	//freopen("xepgach.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}