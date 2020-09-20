#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 2001
#define maxM 4000001
#define des first
#define cost second

typedef int maxn;
typedef long long maxa;
typedef long maxm;
typedef std::pair <maxn, maxa> info;

maxn n;
maxm m;
maxa cmin[maxN], C[maxN][maxN], res;
bool done[maxN];


void Prepare() {
	std::cin >> n;

	maxa a[maxN];
	for (maxm i = 0; i < n; i++)
		std::cin >> a[i];

	for (maxn i = 0; i < n; i++)
		for (maxn j = 0; j < n; j++) C[i][j] = a[i] ^ a[j];
}


class cmp {
public:
	bool operator() (const info &x, const info &y) {
		return x.cost < y.cost;
	}
};
std::priority_queue <info, std::vector <info>, cmp > pq;


void Fill(const maxn &u) {
	for (maxn v = 0; v < n; v++) {
		maxa d = C[u][v];

		if (done[v] || d <= cmin[v]) continue;

		cmin[v] = d;
		pq.push(std::make_pair(v, cmin[v]));
	}
}


maxn Find() {
	while (!pq.empty() && done[pq.top().des]) pq.pop();
	if (pq.empty()) return -1;

	maxn re = pq.top().des;
	pq.pop();
	return re;
}


void Prim() {
	maxn cur = 0;
	cmin[cur] = 0;
	pq.push(std::make_pair(cur, cmin[cur]));

	for (maxn i = 0; i < n; i++) {
		cur = Find();
		done[cur] = 1;
		Fill(cur);
	}
}


void Process() {
	Prim();
	
	for (maxn i = 0; i < n; i++) res += cmin[i];
	std::cout << res;
}


int main() {
	freopen("game.inp", "r", stdin);
	freopen("game.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}