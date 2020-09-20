// AC SPOJ
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 200002
#define N (2*n)

typedef long maxn, maxa;

maxn n, res;
maxa a[maxN], sum[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i], a[i + n] = a[i];
	for (maxn i = 1; i <= N; i++) sum[i] = a[i] + sum[i - 1];
}


class cmp {
public:
	bool operator() (const maxn x, const maxn y) {
		return sum[x] > sum[y];
	}
};
std::priority_queue <maxn, std::vector <maxn>, cmp> pq;


void Process() {
	for (maxn i = 1; i < n; i++) pq.push(i);

	for (maxn i = 1; i <= n; i++) {
		pq.push(i + n - 1);
		while (pq.top() < i) pq.pop();
		if (sum[pq.top()] - sum[i - 1] > 0) ++res;
	}

	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}