#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>

#define maxN 100001

typedef long maxn;
typedef long maxa;

maxn n, idx[maxN];
maxa a[maxN], e[maxN], MAXA;
std::map <maxa, std::set <maxa> > map;


bool cmp(const maxn x, const maxn y) {
	return e[x] > e[y];
}

void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> e[i] >> a[i], map[a[i]].insert(e[i]), idx[i] = i, MAXA = std::max(MAXA, a[i]);
	std::sort(idx, idx + n, cmp);
}


maxa BS(const maxa A, const maxa E) {
	maxa l = 1, r = MAXA;
	while (l != r) {

	}
}