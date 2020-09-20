// AC Kattis
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 1000001
#define maxM 1000001

typedef long maxn, maxm;

maxn n;
maxm m;
bool done[maxN], inQ[maxN];
std::vector <maxn> ad[maxN], res;


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; 
		std::cin >> u >> v, --u, --v;
		ad[v].push_back(u);
	}
}


bool DFS(const maxn u) {
	done[u] = inQ[u] = 1;
	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (inQ[v] || (!done[v] && !DFS(v))) return 0;
	}
	inQ[u] = 0; res.push_back(u); 
	return 1;
}


bool Process() {
	for (maxn i = 0; i < n; i++) 
		if (!done[i] && !DFS(i)) return 0;

	for (maxn i = 0; i < res.size(); i++) std::cout << res[i] + 1 << '\n';
	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "IMPOSSIBLE";
}