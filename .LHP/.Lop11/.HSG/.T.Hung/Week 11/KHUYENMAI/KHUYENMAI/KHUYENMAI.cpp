// not done
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <bitset>

#define maxN 1002
#define mn first
#define mx second

typedef int maxn;
typedef std::pair <maxn, maxn> cnt_t;

maxn n, K, next[maxN], inS[maxN];
cnt_t cnt[maxN];
bool done[maxN], not_root[maxN];
std::vector <cnt_t> V;
std::bitset <maxN> bset[2];


void Prepare() {
	std::cin >> n >> K;
	for (maxn u = 1; u <= n; u++) std::cin >> next[u], not_root[next[u]] = u != next[u] ? 1 : not_root[next[u]];
}


maxn DFS(const maxn u, const maxn Cnt) {
	done[u] = cnt[u].mn = cnt[u].mx = 1;
	maxn v = next[u];
	if (!done[v]) {
		inS[u] = Cnt; maxn st = DFS(v, Cnt + 1);
		if (!st) cnt[u].mx += cnt[v].mx, cnt[u].mn = cnt[v].mn;
		else cnt[u] = cnt[v];
		if (st == u) st = 0;
		inS[u] = 0; return st;
	}
	if (inS[v]) {
		cnt[u].mn = cnt[u].mx = Cnt - inS[v] + 1; return v;
	}
	if (u != v) cnt[u].mx += cnt[v].mx, cnt[u].mn = cnt[v].mn; return 0;
}


void Process() {
	for (maxn u = 1; u <= n; u++) {
		if (not_root[u]) continue;
		DFS(u, 1); V.push_back(cnt[u]);
	}
	for (maxn u = 1; u <= n; u++) {
		if (done[u]) continue;
		DFS(u, 1); V.push_back(cnt[u]);
	}
	bool p = 1; bset[p][0] = 1;
	for (maxn i = 0; i < V.size(); i++, p = !p) {
		bset[p] = bset[!p];
		for (maxn j = V[i].mn; j <= V[i].mx; j++) bset[p] |= (bset[!p] << j);
	}
	for (maxn i = K; i >= 0; i--) if (bset[p][i]) {
		std::cout << i; return;
	}
}


int main() {
	Prepare();
	Process();
}