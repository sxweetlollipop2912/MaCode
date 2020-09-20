#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 400001
#define maxM 1000001
#define MOD (maxr)1000003

typedef long maxn, maxm;
typedef long long maxr;

maxn n, l[maxN], r[maxN];
maxm m, a[maxN];
maxr res;


void Prepare() {
	std::cin >> n >> m;
	for (maxn i = 0; i < 2 * n; i++) std::cin >> a[i];
}


void Process() {
	for (maxn cn = 1; cn <= n; cn++) {
		for (maxn i = cn - 1; i < cn - 1 + cn; i++) {

		}
	}
}