// not done
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 1001
#define maxM 1000001
#define maxC 1001
#define maxP 1001
#define maxT 3
#define maxQ 7
#define maxR 2000000001

typedef long maxn, maxm, maxc, maxp, maxr;

maxn n, cnt[maxT], S;
maxm m, min_c[maxN];
int Q;
bool choice[maxQ][maxT] = { { 1,0,0 },{ 0,1,0 },{ 0,0,1 },{ 1,1,0 },{ 1,0,1 },{ 0,1,1 },{ 1,1,1 } };
maxc d[maxN][maxN];
maxp p[maxT][maxN];
bool done[maxN];
maxr res[maxN];


void InputT(int id) {
	for (maxn i = 0; i < cnt[id]; i++) {
		maxn x;
		maxp pp;
		std::cin >> x >> pp;
		//p[id][x - 1] = pp;
		//std::cout << id << ' ' << x << ' ' << p[id][x] << '\n';
		if (!p[id][x - 1]) p[id][x - 1] = pp;
		else {
			p[id][x - 1] = std::min(p[id][x - 1], pp);
			cnt[id]--;
			i--;
		}
	}
}


void Prepare() {
	std::cin >> n >> m >> cnt[0] >> cnt[1] >> cnt[2] >> S >> Q;
	Q--; S--;

	for (maxm i = 0; i < m; i++) {
		maxn u, v, c;
		std::cin >> u >> v >> c;
		u--; v--;
		if (d[u][v]) c = std::min(d[u][v], c);
		d[u][v] = c;
		d[v][u] = c;
		//std::cout << u << ' ' << v << ' ' << c << ' '  << d[u][v] << '\n';
	}
	InputT(0);
	InputT(1);
	InputT(2);

	cnt[0] *= choice[Q][0];
	cnt[1] *= choice[Q][1];
	cnt[2] *= choice[Q][2];

	std::fill(min_c, min_c + n, maxC);
	//std::cout << Q << ' ' << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << '\n';
}


void Fill(maxn u) {
	for (maxn v = 0; v < n; v++)
		if (!done[v] && d[u][v]) min_c[v] = std::min(min_c[v], min_c[u] + d[u][v]);
}


maxn Find() {
	maxn re = -1;
	maxr re_m = maxR;
	for (maxn i = 0; i < n; i++)
		if (!done[i] && min_c[i] < re_m) {
			re_m = min_c[i];
			re = i;
		}
	return re;
}


bool UpdateCNT(maxn x) {
	if (x == -1) return 1;
	if (cnt[0] && p[0][x]) cnt[0]--;
	if (cnt[1] && p[1][x]) cnt[1]--;
	if (cnt[2] && p[2][x]) cnt[2]--;
	//std::cout << min_c[x] << ' ' << x << ' ' << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << '\n';
	return cnt[0] + cnt[1] + cnt[2] == 0;
}


void Dijkstra() {
	min_c[S] = 0;
	done[S] = 1;
	UpdateCNT(S);

	while (true) {
		Fill(S);
		S = Find();
		done[S] = 1;
		if (UpdateCNT(S)) break;
	}
}


void FillRes() {
	int t = 0;
	while (!choice[Q][t]) t++;

	for (maxn i = 0; i < n; i++) res[i] = min_c[i] + p[t][i];

	for (t = t + 1; t < maxT; t++) {
		if (!choice[Q][t]) continue;

		for (maxn i = 0; i < n; i++) {
			maxr num = res[i];
			bool check = 0;

			for (maxn j = 0; j < n; j++) {
				if (!p[t][j]) continue;

				maxr cand = (i != j) * min_c[j] + p[t][j];
				res[i] = std::min(!check * maxR + res[i], num + cand);
				check = 1;
			}
		}
	}
}


int main() {
	//freopen("muaqua.inp", "r", stdin);
	//freopen("muaqua.out", "w", stdout);
	Prepare();
	Dijkstra();
	FillRes();
	std::cout << *std::min_element(res, res + n);
}

