#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define maxN 1001
#define U first
#define V second

typedef int maxn;
typedef std::pair <maxn, maxn> e_t;

maxn N, M, res;
std::vector <maxn> ad[maxN];
std::vector <e_t> W;
std::set <e_t> set;
std::set <maxn> Wn;
std::map <e_t, maxn> map;


void Init() {
	N = M = res = 0;
	for (maxn i = 0; i < maxN; i++) ad[i].clear();
	W.clear();
	Wn.clear();
	set.clear();
	map.clear();
}


void Prepare() {
	maxn n, m, w;
	std::cin >> n >> m >> w;
	N += n, M += m;

	for (maxn i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		--u, --v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	for (maxn i = 0; i < w; i++) {
		maxn u, v;
		std::cin >> u >> v;
		--u, --v;
		ad[u].push_back(v);
		ad[v].push_back(u);

		W.push_back(e_t(std::min(u, v), std::max(u, v)));

		Prepare();
	}
}


void PushSet() {
	for (maxn i = 0; i < N; i++) for (maxn j = 0; j < ad[i].size(); j++)
		set.insert(e_t(std::min(i, ad[i][j]), std::max(i, ad[i][j])));
}


void Remove(maxn u, maxn v) {
	if (u > v) std::swap(u, v);
	Wn.insert(u);
	Wn.insert(v);

	set.erase(e_t(u, v));
	map[e_t(u, v)] += 2;

	for (maxn i = 0; i < ad[u].size(); i++) {
		e_t e = e_t(std::min(u, ad[u][i]), std::max(u, ad[u][i]));
		set.erase(e);
		++map[e];
	}
	for (maxn i = 0; i < ad[v].size(); i++) {
		e_t e = e_t(std::min(v, ad[v][i]), std::max(v, ad[v][i]));
		set.erase(e);
		++map[e];
	}
}


void Process() {
	PushSet();
	for (maxn i = 0; i < W.size(); i++) {
		if (set.find(e_t(W[i])) == set.end()) continue;
		res += 2;
		Remove(W[i].U, W[i].V);
		//std::cout << W[i].U + 1 << ' ' << W[i].V + 1 << '\n';
	}
	while (!set.empty()) {
		res += 2;
		//std::cout << (*set.begin()).U + 1 << ' ' << (*set.begin()).V + 1 << '\n';
		Remove((*set.begin()).U, (*set.begin()).V);
	}
	for (maxn i = 0, j; i < N; i++) {
		if (Wn.find(i) == Wn.end()) continue;

		for (j = 0; j < ad[i].size(); j++) {
			e_t e = e_t(std::min(i, ad[i][j]), std::max(i, ad[i][j]));
			if (map[e] == 1) break;
		}
		if (j == ad[i].size()) {
			for (j = 0; j < ad[i].size(); j++) {
				e_t e = e_t(std::min(i, ad[i][j]), std::max(i, ad[i][j]));
				--map[e];
			}
			//std::cout << i + 1 << '\n';
			--res;
		}
	}
	std::cout << res << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Init();
		Prepare();
		Process();
	}
}