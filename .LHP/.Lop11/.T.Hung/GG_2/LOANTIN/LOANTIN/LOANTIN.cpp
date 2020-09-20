#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#pragma warning(disable:4996)

#define maxN 10001

typedef int maxn, maxm;

maxn n, day[maxN], cnt[maxN];
std::vector <maxn> ad[maxN];
std::queue <maxn> bfs;


void Prepare() {
	std::cin >> n;

	for (maxn u = 0, m, v; u < n; u++) {
		std::cin >> m;
		while (m--) {
			std::cin >> v;
			ad[u].push_back(v);
		}
	}
}


void BFS(const maxn st) {
	day[st] = 0;
	bfs.push(st);

	while (!bfs.empty()) {
		maxn u = bfs.front(); bfs.pop();
		++cnt[day[u]];

		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i];
			if (day[v] != -1) continue;
			day[v] = day[u] + 1;
			bfs.push(v);
		}
	}
}


void Process() {
	maxn st; std::cin >> st;

	if (ad[st].empty()) {
		std::cout << "0\n";
		return;
	}

	std::fill(day, day + n, -1);
	std::fill(cnt, cnt + n,  0);
	BFS(st);

	maxn res = std::max_element(cnt, cnt + n) - cnt;
	std::cout << cnt[res] << ' ' << res << '\n';
}


int main() {
	//freopen("loantin.inp", "r", stdin);
	//freopen("loantin.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	int t; std::cin >> t;
	while (t--) Process();
}