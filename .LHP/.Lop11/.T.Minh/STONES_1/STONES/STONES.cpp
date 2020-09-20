#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 10001
#define maxM 100001

typedef int maxn;
typedef long maxm;

maxn n, size[maxN], root[maxN];
maxm m;


void Prepare() {
	std::cin >> n >> m;
	for (maxn i = 0; i < n; i++) size[i] = 1, root[i] = i;
}


void Union(maxn x, maxn y) {
	while (x != root[x]) x = root[x];
	while (y != root[y]) y = root[y];

	if (x == y) return;

	if (size[x] < size[y]) root[x] = y, size[y] += size[x];
	else root[y] = x, size[x] += size[y];
}


void Process() {
	for (maxm i = 0; i < m; i++) {
		maxn a, b;
		std::cin >> a >> b;
		--a, --b;
		Union(a, b);
	}
	std::cout << *std::max_element(size, size + n);
}


int main() {
	//freopen("stones.inp", "r", stdin);
	//freopen("stones.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}