#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iomanip>

#define maxN 100002
//#define maxA 1000000001

typedef long maxn;
typedef double maxa;

const maxa eps = 1e-9;

maxn n;
maxa L, a[maxN];


void Prepare() {
	std::cin >> n >> L;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
	std::sort(a, a + n);
}


bool Check(const maxa D) {
	maxa cur = 0;
	for (maxn i = 0; i < n; i++) {
		maxa tmp = std::min(cur, a[i]) + D;
		if (tmp - eps > a[i]) cur = std::max(cur, tmp);
		else return 0;
	}
	if (cur - eps > L) return 1; else return 0;
}


void Process() {
	maxa l = 0, r = L;
	for (maxn i = 0; i < 150 && r - l > eps; i++) {
		maxa m = (l + r) / (maxa)2;
		if (!Check(m)) l = m;
		else r = m;
	}
	std::cout << std::fixed; std::cout << std::setprecision(2);
	std::cout << l;
}


int main() {
	//freopen("denduong.inp", "r", stdin);
	//freopen("denduong.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}