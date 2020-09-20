// AC UVa
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#pragma warning(disable:4996)

#define maxN 10000

typedef int maxn;

maxn st, en, f[4] = { 1, 10, 100, 1000 };
maxn step[maxN];


maxn nxt() {
	int a, b, c, d; std::cin >> a >> b >> c >> d;
	return a * f[3] + b * f[2] + c * f[1] + d * f[0];
}

void Prepare() {
	st = nxt(), en = nxt();

	maxn cnt; std::cin >> cnt;
	std::fill(step, step + maxN, -1);
	while (cnt--) step[nxt()] = -2;
}


maxn BFS(const maxn st, const maxn en) {
	std::queue <maxn> bfs;
	step[st] = 0; bfs.push(st);

	while (!bfs.empty() && bfs.front() != en) {
		maxn u = bfs.front(); bfs.pop();

		for (int i = 0; i < 4; i++) {
			maxn v = (u / f[i]) % 10 != 9 ? u + f[i] : u - f[i] * 9;
			if (step[v] == -1) {
				step[v] = step[u] + 1;
				bfs.push(v);
			}
			v = (u / f[i]) % 10 != 0 ? u - f[i] : u + f[i] * 9;
			if (step[v] == -1) {
				step[v] = step[u] + 1;
				bfs.push(v);
			}
		}
	}
	return step[en];
}


void Process() {
	std::cout << BFS(st, en) << '\n';
}


int main() {
	//freopen("10067.inp", "r", stdin);
	//freopen("10067.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Prepare();
		Process();
	}
}