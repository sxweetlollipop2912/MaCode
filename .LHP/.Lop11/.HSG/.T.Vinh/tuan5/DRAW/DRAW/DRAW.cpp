#include <iostream>
#include <algorithm>
#include <cstdio>

#pragma warning(disable:4996)

#define maxN 1003
#define maxG 1000002
#define maxK 10002
#define idx(x, y) (((x) - 1) * n + ((y) - 1))
#define x first
#define y second

typedef long maxn;
typedef int maxk;
typedef std::pair <maxn, maxn> co_t;

maxn m, n, root[maxG], size[maxG], cnt[maxN][maxN], res[maxK], f[4][2] = { {-1, 0},{0,-1},{0,1},{1,0} };
maxk K;
co_t st[maxK], en[maxK];


void Prepare() {
	std::cin >> n >> m >> K;
	for (maxk k = 0; k < K; k++) {
		std::cin >> st[k].y >> st[k].x >> en[k].y >> en[k].x;
		for (maxn i = st[k].x; i <= en[k].x; i++) for (maxn j = st[k].y; j <= en[k].y; j++) ++cnt[i][j];
	}

	for (maxn i = 1; i <= m; i++) for (maxn j = 1; j <= n; j++) 
		root[idx(i, j)] = idx(i, j), size[idx(i, j)] = 1;

	for (maxn i = 1; i <= m; i++) cnt[i][0] = cnt[i][n + 1] = 1;
	for (maxn j = 1; j <= n; j++) cnt[0][j] = cnt[m + 1][j] = 1;
}


maxn Root(maxn a) {
	if (a != root[a]) root[a] = Root(root[a]);
	return root[a];
}


bool Union(maxn a, maxn b) {
	a = Root(a), b = Root(b);
	if (a == b) return 0;

	if (size[a] < size[b]) root[a] = b, size[b] += size[a];
	else root[b] = a, size[a] += size[b];
	return 1;
}


void Process() {
	for (maxn i = 1; i <= m; i++) for (maxn j = 1; j <= n; j++) {
		if (cnt[i][j]) continue;
		++res[K];
		if (!cnt[i - 1][j]) res[K] -= Union(idx(i, j), idx(i - 1, j));
		if (!cnt[i][j - 1]) res[K] -= Union(idx(i, j), idx(i, j - 1));
	}

	for (maxk k = K - 1; k > 0; k--) {
		res[k] = res[k + 1];
		for (maxn i = st[k].x; i <= en[k].x; i++) for (maxn j = st[k].y; j <= en[k].y; j++) {
			if (--cnt[i][j]) continue;
			++res[k];
			for (int k1 = 0; k1 < 4; k1++) {
				maxn x1 = i + f[k1][0], y1 = j + f[k1][1];
				if (!cnt[x1][y1]) res[k] -= Union(idx(i, j), idx(x1, y1));
			}
		}
	}

	for (maxk i = 1; i <= K; i++) std::cout << res[i] << '\n';
}


int main() {
	//freopen("draw.inp", "r", stdin);
	//freopen("draw.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}