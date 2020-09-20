#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>

#pragma warning(disable:4996)

#define N (26*2)
#define maxN (N + 1)
//#define maxM 1001
//#define maxP 1000000001 // 10^9
#define maxR (maxd)200000000001
#define cntCT 25
//#define costCT (double)20

typedef int maxn, maxm;
typedef long long maxd;

struct pq_t {
	maxn v; maxd d;
};
pq_t newPQ_t(maxn v, maxd d) {
	pq_t re; re.v = v; re.d = d;
	return re;
}

maxm m;
std::vector <maxn> ad[maxN];
maxn parent[maxN], start, des;
maxd re[maxN];
maxn id[123] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,-1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51 };
char toChar[N] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
bool done[maxN];

class cmp_pq {
public:
	bool operator()(const pq_t& p1, const pq_t& p2) {
		return p1.d > p2.d;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp_pq> pq;


void Init() {
	for (maxn i = 0; i < N; i++) ad[i].clear();

	pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp_pq>();
	std::fill(parent, parent + maxN, -1);
	std::fill(re, re + maxN, maxR);
	std::fill(done, done + maxN, 0);
}


void Prepare() {
	for (maxm i = 0; i < m; i++) {
		char u, v;
		std::cin >> u >> v;
		ad[id[u]].push_back(id[v]);
		ad[id[v]].push_back(id[u]);
	}

	char S, D; maxd P;
	std::cin >> P >> S >> D;

	start = id[D], des = id[S];
	re[start] = P;
}


maxd cost(maxn v, maxd d) {
	if (v > cntCT) return 1;

	maxd l = d, r = maxR;
	while (l != r) {
		maxd m = (l + r) / 2;
		if (m - ((m + 19) / 20) < d) l = m + 1;
		else r = m;
	}
	return l - d;
}


void Fill(maxn u) {
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		maxd new_d = re[u] + cost(v, re[u]);
		if (done[v] || re[v] <= new_d) continue;

		parent[v] = u;
		re[v] = new_d;
		pq.push(newPQ_t(v, re[v]));
	}
}


maxn Find() {
	while (!pq.empty() && done[pq.top().v]) pq.pop();
	if (pq.empty()) return -1;

	maxn re = pq.top().v;
	pq.pop();
	return re;
}


maxd Dijkstra() {
	re[start] += cost(start, re[start]);
	maxn cur = start;

	while (cur != -1 && cur != des) {
		done[cur] = 1;
		Fill(cur);
		cur = Find();
	}

	return cur == des ? re[des] : -1;
}


void Trace() {
	if (parent[des] == -1) return;

	maxn x = des;
	while (parent[x] != -1) {
		std::cout << toChar[x] << '-';
		x = parent[x];
	}
	std::cout << toChar[x] << '\n';
}


int main() {
	//freopen("toll.inp", "r", stdin);
	//freopen("toll.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q = 0;
	while (std::cin >> m) {
		if (m == -1) return 0;
		q++;
		std::cout << '#' << q << '\n';

		Init();
		Prepare();
		std::cout << Dijkstra() << '\n';
		Trace();
	}
}