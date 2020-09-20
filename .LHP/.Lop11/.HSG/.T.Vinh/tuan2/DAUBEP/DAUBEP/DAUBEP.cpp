#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>

#define maxN 101
#define maxM 100001
#define maxA 101
#define maxD 1000000

typedef int maxn;
typedef long maxa;

maxn n;
maxa M, recipe[maxN], stock[maxN], ps[maxN], pps[maxN], pb[maxN], ppb[maxN];


void Prepare() {
	std::cin >> n >> M;
	for (maxn i = 0; i < n; i++) std::cin >> recipe[i] >> stock[i] >> ps[i] >> pps[i] >> pb[i] >> ppb[i];
}


maxa price(const maxa need, const maxa ps, const maxa pps, const maxa pb, const maxa ppb) {
	maxa re = ceil(need / (double)ps) * pps;
	for (maxa i = 0; i <= need / ps; i++) {
		re = std::min(re, pps * i + (maxa)ceil((need - ps * i) / (double)pb) * ppb);
	}
	return re;
}


bool Get_material(const maxa dish, maxa M) {
	for (maxn i = 0; i < n; i++) {
		maxa need = std::max(recipe[i] * dish - stock[i], (maxa)0);
		M -= price(need, ps[i], pps[i], pb[i], ppb[i]);
	}
	return M >= 0;
}


void Process() {
	maxa l = 0, r = maxD;
	while (l != r) {
		maxa m = (l + r + 1) / 2;
		if (Get_material(m, M)) l = m;
		else r = m - 1;
	}
	std::cout << l;
}


int main() {
	//freopen("daubep.inp", "r", stdin);
	//freopen("daubep.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}