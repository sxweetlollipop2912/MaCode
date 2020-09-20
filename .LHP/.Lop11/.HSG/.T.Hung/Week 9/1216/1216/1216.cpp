// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <math.h>

#define maxN 10001
#define maxD 10000000001
#define X first
#define Y second
#define V first
#define Dist second
#define dist(cx, cy) ((cx.X - cy.X) * (cx.X - cy.X) + (cx.Y - cy.Y) * (cx.Y - cy.Y))

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> co_t;
typedef std::pair <maxn, maxa> pq_t;

maxn n, RT;
co_t co[maxN];
std::priority_queue <maxa, std::vector <maxa>> e_pq;

class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.Dist > p2.Dist;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;
bool done[maxN];


void Init() {
	pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp>();
	e_pq = std::priority_queue <maxa, std::vector <maxa>>();
	std::fill(done, done + n, 0);
	n = 0;
}


void Prepare() {
	std::cin >> RT;
	
	for (maxa x, y; std::cin >> x && x != -1;) {
		std::cin >> y;
		co[n].X = x, co[n].Y = y, ++n;
	}
}


void Prim() {
	pq.push(pq_t(0, 0));

	for (maxn i = 0; i < n; i++) {
		while (done[pq.top().V]) pq.pop();

		maxn u = pq.top().V; done[u] = 1; 
		e_pq.push(pq.top().Dist); pq.pop();

		for (maxn v = 0; v < n; v++)
			if (!done[v]) pq.push(pq_t(v, dist(co[u], co[v])));
	}
}


void Process() {
	Prim();
	for (maxn i = 1; i < RT && !e_pq.empty(); i++) e_pq.pop();
	if (e_pq.empty()) std::cout << "0\n";
	else std::cout << ceil(sqrt(e_pq.top())) << '\n';
}


int main() {
	//freopen("1216.inp", "r", stdin);
	//freopen("1216.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Init();
		Prepare();
		Process();
	}
}