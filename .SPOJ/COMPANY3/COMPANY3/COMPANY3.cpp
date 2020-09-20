// AC SPOJ
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 1001

typedef int maxn;
typedef long maxm;

maxn n, mch[maxN], res;
maxm m;
bool done[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; std::cin >> u >> v, --u, --v;
		ad[u].push_back(v);
	}
}


bool DFS(const maxn u) {
	if (done[u]) return 0;
	done[u] = 1;
	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (mch[v] != -1 && !DFS(mch[v])) continue;
		mch[v] = u; return 1;
	}
	return 0;
}


void Process() {
	std::fill(mch, mch + n, -1);
	for (maxn i = 0; i < n; i++) {
		std::fill(done, done + n, 0);
		res += DFS(i);
	}
	std::cout << n - res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}