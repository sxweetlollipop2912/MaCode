#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1000001
#define maxA 1000000001
#define val first
#define idx second

typedef long maxn, maxa;
typedef std::pair <maxa, maxn> p_t;

maxn na, nb, resa, resb;
p_t a[maxN], b[maxN];
maxa S, res;


void Prepare() {
	std::cin >> na >> nb >> S;
	for (maxn i = 0; i < na; i++) std::cin >> a[i].val, a[i].idx = i;
	for (maxn i = 0; i < nb; i++) std::cin >> b[i].val, b[i].idx = i;
	std::sort(a, a + na, std::greater<p_t>());
	std::sort(b, b + nb);
}


void Process() {
	resa = resb = res = -1;
	for (maxn ia = 0, ib = 0; ia < na; ia++) for (; ib < nb && a[ia].val + b[ib].val <= S; ib++) {
		if (res >= a[ia].val + b[ib].val) continue;
		res = a[ia].val + b[ib].val, resa = a[ia].idx, resb = b[ib].idx;
	}
	if (res == -1) std::cout << 0;
	else std::cout << resa + 1 << ' ' << resb + 1;
}


int main() {
	//freopen("flowers.inp", "r", stdin);
	//freopen("flowers.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}