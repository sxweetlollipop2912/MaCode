#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define maxN 5001

typedef int maxn, maxm;

maxn n, cnt[maxN], A, B;
maxm m;
bool done[maxN];
std::vector <maxn> ad[maxN];
std::queue <maxn> q;


void Prepare() {
	std::cin >> A >> B >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; std::cin >> u >> v;
		ad[u].push_back(v); ++cnt[v];
	}
}


void Process() {
	for (maxn i = 0; i < n; i++) if (!cnt[i]) q.push(i);
	maxn Cnt = 0;

	while (!q.empty() && Cnt + q.size() <= A) {
		Cnt += q.size();
		for (maxn i = (maxn)q.size() - 1; i >= 0; i--) {
			maxn u = q.front();
			for (maxm i = 0; i < ad[u].size(); i++) {
				maxn v = ad[u][i];
				if (!(--cnt[v])) q.push(v);
			}
			q.pop();
		}
	}
	std::cout << Cnt << '\n';

	while (!q.empty() && Cnt + q.size() <= B) {
		Cnt += q.size();
		for (maxn i = (maxn)q.size() - 1; i >= 0; i--) {
			maxn u = q.front();
			for (maxm i = 0; i < ad[u].size(); i++) {
				maxn v = ad[u][i];
				if (!(--cnt[v])) q.push(v);
			}
			q.pop();
		}
	}
	std::cout << Cnt << '\n';
	std::cout << n - Cnt - (q.size()) * (Cnt != B);
}


int main() {
	//freopen("thangtien.inp", "r", stdin);
	//freopen("thangtien.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}