#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 200001
#define Cap first
#define Cost second

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> inf_t;

maxn n, m, K;
maxa res;
inf_t ks[maxN], req[maxN];
std::priority_queue <maxa, std::vector <maxa>> pq, pq_res;


bool cmp_cost(const inf_t x, const inf_t y) {
	return x.Cost < y.Cost;
}
bool cmp_cap(const inf_t x, const inf_t y) {
	return x.Cap < y.Cap;
}

void Prepare() {
	std::cin >> n >> m >> K;

	for (maxn i = 0; i < n; i++) std::cin >> ks[i].Cost >> ks[i].Cap;
	for (maxn i = 0; i < m; i++) std::cin >> req[i].Cost >> req[i].Cap;

	std::sort(ks, ks + n, cmp_cost);
	std::sort(req, req + m, cmp_cap);
}


void Process() {
	for (maxn ik = 0, ir = 0; ik < n; ik++) {
		while (ir < m && req[ir].Cap <= ks[ik].Cap) pq.push(req[ir++].Cost);
		if (pq.empty() || pq.top() <= ks[ik].Cost) continue;
		pq_res.push(pq.top() - ks[ik].Cost); pq.pop();
	}
	while (K-- && !pq_res.empty()) {
		res += pq_res.top(); pq_res.pop();
	}
	std::cout << res;
}


int main() {
	//freopen("datphong.inp", "r", stdin);
	//freopen("datphong.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}