#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <vector>

#define maxN 65
#define n 8
#define N 64
#define idx(x, y) ((x) * n + (y))
#define row(x) ((x) / n)
#define col(x) ((x) % n)
#define valid(x, y) ((x) >= 0 && (x) < n && (y) >= 0 && (y) < n)

typedef int maxn;

maxn pos[maxN], num[maxN], f[8][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2} }, par[maxN];


void Prepare() {
	for (maxn i = 0; i < N; i++) std::cin >> num[i], --num[i], pos[num[i]] = i;
}


void Route(const maxn st, const maxn en) {
	//std::cout << st << ' ' << en << '\n';
	std::queue <maxn> bfs;
	std::fill(par, par + N, -1);

	par[st] = st; bfs.push(st);

	while (!bfs.empty()) {
		maxn u = bfs.front(); bfs.pop();
		if (u == en) break;
		for (int i = 0; i < 8; i++) {
			maxn vx = row(u) + f[i][0], vy = col(u) + f[i][1], v = idx(vx, vy);
			if (!valid(vx, vy) || par[v] != -1) continue;
			par[v] = u;
			bfs.push(v);
		}
	}

	std::vector <maxn> route;
	for (maxn i = en; i != st; i = par[i]) route.push_back(i); route.push_back(st);

	for (maxn i = (maxn)route.size() - 1; i > 0; i--) {
		maxn u = route[i], v = route[i - 1];
		std::cout << (char)(col(u) + 'a') << n - row(u) << ' ' << (char)(col(v) + 'a') << n - row(v) << '\n';
	}
	for(maxn i = 1; i < (maxn)route.size() - 1; i++) {
		maxn u = route[i], v = route[i + 1];
		std::cout << (char)(col(u) + 'a') << n - row(u) << ' ' << (char)(col(v) + 'a') << n - row(v) << '\n';
	}
}


void Process() {
	for (maxn i = 0; i < N; i++) {
		if (num[i] != i) Route(i, pos[i]);
		pos[num[i]] = pos[i], num[pos[i]] = num[i], pos[i] = i, num[i] = i;
	}
}


int main() {
	//freopen("banco.inp", "r", stdin);
	//freopen("banco.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}