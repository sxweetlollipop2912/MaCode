#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 102
#define maxM 5051
#define U first
#define V second
#define opp(x) ((x) ^ 1)

typedef int maxn, maxm;
typedef std::pair <maxn, maxn> e_t;

maxn n, CNTodd, st;
bool cnt[maxN], done[maxM];
maxm m;
std::vector <e_t> e;
std::vector <maxm> ad[maxN];
std::vector <maxn> vec, res;


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; std::cin >> u >> v;
		ad[u].push_back(e.size());
		ad[v].push_back(opp(e.size()));
		e.push_back(e_t(u, v));
		e.push_back(e_t(v, u));
		cnt[u] = !cnt[u], cnt[v] = !cnt[v];
	}

	st = 1;
	for (maxn i = 1; i <= n; i++) {
		if (!cnt[i]) continue;

		ad[0].push_back(e.size());
		ad[i].push_back(opp(e.size()));
		e.push_back(e_t(0, i));
		e.push_back(e_t(i, 0));
		st = 0, ++CNTodd;
	}
}


void Process() {
	vec.push_back(st);

	while (!vec.empty()) {
		maxn u = vec.back();
		while (!ad[u].empty() && done[ad[u].back()]) ad[u].pop_back();

		if (!ad[u].empty()) {
			done[ad[u].back()] = done[opp(ad[u].back())] = 1;
			vec.push_back(e[ad[u].back()].V);
			ad[u].pop_back();
		}
		else {
			res.push_back(u); vec.pop_back();
		}
	}

	for (maxm i = 0; i < res.size(); i++) if (res[i] != 0) std::cout << res[i] << ' ';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}