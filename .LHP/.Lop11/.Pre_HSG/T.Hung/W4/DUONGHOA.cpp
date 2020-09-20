#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 10001
#define maxM 250001
#define maxL 1001
#define maxD 250000001
#define vert first
#define dist second
#define st 0
#define en (n - 1)

typedef long maxn, maxm, maxa;
typedef std::pair <maxa, maxn> ad_t, pq_t;

maxn n, m, Length;
maxa mn[maxN];
std::vector <ad_t> ad[maxN];
bool done[maxN];


void Prepare() {
	std::cin >> n >> m;
	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa d;
		std::cin >> u >> v >> d;
		ad[u].push_back(ad_t(v, d));
		ad[v].push_back(ad_t(u, d));
	}
}


//-------------------- DIJKSTRA --------------------------------

class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.dist > p2.dist;
	}
};
std::priority_queue  <pq_t, std::vector <pq_t>, cmp > pq;


void Fill(const maxn u) {
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].vert; maxa d = mn[u] + ad[u][i].dist;
		if (done[v] || mn[v] <= d) continue;
		mn[v] = d;
		pq.push(pq_t(v, mn[v]));
	}
}


maxn Find() {
	while (!pq.empty() && done[pq.top().vert]) pq.pop();
	if (pq.empty()) return -1;

	maxn re = pq.top().vert;
	pq.pop();
	return re;
}


maxa Dijkstra(maxn u, const maxn des) {
	std::fill(done, done + n, 0);
	std::fill(mn, mn + n, maxD);
	pq = std::priority_queue  <pq_t, std::vector <pq_t>, cmp >();

	mn[u] = 0;
	while (u != des) {
		done[u] = 1;
		Fill(u);
		u = Find();
	}
	return mn[des];
}

//------------------ END_OF_DIJKSTRA -------------------------------


maxa DFS(const maxn v, const maxa d, const maxa Length) {
	if (done[v]) return 0;
	done[v] = 1; 

	maxa re = 0;
	for (maxn i = 0; i < ad[v].size(); i++) {
		maxn u = ad[v][i].vert; 
		if (mn[u] + ad[v][i].dist + d == Length) 
			re += ad[v][i].dist + DFS(u, d + ad[v][i].dist, Length);
	}
	return re;
}


void Process() {
	Length = Dijkstra(st, en);

	std::fill(done, done + n, 0);
	std::cout << DFS(en, 0, Length) * 2;
}


int main() {
	freopen("duonghoa.inp", "r", stdin);
	freopen("duonghoa.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}