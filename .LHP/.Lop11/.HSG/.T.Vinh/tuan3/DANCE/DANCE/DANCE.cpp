#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 100001

typedef long maxn;
typedef int maxa;
typedef std::vector <maxa> v_t;

maxn n, res;
v_t mlo, mhi, flo, fhi;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		maxa a; std::cin >> a;
		if (a < 0) mhi.push_back(abs(a));
		else mlo.push_back(a);
	}
	for (maxn i = 0; i < n; i++) {
		maxa a; std::cin >> a;
		if (a < 0) fhi.push_back(abs(a));
		else flo.push_back(a);
	}

	std::sort(mhi.begin(), mhi.end()); std::sort(mlo.begin(), mlo.end());
	std::sort(fhi.begin(), fhi.end()); std::sort(flo.begin(), flo.end());
}


maxn Count(const v_t& lo, const v_t& hi) {
	maxn il = 0, ih = 0, cntl = 0, re = 0;

	while (ih < hi.size()) {
		while (il < lo.size() && lo[il] < hi[ih]) ++cntl , ++il;
		if (cntl) ++re, --cntl;
		++ih;
	}

	return re;
}


void Process() {
	res = Count(flo, mhi) + Count(mlo, fhi);
	std::cout << res;
}


int main() {
	freopen("dance.inp", "r", stdin);
	freopen("dance.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}