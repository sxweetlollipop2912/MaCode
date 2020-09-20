#include <iostream>
#include <cstdio>
#include <queue>

#define maxN 100002

typedef long maxn;

maxn n, k, step;
maxn re[maxN];
std::queue <maxn> Queue;


void Prepare() {
	freopen("CUUHOA.inp", "r", stdin);
	freopen("CUUHOA.out", "w", stdout);
	std::cin >> n >> k;
}


bool Fit(maxn x) {
	return x >= 0 && x < maxN && re[x] == 0;
}


void Push(maxn u, maxn v) {
	re[v] = re[u] + 1;
	Queue.push(v);
}


void Add(maxn u) {
	maxn v = u + 1;
	if (Fit(v)) Push(u, v);
	v = u - 1;
	if (Fit(v)) Push(u, v);
	v = 2 * u;
	if (Fit(v)) Push(u, v);
}


void BFS() {
	Queue.push(n);
	re[n] = 1;

	while (re[k] == 0) {
		maxn len = Queue.size();
		for (maxn i = 0; i < len; i++) {
			Add(Queue.front());
			Queue.pop();
		}
	}
}


int main() {
	Prepare();
	BFS();
	std::cout << re[k] - 1;
}
