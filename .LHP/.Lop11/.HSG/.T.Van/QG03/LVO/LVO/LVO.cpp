#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1001
#define maxM 2001

typedef int maxn, maxm;

maxn n, root[maxN], size[maxN];
int q;


maxn Root(maxn x) {
	while (x != root[x]) x = root[x];
	return x;
}

void Union(maxn x, maxn y) {
	x = Root(x), y = Root(y);

	if (x == y) return;

	if (size[x] < size[y]) root[x] = y, size[y] += size[x];
	else root[y] = x, size[x] += size[y];
}


void Prepare() {
	maxm m = 0;
	std::cin >> n >> m >> q;

	for (maxn i = 0; i < n; i++) root[i] = i, size[i] = 1;

	while (m--) {
		maxn x, y; 
		std::cin >> x >> y, --x, --y;
		Union(x, y);
	}
}


void Process() {
	while (q--) {
		maxn x, y; std::cin >> x >> y, --x, --y;
		std::cout << (Root(x) == Root(y)) << '\n';
	}
}


int main() {
	//freopen("lvo.inp", "r", stdin);
	//freopen("lvo.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}