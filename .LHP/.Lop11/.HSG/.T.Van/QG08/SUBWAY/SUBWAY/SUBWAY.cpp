#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>

#define maxN 20001
#define endl -1

typedef int maxn;

maxn n, X[maxN], Y[maxN], cnt[maxN];
std::vector <maxn> ad[maxN], V, res;
bool done[maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n - 1; i++) {
		std::cin >> X[i] >> Y[i], --X[i], --Y[i];
		ad[X[i]].push_back(i);
		ad[Y[i]].push_back(i);
		++cnt[X[i]], ++cnt[Y[i]];
	}
}


void DFS(const maxn u) {
	res.push_back(u + 1);

	while (!ad[u].empty() && done[ad[u].back()]) ad[u].pop_back();
	if (ad[u].empty()) return;

	maxn id = ad[u].back(), v = X[id] == u ? Y[id] : X[id];
	done[id] = 1, --cnt[u], --cnt[v]; 
	if (cnt[u] & 1) V.push_back(u);
	DFS(v);
}


void Process() {
	for (maxn i = 0; i < n; i++) if (cnt[i] & 1) V.push_back(i);

	res.push_back(0);
	while (!V.empty()) {
		maxn u = V.back(); V.pop_back();
		if (!(cnt[u] & 1)) continue;
		DFS(u);
		++res[0]; res.push_back(endl);
	}

	std::cout << res[0] << '\n';
	for (maxn i = 1; i < res.size(); i++) {
		if (res[i] == endl) std::cout << '\n';
		else std::cout << res[i] << ' ';
	}
}


int main() {
	//freopen("subway.inp", "r", stdin);
	//freopen("subway.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}