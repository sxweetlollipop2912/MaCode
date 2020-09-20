// AC UVa
// walk: 1km/h, sub: 4km/h, m -> km
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <sstream>

#pragma warning(disable:4996)

#define maxN 203
#define maxA 99999999999999999
#define t(st, en) (d[st][en] * (!sub[st][en]? 4 : 1))
#define d(x, y, X, Y) (sqrt((x - X) * (x - X) + (y - Y) * (y - Y)))
#define X first
#define Y second
#define V first
#define cost second
#define st 0
#define en 1


typedef int maxn;
typedef long double maxa;
typedef std::string str;
typedef std::pair <maxa, maxa> p_t;
typedef std::pair <maxn, maxa> pq_t;

maxn n;
str s;
p_t c[maxN];
maxa d[maxN][maxN], mn[maxN];
bool sub[maxN][maxN];

class cmp {
public:
	bool operator()(const pq_t p1, const pq_t p2) {
		return p1.cost > p2.cost;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


void Init() {
	memset(sub, 0, sizeof(sub));
	pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp>();
}


void Prepare() {
	std::cin >> c[st].X >> c[st].Y >> c[en].X >> c[en].Y;

	n = 2;
	std::cin.ignore();
	while (std::getline(std::cin, s) && !s.empty()) {
		maxn idx = n;
		std::stringstream ss(s);
		maxa x, y;
		while (ss >> x >> y && x != -1) {
			c[n].X = x, c[n].Y = y;
			if (n != idx) sub[n][n - 1] = sub[n - 1][n] = 1;
			++n;
		}
	}

	for (maxn i = 0; i < n; i++) for (maxn j = i; j < n; j++)
		d[i][j] = d[j][i] = d(c[i].X, c[i].Y, c[j].X, c[j].Y);
}


maxa Dijkstra() {
	std::fill(mn, mn + n, maxA);
	mn[st] = 0; pq.push(pq_t(st, mn[st]));

	while (!pq.empty()) {
		maxn u = pq.top().V; pq.pop();
		for (maxn v = 0; v < n; v++) {
			if (mn[u] + t(u, v) >= mn[v]) continue;
			mn[v] = mn[u] + t(u, v);
			pq.push(pq_t(v, mn[v]));
		}
		while (!pq.empty() && pq.top().cost != mn[pq.top().V]) pq.pop();
	}
	
	return mn[en];
}



void Process() {
	std::cout << round(Dijkstra() * (maxa)6 / (maxa)1000 / (maxa)4) << '\n';
}


int main() {
	//freopen("10389.inp", "r", stdin);
	//freopen("10389.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; bool pe = 1; std::cin >> t;

	std::cin.ignore();
	std::getline(std::cin, s);
	while (t--) {
		if (!pe) std::cout << '\n';
		else pe = 0;
		Init();
		Prepare();
		Process();
	}
}