#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 40001
#define maxA 9999999999999999

typedef int maxn, maxm;
typedef long long maxa;

maxn n, d1[maxN], d2[maxN], dd[maxN];
maxm m;
maxa X, Y, Z, res;
std::vector <maxn> ad[maxN];
bool done[maxN];
std::queue <maxn> bfs;


void Prepare() {
	std::cin >> X >> Y >> Z >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn x, y;
		std::cin >> x >> y, --x, --y;
		ad[x].push_back(y);
		ad[y].push_back(x);
	}
}


void BFS(const maxn st, maxn d[]) {
	std::fill(done, done + n, 0);
	std::fill(d, d + n, maxA);

	bfs.push(st); done[st] = 1, d[st] = 0;

	while (!bfs.empty()) {
		maxn u = bfs.front(); bfs.pop();
		for (maxm i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i];
			if (done[v]) continue;
			done[v] = 1, d[v] = d[u] + 1;
			bfs.push(v);
		}
	}
}


void Process() {
	BFS(0, d1); BFS(1, d2); BFS(n - 1, dd);
	res = maxA;
	for (maxn i = 0; i < n; i++) 
		if (d1[i] != maxA && d2[i] != maxA && dd[i] != maxA) res = std::min(res, (X * (maxa)d1[i]) + (Y * (maxa)d2[i]) + (Z * (maxa)dd[i]));
	std::cout << res;
}


int main() {
	//freopen("group.inp", "r", stdin);
	//freopen("group.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}