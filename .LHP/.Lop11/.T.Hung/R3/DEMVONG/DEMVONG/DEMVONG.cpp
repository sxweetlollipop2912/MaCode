#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100
#define eps (maxa)1e-7
#define sqr(x) (maxa)((x) * (x))
#define d(id1, id2) (maxa)(sqr(x[id1] - x[id2]) + sqr(y[id1] - y[id2]))

typedef int maxn;
typedef double maxa;

maxn n, res, cnt[maxN], root[maxN];
maxa x[maxN], y[maxN], r[maxN];


void Prepare() {
	for (maxn i = 0; i < n; i++) std::cin >> x[i] >> y[i] >> r[i], root[i] = i, cnt[i] = 1;
}


bool Intersect(const maxn id1, const maxn id2) {
	return d(id1, id2) < (sqr(r[id1] + r[id2]) - eps) && (d(id1, id2) - eps) > sqr(r[id1] - r[id2]);
}


maxn Union(maxn x, maxn y) {
	while (x != root[x]) x = root[x];
	while (y != root[y]) y = root[y];

	if (x == y) return cnt[x];

	if (cnt[x] < cnt[y]) std::swap(x, y);
	root[y] = x, cnt[x] += cnt[y];

	return cnt[x];
}


void Process() {
	res = 1;
	for (maxn i = 0; i < n; i++) for (maxn j = i + 1; j < n; j++) {
		if (Intersect(i, j)) res = std::max(res, Union(i, j));
	}
	std::cout << res << '\n';
}


int main() {
	freopen("demvong.inp", "r", stdin);
	freopen("demvong.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n != -1) {
		Prepare();
		Process();
	}
}