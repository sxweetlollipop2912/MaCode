#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
#include <vector>

#define maxN 200001
#define id2(x) (x)
#define id1(x) ((x) + n2)
#define maxA 27
#define A 26
#define num(c) ((c) - 'A')
#define idx first
#define cost second

typedef long maxn;
typedef int maxa;
typedef std::string str;
typedef std::pair <maxn, maxn> pq_t;

maxn n, n1, n2, K, f[3][maxN], N[3], cnt[maxN][maxA], res;
str S;
int p;
bool done[maxN];


void Prepare() {
	std::cin >> n >> n1 >> n2 >> K >> S;

	for (maxn i = 0; i < n1; i++) f[0][i] = id1(i);
	for (maxn i = 0; i < n2; i++) f[1][i] = id2(i);
	p = 1, N[0] = n1, N[1] = n2;
}


class cmp {
public:
	bool operator()(const pq_t p1, const pq_t p2) {
		return p1.cost > p2.cost;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


void Process() {
	while (N[p] < S.size()) {
		p = (p + 1) % 3;
		maxn p1 = (p + 2) % 3, p2 = (p + 1) % 3;
		N[p] = N[p1] + N[p2];
		for (maxn i = 0; i < N[p1]; i++) f[p][i] = f[p1][i];
		for (maxn i = 0; i < N[p2]; i++) f[p][i + N[p1]] = f[p2][i];
	}

	for (maxn i = n1 + n2; i < n; i++) ++cnt[f[p][i]][num(S[i])];
	res = n;
	for (maxn i = 0; i < n1 + n2; i++) {
		res -= cnt[i][num(S[i])] + 1;
		for (maxa a = 0; a < A; a++) 
			if (a != num(S[i])) pq.push(pq_t(i, cnt[i][num(S[i])] - cnt[i][a]));
	}

	for (maxn i = 0; i < K && !pq.empty() && pq.top().cost < 0; i++) {
		res += pq.top().cost, done[pq.top().idx] = 1; pq.pop();
		while (!pq.empty() && done[pq.top().idx]) pq.pop();
	}

	std::cout << res;
}


int main() {
	//freopen("comstr.inp", "r", stdin);
	//freopen("comstr.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}