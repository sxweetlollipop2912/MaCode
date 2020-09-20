#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>

#define maxN 1001
#define maxM 100001

typedef int maxn, maxm;
typedef long long maxa;

maxn n, root[maxN], size[maxN], mx[maxN], res;
maxm m;
maxa a[maxN];
std::multiset <maxa> set[maxN];


maxn Root(maxn x) {
	while (x != root[x]) x = root[x];
	return x;
}


bool Union(maxn x, maxn y) {
	x = Root(x), y = Root(y);

	if (x == y) return 0;

	if (size[x] > size[y]) root[y] = x, size[x] += size[y];
	else root[x] = y, size[y] += size[x];

	return 1;
}


void Prepare() {
	std::cin >> n >> m;
	for (maxn i = 0; i < n; i++) std::cin >> a[i], root[i] = i, size[i] = 1;

	while (m--) {
		maxn x, y; 
		std::cin >> x >> y, --x, --y;
		Union(x, y);
	}
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		maxn ri = Root(i);
		set[ri].insert(a[i]);
		mx[ri] = std::max(mx[ri], (maxn)set[ri].count(a[i]));
		//std::cout << i << ' ' << ri << ' ' << a[i] << ' ' << mx[ri] << '\n';
	}
	for (maxn i = 0; i < n; i++) 
		if (i == Root(i)) res += size[i] - mx[i];

	std::cout << res;
}


int main() {
	freopen("meet.inp", "r", stdin);
	freopen("meet.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}