#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 100001
#define maxM 1000001
#define pA first
#define pB second

typedef long maxn, maxm;
typedef std::pair <maxn, maxn> p_t;

maxn n, A, B, low[maxN], num[maxN], par[maxN], CNT;
maxm m, res;
std::vector <maxn> ad[maxN];
bool a[maxN], b[maxN];


void Prepare() {
	std::cin >> n >> m >> A >> B;
	for (maxn i = 0, u; i < A && std::cin >> u; i++) a[--u] = 1;
	for (maxn i = 0, u; i < B && std::cin >> u; i++) b[--u] = 1;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; std::cin >> u >> v, --u, --v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
}


p_t DFS(const maxn u) {
	num[u] = low[u] = ++CNT;
	p_t re; re.pA = a[u], re.pB = b[u];

	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];

		if (!num[v]) {
			par[v] = u;
			p_t cnt = DFS(v);
			low[u] = std::min(low[u], low[v]);

			if (low[v] > low[u] && (cnt.pA == 0 || cnt.pA == A || cnt.pB == 0 || cnt.pB == B)) ++res;
			re.pA += cnt.pA, re.pB += cnt.pB;
		}
		else if (par[u] != v) low[u] = std::min(low[u], num[v]);
	}

	return re;
}


void Process() {
	DFS(0);
	std::cout << res;
}


int main() {
	//freopen("dutcap.inp", "r", stdin);
	//freopen("dutcap.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}