#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 502
#define maxM 200001
#define U first
#define V second
#define opp(x) ((x) ^ 1)
#define idR(x) (x)
#define idC(x) ((x) + m)
#define N (m + n)

typedef int maxn, maxm;
typedef std::pair <maxn, maxn> e_t;

maxn m, n, CNTodd, st;
bool cnt[maxN], done[maxM];
int res[maxN][maxN];
std::vector <e_t> e;
std::vector <maxm> ad[maxN];
std::vector <maxn> vec, tour;


void Prepare() {
	std::cin >> m >> n;

	for (maxn u = idR(1); u <= idR(m); u++) for (maxn v = idC(1); v <= idC(n); v++) {
		bool p; std::cin >> p;
		if (!p) continue;

		ad[u].push_back(e.size());
		ad[v].push_back(opp(e.size()));
		e.push_back(e_t(u, v));
		e.push_back(e_t(v, u));
		cnt[u] = !cnt[u], cnt[v] = !cnt[v], res[u][v - m] = 1;
	}

	st = 1;
	for (maxn i = 1; i <= N; i++) {
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
			tour.push_back(u); vec.pop_back();
		}

		if (!vec.empty()) continue;
		for (maxn u = 0; u <= m; u++) {
			while (!ad[u].empty() && done[ad[u].back()]) ad[u].pop_back();
			if (ad[u].empty()) continue;
			vec.push_back(u); break;
		}
	}

	for (maxm i = 1; i < tour.size(); i++) {
		maxn u = tour[i - 1], v = tour[i];
		//std::cout << u << ' ' << v << '\n';
		if (!u || u > m || v <= m) continue;
		res[u][v - m] = 2;
	}

	for (maxn i = 1; i <= m; i++, std::cout << '\n') for (maxn j = 1; j <= n; j++) std::cout << res[i][j] << ' ';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}