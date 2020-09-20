// AC 70/70
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

#define maxN 100001
#define X first
#define Y second
#define lu first
#define rd second
#define val first
#define idx second
#define abs(x) ((x) >= 0? (x) : -(x))

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> co_t;
typedef std::pair <co_t, co_t> rec_t;
typedef std::pair <maxa, maxn> v_t;

maxn n, low[maxN], num[maxN], par[maxN], CNT;
maxn s[maxN], S, res;
rec_t R[maxN];
std::map<maxa, std::vector <v_t>> mapXfi, mapXse, mapYfi, mapYse;
std::vector <maxn> ad[maxN], bridge;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		std::cin >> R[i].lu.X >> R[i].lu.Y >> R[i].rd.X >> R[i].rd.Y;

		mapXfi[R[i].lu.X].push_back(v_t(R[i].rd.Y, i));
		mapXse[R[i].lu.X].push_back(v_t(R[i].lu.Y, i));
		mapXfi[R[i].rd.X].push_back(v_t(R[i].rd.Y, i));
		mapXse[R[i].rd.X].push_back(v_t(R[i].lu.Y, i));

		mapYfi[R[i].lu.Y].push_back(v_t(R[i].lu.X, i));
		mapYse[R[i].lu.Y].push_back(v_t(R[i].rd.X, i));
		mapYfi[R[i].rd.Y].push_back(v_t(R[i].lu.X, i));
		mapYse[R[i].rd.Y].push_back(v_t(R[i].rd.X, i));
	}

	for (auto i = mapXfi.begin(); i != mapXfi.end(); i++)
		std::sort(i->second.begin(), i->second.end());
	for (auto i = mapXse.begin(); i != mapXse.end(); i++)
		std::sort(i->second.begin(), i->second.end());

	for (auto i = mapYfi.begin(); i != mapYfi.end(); i++)
		std::sort(i->second.begin(), i->second.end());
	for (auto i = mapYse.begin(); i != mapYse.end(); i++)
		std::sort(i->second.begin(), i->second.end());

	std::fill(par, par + n, -1);
}


maxn BS(std::vector <v_t> &V, maxn x) { //v[i].val >= x
	maxn l = 0, r = V.size() - 1;
	while (l != r) {
		maxn m = (l + r) / 2;
		if (V[m].val < x) l = m + 1;
		else r = m;
	}
	return V[l].val >= x ? l : V.size();
}


void SetPath(std::vector <v_t> &V, const maxn fi, const maxn se, const maxn u) {
	for (maxn i = BS(V, fi); i < V.size() && V[i].val <= se; i++) {
		maxn v = V[i].idx;
		if (u == v) continue;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
}


void SetGraph() {
	for (maxn u = 0; u < n; u++) {
		rec_t rU = R[u];
		
		SetPath(mapYfi[R[u].rd.Y], R[u].lu.X, R[u].rd.X, u);
		SetPath(mapYse[R[u].rd.Y], R[u].lu.X, R[u].rd.X, u);

		SetPath(mapYfi[R[u].lu.Y], R[u].lu.X, R[u].rd.X, u);
		SetPath(mapYse[R[u].lu.Y], R[u].lu.X, R[u].rd.X, u);

		SetPath(mapXfi[R[u].lu.X], R[u].rd.Y, R[u].lu.Y, u);
		SetPath(mapXse[R[u].lu.X], R[u].rd.Y, R[u].lu.Y, u);

		SetPath(mapXfi[R[u].rd.X], R[u].rd.Y, R[u].lu.Y, u);
		SetPath(mapXse[R[u].rd.X], R[u].rd.Y, R[u].lu.Y, u);
	}
}



void DFS_Br(const maxn u) {
	++S, s[u] = 1;
	low[u] = num[u] = ++CNT;

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];

		if (par[v] == -1) {
			par[v] = u;
			DFS_Br(v);
			low[u] = std::min(low[u], low[v]);
			s[u] += s[v];
			if (low[v] > num[u]) bridge.push_back(v);
		}
		else if (par[u] != v)
			low[u] = std::min(low[u], num[v]);
	}
}


void Process() {
	SetGraph();

	CNT = 0, res = maxN;
	for (maxn i = 0; i < n; i++)
		if (par[i] == -1) {
			S = 0;
			par[i] = i;
			DFS_Br(i);

			while (!bridge.empty()) {
				maxn v = bridge.back(), u = par[v];
				res = std::min(res, abs(S - 2 * s[v]));
				bridge.pop_back();
			}
		}

	if (res != maxN) std::cout << res;
	else std::cout << -1;
}


int main() {
	//freopen("building.inp", "r", stdin);
	//freopen("building.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}