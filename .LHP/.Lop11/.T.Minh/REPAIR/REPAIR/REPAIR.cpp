#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 2002
#define maxA 10000000001
#define N (S + C)
#define Cid(x) (x)
#define Sid(x) ((x) + C)
#define vert first
#define cost second
#define x first
#define y second

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> pq_t;
typedef std::pair <maxn, maxn> e_t;

maxn C, S, par[maxN], cnt[maxN];
maxa d[maxN][maxN], mn[maxN], res;
bool connect[maxN][maxN], done[maxN];
std::vector <e_t> res_list;


void Prepare() {
	std::cin >> C >> S;
	for (maxn i = 1; i <= N; i++) for (maxn j = 1; j <= N; j++) d[i][j] = maxA;
	for (maxn i = 1; i <= C; i++) for (maxn j = 1; j <= S; j++) 
		std::cin >> d[Cid(i)][Sid(j)], d[Cid(i)][Sid(j)] = d[Sid(j)][Cid(i)] = d[Cid(i)][Sid(j)] == -1 ? maxA : d[Cid(i)][Sid(j)];
}


class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.cost > p2.cost;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


void Fill(const maxn u) {
	for (maxn v = 1; v <= N; v++) {
		if (done[v] || mn[v] <= d[u][v]) continue;
		mn[v] = d[u][v];
		par[v] = u;
		pq.push(pq_t(v, mn[v]));
	}
}


void Prim() {
	std::fill(mn, mn + N + 1, maxA);
	mn[1] = 0, par[1] = 1;
	pq.push(pq_t(1, mn[1]));

	for (maxn i = 1; i < N && !pq.empty(); i++) {
		maxn cur = pq.top().vert; pq.pop();
		done[cur] = 1;
		Fill(cur);
		while (!pq.empty() && pq.top().cost != mn[pq.top().vert]) pq.pop();
	}
}


void Process() {
	Prim();

	for (maxn i = 2; i <= N; i++) connect[par[i]][i] = connect[i][par[i]] = 1, ++cnt[i], ++cnt[par[i]];

	for (maxn s = 1; s <= S; s++) {
		for (maxn c = 1; cnt[Sid(s)] >= 2 && c <= C; c++) {
			if (!connect[Cid(c)][Sid(s)]) continue;
			if (d[Cid(c)][Sid(s)]) res_list.push_back(e_t(c, s));
			res += d[Cid(c)][Sid(s)];
		}
	}

	std::cout << res << '\n' << res_list.size() << '\n';
	for (maxn i = 0; i < res_list.size(); i++) std::cout << res_list[i].x << ' ' << res_list[i].y << '\n';
}


int main() {
	//freopen("repair.inp", "r", stdin);
	//freopen("repair.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}