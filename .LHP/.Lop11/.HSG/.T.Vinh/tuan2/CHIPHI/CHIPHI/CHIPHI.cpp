#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 401
#define maxA 99999999999999999
#define M (n * (n - 1) / 2)
#define x first.first
#define y first.second
#define cost second

typedef int maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxn> e_t;
typedef std::pair <e_t, maxa> ef_t;

maxn n;
maxm m;
maxa C[maxN][maxN];
std::vector <ef_t> edge;


bool cmp(const ef_t e1, const ef_t e2) {
	return e1.cost < e2.cost;
}

void Prepare() {
	std::cin >> n >> m;
	for (maxm i = 0; i < M; i++) {
		maxn u, v; maxa a;
		std::cin >> u >> v >> a;
		--u, --v;
		C[u][v] = C[v][u] = a;
		edge.push_back(ef_t(e_t(u, v), a));
	}
}


void Floyd() {
	for (maxn k = 0; k < n; k++) for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++)
		C[i][j] = std::min(C[i][k] + C[k][j], C[i][j]);
}


maxa Alternative(const maxn u, const maxn v) {
	maxa re = maxA;
	for (maxn k = 0; k < n; k++) {
		if (k != u && k != v) re = std::min(re, C[u][k] + C[k][v]);
	}
	return re;
}


bool Process() {
	Floyd();
	maxm m1 = M;
	for (maxm i = 0; i < edge.size(); i++) {
		maxn u = edge[i].x, v = edge[i].y; 
		maxa a = edge[i].cost, alter = Alternative(u, v);
		if (C[u][v] != a) return 0;
		if (alter == a) --m1;
	}
	return m1 <= m;
}


int main() {
	//freopen("chiphi.inp", "r", stdin);
	//freopen("chiphi.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (Process()) std::cout << "YES";
	else std::cout << "NO";
}