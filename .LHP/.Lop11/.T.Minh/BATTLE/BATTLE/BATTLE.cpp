#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>

#define maxN 1002
#define x first
#define y second
#define sqr(a) ((a) * (a))
#define d(a, b) ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y))

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> co_t;

maxn n, res;
co_t co[maxN];
maxa r[maxN], e[maxN];
bool done[maxN], inS[maxN], st[maxN];


void Prepare() {
	std::fill(done, done + n + 1, 0);
	std::fill(st, st + n + 1, 0);
	
	for (maxn i = 1; i <= n; i++) 
		std::cin >> co[i].x >> co[i].y >> r[i] >> e[i];
}


bool go(const maxn u, const maxn v) {
	return u != v && d(co[u], co[v]) <= sqr(r[u] + e[u] + r[v]);
}


bool DFS(const maxn u) {
	done[u] = inS[u] = 1;
	bool re = 0, flag = 1;

	for (maxn v = 1; v <= n; v++) {
		if (!go(u, v)) continue;

		flag = 0;
		st[v] |= (!done[v] || !inS[v]);
		if (!done[v]) re |= DFS(v);
		else re |= inS[v];
	}

	inS[u] = 0;
	return re || flag;
}


void Process() {
	res = 0;
	for (maxn u = 1; u <= n; u++)
		if (!done[u]) res += DFS(u);

	std::cout << res << ' ';
	for (maxn u = 1; u <= n; u++)
		if (!st[u]) std::cout << u << ' ';
	std::cout << '\n';
}


int main() {
	//freopen("battle.inp", "r", stdin);
	//freopen("battle.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) {
		Prepare();
		Process();
	}
}