#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 2501
#define row(x) ((x) / n)
#define col(x) ((x) % n)
#define id(x, y) ((x) * n + (y))
#define valid(x, y) ((x) >= 0 && (x) < n && (y) >= 0 && (y) < n)

typedef int maxn;

maxn n, st = 0, en, step[maxN], f[8][2] = { {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };
std::vector <maxn> res;


void Prepare() {
	maxn x, y;
	std::cin >> n >> x >> y, --x, --y, en = id(x, y);
}


bool BFS(const maxn st, const maxn en) {
	std::queue <maxn> bfs;
	bfs.push(st); step[st] = 1;

	while (!bfs.empty()) {
		maxn u = bfs.front(), ux = row(u), uy = col(u); bfs.pop();
		if (u == en) return 1;

		for (int i = 0; i < 8; i++) {
			maxn vx = ux + f[i][0], vy = uy + f[i][1], v = id(vx, vy);
			if (!valid(vx, vy) || step[v]) continue;
			step[v] = step[u] + 1;
			bfs.push(v);
		}
	}
	return 0;
}


bool Process() {
	if (!BFS(st, en)) return 0;

	for(maxn v = en; v != st; res.push_back(v)) for (int i = 0; i < 8; i++) {
		maxn ux = row(v) + f[i][0], uy = col(v) + f[i][1], u = id(ux, uy);
		if (!valid(ux, uy) || step[u] != step[v] - 1) continue;
		v = u; break;
	}

	for (maxn i = res.size() - 1; i >= 0; i--) std::cout << row(res[i]) + 1 << ' ' << col(res[i]) + 1 << '\n';
	std::cout << row(en) + 1 << ' ' << col(en) + 1;
	
	return 1;
}


int main() {
	//freopen("horse.inp", "r", stdin);
	//freopen("horse.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}