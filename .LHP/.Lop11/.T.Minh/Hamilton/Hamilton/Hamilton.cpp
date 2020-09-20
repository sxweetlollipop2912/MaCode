#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 102
#define none 0
#define path 1
#define cycle 2

typedef int maxn, maxm;

maxn n, cnt[maxN], CNT = -1;
maxm m;
std::vector <maxn> ad[maxN], v, res;
bool done[maxN], map[maxN][maxN];
int state;


bool cmp(const maxn x, const maxn y) {
	return cnt[x] < cnt[y];
}


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		++cnt[u], ++cnt[v], map[u][v] = map[v][u] = 1;
		ad[u].push_back(v); ad[v].push_back(u);
	}

	for (maxn u = 1; u <= n; u++) {
		map[u][u] = 1;
		ad[0].push_back(u);
		std::sort(ad[u].begin(), ad[u].end(), cmp);
	}
	std::sort(ad[0].begin(), ad[0].end(), cmp);
}


void Copy(std::vector <maxn>& ve, const int st) {
	if (st <= state) return;
	state = st, res = ve;
}


void Try(const maxn u, std::vector <maxn>& ve) {
	done[u] = 1, ++CNT; ve.push_back(u);
	if (CNT == n) {
		Copy(ve, map[u][ve[1]] + 1);
		return;
	}

	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (done[v]) continue;
		Try(v, ve);
	}

	done[u] = 0, --CNT; ve.pop_back();
}


void Process() {
	Try(0, v);
	std::cout << state << '\n';
	for (maxn i = 1; i < res.size(); i++) std::cout << res[i] << ' ';
}


int main() {
	//freopen("hamilton.inp", "r", stdin);
	//freopen("hamilton.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}