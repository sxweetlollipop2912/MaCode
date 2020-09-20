#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 1001
#define maxA 1250000001
#define x first
#define y second
#define vert first
#define dist second
#define d(a, b) ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))

typedef int maxn;
typedef long maxa;
typedef std::pair <maxa, maxa> p_t;
typedef std::pair <maxn, maxa> pq_t;

maxn n;
bool done[maxN];
maxa res;
p_t p[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> p[i].x >> p[i].y;
}


class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.dist > p2.dist;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


void Prim() {
	pq.push(pq_t(0, 0));

	for (maxn i = 0; i < n; i++) {
		while (done[pq.top().vert]) pq.pop();

		maxn u = pq.top().vert; done[u] = 1;
		res = std::max(res, pq.top().dist);
		pq.pop();

		for (maxn v = 0; v < n; v++)
			if (!done[v]) pq.push(pq_t(v, d(p[u], p[v])));
	}
}


void Process() {
	Prim();
	std::cout << res;
}


int main() {
	//freopen("connect.inp", "r", stdin);
	//freopen("connect.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}